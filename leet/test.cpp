#include <iostream>
#include <vector>
using namespace std;

// select employees.emp_no, salary from employees, salaries where employees.emp_no = salaries.emp_no 
// and hire_date = from_date order by emp_no desc;

//select emp_no from employees
//where emp_no not in(select emp_no from dept_manager);

//select emp_no, manager from
//(select dept_emp.emp_no emp_no, dept_manager.emp_no manager from dept_emp, dept_manager
//    where dept_emp.dept_no = dept_manager.dept_no) t1 where emp_no <> manager;


//# Write your MySQL query statement below
//select s1.score score, (select count(distinct s2.score) from Scores s2 where s1.score <= s2.score) 'rank'
//from Scores s1 order by s1.score desc;


//select s1.score score, count(distinct s2.score) 'rank'
//from Scores s1
//inner join Scores s2
//on  s1.score <= s2.score
//group by s1.id, s1.score
//order by s1.score desc;

int main()
{
    vector<int> ans{ 4,6,7,7 };
    Solution s;
    s.findSubsequences(ans);
    return 0;
}