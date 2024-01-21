# Write your MySQL query statement below
SELECT x, y, z, IF(((x+y)>z AND (y+z)>x AND (x+z)>y), "Yes", "No") AS triangle 
FROM Triangle