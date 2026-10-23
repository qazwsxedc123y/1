#define  _CRT_SECURE_NO_WARNINGS
// 1141
# Write your MySQL query statement below 2019 - 06 - 28 µ½ 2019 - 07 - 27
select activity_date as day, count(distinct user_id) as active_users from Activity
where activity_date >= '2019-06-28' and activity_date <= '2019-07-27'
group by activity_date;

// 1148
# Write your MySQL query statement below
select distinct(author_id) as id
from Views where author_id = viewer_id
order by id;

// 1179
# Write your MySQL query statement below
select distinct
D.id,
Jan.revenue Jan_Revenue,
Feb.revenue Feb_Revenue,
Mar.revenue Mar_Revenue,
Apr.revenue Apr_Revenue,
May.revenue May_Revenue,
Jun.revenue Jun_Revenue,
Jul.revenue Jul_Revenue,
Aug.revenue Aug_Revenue,
Sep.revenue Sep_Revenue,
Oct.revenue Oct_Revenue,
Nov.revenue Nov_Revenue,
Dec1.revenue Dec_Revenue
from Department D
left join(select id, revenue from Department where month = 'Jan') as Jan on Jan.id = D.id
left join(select id, revenue from Department where month = 'Feb') as Feb on Feb.id = D.id
left join(select id, revenue from Department where month = 'Mar') as Mar on Mar.id = D.id
left join(select id, revenue from Department where month = 'Apr') as Apr on Apr.id = D.id
left join(select id, revenue from Department where month = 'May') as May on May.id = D.id
left join(select id, revenue from Department where month = 'Jun') as Jun on Jun.id = D.id
left join(select id, revenue from Department where month = 'Jul') as Jul on Jul.id = D.id
left join(select id, revenue from Department where month = 'Aug') as Aug on Aug.id = D.id
left join(select id, revenue from Department where month = 'Sep') as Sep on Sep.id = D.id
left join(select id, revenue from Department where month = 'Oct') as Oct on Oct.id = D.id
left join(select id, revenue from Department where month = 'Nov') as Nov on Nov.id = D.id
left join(select id, revenue from Department where month = 'Dec') as Dec1 on Dec1.id = D.id;