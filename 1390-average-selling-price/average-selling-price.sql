# Write your MySQL query statement below
select p.product_id,ifnull(round(sum(u.units*p.price)/sum(u.units),2),0) as average_price 
from  Prices p left join UnitsSold u on p.product_id=u.product_id and u.purchase_date between start_date and end_date group by p.product_id;