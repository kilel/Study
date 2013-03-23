use AdventureWorks2008R2
GO

--2.6. ������� �������� ���������, ����������� ��������� �������� 
--(��-������, ����) � ��������, ����������� � ��������� ������������� ������ 
--(��-�� SellStartDate � SellEndDate). � ���� ��������� ������������� �������� 
--�� ������������ �������� ����������.

CREATE PROC lab6_proc @stda datetime = NULL, @enda datetime = NULL
AS
BEGIN
	SELECT Name, ListPrice
	FROM Production.Product p
	WHERE  (@stda IS NULL OR  p.SellStartDate > @stda ) AND  (@enda IS NULL OR  p.SellEndDate > @enda ) 
END
