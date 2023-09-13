# Write your MySQL query statement below
SELECT (CASE
    WHEN MOD(id,2)!=0 AND (SELECT count(id) FROM seat)!=id THEN s.id+1
    WHEN MOD(id,2)=0 THEN s.id-1
    ELSE s.id
    END) AS id,student
FROM seat AS s
ORDER BY id;