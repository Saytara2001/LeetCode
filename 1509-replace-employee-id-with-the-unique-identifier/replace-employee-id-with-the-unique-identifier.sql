/* Write your T-SQL query statement below */

select Eu.unique_id, E.name
from Employees E left join EmployeeUNI Eu
on E.id = Eu.id