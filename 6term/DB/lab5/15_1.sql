USE tempdb
GO

--всех, кто может устроиться, но не устраивается

select w.* 
from worker w 
	INNER JOIN employer e
		ON w.work_type = e.work_type
WHERE w.id NOT IN 
(
	SELECT worker
	FROM deals
)