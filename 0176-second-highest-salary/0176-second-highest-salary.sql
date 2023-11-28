# Write your MySQL query statement below

SELECT MAX(Salary) AS SecondHighestSalary 
FROM Employee
WHERE Salary NOT IN (
    SELECT MAX(Salary) FROM Employee
)