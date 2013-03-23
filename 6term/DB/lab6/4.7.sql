USE AdventureWorks2008R2
GO

SELECT DISTINCT i.name as 'index name',
t.name as 'table name',
--COUNT(ic.column_id) as 'columns'
ic.column_id,
co.name
FROM  sys.indexes i
	INNER JOIN sys.tables t
	ON t.object_id = i.object_id
	INNER JOIN sys.index_columns ic
	ON ic.index_id = i.index_id
	INNER JOIN sys.columns co
	ON co.object_id = t.object_id AND co.column_id = ic.column_id
--GROUP BY i.name, t.name