USE dbase
GO

IF EXISTS
( 
  SELECT * 
  FROM sys.tables
  WHERE name = N'empl_sek'
)
DROP table empl_sek
GO

IF EXISTS
( 
  SELECT * 
  FROM sys.partition_schemes
  WHERE name = 'sch_sal'
)
DROP PARTITION SCHEME sch_sal
GO

IF EXISTS
( 
  SELECT * 
  FROM sys.partition_functions
  WHERE name = N'par_salary'
)
DROP PARTITION FUNCTION par_salary
GO



CREATE PARTITION FUNCTION par_salary(int)
AS RANGE
FOR VALUES(0, 20000)
GO

CREATE PARTITION SCHEME sch_sal
AS PARTITION par_salary
TO ([firstfg],[secfg],[thirdfg])
GO

CREATE TABLE empl_sek
(
	id int NOT NULL,
	salary int NOT NULL
)
ON sch_sal(salary)
GO

INSERT empl_sek(id,salary)
(
	SELECT id,salary
	FROM employers
)
GO

SELECT *, $Partition.par_salary(salary)
FROM empl_sek
ORDER BY id