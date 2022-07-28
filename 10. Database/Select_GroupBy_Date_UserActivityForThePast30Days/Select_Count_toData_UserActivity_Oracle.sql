select to_char(activity_date,'yyyy-mm-dd') day,
        count(distinct user_id) active_users
from Activity 
where 
    to_date(activity_date) between
    to_date('2019-07-28')-30 and to_date('2019-07-27')
group by to_char(activity_date,'yyyy-mm-dd')