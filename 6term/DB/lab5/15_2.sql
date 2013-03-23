USE tempdb
GO

--всех, кто устроился на работу

SELECT w.fname, w.sname, d.work_type, d.salary, e.name as 'company name'
FROM worker w
	INNER JOIN deals d
		ON w.id = d.worker
	INNER JOIN employer e
		ON e.id = d.empl
