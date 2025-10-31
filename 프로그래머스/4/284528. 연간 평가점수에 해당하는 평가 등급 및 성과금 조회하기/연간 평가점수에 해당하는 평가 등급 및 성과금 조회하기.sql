SELECT
    A.EMP_NO,
    A.EMP_NAME,
    CASE
        WHEN B.SCORE >= 96 THEN 'S'
        WHEN B.SCORE >= 90 THEN 'A'
        WHEN B.SCORE >= 80 THEN 'B'
    ELSE 'C'
    END AS GRADE,
    CASE
        WHEN B.SCORE >= 96 THEN A.SAL * 0.2
        WHEN B.SCORE >= 90 THEN A.SAL * 0.15
        WHEN B.SCORE >= 80 THEN A.SAL * 0.1
        ELSE 0
    END AS BONUS
FROM
    HR_EMPLOYEES AS A
JOIN
    (
        SELECT
            EMP_NO,
            YEAR,
            AVG(SCORE) AS SCORE
        FROM
            HR_GRADE
        WHERE 
            YEAR = 2022
        GROUP BY 
            EMP_NO
    ) AS B
    
    ON A.EMP_NO = B.EMP_NO
ORDER BY
    EMP_NO
























# SELECT
#     E.EMP_NO,
#     E.EMP_NAME,
#     CASE
#         WHEN G.AVG_SCORE >= 96 THEN 'S'
#         WHEN G.AVG_SCORE >= 90 THEN 'A'
#         WHEN G.AVG_SCORE >= 80 THEN 'B'
#         ELSE 'C'
#     END AS GRADE,
#     CASE
#         WHEN G.AVG_SCORE >= 96 THEN E.SAL * 0.20
#         WHEN G.AVG_SCORE >= 90 THEN E.SAL * 0.15
#         WHEN G.AVG_SCORE >= 80 THEN E.SAL * 0.10
#         ELSE 0
#     END AS BONUS
# FROM
#     HR_EMPLOYEES AS E
# JOIN (
#     SELECT
#         EMP_NO,
#         AVG(SCORE) AS AVG_SCORE
#     FROM
#         HR_GRADE
#     WHERE
#         YEAR = 2022 
#     GROUP BY
#         EMP_NO
# ) AS G ON E.EMP_NO = G.EMP_NO
# ORDER BY
#     E.EMP_NO ASC;