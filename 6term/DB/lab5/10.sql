USE AdventureWorks2008R2
GO

--Вывести информацию (фамилия, имя из таблицы Person.Person) о со-трудниках, 
--для которых значение премии в таблице Sales.SalesPerson 
--составляет 5 000 (поле Bonus)

SELECT p.FirstName + ' '+p.LastName as 'name'
FROM Person.Person p INNER JOIN Sales.SalesPerson s
	ON p.BusinessEntityID = s.BusinessEntityID
WHERE s.Bonus = 5000