use AdventureWorks2008R2
GO

--1.6. Создать необходимые триггеры UPDATE, INSERT, DELETE, которые будут 
--разрешать изменение данных в таблице Sales.SalesOrderDetail только в том случае, 
--когда заказ находится в стадии выполнения (таблица Sales.SalesOrderHeader, 
--поле Status=1).

//ко всем тем добавить AND status = 1