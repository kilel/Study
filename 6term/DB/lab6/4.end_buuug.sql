USE AdventureWorks2008R2
GO

IF EXISTS (SELECT * from sys.procedures where name = 'reb_index')
DROP PROCEDURE reb_index
GO

CREATE PROCEDURE reb_index @obj_name nvarchar(60)
AS
BEGIN

CREATE TABLE tmp_ind
(
	id int IDENTITY,
	name nvarchar(100)
)
INSERT tmp_ind(name)
(SELECT name
FROM sys.dm_db_index_physical_stats (DB_ID(N'AdventureWorks2008R2'),
	OBJECT_ID(@obj_name), NULL, NULL, NULL) AS a
	JOIN sys.indexes AS b 
	ON	a.object_id = b.object_id AND 
		a.index_id = b.index_id
WHERE avg_fragmentation_in_percent > 30 
)
DECLARE @cnt int = 0
DECLARE @max_cnt int = (SELECT MAX(id) FROM tmp_ind)
DECLARE @thisname nvarchar(100)
WHILE @cnt < @max_cnt
BEGIN
SET @cnt = @cnt + 1
SET @thisname = (SELECT name FROM tmp_ind where id = @cnt)
ALTER INDEX @thisname ON @objname REBUILD WITH (ONLINE = ON)

END




DROP TABLE tmp_ind
END
