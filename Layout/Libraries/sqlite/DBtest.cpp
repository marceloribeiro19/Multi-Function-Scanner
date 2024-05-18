#include <iostream>
#include <string>
#include <fstream>

//#include "json-develop/single_include/nlohmann/json.hpp"
#include "jsoncpp-master/include/json/value.h"
#include "jsoncpp-master/include/json/json.h"

#include "SQLITE/sqlite3.h"
#include "CDatabaseManage.h"
#include "CProduct.h"

using namespace std;   

void thread_DBM()
{
    


}

int main(){

const char* db_directory= "BaseDeDados";

sqlite3* db;
vector<CProduct> Products_List;

string Barcode1 = "A-0001-Z";
string Barcode2 = "A-0002-Z";
string Barcode3 = "A-0003-Z";

sqlite3_open(db_directory, &db);
CDatabaseManage DB(db_directory,db);
Products_List = DB.InitDB("Products.json",db_directory,db);
//-------------------------------------

    int x;  
    switch (x)
    {
        case 0: // add product
            DB.DatabaseADD(Barcode1, Products_List,db,db_directory);
        break;
        case 1: //remove product
            DB.DatabaseREM(Barcode2, Products_List,db,db_directory);
        break;
        case 2: // search product
            cout << DB.DatabaseSearch(Barcode1,db).getQuantity() << endl;
        break;
        case 3: //register sale
            DB.DatabaseSale(Products_List); 
        break;
    }



/*
    DB.DatabaseADD(Barcode1, Products_List,db,db_directory);
    DB.DatabaseADD(Barcode2, Products_List,db,db_directory);


    /*DB.DatabaseREM(Barcode1, Products_List,db,db_directory);
    DB.DatabaseREM(Barcode2, Products_List,db,db_directory);
    DB.DatabaseREM(Barcode3, Products_List,db,db_directory);
    

    cout << DB.DatabaseSearch(Barcode1,db).getQuantity() << endl;
    cout << DB.DatabaseSearch(Barcode2,db).getQuantity() << endl;
    cout << DB.DatabaseSearch(Barcode3,db).getQuantity() << endl;

    for (int x=0; x< Products_List.size();x++){
        cout << Products_List[x].getName()<<endl;
        cout << Products_List[x].getBarcode()<<endl;
        cout << Products_List[x].getPrice()<<endl;
        cout << Products_List[x].getQuantity()<<endl;
        cout << Products_List[x].getSuplier ()<<endl;
    
        Products_List[x].setBuyed_Qty(x+1);
    }
    //roducts_List[Products_List.size()-1].setBuyed_Qty(0);
    DB.DatabaseSale(Products_List);             //REQUIRES THE PRODUCT SET BUYED QUANTITY FIRST
    */
    return 0;
}