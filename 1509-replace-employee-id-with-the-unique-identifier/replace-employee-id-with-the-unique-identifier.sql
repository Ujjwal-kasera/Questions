# Write your MySQL query statement below
SELECT unique_id,name
FROM employees AS e1
LEFT JOIN employeeuni AS e2
ON e1.id=e2.id;