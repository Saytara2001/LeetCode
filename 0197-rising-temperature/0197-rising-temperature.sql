/* Write your T-SQL query statement below */
select distinct W.id
from Weather W join Weather Wa
on DATEDIFF(dd, Wa.recordDate, W.recordDate) = 1 and W.temperature > Wa.temperature 