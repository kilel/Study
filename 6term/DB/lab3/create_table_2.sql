USE tempdb
GO
--
CREATE TABLE my_spes
(
	specID int NOT NULL IDENTITY(1,1) PRIMARY KEY,
	offerName nvarchar(50) NOT NULL,
	descr nvarchar(MAX) NOT NULL
)
GO
