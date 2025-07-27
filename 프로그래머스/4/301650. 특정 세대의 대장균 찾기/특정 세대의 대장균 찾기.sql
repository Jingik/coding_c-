-- 코드를 작성해주세요

SELECT
    A.ID
FROM 
    ECOLI_DATA AS A 
    INNER JOIN
    (
    SELECT
        A.ID
    FROM
        ECOLI_DATA AS A 
        INNER JOIN 
        (SELECT
            ID
        FROM
            ECOLI_DATA
        WHERE ISNULL(PARENT_ID)) AS B
        ON A.PARENT_ID = B.ID
    ) AS C
    ON A.PARENT_ID = C.ID

    