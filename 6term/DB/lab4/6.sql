USE AdventureWorks2008R2
GO
--Вычислить средние цены и объёмы продаж из таблицы Sales.SalesOrderDetail, 
--сгруппированные по коду продукта (ProductID) 
--и идентификатору специального предложения (SpecialOfferID).

select ProductID, SpecialOfferID,
AVG(LineTotal) as 'среднее',
SUM(LineTotal) as 'итого'
from Sales.SalesOrderDetail
group by ProductID, SpecialOfferID
GO