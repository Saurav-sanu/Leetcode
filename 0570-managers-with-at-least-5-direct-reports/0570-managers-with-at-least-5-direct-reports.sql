# Write your MySQL query statement below
select A1.name from Employee as A1 join Employee as A2 
on A1.id=A2.managerId
group by A1.id 
having count(A2.id)>=5
-- group by A1.id having count(B1.managerId)>=5