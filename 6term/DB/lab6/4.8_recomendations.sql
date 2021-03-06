use [AdventureWorks2008R2]
go

CREATE NONCLUSTERED INDEX [_dta_index_SalesOrderDetail_5_898102240__K5_4_7_8] ON [Sales].[SalesOrderDetail] 
(
	[ProductID] ASC
)
INCLUDE ( [OrderQty],
[UnitPrice],
[UnitPriceDiscount]) WITH (SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF) ON [PRIMARY]
go

CREATE STATISTICS [_dta_stat_1717581157_15_16] ON [Production].[Product]([DaysToManufacture], [ProductLine])
go

CREATE STATISTICS [_dta_stat_1717581157_1_2] ON [Production].[Product]([ProductID], [Name])
go

CREATE STATISTICS [_dta_stat_1717581157_2_16_15] ON [Production].[Product]([Name], [ProductLine], [DaysToManufacture])
go

