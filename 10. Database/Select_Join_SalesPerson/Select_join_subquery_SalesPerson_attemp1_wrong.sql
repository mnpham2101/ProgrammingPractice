# Write your MySQL query statement below
select name from SalesPerson
join Orders
on Orders.sales_id = SalesPerson.sales_id
where Orders.com_id = (
                        select Company.com_id from Company where Company.name != "RED"          
                        )
                        # sub query will returns more than 1 rows