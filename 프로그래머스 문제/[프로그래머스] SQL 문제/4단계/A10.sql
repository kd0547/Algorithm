/*
 FOOD_PRODUCT와 FOOD_ORDER 테이블에서 생산일자가 2022년 5월인 식품들의 식품 ID, 식품 이름, 총매출을 조회하는 SQL문을 작성해주세요. 
 이때 결과는 총매출을 기준으로 내림차순 정렬해주시고 총매출이 같다면 식품 ID를 기준으로 오름차순 정렬해주세요.
 */
SELECT
    fo.product_id,
    product_name,
    sum(fp.price * fo.amount) as total
from
    food_product fp
    inner join food_order fo on fo.product_id = fp.product_id
where
    produce_date like '2022-05-%%'
group by
    fp.PRODUCT_ID,
    fp.PRODUCT_NAME
order by
    total DESC,
    fp.PRODUCT_ID