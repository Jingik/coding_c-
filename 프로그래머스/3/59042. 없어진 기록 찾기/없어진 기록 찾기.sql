-- 코드를 입력하세요
SELECT
    O.ANIMAL_ID,
    O.NAME
FROM
    ANIMAL_INS AS I
RIGHT JOIN
    ANIMAL_OUTS AS O ON I.ANIMAL_ID = O.ANIMAL_ID
WHERE
    I.ANIMAL_ID IS NULL
    
# 입양을 간 기록은 있는데 보호소에 들어온 기록이 없는 동물
# INS는 보호소에 들어온 기록, OUTS은 나간 기록