USE AdventureWorks2008R2
GO

--на реорганизацию  ALTER INDEX REORGANIZE
SELECT a.index_id, 
name, 
avg_fragmentation_in_percent
FROM sys.dm_db_index_physical_stats (DB_ID(N'AdventureWorks2008R2'),
	OBJECT_ID(N'Production.Product'), NULL, NULL, NULL) AS a
	JOIN sys.indexes AS b 
	ON	a.object_id = b.object_id AND 
		a.index_id = b.index_id
WHERE avg_fragmentation_in_percent > 5 AND avg_fragmentation_in_percent <= 30

--на перестройку   ALTER INDEX REBUILD WITH (ONLINE = ON)


ALTER INDEX
ALL ON Production.Product 
REBUILD WITH (ONLINE = ON) 
WHERE id IN 
(
SELECT a.index_id
FROM sys.dm_db_index_physical_stats (DB_ID(N'AdventureWorks2008R2'),
	OBJECT_ID(N'Production.Product'), NULL, NULL, NULL) AS a
	JOIN sys.indexes AS b 
	ON	a.object_id = b.object_id AND 
		a.index_id = b.index_id
WHERE avg_fragmentation_in_percent > 30 
)
