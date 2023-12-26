SELECT
    *
FROM
    (
        SELECT
            f.flavor AS FLAVOR
        FROM
            FIRST_HALF f,
            JULY j
        WHERE
            f.FLAVOR = j.FLAVOR
        GROUP BY
            f.flavor
        ORDER BY
            sum(f.TOTAL_ORDER + j.TOTAL_ORDER) DESC
    )
WHERE
    ROWNUM <= 3;