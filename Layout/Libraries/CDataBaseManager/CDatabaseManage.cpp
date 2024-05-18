#include "CDatabaseManage.h"

using namespace std;

static CProduct DB_Product_find(string Barcode,sqlite3* db)
{
    string sqlQuery = "SELECT * FROM productsDB WHERE Barcode = '" + Barcode + "'";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)    //Error Handle
    {
        cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return CProduct("", "", "", 0, "");
    }

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)   //Product Found
    {
        // Fetch the product details directly using sqlite3_column_* functions
        string name     = (const char *)sqlite3_column_text(stmt, 0);
        string price    = (const char *)sqlite3_column_text(stmt, 2);
        int quantity = sqlite3_column_int(stmt, 3);
        string supplier = (const char *)sqlite3_column_text(stmt, 4);

        sqlite3_finalize(stmt);
        return CProduct(name, Barcode, price, quantity, supplier);
    }

    cerr << "Product not found in the database." << std::endl;
    sqlite3_finalize(stmt);
    return CProduct("", "", "", 0, "");
}

CDatabaseManage::CDatabaseManage()
{}
CDatabaseManage::CDatabaseManage(const char* DB_Path,sqlite3* db)
{
    this->DB_Path = DB_Path;
    this->db = db;
}

CDatabaseManage::~CDatabaseManage(){
    sqlite3_close(db);
}

vector<CProduct> CDatabaseManage::InitDB(string JsonFilePath,sqlite3* db) {

    vector<CProduct> products;
    char*err;
    ifstream jsonFile(JsonFilePath);
    Json::Value JsonProduct;
    Json::Reader reader;
    reader.parse(jsonFile,JsonProduct);

    for (const Json::Value&JsonINDEX : JsonProduct) {
        string name = JsonINDEX["Name"].asString();
        string barcode = JsonINDEX["Barcode"].asString();
        string price = JsonINDEX["Price"].asString();

        string suplier = JsonINDEX["Suplier"].asString();

        int quantity = 0;           //Sets a default value so if the product doesnt exist the quantity will be 0


        //---------Quantity fetch from the DataBase------
        string fetch_qnty = "SELECT Quantity FROM productsDB WHERE Barcode = '" + barcode + "';";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, fetch_qnty.c_str(), -1, &stmt, NULL);

        if (rc == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                // Extract the quantity value from the result set
                quantity = sqlite3_column_int(stmt, 0);
            }

            sqlite3_finalize(stmt);
        } else {
            cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << endl;
        }
        //-----------------------------------------------

        CProduct product(name, barcode, price,quantity, suplier);     //Creates the product with the respective attributes
        products.push_back(product);                                     //Insert the product in the vector list

        if(DB_Product_find(barcode, db) == CProduct("", "", "",0, ""))   //If the return value of DB_Product_find() is NULL it means it didnt find that product in-
        {                                                                //the Data base so it can add it then.
            string write_cmd = "INSERT INTO productsDB (Name, Barcode, Price, Quantity, Suplier) VALUES ('" + name + "','" + barcode + "','" + to_string(quantity) + "','" + price + "','" + suplier + "');";
            int ce = sqlite3_exec(db, write_cmd.c_str(),NULL, NULL, &err);
            if(ce != SQLITE_OK){
                cerr << "Initial_table error: " << err;
            }
        }
    }
    return products;        //Returns the full object vector
}

void CDatabaseManage::DatabaseADD(string Scanned_barcode, vector<CProduct> &products,sqlite3* db,string JsonFilePath)
{
    ifstream jsonFile(JsonFilePath);
    Json::Value JsonPRDCT;
    Json::Reader reader;
    reader.parse(jsonFile,JsonPRDCT);

    for (CProduct &product : products) {                                                    //Walks the products list until the end
        if(DB_Product_find(Scanned_barcode,db).getBarcode() == product.getBarcode())        //If the scanned code is equal to an existent code-
        {                                                                                   //Then increment that product's quantity
            product.IncQuantity();                                                          //Incrementa em 1 a quantidade

            string updateQty = "UPDATE productsDB SET Quantity = " + to_string(product.getQuantity()) + " WHERE Barcode = '" + product.getBarcode() + "'"; //Sets the SQL command  to update qty value
            int rc = sqlite3_exec(db, updateQty.c_str(), nullptr, nullptr, nullptr);
            if (rc != SQLITE_OK)  cerr << "Error adding DB product quantity: " << sqlite3_errmsg(db) << endl;
        }
    }
}

void CDatabaseManage::DatabaseREM(string Scanned_barcode, vector<CProduct> &products,sqlite3* db,string JsonFilePath)
{
    ifstream jsonFile(JsonFilePath);
    Json::Value JsonPRDCT;
    Json::Reader reader;
    reader.parse(jsonFile,JsonPRDCT);

    for (CProduct &product : products) {                                                    //Walks the products list until the end
        if(DB_Product_find(Scanned_barcode,db).getBarcode() == product.getBarcode())        //If the scanned code is equal to an existent code-
        {                                                                                   //then increment that product's quantity
            if(product.getQuantity() > 0)product.DecQuantity();                               //Decrementa em 1 a quantidade


            string updateQty = "UPDATE productsDB SET Quantity = " + to_string(product.getQuantity()) + " WHERE Barcode = '" + product.getBarcode() + "'"; //Sets the SQL command  to update qty value
            int rc = sqlite3_exec(db, updateQty.c_str(), nullptr, nullptr, nullptr);
            if (rc != SQLITE_OK)  cerr << "Error removing DB product quantity: " << sqlite3_errmsg(db) << endl;
        }
    }
}

CProduct CDatabaseManage::DatabaseSearch(string Barcode,sqlite3* db)
{
    return DB_Product_find (Barcode,db);
}



void CDatabaseManage::DatabaseSale(vector<CProduct> &products_list)
{
    string FieldValues[products_list.size()];
    size_t LastProduct = products_list.size() - 1;
    int Flag_Buyed;

    //PURCHASE CHECKING...
    for (int x = 0; x < LastProduct; x++)
    {
        if (products_list[x].getBuyed_Qty() > 0)       //If the product was bought
        {
            products_list[x].setScansAmount(0);         //Resets the num of scanns for the next purchase start with 0 scans in each product
            Flag_Buyed = 1;
            FieldValues[x] = to_string(products_list[x].getBuyed_Qty()) + ",";
            cout << FieldValues[x] << endl;
            products_list[x].setBuyed_Qty(0);           //resets the buyed quantity for future purchases
        }
        else FieldValues[x] = ",,";
    }
    // Because the last product doesn't have a comma next to him
    if (products_list[LastProduct].getBuyed_Qty() > 0) //If the product was bought
    {
        products_list[LastProduct].setScansAmount(0);   //Resets the num of scanns for the next purchase start with 0 scans in each product
        Flag_Buyed = 1;
        FieldValues[LastProduct] = to_string(products_list[LastProduct].getBuyed_Qty());
        cout << FieldValues[LastProduct] << endl;
        products_list[LastProduct].setBuyed_Qty(0);     //resets the buyed quantity for future purchases
    }
    else FieldValues[LastProduct] = "";



    //In case of purchase it will update the website grafics
    if (Flag_Buyed)
    {
        Flag_Buyed = 0;

        //DATE AND TIME  FETCHING...
        time_t now = time(0);
        tm* localtime = gmtime(&now);
        int year = localtime->tm_year + 1900;
        int month = localtime->tm_mon + 1;

        string DateTime = to_string(year)+"-"+to_string(month)+"-"+ to_string(localtime->tm_mday)+"T"+to_string(localtime->tm_hour) +":"+to_string(localtime->tm_min)+":"+to_string(localtime->tm_sec);



        //WRITE TO THE .CSV FILE WITH THE UPDATED PURSHASE INFROMATION
        ofstream outputFile("bulk_update.csv");
        if (!outputFile.is_open())
        {
            cerr << "Erro ao abrir o arquivo CSV para escrita." << endl;
        }
        else
        {
            outputFile << "write_api_key=LDR330TRY4KZZOK7&time_format=absolute&updates=" + DateTime +",";   //Writes first the inicial infromation and then the Grafic values
            for (int i = 0; i <= LastProduct; i++)
            {
                outputFile << FieldValues[i];
            }
        }
        outputFile.close();                                                                                 //closes the the file on write mode



        //READS THE UPDATED INFROMATION FROM THE .CSV FILE
        ifstream file("bulk_update.csv");
        if (!file.is_open())
        {
            cerr << "Error opennig CSV file." << endl;
        }
        else
        {
            //Reads from the .csv file into the "file_contents" string
            stringstream buffer;
            buffer << file.rdbuf();
            string file_contents = buffer.str();
            file.close();                      //closes the read mode csv

            CURL *cURL;
            CURLcode res;

            cURL = curl_easy_init();           //cURL initialization
            if(cURL) {

                //Sets the URL with the desiared channel
                curl_easy_setopt(cURL, CURLOPT_URL, "https://api.thingspeak.com/channels/2349110/bulk_update.csv");

                //Sets the Data the will be sent in the request
                curl_easy_setopt(cURL, CURLOPT_POSTFIELDS, file_contents.c_str());      //Needs to be a Char* because cURL is a C language library

                //Executes the request
                res = curl_easy_perform(cURL);

                //Performing Error check
                if(res != CURLE_OK) cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;

                curl_easy_cleanup(cURL);
            }
            curl_global_cleanup();
        }
    }
}
