use AdventureWorks2008R2
GO

--1.3. ������� ������� INSERT (INSTEAD OF), ������� ����� ��������� ���-������ 
--����� ������ � ������� Sales.SalesOrderDetail ������ � ��� ������, ��-�� ����������
-- ����������� ������ (OrderQty) �� ����������� ���������� ����-�� 
--(������� Production.Product, ���� ReorderPoint).

CREATE TRIGGER allow_ins ON Sales.SalesOrderDetail 
INSTEAD OF INSERT
AS
BEGIN
	INSERT Sales.SalesOrderDetail(CarrierTrackingNumber,ModifiedDate,OrderQty,ProductID,SalesOrderDetailID,SalesOrderID,SpecialOfferID,UnitPrice,UnitPriceDiscount,rowguid)
	(select 
	i.CarrierTrackingNumber,
	i.ModifiedDate,
	i.OrderQty,
	i.ProductID,
	i.SalesOrderDetailID,
	i.SalesOrderID,
	i.SpecialOfferID,
	i.UnitPrice,
	i.UnitPriceDiscount,
	i.rowguid
	from inserted  i
		join Production.Product pr
		ON i.ProductID = pr.ProductID AND i.OrderQty <= pr.ReorderPoint
	)
	
END