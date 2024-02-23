--lab11 : Innerjoin                   date : 2080/11/04
                                      --UTSHAV PAUDEL
create table tab1
(
NUMID numeric(5),
);

insert into tab1(NUMID)
values(12),
(14),
(10),
(11)

create table tab2
(
NUMID numeric(5),
);

insert into tab2(NUMID)
values(13),
(13),
(11),
(12);


-- perfroming inner join
select * from tab1 
inner join tab2
on tab1.NUMID = tab2.NUMID;