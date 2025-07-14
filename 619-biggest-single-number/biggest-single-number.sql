# Write your MySQL query statement below
select max(a.num) as num from
(
    select num,count(*) from mynumbers 
    group by num
    having count(num)=1
)as a