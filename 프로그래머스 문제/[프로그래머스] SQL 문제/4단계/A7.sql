/*
 USER_INFO 테이블과 ONLINE_SALE 테이블에서 년, 월, 성별 별로 상품을 구매한 회원수를 집계하는 SQL문을 작성해주세요. 
 결과는 년, 월, 성별을 기준으로 오름차순 정렬해주세요. 이때, 성별 정보가 없는 경우 결과에서 제외해주세요.
 */
SELECT
    DATE_FORMAT(s.sales_date, '%Y') AS YEAR,
    MONTH(s.sales_date) AS MONTH,
    i.GENDER AS GENDER,
    COUNT(DISTINCT(s.USER_ID)) AS USERS
FROM
    USER_INFO i
    INNER JOIN ONLINE_SALE s ON i.USER_ID = s.USER_ID
WHERE
    i.GENDER IS NOT NULL
GROUP BY
    DATE_FORMAT(s.sales_date, '%m'),
    i.GENDER
ORDER BY
    1,
    2,
    3