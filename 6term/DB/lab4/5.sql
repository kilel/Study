USE AdventureWorks2008R2
GO

--����� ����� ����� ������ (LineTotal) ��� ������� ������ 
--�� ������� Sales.SalesOrderDetail. 
--��������� ������������� �� ���� ������ (SalesOrderID).

select sum(LineTotal) as '����� ������'
from Sales.SalesOrderDetail
GO