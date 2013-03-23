﻿Задание 1. Создание триггеров.
1.1. Создать триггер DELETE (INSTEAD OF), который будет копировать сведения о кандидатах (таблица HumanResources.JobCandidate) в новую таб-лицу HumanResources.JobCandidateHistory (необходимо создать самостоя-тельно) в случае, если кто-либо удалит данные о них из таблицы HumanResources.JobCandidate. Необходимо также записывать в поле RejectedDate текущую дату с помощью функции GETDATE.
1.2. Создать триггер DELETE (INSTEAD OF) для таблицы Sales.SalesOrderHeader, который будет блокировать удаление записи при на-личии ссылающихся на неѐ строк из таблицы Sales.SalesOrderDetail.
1.3. Создать триггер INSERT (INSTEAD OF), который будет разрешать соз-давать новую строку в таблице Sales.SalesOrderDetail только в том случае, ес-ли количество заказанного товара (OrderQty) не превосходит складского запа-са (таблица Production.Product, поле ReorderPoint).
1.4. Создать триггер INSERT (AFTER), который будет уменьшать количест-во продукта на складе (таблица Production.Product, поле ReorderPoint) при создании новой строки в таблице Sales.SalesOrderDetail.
1.5. Создать необходимые триггеры UPDATE, которые будут разрешать из-менение данных в таблице Sales.SalesOrderDetail только в том случае, если но-вое запрошенное количество может быть предоставлено заказчику. При этом следует внести необходимые изменения в данные на складе.
1.6. Создать необходимые триггеры UPDATE, INSERT, DELETE, которые будут разрешать изменение данных в таблице Sales.SalesOrderDetail только в том случае, когда заказ находится в стадии выполнения (таблица Sales.SalesOrderHeader, поле Status=1).
1.7. Создать несколько триггеров для БД своего варианта. Созданные триг-геры должны представлять все типы DML-триггеров (INSTEAD OF, AFTER для INSERT, UPDATE и DELETE).
2. Создание хранимых процедур.
Задание 2. Создание хранимых процедур.
2.1. Создать хранимую процедуру, реализующую следующий запрос:
SELECT Name, ProductNumber, DaysToManufacture
FROM Production.Product
WHERE DaysToManufacture >= 1
ORDER BY DaysToManufacture DESC, Name
Выполнить созданную процедуру.
2.2. Изменить хранимую процедуру (задание 2.1) таким образом, чтобы она принимала в качестве параметра количество дней, требуемых для производства продукции (поле DaysToManufacture). В теле процедуры установить проверку на корректность значения параметра.
2.3. Создать хранимую процедуру GetDiscounts в схеме Sales, которая из-влекает следующие столбцы из таблицы Sales.SpecialOffer: Description, Dis-countPct, Type, Category, StartDate, EndDate, MinQty и MaxQty. Процедура должна возвращать все строки, отсортированные по параметрам StartDate и EndDate.
2.4. Создать хранимую процедуру GetDiscountsForCategory в схеме Sales, которая принимает входной параметр @Category, имеющий тип данных nvarchar и принимающий до 50 символов. Эта процедура должна извлекать те же столбцы, что и для GetDiscounts, но должна фильтровать строки на основе параметра @Category.
2.5. Создать хранимую процедуру GetDiscountsForCategoryAndDate в схе-ме Sales, которая принимает параметр @Category, как и GetDiscountsForCategory, но включает дополнительный входной параметр @DateToCheck datetime. Параметр @DateToCheck должен иметь возмож-ность принимать стандартное значение NULL. Если значение NULL указано для параметра @DateToCheck, задать для этого параметра значение текущих даты и времени, используя функцию GETDATE. Эта процедура должна извле-кать те же столбцы, что и для GetDiscounts, но должна фильтровать строки на основе параметров @Category и @DateToCheck.
2.6. Создать хранимую процедуру, реализующую получение сведений (на-звание, цена) о продукте, продаваемом в указанный пользователем период (по-ля SellStartDate и SellEndDate). В теле процедуры предусмотреть проверку на корректность значений параметров.
2.7. Создать процедуру AddDiscount в схеме Sales, которая вставляет новые записи в таблицу Sales.SpecialOffer. Инструкция INSERT должна быть защи-щена соответствующей обработкой ошибок, и любые ошибки должны быть за-писаны в таблицу dbo.ErrorLog. Если новая вставка завершится успешно, па-раметр @NewProductID должен быть обновлен на значение функции
89
SCOPE_IDENTITY. Возвращаемое значение должно также указывать успех или неудачу вставки.
2.8. Создать хранимую процедуру (набор хранимых процедур), реализую-щую создание нового заказа на продажу. Количество заказанных позиций (раз-личных продуктов) не превышает пяти. Хранимая процедуры (процедуры) должна создавать новую запись в таблице Sales.SalesOrderHeader и необходи-мое количество новых строк в таблице Sales.SalesOrderDetail.
2.9. Создать несколько хранимых процедур для БД своего варианта.