
select d.name Department, e.name Employee, e.salary Salary
from employee e inner join department d on e.departmentId=d.id
where (e.departmentId, e.salary)in
 (select departmentId, max(salary)
 from employee
 group by departmentId )
