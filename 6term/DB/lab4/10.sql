USE AdventureWorks2008R2
GO

--������� �� ������� Sales.SalesOrderDetail ���������� � ���� � ����-��� ���� 
--��������� ���������, ��� ������� ���������� � ����� ������ ���-������ 10 ����. 
--��������� ������������� �� ������� ����

select ProductID, AVG(LineTotal/OrderQty) as '����'
from Sales.SalesOrderDetail
where OrderQty > 10
group by ProductID
order by AVG(LineTotal/OrderQty) 
GO