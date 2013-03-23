USE AdventureWorks2008R2
GO

--¬ывести информацию (фамили€, им€, дата поступлени€ на работу) о кандидатах на должность, 
--прин€тых на работу. »спользовать таблицы Per-son.Person (пол€ FirstName, LastName и BusinessEntityID), 
--HumanRe-sources.JobCandidate (поле BusinessEntityID) и 
--HumanResources.Employee (пол€ BusinessEntityID и HireDate).

SELECT p.FirstName, p.LastName, e.HireDate
FROM Person.Person p, HumanResources.Employee e, HumanResources.JobCandidate j
WHERE p.BusinessEntityID = e.BusinessEntityID AND p.BusinessEntityID = j.BusinessEntityID