use AdventureWorks2008R2
GO

--2.5. Создать хранимую процедуру GetDiscountsForCategoryAndDate в схе-ме Sales, 
--которая принимает параметр @Category, как и GetDiscountsForCategory, но включает 
--дополнительный входной параметр @DateToCheck datetime. Параметр @DateToCheck 
--должен иметь возмож-ность принимать стандартное значение NULL. Если значение 
--NULL указано для параметра @DateToCheck, задать для этого параметра значение 
--текущих даты и времени, используя функцию GETDATE. 
--Эта процедура должна извле-кать те же столбцы, что и для GetDiscounts, 
--но должна фильтровать строки на основе параметров @Category и @DateToCheck..


CREATE PROC Sales.GetDiscountsForCategoryAndDate @Category nvarchar(50), @DateToCheck datetime = NULL
AS
BEGIN
	IF @DateToCheck IS NOT NULL
	SET @DateToCheck = GETDATE()
	
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
	WHERE Category = @Category AND EndDate >= @DateToCheck
	ORDER BY StartDate, EndDate	
END
