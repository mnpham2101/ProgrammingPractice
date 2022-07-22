# Write your MySQL, SQL server, Oracle  query statement below
select Employees.employee_id 
from Employees 
left join Salaries                                      
on Employees.employee_id=Salaries.employee_id           /* select all employee_ids from 2 tables */
where Salaries.salary is null                           /* pick out employee_ids where salary is nmissing */

union

select Salaries.employee_id 
from Salaries 
left join Employees                                      
on Employees.employee_id=Salaries.employee_id           /* select all employee_ids from 2 tables */
where Employees.name is null                            /* pick out employee_ids where name is missing */

order by employee_id