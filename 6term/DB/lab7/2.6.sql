use AdventureWorks2008R2
GO

--2.6. Создать хранимую процедуру, реализующую получение сведений 
--(на-звание, цена) о продукте, продаваемом в указанный пользователем период 
--(по-ля SellStartDate и SellEndDate). В теле процедуры предусмотреть проверку 
--на корректность значений параметров.

CREATE PROC lab6_proc @stda datetime = NULL, @enda datetime = NULL
AS
BEGIN
	SELECT Name, ListPrice
	FROM Production.Product p
	WHERE  (@stda IS NULL OR  p.SellStartDate > @stda ) AND  (@enda IS NULL OR  p.SellEndDate > @enda ) 
END
