SELECT
    A.CATEGORY,
    A.PRICE AS MAX_PRICE,
    A.PRODUCT_NAME
FROM 
    FOOD_PRODUCT AS A 
JOIN (
        SELECT 
            CATEGORY, 
            MAX(PRICE) MAX_PRICE
        FROM 
            FOOD_PRODUCT
        WHERE 
            CATEGORY IN ("과자", "국", "김치", "식용유")
        GROUP BY 
            CATEGORY
    ) AS B
        ON A.CATEGORY = B.CATEGORY AND A.PRICE = B.MAX_PRICE
ORDER BY 
    PRICE DESC;