# Write your MySQL query statement below
SELECT product_name, year, price
FROM Product INNER JOIN Sales 
USING(product_id)
