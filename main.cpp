// working with sqlite3 api
#include <sqlite3.h>
#include <iostream>
using namespace std;

bool checkQuery(const char *query)
{
    return true;
}

bool query(sqlite3 *ppDb, const char *query)
{
    if (!ppDb)
        return false;

    if (!checkQuery(query))
        return false;

    sqlite3_stmt *stmt = nullptr;
    const char *pzTail = nullptr;

    if (!sqlite3_prepare(ppDb, query, -1, &stmt, &pzTail) == SQLITE_OK)
        return false;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        for (int i{0}; i < sqlite3_column_count(stmt); ++i)
        {
            cout << sqlite3_column_text(stmt, i) << "|";
        }
        cout << endl;
    }
    return true;
}

int main()
{
    sqlite3 *ppDb = nullptr;
    if (sqlite3_open("chinook.db", &ppDb) == SQLITE_OK)
    {
        const char *zSql = "SELECT * FROM albums;";
        query(ppDb, zSql);
    }
}