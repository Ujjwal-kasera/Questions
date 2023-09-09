# # Write your MySQL query statement below
# select name 
# from customer 
# where id not in (
#   select id 
#   from customer 
#   where referee_id=2
#   );

# Write your MySQL query statement below
select name 
from customer 
where (referee_id is null or referee_id!=2);