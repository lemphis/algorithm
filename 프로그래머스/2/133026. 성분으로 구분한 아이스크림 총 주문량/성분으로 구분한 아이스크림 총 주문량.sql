SELECT 
    INGREDIENT_TYPE,
    SUM(TOTAL_ORDER) AS TOTAL_ORDER
FROM
    FIRST_HALF
INNER JOIN
    ICECREAM_INFO USING (FLAVOR)
GROUP BY
    INGREDIENT_TYPE