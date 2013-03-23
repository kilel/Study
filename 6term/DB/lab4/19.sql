USE AdventureWorks2008R2
GO
--Вывести из таблицы Person.Person список сотрудников, чья фамилия начинается 
--на «G» в виде XML-документа. Для создания XML-документа 
--ис-пользовать аргументы AUTO, TYPE, XMLSCHEMA, ELEMENTS XSINIL
select *
from Person.Person
where LastName like 'G%'
for xml auto, xmlschema, elements xsinil, TYPE
GO