SELECT
    ANIMAL_ID,
    NAME
FROM
    (
        SELECT
            i.ANIMAL_ID,
            i.NAME,
            DATEDIFF(
                DATE_FORMAT(o.DATETIME, '%Y-%m-%d'),
                DATE_FORMAT(i.DATETIME, '%Y-%m-%d')
            ) AS TIME,
            ROW_NUMBER() OVER (
                ORDER BY
                    DATEDIFF(
                        DATE_FORMAT(o.DATETIME, '%Y-%m-%d'),
                        DATE_FORMAT(i.DATETIME, '%Y-%m-%d')
                    ) DESC
            ) AS rnk
        FROM
            ANIMAL_INS i
            INNER JOIN ANIMAL_OUTS o ON i.ANIMAL_ID = o.ANIMAL_ID
    ) AS Subquery
WHERE
    rnk <= 2;