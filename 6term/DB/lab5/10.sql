USE AdventureWorks2008R2
GO

--������� ���������� (�������, ��� �� ������� Person.Person) � ��-���������, 
--��� ������� �������� ������ � ������� Sales.SalesPerson 
--���������� 5 000 (���� Bonus)

SELECT p.FirstName + ' '+p.LastName as 'name'
FROM Person.Person p INNER JOIN Sales.SalesPerson s
	ON p.BusinessEntityID = s.BusinessEntityID
WHERE s.Bonus = 5000