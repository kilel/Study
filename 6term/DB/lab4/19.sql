USE AdventureWorks2008R2
GO
--������� �� ������� Person.Person ������ �����������, ��� ������� ���������� 
--�� �G� � ���� XML-���������. ��� �������� XML-��������� 
--��-���������� ��������� AUTO, TYPE, XMLSCHEMA, ELEMENTS XSINIL
select *
from Person.Person
where LastName like 'G%'
for xml auto, xmlschema, elements xsinil, TYPE
GO