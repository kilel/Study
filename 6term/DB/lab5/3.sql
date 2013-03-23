USE AdventureWorks2008R2
GO

--������� ���������� (�������, ���, ���� ����������� �� ������) � ���������� �� ���������, 
--�������� �� ������. ������������ ������� Per-son.Person (���� FirstName, LastName � BusinessEntityID), 
--HumanRe-sources.JobCandidate (���� BusinessEntityID) � 
--HumanResources.Employee (���� BusinessEntityID � HireDate).

SELECT p.FirstName, p.LastName, e.HireDate
FROM Person.Person p, HumanResources.Employee e, HumanResources.JobCandidate j
WHERE p.BusinessEntityID = e.BusinessEntityID AND p.BusinessEntityID = j.BusinessEntityID