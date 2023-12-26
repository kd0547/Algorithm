SELECT
    category,
    sum(sales) as TOTAL_SALES
FROM
    BOOK b
    inner join BOOK_SALES bs ON b.BOOK_ID = bs.BOOK_ID
WHERE
    YEAR(bs.sales_date) = 2022
    AND MONTH(bs.sales_date) = 1
GROUP BY
    category
ORDER BY
    category;