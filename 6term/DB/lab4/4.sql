USE AdventureWorks2008R2
GO

--������� ���������� � ���������� ����������� (JobTitle) 
--�������� �� ������� HumanResources.Employee. ��������� ������������� �� ��������. 
--������� �� �������������� ������� ��� ������������� ������.

select distinct JobTitle as '���������'
from HumanResources.Employee
order by JobTitle
GO