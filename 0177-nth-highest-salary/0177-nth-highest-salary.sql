CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      Select distinct salary from employee emp where N-1=(select count(distinct salary) from employee emp2 where emp2.salary > emp.salary)
      
  );
END