/* Write your T-SQL query statement below */
select En.unique_id, E.name 
from Employees E left join EmployeeUNI EN
on E.id = En.id