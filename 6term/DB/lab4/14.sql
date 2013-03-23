USE AdventureWorks2008R2
GO
--Вывести из таблицы Person.Person информацию о сотрудниках с име-нем 
--Cheryl или Sheryl. Результат отсортировать по фамилии

select *
from Person.Person
where FirstName = 'Cheryl' or FirstName = 'Sheryl'
order by LastName
GO