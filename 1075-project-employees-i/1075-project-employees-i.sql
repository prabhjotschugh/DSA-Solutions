# Write your MySQL query statement below
SELECT 
    prj.project_id, 
    ROUND(AVG(e.experience_years), 2) AS average_years
FROM employee e
RIGHT JOIN project prj 
    ON prj.employee_id = e.employee_id
GROUP BY prj.project_id;
