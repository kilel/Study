use AdventureWorks2008R2
GO

--2.2. »зменить хранимую процедуру (задание 2.1) таким образом, чтобы она 
--принимала в качестве параметра количество дней, требуемых дл€ производства 
--продукции (поле DaysToManufacture). ¬ теле процедуры установить проверку на 
--корректность значени€ параметра.

CREATE PROC lab2_2pr @days int
AS
BEGIN
	SELECT Name, ProductNumber, DaysToManufacture
	FROM Production.Product
	WHERE DaysToManufacture >= @days
	ORDER BY DaysToManufacture DESC, Name
END