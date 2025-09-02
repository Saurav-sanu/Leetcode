# Write your MySQL query statement below
select query_name ,

 ROUND(SUM(rating/position) / COUNT(*), 2) AS quality,
ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 2) AS poor_query_percentage
from Queries 
group by query_name