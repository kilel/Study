USE AdventureWorks2008R2
GO

--������� ���������� ��� ���� ������� (���� � ����� ���������) � ���-������ ����������� (�������, ���), 
--���� ����, ���������� �� ��� ������. ��-���������� ������� Person.Person � Sales.SalesOrderHeader. 
--��������� �������-������ �� ���� ���������. 
--����������� ����: BusinessEntityID, FirstName � LastName (������� Person.Person), 
--OrderDate, SalesOrderNumber � SalesPersonID (������� Sales.SalesOrderHeader).


SELECT s.OrderDate, 
s.SalesOrderNumber, 
p.FirstName,
p.LastName
FROM Person.Person p, Sales.SalesOrderHeader s
WHERE p.BusinessEntityID = s.SalesPersonID
ORDER BY s.OrderDate