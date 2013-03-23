USE AdventureWorks2008R2
GO

--Вывести информацию о должностях сотрудников (JobTitle) 
--компании из таблицы HumanResources.Employee. Результат отсортировать по алфавиту. 
--Удалить из результирующей таблицы все повторяющиеся строки.

select distinct JobTitle as 'Должность'
from HumanResources.Employee
order by JobTitle
GO