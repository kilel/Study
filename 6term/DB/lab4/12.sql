USE AdventureWorks2008R2
GO

--������� �� ������� Production.Product ���������� ��� ���� ������-���, 
--� ������������ ������� ����������� ����� �ball�

select *
from Production.Product
where Name like '%Tube%'
GO