USE AdventureWorks2008R2
GO

--Вывести информацию обо всех заказах (дата и номер документа) с ука-занием сотрудников (фамилия, имя), 
--если есть, отвечавших за эти заказы. Ис-пользовать таблицы Person.Person и Sales.SalesOrderHeader. 
--Результат отсорти-ровать по дате документа. 
--Необходимые поля: BusinessEntityID, FirstName и LastName (таблица Person.Person), 
--OrderDate, SalesOrderNumber и SalesPersonID (таблица Sales.SalesOrderHeader).


SELECT s.OrderDate, 
s.SalesOrderNumber, 
p.FirstName,
p.LastName
FROM Person.Person p, Sales.SalesOrderHeader s
WHERE p.BusinessEntityID = s.SalesPersonID
ORDER BY s.OrderDate