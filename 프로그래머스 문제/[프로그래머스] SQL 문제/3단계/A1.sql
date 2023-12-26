SELECT
    (
        '/home/grep/src/' || board_id || '/' || FILE_ID || FILE_NAME || FILE_EXT
    ) AS FILE_PATH
FROM
    USED_GOODS_FILE
WHERE
    BOARD_ID IN (
        SELECT
            BOARD_ID
        FROM
            USED_GOODS_BOARD
        ORDER BY
            VIEWS DESC
        FETCH FIRST
            1 ROW ONLY
    )
ORDER BY
    FILE_PATH DESC