USE AdventureWorks2008R2
GO
--Вывести информацию о наименовании, номере и цене всех продуктов из таблицы 
--Production.Product, для которых линейки продуктов начинаются символом R 
--и для которых длительность изготовления не превышает 4 дней. 
--Результат отсортировать по наименованию продукта

select 
Name as 'Имя',
ProductNumber as 'Номер',
ListPrice as 'Цена'
from Production.Product
where Name like 'R%' and DaysToManufacture <= 4
order by Name
GO