/*
 
 MEMBER_PROFILE와 REST_REVIEW 테이블에서 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회하는 SQL문을 작성해주세요. 
 회원 이름, 리뷰 텍스트, 리뷰 작성일이 출력되도록 작성해주시고, 결과는 리뷰 작성일을 기준으로 오름차순, 
 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순 정렬해주세요.
 
 -- MEMBER_PROFILE 과 REST_REVIEW을 MEMBER_ID로 LEFT OUTER JOIN하고 
 -- 서브쿼리로 REST_REVIEW에서 MEMBER_ID로 그룹화하고 ORDER BY로 COUNT함수를 사용해 리뷰를 많이 쓴 사람부터 내림차순 정렬한다.
 */
SELECT
    mp.MEMBER_NAME,
    rw.REVIEW_TEXT,
    date_format(rw.REVIEW_DATE, '%Y-%m-%d') REVIEW_DATE
FROM
    REST_REVIEW rw
    left outer join MEMBER_PROFILE mp on rw.MEMBER_ID = mp.MEMBER_ID
WHERE
    mp.member_id = (
        select
            member_id
        from
            rest_review
        group by
            member_id
        order by
            count(review_id) desc
        limit
            1
    )
ORDER BY
    REVIEW_DATE,
    REVIEW_TEXT ASC;