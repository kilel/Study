USE AdventureWorks2008R2
GO
--2.3. ������� �������� ��������� GetDiscounts � ����� Sales, ������� ��-������� 
--��������� ������� �� ������� Sales.SpecialOffer: Description, Dis-countPct, 
--Type, Category, StartDate, EndDate, MinQty � MaxQty. ��������� ������ ���������� 
--��� ������, ��������������� �� ���������� StartDate � EndDate.

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