use AdventureWorks2008R2
GO

--1.4. ������� ������� INSERT (AFTER), ������� ����� ��������� ��������-�� ��������
-- �� ������ (������� Production.Product, ���� ReorderPoint) ��� �������� ����� 
--������ � ������� Sales.SalesOrderDetail.

CREATE TRIGGER do_after ON Sales.SalesOrderDetail
AFTER INSERT
AS
BEGIN
	UPDATE Production.Product
	SET ReorderPoint =	ReorderPoint - (
	select OrderQty from inserted i where i.ProductID = ProductID
	) 
	WHERE ProductID IN (select i.ProductID  from inserted i)
END