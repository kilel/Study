use AdventureWorks2008R2
GO

--1.4. Создать триггер INSERT (AFTER), который будет уменьшать количест-во продукта
-- на складе (таблица Production.Product, поле ReorderPoint) при создании новой 
--строки в таблице Sales.SalesOrderDetail.

CREATE TRIGGER do_after ON Sales.SalesOrderDetail
AFTER INSERT
AS
BEGIN
	UPDATE Production.Product
	SET ReorderPoint =	ReorderPoint - (
	select OrderQty from inserted i where i.ProductID = ProductID
	) 
	WHERE ProductID IN (select i.ProductID  from inserted i)
END