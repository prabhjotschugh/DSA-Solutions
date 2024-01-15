# Write your MySQL query statement below
select name
from salesperson
where sales_id not in (
    select sales_id
    from orders
    left join company using(com_id)
    where orders.sales_id = salesperson.sales_id and company.name = "RED"
)