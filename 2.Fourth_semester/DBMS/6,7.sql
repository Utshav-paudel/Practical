--Lab6  Alter and Truncate command Implementation                 date : 2080/10/18
                                                                 --utshav paudel

-- creating table
create table practical1(
roll_no int,
names varchar(20),
birth_date int);

--inserting values is not possible since email column is not available
insert into practical1
values(1,'Ayush',2060,'ayush@gmail.com'),
(2,'ram', 2059, 'ram@bhateygmail.com'),
(3,'utshav', 2060, 'utshav@gmail.com'),
(4,'hari', 2045, 'hari@gmail.com');


--email cannot be inserted so using alter table to add column 
alter table practical1
add email varchar(100);                 -- adding column email

--inserting is possible as alter create email column
insert into practical1
values(1,'Ayush',2060,'ayush@gmail.com'),
(2,'ram', 2059, 'ram@bhateygmail.com'),
(3,'utshav', 2060, 'utshav@gmail.com'),
(4,'hari', 2045, 'hari@gmail.com');

-- displaying result
select * from practical1;


--removing all values of table
truncate table practical1;

select * from practical1;


--lab7 data manipulation language                                 --utshav paudel

--CREATING Table 
create table customer(
CUST_NO numeric(4) primary key,
FNAME varchar(20),
LNAME varchar(20),
ADDR varchar(20),
CITY  varchar(10),
STATES varchar(10),
PIN varchar(10),
BIRTH_DATE date
);

-- insert
insert into customer
values(1,'ram', 'ghimire', 'baneshwor','kathmandu','bagmati','123456','02/02/1990'),
(2,'ranjit', 'basnet', 'baneshwor','kathmandu','bagmati','123456','2/4/1990'),
(3,'ramen', 'kunwar', 'baneshwor','kathmandu','bagmati','123456','2/5/1987'),
(4,'ramesh', 'ghimire', 'baneshwor','kathmandu','bagmati','123456','2/6/1923');



--deleting from table
delete from customer where CUST_NO=4;

--select
select * from customer; 

--updating values
update customer set FName='sita' where CUST_NO = 3;

--select
select * from customer;

insert into customer
values(6,'hari', 'gaire', 'charnumber','kapilvastu', 'lumbini','45434', '17-MARCH-18');
truncate table customer;

--selecting columns
select LNAME from customer;

--selecting matching condition
select * from customer
where STATES = 'lumbini' ;

-- selecting multiples column
select FNAME, LNAME from customer;


select * from customer order by BIRTH_DATE;