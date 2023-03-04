## 单表聚合
- 已知关系DWVENDOR, 关系DWVENDOR,按V_AREACODE属性分组,选择行数,满足(V_CODE属性>=25595 且 V_NAME属性='Gomez Bros.')
  - CODE FROM WEIQIN
    ```
    SELECT * FROM DWENDOR
    WHERE V_CODE>=25595 AND V_NAME='Gomez Bros.'
    GROUP BY V_AREACODE
    ```
  - 标准答案
    ```
    SELECT COUNT(*) FROM DWVENDOR
    ```
- 已知关系DWDAYSALESFACT, 关系DWDAYSALESFACT,按TM_ID属性分组,选择SALE_UNITS属性所有值之和,SALE_PRICE属性最大值,满足(P_CODE属性='89-WRE-Q' 或 TM_ID属性<202)
  - code from weiqin
    ```
    SELECT SUM(SALE_UNITS),MAX(SALE_PRICE)
    FROM DWDAYSDALESFACT
    WHERE P_CODE='89-WRE-Q' OR TM_ID<202
    GROUP BY TM_ID
    ```
  - 标准答案
    ```
    SELECT SUM(SALE_UNITS),MAX(SALE_PRICE) 
    FROM DWDAYSALESFACT 
    WHERE (P_CODE='89-WRE-Q' OR TM_ID<202) 
    GROUP BY TM_ID
    ```
    区别好像在于我没有括号？但是我感觉这里的括号并不重要
  
## 双表
- 已知关系EMPLOYEE, 关系PROJECT2, 关系EMPLOYEE与关系PROJECT2进行交叉连接,选择所有属性
  - 标准答案：
    ```
    SELECT * FROM (EMPLOYEE cross join PROJECT2)
    ```
- 已知关系DWMANAGER, 关系DWPROJECT, 关系DWMANAGER与关系DWPROJECT进行自然连接,,选择所有属性,满足((MGR_ZIP属性='29185' 且 DWMANAGER的MGR_CODE属性<>DWPROJECT的MGR_CODE属性) 或 PROJ_BID_PRICE属性<>10314545)
  - code from weiqin:
    ```
    SELECT* FROM DWPROJECT JOIN DWMANAGER USING(MGR_CODE)
    WHERE MGR_ZIP='29185' OR PROJ_BIS_PRICE<>10314545
     ```
  - 标准答案
    ```
    SELECT * FROM (DWMANAGER natural join DWPROJECT) 
    WHERE ((MGR_ZIP='29185' 
    AND DWMANAGER.MGR_CODE<>DWPROJECT.MGR_CODE) 
    OR PROJ_BID_PRICE<>10314545)
    ```
    
    understanding:
    1. 我不太理解natural在哪里，since这两个表里面的值类型都不一样。
    2. “DWMANAGER.MGR_CODE<>DWPROJECT.MGR_CODE”意思是这两个键不可以等值？那我join出来的结果是什么？ -> 哦我理解了...给的e.g.里面DWPROJECT的前两行列名反了
    3. 那个不等条件就是用来麻我的，啥用没有
  
- 已知关系JOB, 关系CHARGE, 关系JOB与关系CHARGE进行内连接,(满足JOB的JOB_CODE属性=CHARGE的JOB_CODE属性),选择所有属性
  - code from weiqin:
    ```
    SELECT * FROM JOB JOIN CHARGE
    ON JOIB.JOB_CODE=CHARGE.JOB_CODE
    ```
  - 标答的join那里写的是inner join，我感觉好像没有必要诶
  
## 双表聚合

- 已知关系PAINTING, 关系PAINTER, 关系PAINTING与关系PAINTER进行内连接,(满足PAINTING的PAINTER_NUM属性=PAINTER的PAINTER_NUM属性),按PAINTING的PAINTER_NUM属性分组,选择PAINTING的PAINTER_NUM属性,满足(PAINTER_LNAME属性='McDonald' 或 PAINTER的PAINTER_NUM属性<>10016),且满足PAINTER的PAINTER_NUM属性最大值=10016
  - code from weiqin:
  ```
  SELECT PAINTING.PAINTING_NUM
  FROM PAINTING JOIN PAINTER USING (PAINTER_NUM)
  WHERE (PAINTER_LNAME='MxDonald' OR PAINTER_NUM <>1006) 
  AND MAX(PAINTER.PAINTER_NUM)=10016
  GROUP BY PAINTING.PAINTER_NUM
  ```
  - 标准答案
  ```
  SELECT PAINTING.PAINTER_NUM 
  FROM (PAINTING inner join PAINTER on PAINTING.PAINTER_NUM=PAINTER.PAINTER_NUM) 
  WHERE (PAINTER_LNAME='McDonald' 
  OR PAINTER.PAINTER_NUM<>10016) 
  GROUP BY PAINTING.PAINTER_NUM 
  HAVING MAX(PAINTER.PAINTER_NUM)=10016
  ```

  understanding:
  - eiiii他这里用了HAVING子句？？去搜搜用法
  
  

- 已知关系EMPLOYEE, 关系PROJECT2, 关系EMPLOYEE与关系PROJECT2进行交叉连接,,按EMP_AREA_CODE属性分组,选择行数,满足(EMP_LNAME属性='Ramoras' 或 EMP_INITIAL属性='D')
  - code from weiqin:
  ```
  SELECT COUNT(*)
  FROM EMPLOYEE CROSS JOIN PROJECT2
  WHERE (EMP_LNAME='Ramoras' OR EMP_INITIAL='D')
  GROUP BY EMP_AREA_CODE
  ```
