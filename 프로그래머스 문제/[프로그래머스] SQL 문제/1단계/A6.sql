/*
 상반기 아이스크림 총주문량이 3,000보다 높으면서 아이스크림의 주 성분이 과일인 
 아이스크림의 맛을 총주문량이 큰 순서대로 조회하는 SQL 문을 작성해주세요.
 */
SELECT
    f.FLAVOR
FROM
    FIRST_HALF f
    inner join ICECREAM_INFO i ON f.FLAVOR = i.FLAVOR
WHERE
    total_order > 3000
    and ingredient_type = 'fruit_based'
order by
    total_order desc