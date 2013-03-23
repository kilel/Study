USE dbase
GO

CREATE TABLE employers
(
	id int NOT NULL IDENTITY (1, 1) PRIMARY KEY ,
	name nvarchar(100) NOT NULL,
	work_type nvarchar(200) NOT NULL,
	requ nvarchar(MAX) ,	--требования
	adress nvarchar(MAX),
	email nvarchar(100) not null,
	phone nvarchar(20), 
	vacancy int default 1 not null,
	salary int not null
)

CREATE TABLE workers
(
	id int NOT NULL IDENTITY (1, 1) PRIMARY KEY ,
	
	fname nvarchar(100) NOT NULL,	--имя
	sname nvarchar(100) NOT NULL,	--фамилия
	tname nvarchar(100),			--отчество
	qual nvarchar(100) NOT NULL,
	work_type nvarchar(200) NOT NULL,
	add_info nvarchar(MAX),
	Found_work datetime,
	salary int default 0	
)

create table deals
(
	id int NOT NULL IDENTITY (1, 1) PRIMARY KEY ,
	
	empl int NOT NULL FOREIGN KEY references employers(id),
	worker int NOT NULL FOREIGN KEY references workers(id),
	work_type nvarchar(200) NOT NULL,	
	salary int NOT NULL
	
)
GO