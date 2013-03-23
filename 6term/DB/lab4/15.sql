USE AdventureWorks2008R2
GO
--Вывести из таблицы Person.Person информацию о сотрудниках с фами-лией Zheng или Zhang. 
--Результат отсортировать по фамилии и имени.

select *
from Person.Person
where LastName = 'Zheng' or LastName = 'Zhang'
order by LastName, FirstName
GO