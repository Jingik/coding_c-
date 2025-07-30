WITH RECURSIVE Generation AS (
    SELECT
        ID,
        PARENT_ID,
        1 AS generation_num
    FROM
        ECOLI_DATA
    WHERE
        PARENT_ID IS NULL

    UNION ALL

    SELECT
        E.ID,
        E.PARENT_ID,
        G.generation_num + 1 AS generation_num
    FROM
        ECOLI_DATA AS E
    INNER JOIN
        Generation AS G ON E.PARENT_ID = G.ID 
    WHERE
        G.generation_num < 4
)
SELECT
    ID
FROM
    Generation
WHERE
    generation_num = 3
ORDER BY
    ID ASC;