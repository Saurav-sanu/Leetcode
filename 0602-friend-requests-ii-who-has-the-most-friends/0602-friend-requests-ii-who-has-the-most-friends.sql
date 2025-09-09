# Write your MySQL query statement below
select id ,count(id) as num from (
    select requester_id as id,accepter_id as id2 from RequestAccepted
    union 
    select accepter_id as id,requester_id as id2 from RequestAccepted
)

as all_friends
group by id
order by num DESC
limit 1