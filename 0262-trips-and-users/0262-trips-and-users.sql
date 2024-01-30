# Write your MySQL query statement below
SELECT Request_at AS Day, ROUND(SUM(IF(Status = 'completed', 0, 1))/COUNT(Status), 2) AS 'Cancellation Rate' 
FROM Trips 
WHERE Client_Id NOT IN (SELECT Users_Id FROM Users WHERE Banned = 'Yes') 
    AND Driver_Id NOT IN (SELECT Users_Id FROM Users WHERE Banned = 'Yes')
    AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Request_at;