-- USED_GOODS_BOARD와 USED_GOODS_REPLY 테이블을 조인하여 조건에 맞는 댓글 정보를 조회합니다.
SELECT
    B.TITLE,          -- 게시글 제목
    B.BOARD_ID,       -- 게시글 ID
    R.REPLY_ID,       -- 댓글 ID
    R.WRITER_ID,      -- 댓글 작성자 ID
    R.CONTENTS,       -- 댓글 내용
    -- 댓글 작성일자를 'YYYY-MM-DD' 형식으로 포맷합니다.
    DATE_FORMAT(R.CREATED_DATE, '%Y-%m-%d') AS CREATED_DATE
FROM
    USED_GOODS_BOARD AS B  -- USED_GOODS_BOARD 테이블에 'B'라는 별칭을 부여합니다.
JOIN
    USED_GOODS_REPLY AS R  -- USED_GOODS_REPLY 테이블에 'R'이라는 별칭을 부여합니다.
ON
    B.BOARD_ID = R.BOARD_ID -- BOARD_ID 컬럼을 기준으로 두 테이블을 조인합니다.
WHERE
    -- 게시글(B.CREATED_DATE)이 2022년 10월에 작성된 것만 필터링합니다.
    -- YEAR() 함수로 연도를 추출하고 MONTH() 함수로 월을 추출하여 조건을 설정합니다.
    YEAR(B.CREATED_DATE) = 2022 AND MONTH(B.CREATED_DATE) = 10
ORDER BY
    -- 결과를 댓글 작성일(R.CREATED_DATE) 기준으로 오름차순 정렬합니다.
    R.CREATED_DATE ASC,
    -- 댓글 작성일이 같을 경우 게시글 제목(B.TITLE) 기준으로 오름차순 정렬합니다.
    B.TITLE ASC;
