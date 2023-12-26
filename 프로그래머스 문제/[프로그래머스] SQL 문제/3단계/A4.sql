SELECT
    distinct c.car_id
FROM
    CAR_RENTAL_COMPANY_CAR c
    LEFT OUTER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY h ON c.car_id = h.car_id
WHERE
    car_type = '세단'
    AND MONTH(start_date) = 10
ORDER BY
    c.car_id DESC