CREATE DATABASE SHOOT_MY
ON (NAME = N'dbase', FIlENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL10_50.MSSQLSERVER\MSSQL\DATA\SHOOTMY.ss'),
(NAME = N'fir', FIlENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL10_50.MSSQLSERVER\MSSQL\DATA\s1.ss'), 
(NAME = N'sec', FIlENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL10_50.MSSQLSERVER\MSSQL\DATA\s2.ss'), 
(NAME = N'th', FIlENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL10_50.MSSQLSERVER\MSSQL\DATA\s3.ss') 
AS SNAPSHOT OF dbase
GO