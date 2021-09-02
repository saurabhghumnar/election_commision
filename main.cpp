// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include<iostream>
#include<mysql.h>
#include<windows.h>
#include<sstream>
#include "Person.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.0.104", "admin", "admin", "voting_system", 0, NULL, 0);
    if(conn){
        int qstate = 0;

        Person p;
        p.acceptPersonDetails();

        stringstream ss;
        stringstream s2;
        ss << "INSERT INTO person(name, age, gender) VALUES('" << p.getName() << "','" << p.getAge() << "','" << p.getGender() << "')";
        s2 << "select * from person";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
        query = s2.str();
        q = query.c_str();
        qstate = mysql_query(conn,q);
        MYSQL_RES *result;
        MYSQL_ROW row;
        result = mysql_store_result(conn);
         while(row=mysql_fetch_row(result))
            {
                cout<<"id: "<<row[0]<< " "
                    <<"name: "<<row[1]<< " "
                    <<"phone: "<<row[2]<<endl;
            }
        mysql_free_result(result);

    }else{
        cout << "Connection Error" << endl;
    }
    return 0;
}
