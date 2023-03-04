## Data Definition Language

### ALTER TABLE
相当于对于表格进行修补
```
ALTER TABLE (table1) ADD <colname> <property>
ALTER TABLE <table2> ALTER <colname> DROP DEFAULT
ALTER TABLE <table3> ALTER <colname> SET DEFAULT <new default>
ALTER TABLE <table3> ALTER <colname> TYPE <new type>
```
**notice:**
- 改类型时要注意原有数据的size能不能fit进新的类型里
- 改不好的时候系统可能可以给你一个hint

### Indexes
**index key**: index's reference point that leads to
```
CREATE INDEX <indexname> ON <字段名字> WHERE <property>=x
```
建立index之后找对应项就快很多，但显然我们好像不会对每一个行都建立index...?

drawback of indexes： 存储空间换时间
Each index is associated with only one table -> the index key can have multiple attributes.

**CREATE/DESTROY AN INDEX**:
```
CREATE UNIQUE INDEX <indexname> ON <table(colname)>
```

### CREATING A VIEW
CREATE:
```
CREATE VIEW view_name[<col_list>]
AS select_statement
```

DESTROY:
```
DROP VIEW [IF EXISTS] view_name [RESTRICTS | CASCADE]
```
看一个view的语句也是 `SELECT *  FROM view_name`
- 在基表里面做的改动，在view里面也会体现
- view里面的数据改变了，也可以体现在基表里面的
  - 如果我不想因为对于视图的改动而导致基表改变呢？ -> materialize
  ```
  CREATE MATERIALIZED VIEW view_name
  ```
  这时候再改动view里面的信息，就会报错“不能改变物化视图”view_name“.

### SEQUENCES
CREATE SEQUENCE - define a new sequence generator

### Transactions
```
START TRANSACTION;
STATEMENT1;
STATEMENT2;
STATEMENT3;
COMMIT/ROLLBACK; 
```
- commit:
- rollback:





## big-hw
a second-hand goods reading platform
document看网络学堂