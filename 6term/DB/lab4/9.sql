USE AdventureWorks2008R2
GO
--Вывести из таблицы Sales.SalesOrderDetail информацию о среднем ко-личестве 
--приобретаемых продуктов (OrderQty) и стоимости покупки (OrderQty * UnitPrice). 
--Результат сгруппировать по стоимости и вывести в порядке убыва-ния

select UnitPrice,
AVG(OrderQty) as 'среднее количество',
AVG(OrderQty)*UnitPrice as 'на сумму'
from Sales.SalesOrderDetail
group by UnitPrice
order by UnitPrice
GO