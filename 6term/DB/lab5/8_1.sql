USE AdventureWorks2008R2
GO

--¬ывести информацию обо всех доходах с продаж и скидках по каждому продукту. 
--»спользовать таблицы Production.Product (пол€ ProductID и Name) и 
--Sales.SalesOrderDetail (пол€ ProductID, OrderQty, UnitPrice и UnitPrice-Discount). 
--—оздать запросы двух видов: с использованием внешнего соединени€ и без него.

SELECT 
p.Name,
s.OrderQty,
s.UnitPrice,
s.UnitPriceDiscount
FROM Production.Product p LEFT OUTER JOIN Sales.SalesOrderDetail s
	ON p.ProductID = s.ProductID
	