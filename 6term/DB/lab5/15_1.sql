USE tempdb
GO

--����, ��� ����� ����������, �� �� ������������

select w.* 
from worker w 
	INNER JOIN employer e
		ON w.work_type = e.work_type
WHERE w.id NOT IN 
(
	SELECT worker
	FROM deals
)