USE AdventureWorks2008R2
GO

--4.4. Создать первичный индекс для xml-столбца, используя следующие на-стройки:
-- имя таблицы: Production.Illustration;
-- имя столбца: Diagram;
-- имя индекса: PXML_Illustration_Diagram;
-- тип индекса: кластеризованный, неуникальный;
-- коэффициент заполнения: 60% для конечных и неконечных узлов

CREATE PRIMARY XML INDEX PXML_Illustration_Diagram
ON Production.Illustration(Diagram)
WITH
(
	FILLFACTOR = 60	
)