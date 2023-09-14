SELECT u.user_id,CONCAT(UPPER(SUBSTR(u.name,1,1)),LOWER(SUBSTR(u.name,2))) AS name
FROM users AS u
ORDER BY u.user_id;