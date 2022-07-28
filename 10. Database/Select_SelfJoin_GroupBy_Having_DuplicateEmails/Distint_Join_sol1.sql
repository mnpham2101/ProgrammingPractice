select distinct tableA.email as "email" 
from person as tableA
    join person as tableB
where 
    tableA.email = tableB.email
    and tableA.Id !=tableB.Id