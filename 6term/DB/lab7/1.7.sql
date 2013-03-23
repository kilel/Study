use dbase
GO

--1.7. Создать несколько триггеров для БД своего варианта. 
--Созданные триггеры должны представлять все типы DML-триггеров 
--(INSTEAD OF, AFTER для INSERT, UPDATE и DELETE).

CREATE TRIGGER check_can ON deals
INSTEAD OF INSERT
AS
BEGIN
	INSERT deals(empl,worker,salary,work_type)
	(
		SELECT 
		i.empl,
		i.worker,
		i.salary,
		i.work_type
		FROM inserted i INNER JOIN 
		workers w ON w.id = i.worker
		WHERE w.Found_work IS NULL
	)
END