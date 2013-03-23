USE AdventureWorks2008R2
GO
--������� ���������� � ���� ������ �������� (ProductModelID) 
--� ������� ���� �� ����� ���� �� ������� Production.Product. 
--��������������� ������ ��������, ���� �� ������� ��������� $1000. 
--��������� ������������� �� ���� ������.

select ProductModelID ,
AVG(ListPrice) as '������� ����'
from Production.Product
where ListPrice >= 1000
group by ProductModelID
order by ProductModelID
GO
