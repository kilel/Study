use AdventureWorks2008R2
GO

--2.4. Создать хранимую процедуру GetDiscountsForCategory в схеме Sales, 
--которая принимает входной параметр @Category, имеющий тип данных nvarchar и 
--принимающий до 50 символов. Эта процедура должна извлекать те же столбцы, что 
--и для GetDiscounts, но должна фильтровать строки на основе параметра @Category.

CREATE PROC Sales.GetDiscountsForCategory @Category nvarchar(50)
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
	WHERE Category = @Category
	ORDER BY StartDate, EndDate	
END
