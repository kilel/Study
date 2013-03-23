USE AdventureWorks2008R2
GO

--������� ���������� ��� ���� ������� � ������ � ������� �� ������� ��������. 
--������������ ������� Production.Product (���� ProductID � Name) � 
--Sales.SalesOrderDetail (���� ProductID, OrderQty, UnitPrice � UnitPrice-Discount). 
--������� ������� ���� �����: � �������������� �������� ���������� � ��� ����.

SELECT 
p.Name,
s.OrderQty,
s.UnitPrice,
s.UnitPriceDiscount
FROM Production.Product p INNER JOIN Sales.SalesOrderDetail s
	ON p.ProductID = s.ProductID
	