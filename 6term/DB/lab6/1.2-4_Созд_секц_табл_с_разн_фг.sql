USE dbase
GO

IF EXISTS
( 
  SELECT * 
  FROM sys.tables
  WHERE name = N'retar2'
)
DROP table retar2
GO

IF EXISTS
( 
  SELECT * 
  FROM sys.partition_schemes
  WHERE name = 'sch2'
)
DROP PARTITION SCHEME sch2
GO

IF EXISTS
( 
  SELECT * 
  FROM sys.partition_functions
  WHERE name = N'par1'
)
DROP PARTITION FUNCTION par1
GO



CREATE PARTITION FUNCTION par1(datetime)
AS RANGE
FOR VALUES('20020101','20030101','20040101','20050101', '20060101','20070101','20080101')
GO

CREATE PARTITION SCHEME sch2
AS PARTITION par1
TO ([firstfg], [firstfg], [firstfg], [firstfg], [firstfg], [firstfg], [secfg], [thirdfg])
GO

CREATE TABLE retar2
(
	ReturnID int IDENTITY NOT NULL,
	ProductID int NOT NULL,
	CustomerID int NOT NULL,
	ReturnDate datetime NOT NULL
)
ON sch2(ReturnDate)
GO

INSERT retar2(ProductID, CustomerID, ReturnDate)
(
	SELECT d.ProductID, h.CustomerID, h.OrderDate
	FROM AdventureWorks2008R2.Sales.SalesOrderDetail d, AdventureWorks2008R2.Sales.SalesOrderHeader h
	WHERE h.SalesOrderID = d.SalesOrderID
)
GO

SELECT *, $Partition.par1(ReturnDate)
FROM retar2
ORDER BY ReturnID