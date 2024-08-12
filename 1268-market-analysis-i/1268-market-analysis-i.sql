# Write your MySQL query statement below
-- select u.user_id as  buyer_id, 
-- u.join_date as join_date,
-- count(o.order_date) as orders_in_2019
-- from users u left outer join orders o 
-- on u.user_id=o.buyer_id 
-- where o.order_date between "2019-01-01" and "2019-12-31"
-- group by u.user_id

select user_id as  buyer_id, 
join_date,
(select count(order_date) 
from orders 
where buyer_id=user_id 
and order_date between "2019-01-01" and "2019-12-31") as orders_in_2019
from users