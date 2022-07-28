# Description:
Table: Weather
```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
```
* id is the primary key for this table.
* This table contains information about the temperature on a certain day.
 

Write an SQL query to find all dates' Id with higher temperatures compared to its previous dates (yesterday).

Return the result table in any order.

The query result format is in the following example.

## Example 1:
```
Input: 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output: 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
Explanation: 
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
```

# Solution 1: Self join.
* A self join allows you to join a table to itself. It helps query hierarchical data or compare rows within the same table. A *self join* uses the inner join or `left join` clause. Because the query that uses the self join references the same table, the table alias is used to assign different names to the same table within the query.
* Normally, the table must contain a column (call it X) that acts as the `primary key` and a different column (call it Y) that stores values, which could be `foreign key` that can be matched up with the values in Column X.
* *To join a table itself means that each row of the table is combined with itself and with every other row of the table*.
* in our case, if we just use the follow query:
```
select 
    w1.id
from Weather as w1
join Weather as W2
order by tbl1.id
```
on table:
```
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
```
The output would be: 
```
+----+------------+-------------+----+------------+-------------+
|    |  col2      |  col3       |    | col5       | col6        |
+----+------------+-------------+----+------------+-------------+
| id | recordDate | temperature | id | recordDate | temperature |
+----+------------+-------------+----+------------+-------------+
| 1  | 2015-01-01 | 10          | 1  | 2015-01-01 | 10          |
| 1  | 2015-01-01 | 10          | 2  | 2015-01-02 | 25          |
| 1  | 2015-01-01 | 10          | 3  | 2015-01-03 | 20          |
| 1  | 2015-01-01 | 10          | 4  | 2015-01-04 | 30          |
| 2  | 2015-01-02 | 25          | 1  | 2015-01-01 | 10          | 
| 2  | 2015-01-02 | 25          | 2  | 2015-01-02 | 25          |
| 2  | 2015-01-02 | 25          | 3  | 2015-01-03 | 20          |
| 2  | 2015-01-02 | 25          | 4  | 2015-01-04 | 30          |
| 3  | 2015-01-03 | 20          | 1  | 2015-01-01 | 10          |
| 3  | 2015-01-03 | 20          | 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          | 3  | 2015-01-03 | 20          |
| 3  | 2015-01-03 | 20          | 4  | 2015-01-04 | 30          |
| 4  | 2015-01-04 | 30          | 1  | 2015-01-01 | 10          |
| 4  | 2015-01-04 | 30          | 2  | 2015-01-02 | 25          |
| 4  | 2015-01-04 | 30          | 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          | 4  | 2015-01-04 | 30          |
+----+------------+-------------+----+------------+-------------+
```
* from the output table of `self join`, we could add a condition to select `rows` such that the `temperature` on `col3` is less than the `temperature` on `col6` and the `recordDate` on `col2` and `col5` differ by only 1 date
```
where tbl1.recordDate = DATE_ADD(tbl2.recordDate, INTERVAL 1 DAY) and tbl1.temperature > tbl2.temperature
```
* Ref: https://www.sqlservertutorial.net/sql-server-basics/sql-server-self-join/