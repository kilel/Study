USE AdventureWorks2008R2
GO
--������� ���������� � ������������, ������ � ���� ���� ��������� �� ������� 
--Production.Product, ��� ������� ������� ��������� ���������� �������� R 
--� ��� ������� ������������ ������������ �� ��������� 4 ����. 
--��������� ������������� �� ������������ ��������

select 
Name as '���',
ProductNumber as '�����',
ListPrice as '����'
from Production.Product
where Name like 'R%' and DaysToManufacture <= 4
order by Name
GO