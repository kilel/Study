USE AdventureWorks2008R2
GO

--������� �� ������� Person.PersonPhone ���������� ��� ���� 
--����-������ ������� � ������������ ����� 415

select *
from Person.PersonPhone
where PhoneNumber like '415-%'
GO