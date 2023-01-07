SELECT 
    b.AUTHOR_ID,
    AUTHOR_NAME,
    CATEGORY,
    SUM(PRICE * SALES) AS TOTAL_SALES
FROM BOOK b
    INNER JOIN AUTHOR a ON b.AUTHOR_ID = a.AUTHOR_ID
    INNER JOIN BOOK_SALES bs ON b.BOOK_ID = bs.BOOK_ID
WHERE 
    SALES_DATE BETWEEN '2022-01-01' AND '2022-01-31'
GROUP BY 
    AUTHOR_ID,
    CATEGORY
ORDER BY
    AUTHOR_ID,
    CATEGORY DESC