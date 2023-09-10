# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM employee
Where salary <> (
  SELECT MAX(salary) FROM employee);