USE AdventureWorks2008R2
GO

--Вывести информацию (фамилию, имя) обо всех сотрудниках компании с указанием заказов, за которые 
--они отвечали, а также дату и номер документа о заказе. Если сотрудник не отвечал ни за какие заказы, 
--то он всe равно должен быть включeн в этот список. Использовать таблицы Person.Person, HumanRe-sources.
--Employee и Sales.SalesOrderHeader. Результат отсортировать по коду со-трудника (BusinessEntityID). 
--Необходимые поля: BusinessEntityID (таблицы Per-son.Person, HumanResources.Employee), 
--FirstName и LastName (таблица Person.Person), 
--OrderDate, SalesOrderNumber и SalesPersonID (таблица Sales.SalesOrderHeader)

SELECT 
p.BusinessEntityID,
p.FirstName, 
p.LastName,
s.OrderDate,
s.SalesOrderNumber
FROM Person.Person p 
	INNER JOIN HumanResources.Employee e 
		ON p.BusinessEntityID = e.BusinessEntityID
	LEFT OUTER JOIN Sales.SalesOrderHeader s 
		ON s.SalesPersonID = p.BusinessEntityID

ORDER BY p.BusinessEntityID