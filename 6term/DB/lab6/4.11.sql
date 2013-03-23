USE dbase 
GO
 
 CREATE NONCLUSTERED INDEX my_trye_ind
 ON employers 
 (
	salary
 )