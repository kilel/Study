USE AdventureWorks2008R2;

--������� ���������� (�������, ���, ���� ����������� �� ������) � �����������, ������������� � 
--�������� ����� ������ ���. ������������ ���-���� Person.Person (���� FirstName, 
--LastName � BusinessEntityID) � HumanRe-sources.Employee (���� BusinessEntityID � HireDate). 
--��������� ������������� �� ���� ����������� �� ������.

SELECT p.FirstName, p.LastName, e.HireDate
FROM Person.Person p, HumanResources.Employee e
WHERE p.BusinessEntityID = e.BusinessEntityID
ORDER BY e.HireDate
GO