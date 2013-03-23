USE AdventureWorks2008R2
GO

--Вывести из таблицы Production.Product информацию обо всех продук-тах, 
--в наименовании которых встречается слово «ball»

select *
from Production.Product
where Name like '%Tube%'
GO