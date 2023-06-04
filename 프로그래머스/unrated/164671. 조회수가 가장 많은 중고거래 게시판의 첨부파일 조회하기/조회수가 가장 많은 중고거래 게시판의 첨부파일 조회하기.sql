SELECT CONCAT(
        '/home/grep/src/',
        BOARD_ID,
        '/',
        FILE_ID,
        FILE_NAME,
        FILE_EXT
    ) AS FILE_PATH
FROM (
        SELECT *
        FROM USED_GOODS_BOARD
        ORDER BY VIEWS DESC
        LIMIT 1
    ) b
    INNER JOIN USED_GOODS_FILE f USING (BOARD_ID)
ORDER BY FILE_ID DESC