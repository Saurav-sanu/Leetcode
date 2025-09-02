# Write your MySQL query statement below
select s.student_id ,s.student_name,su.subject_name , count(E.student_id) as attended_exams

from Students as s cross join Subjects as su

left join Examinations as E on s.student_id= E.student_id

and E.subject_name=su.subject_name

GROUP BY s.student_id, s.student_name, su.subject_name
order by s.student_id, s.student_name, su.subject_name

