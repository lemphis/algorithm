SELECT YEAR(SALES_DATE) AS YEAR,
    MONTH(SALES_DATE) AS MONTH,
    COUNT(DISTINCT u.USER_ID) AS PUCHASED_USERS,
    ROUND(COUNT(DISTINCT u.USER_ID) / COUNT, 1) AS PUCHASED_RATIO
FROM ONLINE_SALE o
    INNER JOIN (
        SELECT USER_ID,
            COUNT(*) OVER() AS COUNT
        FROM USER_INFO
        WHERE JOINED BETWEEN '2021-01-01' AND '2021-12-31'
    ) u ON u.USER_ID = o.USER_ID
GROUP BY YEAR,
    MONTH
ORDER BY YEAR,
    MONTH