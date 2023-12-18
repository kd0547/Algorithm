/*  
 USED_GOODS_BOARD와 USED_GOODS_REPLY 테이블에서 
 2022년 10월에 작성된 게시글 제목, 게시글 ID, 댓글 ID, 댓글 작성자 ID, 댓글 내용, 댓글 작성일을 조회하는 SQL문을 작성해주세요. 
 결과는 댓글 작성일을 기준으로 오름차순 정렬해주시고, 댓글 작성일이 같다면 게시글 제목을 기준으로 오름차순 정렬해주세요.
 */
SELECT
    b.title,
    b.board_id,
    r.reply_id,
    r.writer_id,
    r.contents,
    to_char(r.created_date, 'yyyy-mm-dd') as created_date
FROM
    used_goods_board b
    INNER JOIN used_goods_reply r on b.BOARD_ID = r.BOARD_ID
where
    to_char(b.created_date, 'yyyy-mm-dd') like '2022-10-%%'
order by
    created_date,
    b.title;