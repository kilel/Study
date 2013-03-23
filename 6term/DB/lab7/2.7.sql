use dbase
GO

--2.7 написать хранимую процедуру для своей бд

CREATE PROC lala1 @sal int = 0, @wt nvarchar(100) = NULL
AS 
BEGIN
SELECT * from employers
WHERE salary > @sal AND (@wt IS NULL OR @wt = work_type)
END