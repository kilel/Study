USE tempdb
GO

--�������������, � ������� ����� �� ����� ����������

SELECT *
FROM employer e
WHERE NOT EXISTS 
(
	select w.id
	from worker w
	where e.work_type = w.work_type and e.salary >= w.salary
)