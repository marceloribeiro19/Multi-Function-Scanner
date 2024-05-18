#ifndef __DATABASE_
#define __DATABASE_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <unistd.h>

#include "CProduct.h"
#include "jsoncpp-master/include/json/value.h"
#include "jsoncpp-master/include/json/json.h"
#include "SQLITE/sqlite3.h"
#include "curl/include/curl/curl.h"

class CDatabaseManage
{
public:
    CDatabaseManage();
    CDatabaseManage(const char* DB_Path, sqlite3* db);
    ~CDatabaseManage();

    vector<CProduct> InitDB(string JsonFilePath,sqlite3* db);
    void addOperation(string Scanned_barcode, vector<CProduct> &products,sqlite3* db);
    void remOperation(string Scanned_barcode, vector<CProduct> &products,sqlite3* db);
    CProduct searchOperation(string Barcode,sqlite3* db);
    void saleOperation(vector<CProduct> &Bill);

private:
    const char* DB_Path;
    sqlite3* db;
};

#endif
