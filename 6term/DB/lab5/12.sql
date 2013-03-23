USE AdventureWorks2008R2
GO

--¬ывести информацию о модел€х продуктов (таблица Production.Product, пол€ 
--ProductModelID и ListPrice), дл€ которых максимальна€ цена в каталоге превышает 
--среднюю цену по нему на 2% и больше
DECLARE @a int;
SET @a = (select AVG(ListPrice) from Production.Product)
select 
p.ProductModelID,
 p.Name, 
 p.ListPrice,
 @a*p.ListPrice/p.ListPrice as 'avg'
from Production.Product p
where @a*1.02 <=
	(
		SELECT MAX(s.ListPrice)
		FROM Production.Product s
		where s.ProductModelID = p.ProductModelID
	)
	
	
