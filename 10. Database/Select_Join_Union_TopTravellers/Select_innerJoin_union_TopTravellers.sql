# Write your MySQL query statement below  - the codes don't work for SQL Server
select name,sum(distance) as travelled_distance
from Users 
inner join Rides 
on Users.id=Rides.user_id
group by Rides.user_id
union
select name,0 from Users where id not in (select user_id from Rides)
order by travelled_distance desc,name asc