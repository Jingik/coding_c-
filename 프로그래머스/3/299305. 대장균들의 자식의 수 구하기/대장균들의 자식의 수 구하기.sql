SELECT
    A.ID,
    COUNT(B.PARENT_ID) AS CHILD_COUNT -- B.PARENT_ID가 NULL이 아니면 1로 카운트, NULL이면 카운트 안 함 (자식이 없는 경우)
FROM
    ECOLI_DATA AS A
LEFT JOIN
    ECOLI_DATA AS B ON A.ID = B.PARENT_ID -- 같은 테이블을 다시 조인 (별칭은 A와 B로 구분)
GROUP BY
    A.ID
ORDER BY
    A.ID ASC;