# Write your MySQL query statement below
SELECT DEPT.name AS Department, EMP.name AS Employee, EMP.salary AS Salary 
FROM Department DEPT, Employee EMP WHERE
EMP.departmentId = DEPT.id AND (EMP.departmentId, salary) IN 
(SELECT departmentId, MAX(salary) FROM Employee GROUP BY departmentId)