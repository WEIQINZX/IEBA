# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import psycopg2
from psycopg2 import pool

def get_database_info():
    try:
        conn = psycopg2.connect(
            user = 'postgres',
            password = 'yourpassword',
            host = 'localhost',
            database = 'postgres'
        )
        cursor = conn.cursor()
        query = "SELECT user, current_database(), version()"
        cursor.execute(query)
        print('[user] %s\n[database] %s\n[version] %s' % cursor.fetchone())
    except psycopg2.Error as err:
        print(err)
    else:
        conn.close()

def list_cars():
    try:
        config = {
            'user': 'postgres',
            'password': 'yourpassword',
            'host': '127.0.0.1',
            'database': 'postgres'
        }
        conn = psycopg2.connect(**config)
        cursor = conn.cursor()
        query = 'SELECT name, price FROM cars ORDER BY price'
        cursor.execute(query)
        for row in cursor:
            print('%s: %s' % row)
    except psycopg2.Error as err:
        print(err)
    else:
        conn.close()

def init_conn_pool():
    config = {
            'user': 'postgres',
            'password': 'yourpasswor',
            'host': '127.0.0.1',
            'database': 'postgres'
        }
    conn_pool = pool.SimpleConnectionPool(minconn=2, maxconn=5, **config)
    return conn_pool

def show_car(conn_pool, name):
    try:
        conn = conn_pool.getconn()
        cursor = conn.cursor()
        query = 'SELECT name, price FROM cars WHERE name=%s'
        cursor.execute(query, (name, ))
        for row in cursor:
            print("%s: %s" % row)
    except psycopg2.Error as err:
        print(err)
    else:
        conn.close()

def update_car(conn_pool, name, price):
    try:
        conn = conn_pool.getconn()
        cursor = conn.cursor()
        query = 'UPDATE cars SET price=%s WHERE name=%s'
        cursor.execute(query, (price, name))
        print('%s row(s) updated' % cursor.rowcount)
        conn.commit()
    except psycopg2.Error as err:
        print(err)
    else:
        conn.close()


if __name__ == '__main__':
    get_database_info()
    list_cars()
    conn_poll  = init_conn_pool()
    show_car(conn_poll, 'Citroen')
    update_car(conn_poll, 'Citroen', 21500)
    show_car(conn_poll, 'Citroen')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/

