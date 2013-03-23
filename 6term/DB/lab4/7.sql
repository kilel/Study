USE AdventureWorks2008R2
GO

--Вывести информацию о наименовании, цене всех продуктов 
--и коде мо-дели (ProductModelID) из таблицы Production.Product, 
--для которых цена превы-шает $1000. 
--Результат отсортировать по наименованию продукта

select Name as 'Имя', 
ProductModelID as 'Номер модели', 
ListPrice as 'Цена'
from Production.Product
where ListPrice >= 1000
order by Name
GO