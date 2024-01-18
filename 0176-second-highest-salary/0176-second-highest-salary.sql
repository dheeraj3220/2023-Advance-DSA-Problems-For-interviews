# Write your MySQL query statement below
select max(salary) AS SecondHighestSalary from Employee
where salary Not IN (Select max(salary) from Employee)