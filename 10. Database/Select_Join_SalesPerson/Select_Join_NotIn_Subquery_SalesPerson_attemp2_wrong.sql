# Write your MySQL query statement below
select name from SalesPerson
join Orders
on Orders.sales_id = SalesPerson.sales_id
where Orders.com_id not in (
                        select Company.com_id from Company where Company.name = "RED"          
                        )
# Bug: the suborder will pick out com_id =1 in Company table and Where clause returns Com_id = 3, 4. 
#It should be noted that a saleperson with sale_id = 4 could multiple buys, thus have both com_id=1 and com_id = 4

/*
+----------+------------+--------+----------+--------+
| order_id | order_date | com_id | sales_id | amount |
+----------+------------+--------+----------+--------+
| 1        | 1/1/2014   | 3      | 4        | 10000  |     ==> the above subquery result in 3, 4
| 2        | 2/1/2014   | 4      | 5        | 5000   |
| 3        | 3/1/2014   | 1      | 1        | 50000  |
| 4        | 4/1/2014   | 1      | 4        | 25000  |     ==> but sale_id = 4 made purchase for both companies. 
+----------+------------+--------+----------+--------+


*/