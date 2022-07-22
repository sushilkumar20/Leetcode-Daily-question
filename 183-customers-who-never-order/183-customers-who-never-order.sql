# Write your MySQL query statement below
select name as Customers  from Customers where id <> All (select customerId  from Orders);