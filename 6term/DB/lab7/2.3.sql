USE AdventureWorks2008R2
GO
--2.3. Создать хранимую процедуру GetDiscounts в схеме Sales, которая из-влекает 
--следующие столбцы из таблицы Sales.SpecialOffer: Description, Dis-countPct, 
--Type, Category, StartDate, EndDate, MinQty и MaxQty. Процедура должна возвращать 
--все строки, отсортированные по параметрам StartDate и EndDate.

CREATE PROC Sales.lab3_proc
AS
BEGIN
	SELECT 
	Description, 
	DiscountPct, 
	Type, 
	Category, 
	StartDate, 
	EndDate, 
	MinQty,
	MaxQty
	FROM Sales.SpecialOffer
	ORDER BY StartDate, EndDate
END