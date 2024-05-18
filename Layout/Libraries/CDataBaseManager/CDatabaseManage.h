#ifndef __DATABASE_
#define __DATABASE_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <unistd.h>

#include "../Projeto-Scanner-main/libraries/CProduct/CProduct.h"
#include "../Projeto-Scanner-main/libraries/jsoncpp-master/include/json/value.h"
#include "../Projeto-Scanner-main/libraries/jsoncpp-master/include/json/json.h"
#include "../Projeto-Scanner-main/libraries/SQLITE/sqlite3.h"
#include "../Projeto-Scanner-main/libraries/curl/include/curl/curl.h"
//#include "cURL/include/curl/easy.h"


class CDatabaseManage
{
public:
    CDatabaseManage();
    CDatabaseManage(const char* DB_Path, sqlite3* db);
    ~CDatabaseManage();

    vector<CProduct> InitDB(string JsonFilePath,sqlite3* db);
    void DatabaseADD(string Scanned_barcode, vector<CProduct> &products,sqlite3* db,string JsonFilePath);
    void DatabaseREM(string Scanned_barcode, vector<CProduct> &products,sqlite3* db,string JsonFilePath);
    CProduct DatabaseSearch(string Barcode,sqlite3* db);
    void DatabaseSale(vector<CProduct> &Bill);


private:

    const char* DB_Path;
    sqlite3* db;
};

#endif
