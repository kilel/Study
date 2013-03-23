USE AdventureWorks2008R2
GO

--Вывести наименование товара (таблица Production.Product, поля Pro-ductModelID и 
--Name), которому в таблице Production.ProductModel (поля Pro-ductModelID и Name) 
--соответствует наименование 'Long-sleeve logo jersey' (кофта с длинными рукавами, 
--с эмблемой). 
--Составить запросы с использовани-ем ключевого слова EXISTS и ключевого слова IN.

SELECT p.ProductModelID, p.Name
FROM Production.Product p
WHERE  p.ProductModelID  IN 
	(
		SELECT s.ProductModelID
		FROM Production.ProductModel s
		WHERE s.Name = 'Half-Finger Gloves'
	)
	
SELECT p.ProductModelID, p.Name
FROM Production.Product p
WHERE EXISTS 
	(
		SELECT s.ProductModelID
		FROM Production.ProductModel s
		WHERE s.Name = 'Half-Finger Gloves' and p.ProductModelID = s.ProductModelID
	)