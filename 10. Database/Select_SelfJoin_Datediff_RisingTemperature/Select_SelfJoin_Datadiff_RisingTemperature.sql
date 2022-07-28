# Write your MySQL query statement below
SELECT
    tbl1.id AS 'Id'
FROM
    Weather as tbl1
        JOIN
    Weather as tbl2 
        ON DATEDIFF(tbl1.recordDate, tbl2.recordDate) = 1
            AND tbl1.Temperature > tbl2.Temperature