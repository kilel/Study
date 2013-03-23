use AdventureWorks2008R2
GO

--2.5. ������� �������� ��������� GetDiscountsForCategoryAndDate � ���-�� Sales, 
--������� ��������� �������� @Category, ��� � GetDiscountsForCategory, �� �������� 
--�������������� ������� �������� @DateToCheck datetime. �������� @DateToCheck 
--������ ����� ������-����� ��������� ����������� �������� NULL. ���� �������� 
--NULL ������� ��� ��������� @DateToCheck, ������ ��� ����� ��������� �������� 
--������� ���� � �������, ��������� ������� GETDATE. 
--��� ��������� ������ �����-���� �� �� �������, ��� � ��� GetDiscounts, 
--�� ������ ����������� ������ �� ������ ���������� @Category � @DateToCheck..


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
