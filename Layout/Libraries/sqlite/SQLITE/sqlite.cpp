#include "sqlite.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

Database::Database() {
    DB = nullptr;
};


Database::~Database(){
    if(DB){
        sqlite3_close(DB);
    }
}
int Database::openConnection(const char *s){
    char *messageError;
    if(sqlite3_open(s, &DB) != SQLITE_OK){
        sqlite3_free(messageError);
    }

}

int Database::closeConnection(){
    sqlite3_close(&DB);

}



int Database::createTable(const char* s)
{
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS PRODUCTS("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"NAME      TEXT NOT NULL, "
		"PRICE     INT NOT NULL, "
		"SUPPLIER  TEXT  NOT NULL, );";

	try
	{
		int exit = 0;

		exit = openConnection(s);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			sqlite3_free(messageError);
		}
		else
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

	return 0;
}


int Database::insertData(const char* s)
{
	char* messageError;
		
	string sql("INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Alice', 'Chapa', 35, 'Tampa', 'A');"
		"INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Bob', 'Lee', 20, 'Dallas', 'B');"
		"INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Fred', 'Cooper', 24, 'New York', 'C');");

	int exit = sqlite3_open(s);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in insertData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records inserted Successfully!" << endl;

	return 0;
}
