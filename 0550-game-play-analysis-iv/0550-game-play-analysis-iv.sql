# Write your MySQL query statement below
select Round(count(distinct player_id ) / (select count(distinct player_id) from Activity),2)as fraction from Activity 
where 
(player_id,Date_sub(event_Date,INTERVAL 1 DAY))
IN (select player_id ,min(event_date) from activity Group by player_id)