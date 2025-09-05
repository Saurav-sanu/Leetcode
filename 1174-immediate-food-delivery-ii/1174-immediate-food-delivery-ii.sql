# Write your MySQL query statement below
select  ROUND(
        AVG(customer_pref_delivery_date = order_date) * 100,
        2
    ) AS immediate_percentage from Delivery 
where (customer_id,order_date) IN (select customer_id, min(order_date) from delivery group by customer_id );
