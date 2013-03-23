USE AdventureWorks2008R2
GO

--Вывести из таблицы Sales.SalesOrderDetail информацию о коде продан-ных продуктов, 
--для которых среднее количество в заказах превышает 5 штук. 
--Результат отсортировать по коду продуктов.

select distinct ProductID 
from Sales.SalesOrderDetail s
where 5 < (select avg(OrderQty)
		from Sales.SalesOrderDetail ss
		where ss.ProductID = s.ProductID)
	 
order by ProductID
GO