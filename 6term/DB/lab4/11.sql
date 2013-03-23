USE AdventureWorks2008R2
GO

--������� �� ������� Sales.SalesOrderDetail ���������� � ���� ������-��� ���������, 
--��� ������� ������� ���������� � ������� ��������� 5 ����. 
--��������� ������������� �� ���� ���������.

select distinct ProductID 
from Sales.SalesOrderDetail s
where 5 < (select avg(OrderQty)
		from Sales.SalesOrderDetail ss
		where ss.ProductID = s.ProductID)
	 
order by ProductID
GO