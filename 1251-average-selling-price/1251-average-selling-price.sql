# Write your MySQL query statement below
select a1.product_id , IFNULL(ROUND(SUM(a1.price * b1.units) / sum(b1.units), 2), 0) as average_price from Prices as a1 left join UnitsSold as b1 on a1.product_id =b1.product_id
and b1.purchase_date between a1.start_date and a1.end_date
group by a1.product_id