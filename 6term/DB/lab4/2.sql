USE AdventureWorks2008R2
GO

--Вывести информацию о наименовании (Name), номере (ProductNumber) и цене (Listprice) всех продуктов из таблицы Production.Product. Результат отсортировать по наименованию продукта. При-своить столбцам результирующей таблицы заголовки на русском языке.
select 
Name as 'Имя',
ProductNumber as 'Номер',
ListPrice as 'Цена'

from Production.Product
GO