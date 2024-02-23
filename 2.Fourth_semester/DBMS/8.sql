

-------------------------------------------------------------------------------------------

--lab8 : SELECT USING CONDITION AND ORDER                                                    --Utshav Paudel
create table CUSTOMERIO
(CUST_NO numeric(4) primary key,
LNAME  varchar(10),
FNAME varchar(15),
ADDR varchar(20),
CITY varchar(20),
STATES varchar(10),
PIN  varchar(3),
BIRTH_DATE date,
);

select * from CUSTOMERIO;

insert into CUSTOMERIO
values(0001,'paudel','ram','baneshwor','ktm','bagmati','342','2060/10/10'),
(0002,'paudel','sam','baneshwor','ktm','bagmati','342','2050/10/10'),
(34,'paudel','ram','baneshwor','ktm','gandaki','342','2060/12/10'),
(0041,'paudel','hari','baneshwor','ktm','karnali','342','2065/10/10'),
(00051,'paudel','sandeep','baneshwor','ktm','lumbini','342','2060/10/10')

--conditional statement
select * from CUSTOMERIO
where STATES = 'bagmati';


--order by
select * from CUSTOMERIO
order by FNAME;

--DESCENDING ORDER 
select * from CUSTOMERIO
order by FNAME desc;

-- ASCENDING ORDER 
select * from CUSTOMERIO
order by FNAME asc;

--sort by lname
select * from CUSTOMERIO
order by FNAME, LNAME ;