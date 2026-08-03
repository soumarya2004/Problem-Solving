# Write your MySQL query statement below
SELECT e.name AS employee
FROM Employee e
INNER JOIN Employee m
ON e.ManagerId=m.id
WHERE e.salary>m.salary