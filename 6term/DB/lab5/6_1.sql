USE AdventureWorks2008R2
GO

--������� ���������� � �������� (ProductID, Name), ������������ � ������������ 
--� ���� 2005 ����. 
--������������ ������� Production.Product � Production.WorkOrder. 
--������� ������� ���� �����: � �������������� �������� ����������� � ��� ��e.

SELECT p.ProductID, p.Name, w.DueDate
FROM Production.Product p CROSS JOIN Production.WorkOrder w
WHERE 
	p.ProductID = w.ProductID AND 
	MONTH(w.DueDate) = 7 AND 
	YEAR(w.DueDate) = 2005
