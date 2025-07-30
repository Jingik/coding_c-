WITH CALC AS (
    SELECT
        SUM(CODE) AS CD,
        CATEGORY
    FROM
        SKILLCODES
    WHERE
        CATEGORY = 'Front End'
    GROUP BY
        CATEGORY
)

SELECT
    B.ID,
    B.EMAIL,
    B.FIRST_NAME,
    B.LAST_NAME
FROM
    DEVELOPERS AS B
WHERE
    B.SKILL_CODE & (
        SELECT
            CD
        FROM
            CALC
    )
ORDER BY
    B.ID ASC;

