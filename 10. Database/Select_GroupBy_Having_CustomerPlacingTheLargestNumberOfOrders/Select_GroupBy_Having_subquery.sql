SELECT customer_number
FROM orders
GROUP BY customer_number
HAVING COUNT(order_number) = (
    SELECT COUNT(order_number)  order_cnt
    FROM orders
    GROUP BY customer_number
    ORDER BY 1 DESC
    LIMIT 1
)