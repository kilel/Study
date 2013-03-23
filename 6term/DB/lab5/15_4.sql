USE tempdb
GO

--работодателей, к которым никто не устроился

SELECT *
FROM employer e
WHERE e.id NOT IN (select empl from deals)