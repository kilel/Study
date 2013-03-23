USE AdventureWorks2008R2
GO

--¬ывести из таблицы Person.PersonPhone информацию обо всех 
--теле-фонных номерах с региональным кодом 415

select *
from Person.PersonPhone
where PhoneNumber like '415-%'
GO