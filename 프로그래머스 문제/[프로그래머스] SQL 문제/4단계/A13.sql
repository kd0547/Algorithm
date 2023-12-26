WITH RECURSIVE time AS(
    SELECT
        0 AS hour
    UNION
    ALL
    SELECT
        hour + 1
    FROM
        time
    WHERE
        hour < 23
)
SELECT
    time.hour AS HOUR,
    IFNULL(a.s, 0) AS COUNT
FROM
    time
    LEFT JOIN (
        SELECT
            HOUR(DATETIME) t,
            COUNT(*) s
        FROM
            ANIMAL_OUTS
        GROUP BY
            t
        ORDER BY
            t
    ) a ON time.hour = a.t