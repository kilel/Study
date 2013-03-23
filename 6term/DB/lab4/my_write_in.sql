USE tempdb
GO
--INSERT employer(name, work_type, requ, adress, email, phone, salary, vacancy)
--values('Magement', 'super-manager', 'none', 'Poland', 'a@a.a','123', 50000, 1)
--GO

--UPDATE employer
--SET vacancy = 5
--WHERE work_type = 'aspirant'

--INSERT worker(fname, sname, qual, work_type, salary)
--values('Успешный', 'Человек', 'president', 'president', 0)
--GO

--INSERT deals(empl, worker, work_type, salary)
--values(4,5,'manager',2500)
--GO

select * from deals

--SELECT e.id, w.id, w.salary, e.salary, w.work_type
--FROM worker w, employer e
--where w.work_type = e.work_type AND e.salary >= w.salary
--GO