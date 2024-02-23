--LAB9 Altering Table and adding primary key  : DATE : 2080/10/25
                                              --utshav paudel
create table SUPPLIER1
(ID numeric(3),
FNAME varchar(20),
S_CODE numeric(4),
DEPOSIT numeric(6)
);



--adding new column
alter table SUPPLIER1
add L_NAME varchar(20), CITY varchar(5);

--adding primary key
alter table SUPPLIER1
add IDI integer primary key;

Select * from SUPPLIER1;