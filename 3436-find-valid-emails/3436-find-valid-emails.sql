SELECT 
    *
FROM users
WHERE email LIKE '%@%.com'
    AND SUBSTR(email, 1, LOCATE('@', email) - 1) REGEXP '^[a-zA-Z0-9_]+$'
    AND SUBSTR(email,
        LOCATE('@', email) + 1,
        LENGTH(email) - LOCATE('@', email) - 4) REGEXP '^[a-zA-Z]+$'
ORDER BY user_id;