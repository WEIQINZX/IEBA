import psycopg2
import hashlib
conn = psycopg2.connect(database='TEST', user='postgres', password='wqzx110087', host='127.0.0.1', port=5432)
cur = conn.cursor()

'''
cur.execute("SELECT * FROM coursearrangement")
origin = cur.rowcount
#这一行可以只算一次？或者在一开始设定为0？
n = origin
n += 1
name = input("Type ur coursename here:")
year = int(input("Type ur year here:"))
query = "INSERT INTO coursearrangement VALUES({0},'{1}',{2})".format(n, name, year)
cur.execute(query)
conn.commit()
cur.execute("SELECT * FROM coursearrangement")
for row in cur:
    print('id=%d,name=%s,year=%d'%row)
'''

'''
key = input("It's column?")
val = input("And what is it?")
query = "DELETE FROM coursearrangement WHERE {0}={1}".format(key, val)
cur.execute(query)
conn.commit()
cur.execute("SELECT * FROM coursearrangement")
for row in cur:
    print('id=%d,name=%s,year=%d'%row)
'''

'''
cur.execute("SELECT * FROM coursearrangement")
rows = cur.fetchall()
for row in rows:
    print(row[2])
    print(type(row[2]))
'''

'''
import hashlib
a = input("ur password:")
b = 'hahaha'
newa = hashlib.md5()
newa.update(a.encode("utf8"))
#newa.update(b.encode("utf8"))
print(newa.hexdigest())'''


'''num = input("choose a number:")
query = "SELECT * FROM coursearrangement"
query += " WHERE name LIKE '%{0}%'".format(num)
cur.execute(query)
for row in cur:
    print(row)'''

'''
num = int(input("choose a number:"))
query = "SELECT * FROM coursearrangement WHERE id={0}".format(num)
cur.execute(query)
n = cur.rowcount
print("There's %d things from him." %n) 
'''
'''
username = input("username:")
password = input("password:")
query = 'SELECT * FROM users'
cur.execute(query)
rows = cur.fetchall()
_Hash = hashlib.md5()
_Hash.update(password.encode("utf8"))
pwd = _Hash.hexdigest()
print(pwd)
for row in rows:
    print(row)
    if username == row[1]:
        if pwd == row[2]:
            print(row[0])
        else:
            print("inside:Nothing!")'''

'''li = []
for i in range(0, 3):
    ele = {
        'one': input("ur one:"),
        'two': input("ur two:")
    }
    li.append(ele)
print(li)'''


'''key = input("key:")
exempt_postage =input("bool = 0or1?")
state = input("state:")
price = input("price order:")
query = 'SELECT * FROM goods FULL OUTER JOIN orders ON (goods.id=orders.goods_id) WHERE'
if key:
    query += " (goods.name LIKE '%{0}%' OR goods.description LIKE '%{0}%') AND".format(key)'''

'''if exempt_postage is None:
    query += " (goods.exempt_postage=TRUE OR goods.exempt_postage=FALSE)"
elif exempt_postage:
    query += " (goods.exempt_postage=TRUE)"
else:
    query += " (goods.exempt_postage=FALSE)"'''

# cur.execute("select * from comment LEFT OUTER JOIN users ON (comment.user_id=users.id)")
# row = cur.fetchone()
# n = row[4]
# print(str(n)[:19])

# n = input("n= ")
# user_id = input("user_id= ")
# goods_id = input("goods_id=")
# content = input("say sth:")
# query = "INSERT INTO comment VALUES({0},{1},{2},{3}{4}{5})".format(n, user_id, goods_id, '"', content, '"')
# print(query)

content = input("content: ")
new = content.replace("'", "''")
print(new)