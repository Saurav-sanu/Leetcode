# Write your MySQL query statement below
select p.product_name  as product_name ,sum(o.unit) as unit from Products as p join Orders as o
on p.product_id =o.product_id 

where o.order_date between '2020-02-01' and '2020-02-29'
GROUP BY p.product_id, p.product_name
having sum(o.unit)>=100

