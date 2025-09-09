# Write your MySQL query statement below

select visited_on ,(select sum(amount) from customer where visited_on between DATE_SUB(c.visited_on ,interval 6 day) and c.visited_on ) as amount ,
Round((select sum(amount)/7  from customer where visited_on between date_sub(c.visited_on ,interval 6 day) and c.visited_on),2) as average_amount

from Customer c

where visited_on>=(
    select Date_add(min(visited_on),interval 6 day)
    from customer
)
group by visited_on;

