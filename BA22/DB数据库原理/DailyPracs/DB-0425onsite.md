## PL/pgSQL 存储过程相关的过程化语言

### PROCEDURE/FUNCTION

```
CREATE OR REPLACE PROCEDURE addstaff(inputNum int) AS $$
DECLARE mynum smallint = 0;
BEGIN
    WHILE mynum < inputnum LOOP
    INSERT INTO Staff VALUES(...)
    mynum:=mynum+1
    END LOOP
END

```

看notes注意procedure和function的区别，写个notice

$$指的是从这里开始是我的函数过程
FUNCTION是有return的


###processing with cursors
可以用于把查到的东西放到一个列表里方便你一条一条处理
声明变量的时候可以用`变量A%TYPE`来说明我的新变量类型就是和变量A是一样的
然后写游标的代码
declaration里面也要声明游标捏

在正式的代码字段里要打开游标，用完了关上，具体的东西看老师发的NOTE

### trigger触发器
在某个条件下被触发，并开始执行对应操作
写触发器的具体语句->看note
可以用于用户进行更新、删除商品信息
还可以用于技术处理统计值

可以在insert、update操作之前或之后，具体可以看手册
触发级别可以是语句级的，也可以是行级的
在pg里面触发器和触发器函数是可以分开写的

### 嵌入SQL语句
意思大概是可以把SQL嵌入到c/c++/python等别的语言里面

### Extensions
`CREATE EXTENSION plpython3u` 就是用于引入一个python3的扩展
此后可以用来写函数：
- 比如可以调用所有D盘下的文件
- 比如可以写个计算器什么的

