USE tempdb
GO

--работодателей, к которым никто не может устроиться

SELECT *
FROM employer e
WHERE NOT EXISTS 
(
	select w.id
	from worker w
	where e.work_type = w.work_type and e.salary >= w.salary
)