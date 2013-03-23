USE AdventureWorks2008R2
GO

--Вывести из таблицы Production.Product информацию о продуктах с 
--на-именованиями Blade, Crown Race или Spokes

select *
from Production.Product
where Name like '%Blade%' or Name like '%Crown Race%' or Name like '%Spokes%'
GO