USE tempdb
GO

--�������������, � ������� ����� �� ���������

SELECT *
FROM employer e
WHERE e.id NOT IN (select empl from deals)