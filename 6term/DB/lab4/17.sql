USE AdventureWorks2008R2
GO

--������� �� ������� Production.Product ���������� � ��������� � 
--��-������������ Blade, Crown Race ��� Spokes

select *
from Production.Product
where Name like '%Blade%' or Name like '%Crown Race%' or Name like '%Spokes%'
GO