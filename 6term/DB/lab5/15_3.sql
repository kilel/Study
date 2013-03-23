USE tempdb
GO

--всех, для кого нет вакансий

SELECT *
FROM worker w
WHERE NOT EXISTS 
(
	select work_type 
	from employer e
	where e.work_type = w.work_type and w.salary <= e.salary
)