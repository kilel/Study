USE AdventureWorks2008R2
GO
--1.1. ������� ������� DELETE (INSTEAD OF), ������� ����� ���������� �������� � 
--���������� (������� HumanResources.JobCandidate) � ����� ���-���� 
--HumanResources.JobCandidateHistory (���������� ������� ��������-������) � ������, 
--���� ���-���� ������ ������ � ��� �� ������� HumanResources.JobCandidate. 
--���������� ����� ���������� � ���� RejectedDate ������� ���� � ������� ������� GETDATE.
IF NOT exists (select * from sys.tables where name = 'JobCandidateHistory')
CREATE TABLE HumanResources.JobCandidateHistory 
(
	JobCandidateID int NOT NULL,
	BusinesEntityID int ,
	Resume XML,
	ModifiedDate datetime NOT NULL
)
IF EXISTS (select * from sys.triggers where name = 'del_cand')
DROP TRIGGER del_cand
GO 

CREATE TRIGGER del_cand ON HumanResources.JobCandidate 
INSTEAD OF DELETE
AS
BEGIN
	if EXISTS (SELECT * FROM deleted)
	BEGIN
	INSERT   JobCandidateHistory (JobCandidateID, BusinesEntityID, Resume, ModifiedDate)
	(SELECT JobCandidateID, BusinessEntityID, Resume, GETDATE() FROM deleted)
	
	END
END