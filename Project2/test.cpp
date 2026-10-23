#define  _CRT_SECURE_NO_WARNINGS
# Write your MySQL query statement below
select name, bonus from Employee  as a left join Bonus  as b
on a.empId = b.empId where bonus is null or bonus < 1000;

# Write your MySQL query statement below
select name, bonus from Employee a left join Bonus b
on a.empId = b.empId where bonus is null or bonus < 1000;

# Write your MySQL query statement below
select name from Customer where referee_id is null or referee_id != 2;


# Write your MySQL query statement below
SELECT customer_number
from(select customer_number, count(*) as cnt from Orders GROUP BY customer_number) as t
ORDER BY cnt DESC
limit 1;

# Write your MySQL query statement below
select class from
(select count(*) as cnt, class from Courses group by class) as t
where cnt >= 5;

# Write your MySQL query statement below
select name from SalesPerson
where sales_id not in
(select sales_id from Orders a
	left join Company b on a.com_id = b.com_id
	where name = "RED");