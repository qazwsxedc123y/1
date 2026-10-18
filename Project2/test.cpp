#define  _CRT_SECURE_NO_WARNINGS


# Write your MySQL query statement below
select firstName, lastName, city, state
from Person left join Address
on Person.PersonId = Address.PersonId;

# Write your MySQL query statement below
select a.name as Employee from Employee as a
join Employee as b on a.managerId = b.id and a.salary > b.salary;


# Write your MySQL query statement below
select name as Customers from Customers
where Customers.id not in
(select customerId from Orders);


# Write your MySQL query statement below
select name as Customers from Customers as a
left join Orders as b
on a.Id = b.customerId
where b.customerId is null;


# Write your MySQL query statement below
DELETE p1 FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id


# Write your MySQL query statement below
select a.id as Id from Weather as a, Weather as b
where a.Temperature > b.Temperature and TIMESTAMPDIFF(DAY, a.recordDate, b.recordDate) = -1;

# Write your MySQL query statement below
select a.id as Id from Weather as a join Weather as b
on a.Temperature > b.Temperature and TIMESTAMPDIFF(DAY, a.recordDate, b.recordDate) = -1;