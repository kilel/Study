USE AdventureWorks2008R2
GO

--������� ���������� � �������� (ProductID, Name), ������������ � ������������ 
--� ���� 2005 ����. 
--������������ ������� Production.Product � Production.WorkOrder. 
--������� ������� ���� �����: � �������������� �������� ����������� � ��� ��e.

SELECT a.ProductID, a.Name
FROM Production.Product a
WHERE a.ProductID IN 
(
	SELECT p.ProductID
	FROM Production.Product p
	INTERSECT
	SELECT w.ProductID
	FROM Production.WorkOrder w
	WHERE
		MONTH(w.DueDate) = 7 AND 
		YEAR(w.DueDate) = 2005 
)