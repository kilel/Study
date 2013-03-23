USE AdventureWorks2008R2;

--������� ���������� (�������, ���) � ���������� �� ���������, ���-����� �� ������. 
--������������ ������� Person.Person (���� FirstName, Last-Name � BusinessEntityID) � 
--HumanResources.JobCandidate (���� BusinessEntity-ID).

SELECT p.FirstName, p.LastName
FROM Person.Person p, HumanResources.JobCandidate b
WHERE p.BusinessEntityID = b.BusinessEntityID