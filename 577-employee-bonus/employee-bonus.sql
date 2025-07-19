# Write your MySQL query statement below
select e1.name,b1.bonus from Employee e1 left join Bonus b1 
on e1.empId=b1.empId  where b1.bonus<1000 or b1.bonus is null;