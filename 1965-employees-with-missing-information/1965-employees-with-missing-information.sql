# Write your MySQL query statement below
select Employees.employee_id from Employees natural left join Salaries 
where Salaries.salary is null
union 
select Salaries.employee_id from salaries natural left join Employees 
where Employees.name is null
order by employee_id;