USE AdventureWorks2008R2
GO

--Вывести информацию о продукте (ProductID, Name), находившемся в производстве 
--в июле 2005 года. 
--Использовать таблицы Production.Product и Production.WorkOrder. 
--Создать запросы двух типов: с использованием операции пересечения и без неe.

SELECT p.ProductID, p.Name, w.DueDate
FROM Production.Product p CROSS JOIN Production.WorkOrder w
WHERE 
	p.ProductID = w.ProductID AND 
	MONTH(w.DueDate) = 7 AND 
	YEAR(w.DueDate) = 2005
