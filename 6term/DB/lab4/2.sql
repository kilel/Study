USE AdventureWorks2008R2
GO

--������� ���������� � ������������ (Name), ������ (ProductNumber) � ���� (Listprice) ���� ��������� �� ������� Production.Product. ��������� ������������� �� ������������ ��������. ���-������ �������� �������������� ������� ��������� �� ������� �����.
select 
Name as '���',
ProductNumber as '�����',
ListPrice as '����'

from Production.Product
GO