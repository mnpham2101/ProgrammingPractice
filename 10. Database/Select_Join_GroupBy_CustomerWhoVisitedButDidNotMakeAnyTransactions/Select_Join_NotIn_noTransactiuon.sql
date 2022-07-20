select customer_id, 
    count(customer_id) as 'count_no_trans' 
from visits 
where visit_id not in(select distinct(visit_id) from Transactions ) 
group by customer_id;