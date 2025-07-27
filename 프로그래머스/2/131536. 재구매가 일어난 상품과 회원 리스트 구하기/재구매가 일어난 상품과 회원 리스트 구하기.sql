-- 동일한 회원이 동일한 상품 재구매한 데이터 보이게 하기
-- 회원 ID 오름차순, 상품 ID 내림차순

SELECT
    USER_ID,
    PRODUCT_ID
FROM
    ONLINE_SALE
GROUP BY 
    USER_ID, 
    PRODUCT_ID
HAVING
    COUNT(*) > 1
ORDER BY
    USER_ID ASC,
    PRODUCT_ID DESC;