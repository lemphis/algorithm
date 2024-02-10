SELECT ao.ANIMAL_ID, ao.NAME
FROM ANIMAL_INS ai
INNER JOIN ANIMAL_OUTS ao USING (ANIMAL_ID)
ORDER BY DATEDIFF(ao.DATETIME, ai.DATETIME) DESC
LIMIT 2