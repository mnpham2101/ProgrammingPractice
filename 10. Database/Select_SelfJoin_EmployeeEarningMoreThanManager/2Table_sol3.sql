# Write your MySQL query statement below
select 
    tableA.Name as 'Employee'
from 
    Employee as tableA,                         # cartesian product
    Employee as tableB
where 
    tableA.managerId = tableB.Id
    and
    tableA.salary > tableB.salary
    ;