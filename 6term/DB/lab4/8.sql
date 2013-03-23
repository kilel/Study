USE AdventureWorks2008R2
GO
--Вывести информацию о коде модели продукта (ProductModelID) 
--и средней цене по этому коду из таблицы Production.Product. 
--Рассматриваются только продукты, цена на которые превышает $1000. 
--Результат отсортировать по коду модели.

select ProductModelID ,
AVG(ListPrice) as 'Средняя цена'
from Production.Product
where ListPrice >= 1000
group by ProductModelID
order by ProductModelID
GO
