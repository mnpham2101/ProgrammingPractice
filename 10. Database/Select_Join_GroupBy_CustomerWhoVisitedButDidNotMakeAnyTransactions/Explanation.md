# Description:

Table: Visits
```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| visit_id    | int     |
| customer_id | int     |
+-------------+---------+
```
* visit_id is the primary key for this table.
* This table contains information about the customers who visited the mall.
 

Table: Transactions
```
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| transaction_id | int     |
| visit_id       | int     |
| amount         | int     |
+----------------+---------+
```
* transaction_id is the primary key for this table.
* This table contains information about the transactions made during the visit_id.
 

Write an SQL query to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.

Return the result table sorted in any order.

The query result format is in the following example.

## Example 1:
```
Input: 
Visits
+----------+-------------+
| visit_id | customer_id |
+----------+-------------+
| 1        | 23          |
| 2        | 9           |
| 4        | 30          |
| 5        | 54          |
| 6        | 96          |
| 7        | 54          |
| 8        | 54          |
+----------+-------------+
Transactions
+----------------+----------+--------+
| transaction_id | visit_id | amount |
+----------------+----------+--------+
| 2              | 5        | 310    |
| 3              | 5        | 300    |
| 9              | 5        | 200    |
| 12             | 1        | 910    |
| 13             | 2        | 970    |
+----------------+----------+--------+
Output: 
+-------------+----------------+
| customer_id | count_no_trans |
+-------------+----------------+
| 54          | 2              |
| 30          | 1              |
| 96          | 1              |
+-------------+----------------+
```

# Solution 1:

* From example, a Join of the 2 tables will be like the following:
```
+----------+-------------+----------------+----------+-------------+
|       Visits  tbl      |      Transactions tbl                   |    
+----------+-------------+----------------+----------+-------------+
| visit_id | customer_id | transaction_id | visit_id | Explantion   
+----------+-------------+----------------+----------+-------------+
| 1        | 23          |   12           |  1       |
| 2        | 9           |   12           |  2       |
| 4        | 30          |   null         |  null    |   customer didn't make a transaction
| 5        | 54          |   2            |  5       |
| 5        | 54          |   3            |  5       |
| 5        | 54          |   9            |  5       |
| 6        | 96          |   null         |  null    |   customer didn't make a transaction
| 7        | 54          |   null         |  null    |   customer didn't make a transaction
| 8        | 54          |   null         |  null    |   customer didn't make a transaction
```
* we need to make select so that rows corresponding to visit_id = 4, 6, 7 are selected. Those are when a customer visited but didn't make a transaction.
```
select customer_id,
count(visits.visit_id) as count_no_trans 
from Visits
left join Transactions
on Visits.visit_id = Transactions.visit_id
where Transactions.visit_id is null
```
* without `group by` we would have result as :
```
{"headers": ["customer_id", "count_no_trans"], "values": [[30, 4]]}
```
* `group by` help with extrapolating the row by 