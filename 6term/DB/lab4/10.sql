USE AdventureWorks2008R2
GO

--Вывести из таблицы Sales.SalesOrderDetail информацию о коде и сред-ней цене 
--проданных продуктов, для которых количество в одном заказе пре-вышает 10 штук. 
--Результат отсортировать по средней цене

select ProductID, AVG(LineTotal/OrderQty) as 'цена'
from Sales.SalesOrderDetail
where OrderQty > 10
group by ProductID
order by AVG(LineTotal/OrderQty) 
GO