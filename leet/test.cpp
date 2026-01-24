#include <iostream>
#include <vector>
using namespace std;

//insert into actor(actor_id, first_name, last_name, last_update) 
//values(1, 'PENELOPE', 'GUINESS', '2006-02-15 12:34:33'), (2, 'NICK', 'WAHLBERG', '2006-02-15 12:34:33');

// select distinct salary from salaries order by salary desc;

// select * from employees order by hire_date desc limit 1;

// select * from employees order by hire_date desc limit 2, 1;

// select emp_no, count(emp_no) as t from salaries group by emp_no having count(emp_no) > 15;

// SELECT d.dept_no, d.emp_no, s.salary from dept_manager d, salaries s
// where d.to_date = '9999-01-01' and d.to_date = s.to_date and d.emp_no = s.emp_no
// order by d.dept_no;

// select title, count(title) from titles group by title having count(title) >= 2;

// # Write your MySQL query statement below
// select email Email from Person group by email having count(email) >= 2;

// # Write your MySQL query statement below
// select name, population, area from World where area >= 3000000 or population >= 25000000;

//CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
//BEGIN
//declare M int;
//SET M = N - 1;
//RETURN(
//    # Write your MySQL query statement below.
//    select distinct salary from Employee order by salary desc limit M, 1
//);
//END

int main()
{
    vector<int> ans{ 4,6,7,7 };
    Solution s;
    s.findSubsequences(ans);
    return 0;
}