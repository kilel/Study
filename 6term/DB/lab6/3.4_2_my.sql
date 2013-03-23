USE dbase
GO
--Все вакантные места
IF EXISTS
(
	SELECT * FROM sys.views
	WHERE name = N'vacancy'
) DROP VIEW vacancy
GO
CREATE VIEW vacancy
AS
SELECT e.work_type, 
e.requ,
e.email,
e.phone,
e.adress,
e.salary,
e.name
FROM employers e
WHERE e.vacancy > 0
GO

