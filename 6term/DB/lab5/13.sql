USE AdventureWorks2008R2
GO

--������� ���������� (�������, ��� �� ������� Person.Person) � ��-���������, 
--����������� ����� 'BK-M68B-42' (������� Production.Product, ���� ProductNumber). 
--���������� ������������� ������� Sales.SalesOrderHeader (���� SalesOrderID) � 
--Sales.SalesOrderDetail (���� ProductID)
DECLARE @item int = (
		select distinct ProductID 
		from Production.Product 
		where ProductNumber = 'BK-M68B-42')
		

		
SELECT distinct 
p.BusinessEntityID,
p.FirstName+' '+p.LastName
FROM Person.Person p 
	JOIN Sales.SalesOrderHeader sh
		ON sh.SalesPersonID = p.BusinessEntityID
	JOIN Sales.SalesOrderDetail sd
		ON sd.SalesOrderID = sh.SalesOrderID
WHERE sd.ProductID = @item