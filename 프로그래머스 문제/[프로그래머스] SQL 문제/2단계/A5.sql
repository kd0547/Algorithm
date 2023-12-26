SELECT
    ingredient_type,
    SUM(TOTAL_ORDER) AS TOTAL_ORDER
FROM
    FIRST_HALF h
    INNER JOIN ICECREAM_INFO i ON h.FLAVOR = i.FLAVOR
GROUP BY
    ingredient_type
ORDER BY
    total_order ASC