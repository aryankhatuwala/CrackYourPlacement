SELECT DISTINCT p.product_id, p.product_name
FROM product p
JOIN sales s ON p.product_id = s.product_id
WHERE s.sale_date 
AND p.product_id NOT IN (
    SELECT DISTINCT product_id
    FROM sales
    WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31'
);
