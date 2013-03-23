USE AdventureWorks2008R2
GO

--������� ���������� � �������������� ��������, � ������� ���� ����������, 
--���������� ��������� �Sheduling Assistant�, � ��������� ���������� ����� 
--����������. ������������ ������� HumanResources.Department, 
--HumanResources.Employee, HumanResources.EmployeeDepartmentHistory. 
--��� �������� ������� ������ �������� ���� EndDate (NULL) � ������� 
--HumanResources.EmployeeDepartmentHistory
DECLARE @jb nvarchar(80) = 'Tool Designer'


SELECT d.* , COUNT(e.JobTitle) as '���������� � ��������'
FROM HumanResources.Department d 
	INNER JOIN HumanResources.EmployeeDepartmentHistory dh 
		ON dh.DepartmentID = d.DepartmentID
	INNER JOIN HumanResources.Employee e
		ON  e.BusinessEntityID = dh.BusinessEntityID
--WHERE e.JobTitle = @jb
GROUP BY d.DepartmentID, d.GroupName, d.ModifiedDate, d.Name 	

	



/*
SELECT *
FROM HumanResources.Department d 
WHERE d.DepartmentID IN
	(
		SELECT dh.DepartmentID
		FROM HumanResources.EmployeeDepartmentHistory dh 
			JOIN HumanResources.Employee e
				ON  e.BusinessEntityID = dh.BusinessEntityID
		WHERE e.JobTitle = 'Tool Designer'
	)
	*/