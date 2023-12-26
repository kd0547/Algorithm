SELECT
    A.CAR_ID,
    A.CAR_TYPE,
    ROUND(
        (
            A.DAILY_FEE * 30 / 100 * (
                100 - (
                    SELECT
                        DISCOUNT_RATE
                    FROM
                        CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                    WHERE
                        CAR_TYPE = A.CAR_TYPE
                        AND DURATION_TYPE = "30일 이상"
                )
            )
        )
    ) AS FEE
FROM
    CAR_RENTAL_COMPANY_CAR AS A
    JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY AS B ON A.CAR_ID = B.CAR_ID
WHERE
    A.CAR_TYPE IN ("SUV", "세단")
    AND (
        A.CAR_ID NOT IN (
            SELECT
                CAR_ID
            FROM
                CAR_RENTAL_COMPANY_RENTAL_HISTORY
            WHERE
                start_date <= '2022-11-01'
                and end_date >= '2022-11-01'
        )
    )
GROUP BY
    A.CAR_ID
HAVING
    FEE >= 500000
    AND FEE < 2000000
ORDER BY
    FEE DESC,
    CAR_TYPE ASC,
    CAR_ID DESC