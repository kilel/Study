USE AdventureWorks2008R2
GO
--������� �� ������� Person.Person ���������� � ����������� � ����-���� Zheng ��� Zhang. 
--��������� ������������� �� ������� � �����.

select COUNT(BusinessEntityID)
from Person.Person
where LastName = 'Zheng' or LastName = 'Zhang'
GO