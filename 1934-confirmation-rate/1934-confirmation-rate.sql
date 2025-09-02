# Write your MySQL query statement below
select a1.user_id , Round(IFNULL((sum(action='confirmed')/count(action)),0),2) as confirmation_rate from Signups as a1 left join Confirmations as a2 
on a1.user_id=a2.user_id 
group by a1.user_id