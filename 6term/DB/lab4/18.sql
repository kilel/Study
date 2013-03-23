USE AdventureWorks2008R2
GO
--Вывести из таблицы Person.Person список сотрудников в виде XML-документа
select *
from Person.Person
FOR XML auto
GO