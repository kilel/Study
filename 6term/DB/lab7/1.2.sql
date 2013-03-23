use AdventureWorks2008R2
GO
--1.2. Создать триггер DELETE (INSTEAD OF) для таблицы Sales.SalesOrderHeader, 
--который будет блокировать удаление записи при на-личии ссылающихся на неё строк 
--из таблицы Sales.SalesOrderDetail.

Create TRIGGER check_linked ON Sales.SalesOrderHeader
INSTEAD OF DELETE
AS
BEGIN
	DELETE Sales.SalesOrderHeader
	WHERE SalesOrderID IN 
	(
	select SalesOrderID 
	from deleted
	EXCEPT
	select so.SalesOrderID 
	from Sales.SalesOrderDetail so INNER JOIN deleted de
	ON  so.SalesOrderID=de.SalesOrderID
	)
END