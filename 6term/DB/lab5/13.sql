USE AdventureWorks2008R2
GO

--Вывести информацию (фамилия, имя из таблицы Person.Person) о со-трудниках, 
--продававших товар 'BK-M68B-42' (таблица Production.Product, поле ProductNumber). 
--Необходимо задействовать таблицы Sales.SalesOrderHeader (поле SalesOrderID) и 
--Sales.SalesOrderDetail (поле ProductID)
DECLARE @item int = (
		select distinct ProductID 
		from Production.Product 
		where ProductNumber = 'BK-M68B-42')
		

		
SELECT distinct 
p.BusinessEntityID,
p.FirstName+' '+p.LastName
FROM Person.Person p 
	JOIN Sales.SalesOrderHeader sh
		ON sh.SalesPersonID = p.BusinessEntityID
	JOIN Sales.SalesOrderDetail sd
		ON sd.SalesOrderID = sh.SalesOrderID
WHERE sd.ProductID = @item