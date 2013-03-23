USE AdventureWorks2008R2
GO

--4.5. Создать вторичный индекс для столбца , используя следующие на-стройки:
-- имя индекса: XMLPATH_Illustration_Diagram;
-- тип индекса: некластеризованный, неуникальный;
-- коэффициент заполнения: 70% для конечных и неконечных узлов.

CREATE XML INDEX XMLPATH_Illustration_Diagram
ON Production.Illustration(Diagram)
USING XML INDEX PXML_Illustration_Diagram 
FOR VALUE