SELECT a.machine_id,
ROUND(AVG(b.timestamp-a.timestamp),3) AS processing_time
FROM activity a,activity b
WHERE a.machine_id=b.machine_id
AND a.process_id=b.process_id
AND a.activity_type='start'
AND b.activity_type='end'
GROUP BY a.machine_id;

# SELECT 
# machine_id,
# ROUND(SUM(CASE WHEN activity_type='start' THEN timestamp*-1 ELSE timestamp END)*1.0/(SELECT COUNT(DISTINCT process_id)),3) AS processing_time
# FROM activity
# GROUP BY machine_id;