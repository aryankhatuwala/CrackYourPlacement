# Write your MySQL query statement below
select x.name as employee
from employee x join employee y 
on x.managerId=y.id
where x.salary>y.salary