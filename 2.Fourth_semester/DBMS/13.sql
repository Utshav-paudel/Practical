-- lab12 : Primary key and foreign key  with constraints                                Date : 2080/11/04
																						--UTSHAV PAUDEL
create table customers(
ID int not null,
Name varchar(40),
Email varchar(40),
Payment varchar(40),
primary key(ID),                        --- primary key
);

create table orders(
ID int not null,
OrderDescription varchar(40),
OrderDate varchar(40),
Price int,
primary key(ID),
Customer_ID int references customers(ID),               --- foreign key
);



insert into customers values(1,'Bilal','bilal@gmail.com','cash');
insert into orders values(1,'LG Monitor','22/5/2018',2000,1);

select * from customers
select * from orders

