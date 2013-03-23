USE AdventureWorks2008R2
GO

--Вывести информацию (фамилия, имя из таблицы Person.Person и должность из таблицы 
--HumanResources.Employee) о сотрудниках, для которых значение премии в таблице 
--Sales.SalesPerson составляет 5 000 (поле Bonus).

SELECT p.FirstName + ' ' +p.LastName+', '+e.JobTitle as 'worker'
FROM Person.Person p 
	INNER JOIN HumanResources.Employee e
		ON p.BusinessEntityID = e.BusinessEntityID
	INNER JOIN Sales.SalesPerson s
		ON p.BusinessEntityID = s.BusinessEntityID
WHERE s.Bonus = 5000
GO