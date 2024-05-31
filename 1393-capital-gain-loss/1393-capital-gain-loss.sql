# Write your MySQL query statement below
select stock_name ,
sum(CASE WHEN operation = 'Sell' then price ELSE -price END )
as capital_gain_loss
from stocks
group by stock_name;