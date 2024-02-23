--Lab5 : primary key and foreign key implementation                       Date : 2080/10/18
                                                                          --Utshav Paudel

--creating  table "STD_ADD"
create table STD_ADD
(
-- Roll_no is primary key
Roll_no numeric(4) primary key,
Names varchar(10),
Addr varchar(10),
Place varchar(15),
Pin varchar(4),
);

--creating  table "STD_Marks"
create table STD_MARKS(

--Roll_no is foreign key for this table
Roll_no numeric(4) References STD_ADD on delete cascade,
Subjects varchar(8),
Exam_date date,
Marks numeric(3));

drop table STD_MARKS;
drop table STD_ADD;                        --cannot drop std add because it is refrenced by a foreigh key constraint