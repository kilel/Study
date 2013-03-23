USE AdventureWorks2008R2
GO
--������� �������������, ��������� ������ � ����������� �������� (����� Person). 
--� ������ � ����������� �������� ������� ����������, ��� ���, �����, ������� � ���������
CREATE VIEW PERSONAL_seattle 
AS
SELECT p.FirstName+' '+p.LastName AS 'name',
e.JobTitle,
ph.PhoneNumber,
a.AddressLine1,
a.AddressLine2,
a.City,
a.PostalCode
FROM Person.Person p 
	INNER JOIN Person.PersonPhone ph
	ON p.BusinessEntityID = ph.BusinessEntityID
	INNER JOIN Person.BusinessEntityAddress ea
	ON ea.BusinessEntityID = p.BusinessEntityID
	INNER JOIN Person.Address a
	ON ea.AddressID = a.AddressID AND a.City = 'Seattle'
	INNER JOIN HumanResources.Employee e
	ON e.BusinessEntityID = p.BusinessEntityID
	