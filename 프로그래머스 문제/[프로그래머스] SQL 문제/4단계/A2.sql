select
    distinct(history_id),
    case
        when datediff(end_date, start_date) + 1 between 7
        and 29 then round(
            daily_fee *(datediff(end_date, start_date) + 1) *(
                select
                    (100 - DISCOUNT_RATE) / 100
                from
                    CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                where
                    car_type = '트럭'
                    and duration_type = '7일 이상'
            ),
            0
        )
        when datediff(end_date, start_date) + 1 between 30
        and 89 then round(
            daily_fee *(datediff(end_date, start_date) + 1) *(
                select
                    (100 - DISCOUNT_RATE) / 100
                from
                    CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                where
                    car_type = '트럭'
                    and duration_type = '30일 이상'
            ),
            0
        )
        when datediff(end_date, start_date) + 1 >= 90 then round(
            daily_fee *(datediff(end_date, start_date) + 1) *(
                select
                    (100 - DISCOUNT_RATE) / 100
                from
                    CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                where
                    car_type = '트럭'
                    and duration_type = '90일 이상'
            ),
            0
        )
        else round(daily_fee *(datediff(end_date, start_date) + 1), 0)
    end as fee
from
    CAR_RENTAL_COMPANY_RENTAL_HISTORY a
    join CAR_RENTAL_COMPANY_CAR b on a.CAR_ID = b.CAR_ID
    join CAR_RENTAL_COMPANY_DISCOUNT_PLAN c on b.CAR_TYPE = c.CAR_TYPE
where
    b.CAR_TYPE = '트럭'
order by
    FEE desc,
    1 desc