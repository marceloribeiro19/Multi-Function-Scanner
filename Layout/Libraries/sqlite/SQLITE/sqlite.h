#ifndef SQLITE_H
#define SQLITE_h
#include <sqlite3.h>

class Database{
    private:
    sqlite3* DB;
    public:
    Database();
    ~Database();
    int openConnection(const char* s);
    int closeConnection();
    int createDB(const char* c);
    int createTable(const char* s);
    int deleteData(const char* s);
    int insertData(const char* s);
    int updateData(const char* s);  
    int selectData(const char* s);

};

#endif
