--lab 3 and 4 date : 2080/10/11


-- lab3: create a employee table                                  --Utshav Paudel
create table tbl_employee(
[FirstName] VARCHAR(32),
[MiddleName] VARCHAR(32),
[LastName] VARCHAR(32),
[Age] INT,);

-- Inserting values into employee table
insert into tbl_employee(FirstName, LastName, Age)

values
('ramesh', 'basnet', 34),
('Nischal','kunwar',20),
('ayush', 'basnet', 22);

select * from tbl_employee;



--lab4 primary key defination                                                 -- utshav paudel

--creating table with primary key i.e ID

create table tbl_employee1
(
[Id] INT primary key,
[FirsName] varchar(32) not null,
[MiddleName] varchar(32),
[LastName] varchar(32) not null,
[Age] int not null,

) 

insert into tbl_employee1(Id,FirsName,LastName,Age)
values
(1,'Utshav','Paudel',20),
(2,'Ramesh', 'Basnet',23);


--violation of primary key 
insert into tbl_employee1
values(1,'ram','prasad','lamichane',45);

--resolving violation
insert into tbl_employee1
values(3,'ram','prasad','lamichane',45);

select *  from tbl_employee1;
