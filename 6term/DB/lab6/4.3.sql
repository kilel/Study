USE AdventureWorks2008R2
GO

CREATE UNIQUE NONCLUSTERED INDEX IX_Production_Product 
ON Production.Product 
(
	ProductNumber, 
	Color, 
	ReorderPoint, 
	SafetyStockLevel
)
INCLUDE
(
	DaysToManufacture
)
WITH 
(
	FILLFACTOR = 90,
	SORT_IN_TEMPDB = OFF, 
	DROP_EXISTING = OFF,
	ALLOW_ROW_LOCKS = ON,
	ALLOW_PAGE_LOCKS = OFF
) 
ON [PRIMARY]
GO
