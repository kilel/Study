USE AdventureWorks2008R2
GO
--2.1. Создать хранимую процедуру, реализующую следующий запрос:

CREATE PROC lab1_pr
AS
BEGIN
	SELECT Name, ProductNumber, DaysToManufacture
	FROM Production.Product
	WHERE DaysToManufacture >= 1
	ORDER BY DaysToManufacture DESC, Name
END