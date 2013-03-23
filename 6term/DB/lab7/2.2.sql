use AdventureWorks2008R2
GO

--2.2. �������� �������� ��������� (������� 2.1) ����� �������, ����� ��� 
--��������� � �������� ��������� ���������� ����, ��������� ��� ������������ 
--��������� (���� DaysToManufacture). � ���� ��������� ���������� �������� �� 
--������������ �������� ���������.

CREATE PROC lab2_2pr @days int
AS
BEGIN
	SELECT Name, ProductNumber, DaysToManufacture
	FROM Production.Product
	WHERE DaysToManufacture >= @days
	ORDER BY DaysToManufacture DESC, Name
END