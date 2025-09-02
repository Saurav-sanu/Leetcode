# Write your MySQL query statement below
select a1.project_id ,round(sum(a2.experience_years)/count(a1.employee_id),2)  as average_years from Project as a1 left join Employee as a2
on a1.employee_id=a2.employee_id
group by a1.project_id