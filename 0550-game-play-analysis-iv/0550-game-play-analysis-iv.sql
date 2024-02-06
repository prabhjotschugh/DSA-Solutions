# Write your MySQL query statement below
SELECT ROUND(COUNT(distinct a1.player_id)/(SELECT count(distinct player_id) FROM Activity),2) as fraction FROM Activity a1 
JOIN Activity a2
    ON a1.event_date = DATE_ADD(a2.event_date,INTERVAL 1 DAY) AND a1.player_id = a2.player_id
WHERE (a2.player_id,a2.event_date) IN
  (SELECT player_id,min(event_date) FROM Activity 
   GROUP BY player_id)
