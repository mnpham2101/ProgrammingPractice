# Write your MySQL query statement below
# This is a good fix for attempt 2
SELECT name
FROM salesperson
WHERE sales_id NOT IN 
     (
         SELECT sales_id FROM orders WHERE com_id in (SELECT com_id from company where name = "RED")
     );
