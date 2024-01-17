# Write your MySQL query statement below
select * from Cinema where description != "boring" and id in (1,3,5,7,9) order by rating DESC;