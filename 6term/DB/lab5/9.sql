USE AdventureWorks2008R2
GO

--������� ������������ ������ (������� Production.Product, ���� Pro-ductModelID � 
--Name), �������� � ������� Production.ProductModel (���� Pro-ductModelID � Name) 
--������������� ������������ 'Long-sleeve logo jersey' (����� � �������� ��������, 
--� ��������). 
--��������� ������� � ������������-�� ��������� ����� EXISTS � ��������� ����� IN.

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