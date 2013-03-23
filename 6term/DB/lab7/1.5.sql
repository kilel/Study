use AdventureWorks2008R2
GO

--1.5. Создать необходимые триггеры UPDATE, которые будут разрешать 
--из-менение данных в таблице Sales.SalesOrderDetail только в том случае, 
--если но-вое запрошенное количество может быть предоставлено заказчику. 
--При этом следует внести необходимые изменения в данные на складе.

CREATE TRIGGER upd ON Sales.SalesOrderDetail 
INSTEAD OF UPDATE
AS
BEGIN
	UPDATE Sales.SalesOrderDetail
	SET OrderQty = 
	(select 
	i.OrderQty
	from inserted  i
		join Production.Product pr
		ON i.ProductID = pr.ProductID AND i.OrderQty <= pr.ReorderPoint
	WHERE SalesOrderID = i.SalesOrderID AND SalesOrderDetailID = i.SalesOrderDetailID
	)
	WHERE EXISTS
	(select 
	i.OrderQty
	from inserted  i
		join Production.Product pr
		ON i.ProductID = pr.ProductID AND i.OrderQty <= pr.ReorderPoint
	WHERE SalesOrderID = i.SalesOrderID AND SalesOrderDetailID = i.SalesOrderDetailID
	)
	--select * from inserted
	
END
GO


CREATE TRIGGER after_upd ON Sales.SalesOrderDetail
AFTER UPDATE
AS
BEGIN
	UPDATE Production.Product
	SET ReorderPoint =	ReorderPoint - (
	select OrderQty from inserted i where i.ProductID = ProductID
	) 
	WHERE ProductID IN (select i.ProductID  from inserted i)
END