/* Write your T-SQL query statement below */
select W.id
from Weather W join Weather Wa
on DATEDIFF(dd, Wa.recordDate, W.recordDate) = 1 and W.temperature > Wa.temperature 