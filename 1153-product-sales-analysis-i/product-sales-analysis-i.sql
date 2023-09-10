# Write your MySQL query statement below
SELECT product_name,year,price
FROM sales AS s
INNER JOIN product AS p
WHERE s.product_id=p.product_id;