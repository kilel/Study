USE dbase
GO
--все ищущие работу чуваки
IF EXISTS
(
	SELECT * FROM sys.views
	WHERE name = N'WORKER'
) DROP VIEW WORKER
GO
CREATE VIEW WORKER
AS
SELECT * 
FROM workers
WHERE Found_work IS NULL
GO

