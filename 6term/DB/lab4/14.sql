USE AdventureWorks2008R2
GO
--������� �� ������� Person.Person ���������� � ����������� � ���-��� 
--Cheryl ��� Sheryl. ��������� ������������� �� �������

select *
from Person.Person
where FirstName = 'Cheryl' or FirstName = 'Sheryl'
order by LastName
GO