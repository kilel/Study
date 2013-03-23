USE AdventureWorks2008R2
GO
--������� �� ������� Sales.SalesOrderDetail ���������� � ������� ��-�������� 
--������������� ��������� (OrderQty) � ��������� ������� (OrderQty * UnitPrice). 
--��������� ������������� �� ��������� � ������� � ������� �����-���

select UnitPrice,
AVG(OrderQty) as '������� ����������',
AVG(OrderQty)*UnitPrice as '�� �����'
from Sales.SalesOrderDetail
group by UnitPrice
order by UnitPrice
GO