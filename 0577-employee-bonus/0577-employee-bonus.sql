# Write your MySQL query statement below
select name,bonus from Employee  as a1 left join Bonus as b1
on a1.empId=b1.empId
where bonus<1000 or bonus IS null