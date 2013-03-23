USE AdventureWorks2008R2;

--Вывести информацию (фамилия, имя, дата поступления на работу) о сотрудниках, проработавших в 
--компании менее десяти лет. Использовать таб-лицы Person.Person (поля FirstName, 
--LastName и BusinessEntityID) и HumanRe-sources.Employee (поля BusinessEntityID и HireDate). 
--Результат отсортировать по дате поступления на работу.

SELECT p.FirstName, p.LastName, e.HireDate
FROM Person.Person p, HumanResources.Employee e
WHERE p.BusinessEntityID = e.BusinessEntityID
ORDER BY e.HireDate
GO