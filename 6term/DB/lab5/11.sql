USE AdventureWorks2008R2
GO

--������� ���������� (�������, ��� �� ������� Person.Person � ��������� �� ������� 
--HumanResources.Employee) � �����������, ��� ������� �������� ������ � ������� 
--Sales.SalesPerson ���������� 5 000 (���� Bonus).

SELECT p.FirstName + ' ' +p.LastName+', '+e.JobTitle as 'worker'
FROM Person.Person p 
	INNER JOIN HumanResources.Employee e
		ON p.BusinessEntityID = e.BusinessEntityID
	INNER JOIN Sales.SalesPerson s
		ON p.BusinessEntityID = s.BusinessEntityID
WHERE s.Bonus = 5000
GO