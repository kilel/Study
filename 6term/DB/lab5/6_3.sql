USE AdventureWorks2008R2
GO

--Вывести информацию о продукте (ProductID, Name), находившемся в производстве 
--в июле 2005 года. 
--Использовать таблицы Production.Product и Production.WorkOrder. 
--Создать запросы двух типов: с использованием операции пересечения и без неe.

SELECT a.ProductID, a.Name
FROM Production.Product a
WHERE a.ProductID IN 
(
	SELECT p.ProductID
	FROM Production.Product p
	INTERSECT
	SELECT w.ProductID
	FROM Production.WorkOrder w
	WHERE
		MONTH(w.DueDate) = 7 AND 
		YEAR(w.DueDate) = 2005 
)