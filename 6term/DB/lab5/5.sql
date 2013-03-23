USE AdventureWorks2008R2
GO

--������� ���������� (�������, ���) ��� ���� ����������� �������� � ��������� �������, �� ������� 
--��� ��������, � ����� ���� � ����� ��������� � ������. ���� ��������� �� ������� �� �� ����� ������, 
--�� �� ��e ����� ������ ���� �����e� � ���� ������. ������������ ������� Person.Person, HumanRe-sources.
--Employee � Sales.SalesOrderHeader. ��������� ������������� �� ���� ��-�������� (BusinessEntityID). 
--����������� ����: BusinessEntityID (������� Per-son.Person, HumanResources.Employee), 
--FirstName � LastName (������� Person.Person), 
--OrderDate, SalesOrderNumber � SalesPersonID (������� Sales.SalesOrderHeader)

SELECT 
p.BusinessEntityID,
p.FirstName, 
p.LastName,
s.OrderDate,
s.SalesOrderNumber
FROM Person.Person p 
	INNER JOIN HumanResources.Employee e 
		ON p.BusinessEntityID = e.BusinessEntityID
	LEFT OUTER JOIN Sales.SalesOrderHeader s 
		ON s.SalesPersonID = p.BusinessEntityID

ORDER BY p.BusinessEntityID