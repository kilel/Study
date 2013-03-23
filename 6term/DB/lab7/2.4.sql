use AdventureWorks2008R2
GO

--2.4. ������� �������� ��������� GetDiscountsForCategory � ����� Sales, 
--������� ��������� ������� �������� @Category, ������� ��� ������ nvarchar � 
--����������� �� 50 ��������. ��� ��������� ������ ��������� �� �� �������, ��� 
--� ��� GetDiscounts, �� ������ ����������� ������ �� ������ ��������� @Category.

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
