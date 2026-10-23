#define  _CRT_SECURE_NO_WARNINGS
# Write your MySQL query statement below
// 610
select x, y, z,
case
when x + y > z AND x + z > y AND y + z > x THEN 'Yes'
    else 'No'
        end as 'triangle'
        from Triangle;

# Write your MySQL query statement below
select max(num) as num
from
(select num
    from MyNumbers
    group by num
    having count(num) = 1) as t;

# Write your MySQL query statement below
select*
from cinema
where description != 'boring' and id % 2 = 1
order by rating  desc;

# Write your MySQL query statement below
UPDATE salary
set sex =
case sex
when 'm' then 'f'
    else 'm'
        end;


# Write your MySQL query statement below
select actor_id, director_id
from ActorDirector 
group by actor_id, director_id
having count(*) >= 3;


# Write your MySQL query statement below
select product_name, year, price
from Sales left join Product on Sales.product_id = Product.product_id;

# Write your MySQL query statement below
SELECT
user_id,
count(*) AS prompt_count,
round(avg(tokens * 1.0), 2) AS avg_tokens
FROM
prompts
GROUP BY
user_id
HAVING
count(*) >= 3 AND max(tokens) > avg(tokens)
ORDER BY
avg_tokens DESC, user_id ASC


# Write your MySQL query statement below
SELECT
project_id,
ROUND(AVG(e.experience_years), 2)  AS average_years
FROM
Project as p
LEFT JOIN
Employee as e
ON
p.employee_id = e.employee_id
GROUP BY
p.project_id£»

# Write your MySQL query statement below
SELECT
project_id,
ROUND(AVG(e.experience_years), 2)  AS average_years
FROM Project as p
LEFT JOIN Employee as e
ON p.employee_id = e.employee_id
GROUP BY project_id;