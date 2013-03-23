USE AdventureWorks2008R2;

--¬ывести информацию (фамили€, им€) о кандидатах на должность, при-н€тых на работу. 
--»спользовать таблицы Person.Person (пол€ FirstName, Last-Name и BusinessEntityID) и 
--HumanResources.JobCandidate (поле BusinessEntity-ID).

SELECT p.FirstName, p.LastName
FROM Person.Person p, HumanResources.JobCandidate b
WHERE p.BusinessEntityID = b.BusinessEntityID