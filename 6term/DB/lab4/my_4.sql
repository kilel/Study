USE tempdb
GO

--Составить несколько (не менее пяти) однотабличных запросов на вы-борку данных к БД 
--своего варианта, созданной на лабораторной работе № 3. 
--Запросы должны содержать:
-- просмотр таблицы целиком;
-- использование условий-ограничений (проверка на равенство/неравенство значений, 
--проверка на соответствие шаблону, использование арифметических и логических выражений);
-- сортировку выборки;
-- ограничение выборки;
-- функции для работы со строковыми, числовыми и временными значениями 
--(конкатенация, математические функции, функции для вычисления различных значений по дате и времени);

-- получение статистических и обобщающих данных из таблиц 
--(подсчёт числа значений в столбце, подсчёт количества по группам свойств, 
--использование агрегирующих функций, группировка по условию).


SELECT a.name as 'Работодатель',
b.fname + ' ' + b.sname as 'Работник',
a.work_type as 'Должность'
FROM employer a, worker b
where a.work_type = b.work_type AND a.vacancy > 0