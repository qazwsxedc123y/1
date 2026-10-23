#define  _CRT_SECURE_NO_WARNINGS
# Write your MySQL query statement below
# Write your MySQL query statement below
select Product.product_id, Product.product_name from Product left join
Sales on Product.product_id = Sales.product_id
group by Product.product_id, Product.product_name
having min(sale_date) >= '2019-01-01' and max(sale_date) <= '2019-03-31';