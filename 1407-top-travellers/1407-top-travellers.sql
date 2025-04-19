# Write your MySQL query statement below
select name, 
(select case 
when sum(distance) is not null then sum(distance) else 0 end 
from Rides R where R.user_id = U.id) as travelled_distance 
from Users U order by travelled_distance desc, name asc