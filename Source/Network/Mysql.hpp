#ifndef CONFICIA_MYSQL_HPP
#define CONFICIA_MYSQL_HPP

/*
Installation:
sudo apt-get install mysql-server
sudo apt-get install mysql-client
sudo apt-get install libboost
sudo apt-get install libmysqlcppconn
sudo apt-get install libmysqlclient

Linker:
mysqlcppconn-static
mysqlclient

Directories Compiler:
/usr/include

Directories Linker:
/usr/lib
*/

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

namespace cf
{

class Mysql
{
    public:
        Mysql()
        {
        }

        struct DatabaseInfo
        {
            DatabaseInfo(){}

            std::string address;
            std::string username;
            std::string password;
            std::string database;
        };

        ///
        /// Connect to the database using info
        ///
        bool connect(DatabaseInfo info)
        {
            /* Create a connection */
            mDriver = get_driver_instance();
            mCon = mDriver->connect(info.address, info.username, info.password);
            /* Connect to the MySQL test database */
            mCon->setSchema(info.database);

            return !mCon->isClosed();
        }

        ///
        /// Connect to the database using parameters
        ///
        bool connect(std::string const& address, std::string const& username, std::string const& password, std::string const& database)
        {
            DatabaseInfo info;
            info.address = address;
            info.username = username;
            info.password = password;
            info.database = database;
            return connect(info);
        }

        ///
        /// Execute a query and return the result
        ///
        sql::ResultSet* query(std::string const& query)
        {
            if (!mCon->isClosed())
            {
                mStmt = mCon->createStatement();
                mRes = mStmt->executeQuery(query);
                return mRes;
            }
            else
            {
                return nullptr;
            }
        }

        ///
        /// Check if the database is connected
        ///
        bool isConnected() const
        {
            return !mCon->isClosed();
        }

    private:
        sql::Driver* mDriver;
        sql::Connection* mCon;
        sql::Statement* mStmt;
        sql::ResultSet* mRes;
};

}

#endif // CONFICIA_MYSQL_HPP
