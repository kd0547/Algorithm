-- 코드를 입력하세요
SELECT
    CAR_ID,
    ROUND(AVG((end_date - start_date) + 1), 1) AS AVERAGE_DURATION
FROM
    CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY
    CAR_ID
HAVING
    ROUND(AVG((end_date - start_date) + 1), 1) >= 7
ORDER BY
    AVERAGE_DURATION DESC,
    CAR_ID DESC