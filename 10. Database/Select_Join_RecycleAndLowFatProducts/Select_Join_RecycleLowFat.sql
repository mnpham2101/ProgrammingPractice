# Write your MySQL query statement below
select tableA.product_id
from Products as tableA
join Products as tableB
on
    tableA.low_fats = 'Y'
    and
    tableB.recyclable = 'Y'
    and tableA.product_id = tableB.product_id