select 
    w1.id
from Weather as w1
join Weather as W2
on w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY) and w1.temperature > w2.temperature;
