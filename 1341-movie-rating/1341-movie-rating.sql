# Write your MySQL query statement below
(select name as results from Users u join MovieRating mr
on u.user_id=mr.user_id
group by u.user_id
order by count(mr.movie_id)desc,u.name asc
limit 1)

union

(select title as results from Movies m join MovieRating mr
on m.movie_id=mr.movie_id
WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
group by m.movie_id
order by avg(mr.rating) desc,m.title asc
limit 1)