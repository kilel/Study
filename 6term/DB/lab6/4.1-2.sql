USE AdventureWorks2008R2
GO

CREATE UNIQUE NONCLUSTERED INDEX IX_Contact_LastName_FirstName 
ON Person.Person 
(
	LastName,
	FirstName,
	BusinessEntityID --без него пишет, что неуникальны ключи в индексе
)
INCLUDE
(
	Title, 
	MiddleName,
	Suffix
	
)
WITH 
(
	FILLFACTOR = 65,
	SORT_IN_TEMPDB = OFF, 
	DROP_EXISTING = OFF,
	ONLINE = ON
) 
ON [PRIMARY]
GO
