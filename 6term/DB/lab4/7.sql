USE AdventureWorks2008R2
GO

--������� ���������� � ������������, ���� ���� ��������� 
--� ���� ��-���� (ProductModelID) �� ������� Production.Product, 
--��� ������� ���� �����-���� $1000. 
--��������� ������������� �� ������������ ��������

select Name as '���', 
ProductModelID as '����� ������', 
ListPrice as '����'
from Production.Product
where ListPrice >= 1000
order by Name
GO