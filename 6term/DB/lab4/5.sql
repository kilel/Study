USE AdventureWorks2008R2
GO

--Найти общий объём продаж (LineTotal) для каждого заказа 
--из таблицы Sales.SalesOrderDetail. 
--Результат отсортировать по коду заказа (SalesOrderID).

select sum(LineTotal) as 'Объём продаж'
from Sales.SalesOrderDetail
GO