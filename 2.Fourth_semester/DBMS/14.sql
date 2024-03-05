--lab13 --view example date--2080/11/10          --utshav paudel

create table MyDepartment(
Id numeric(5),
Dept_Name varchar(20));
Insert into MyDepartment(Id,Dept_Name)
values(1,'Accounts'),
(2,'HR'),
(3,'Adminstration'),
(4,'Councelling');


select * from MyDepartment;


create table MyEmployees
(
Emp_Id numeric(10),
Emp_Name varchar(40),
Gender varchar(10),
Salary numeric(10),
City varchar(20),
Dept_Id numeric(5),);

insert into MyEmployees(Emp_Id,Emp_Name,Gender,Salary,City,Dept_Id)
values(100, 'Ramesh','male',25000,'Hyderabad',2 ),
(101, 'Ana', 'male', 35000, 'karachi',1),
(102, 'Anu', 'Female', 65000, 'ktm',3),
(103, 'Anil', 'male', 67000, 'chitlang',4),
(104, 'Anish', 'male', 45000, 'pokhara',3),
(105, 'Shyam', 'male', 25000, 'birgunj',2);

create view VW_ForEmployess
as
select * from MyEmployees as A
inner join MyDepartment as B
on B.Id = A.Dept_Id;

select * from VW_ForEmployess;

--droping views
drop view VW_ForEmployess;


--now if we want to remove Id and replace it with Dept_ID


create view VW_ForEmployess1
as
Select A.* , B.Dept_Name from MyEmployees as A
inner join MyDepartment as B
on B.Id = A.Dept_Id;
select * from VW_ForEmployess1;


--column level security : Hide column of salary
Create view VW_ForEmployess2
as 
select A.Emp_Id,A.Emp_Name,A.Gender,A.City,A.Dept_Id, B.Dept_Name
from MyEmployees as A
inner join MyDepartment as B
on B.Id = A.Dept_Id;

select * from VW_ForEmployess2;

--row level security : Hiderow 
Create view VW_ForEmployess3
as
select A.*, B.Dept_Name
from MyEmployees as A
inner join MyDepartment as B
on B.Id = A.Dept_Id
where Dept_Name = 'HR';

select * from VW_ForEmployess3;