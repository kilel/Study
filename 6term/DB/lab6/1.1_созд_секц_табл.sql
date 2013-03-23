USE dbase
GO

IF EXISTS
( 
  SELECT * 
  FROM sys.tables
  WHERE name = N'retar'
)
DROP table retar
GO

IF EXISTS
( 
  SELECT * 
  FROM sys.partition_schemes
  WHERE name = 'sch1'
)
DROP PARTITION SCHEME sch1
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

CREATE PARTITION SCHEME sch1
AS PARTITION par1
ALL TO ([PRIMARY])
GO

CREATE TABLE retar
(
	ReturnID int IDENTITY NOT NULL,
	ProductID int NOT NULL,
	CustomerID int NOT NULL,
	ReturnDate datetime NOT NULL
)
ON sch1(ReturnDate)
GO

INSERT retar(ProductID, CustomerID, ReturnDate)
(
	SELECT d.ProductID, h.CustomerID, h.OrderDate
	FROM AdventureWorks2008R2.Sales.SalesOrderDetail d, AdventureWorks2008R2.Sales.SalesOrderHeader h
	WHERE h.SalesOrderID = d.SalesOrderID
)
GO

SELECT *, $Partition.par1(ReturnDate)
FROM retar
ORDER BY ReturnID