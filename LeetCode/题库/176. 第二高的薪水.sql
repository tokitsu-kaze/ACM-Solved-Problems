# 找到最高的薪水，把它排除即可。

select max(salary) as secondHighestSalary
from employee
where salary != (select max(salary)
from employee)
