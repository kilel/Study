USE AdventureWorks2008R2
GO
--������� �� ������� Person.Person ���������� � ����������� � ����-���� Zheng ��� Zhang. 
--��������� ������������� �� ������� � �����.

select *
from Person.Person
where LastName = 'Zheng' or LastName = 'Zhang'
order by LastName, FirstName
GO