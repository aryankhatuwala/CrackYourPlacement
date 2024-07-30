with func as
(select d.name depName, e.name empName, e.salary empSal, e.departmentId depId,
dense_rank() over(partition by e.departmentId order by e.salary desc) as empRank
from employee e join department d on e.departmentId=d.id)

select depName Department, empName Employee, empSal Salary
from func
where empRank <=3;

-- select * from func;
