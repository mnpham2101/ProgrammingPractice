# Write your MySQL query statement below
select Product.product_id, Product.product_name
from Product
join Sales
on Product.product_id = Sales.product_id
# where sale_date between "2019-01-01" and "2019-03-31"
GROUP BY Product.product_id
HAVING max(Sales.sale_date)<= '2019-03-31' AND MIN(Sales.sale_date)>='2019-01-01';

