use AdventureWorks2008R2
GO
--1.2. ������� ������� DELETE (INSTEAD OF) ��� ������� Sales.SalesOrderHeader, 
--������� ����� ����������� �������� ������ ��� ��-����� ����������� �� �� ����� 
--�� ������� Sales.SalesOrderDetail.

Create TRIGGER check_linked ON Sales.SalesOrderHeader
INSTEAD OF DELETE
AS
BEGIN
	DELETE Sales.SalesOrderHeader
	WHERE SalesOrderID IN 
	(
	select SalesOrderID 
	from deleted
	EXCEPT
	select so.SalesOrderID 
	from Sales.SalesOrderDetail so INNER JOIN deleted de
	ON  so.SalesOrderID=de.SalesOrderID
	)
END