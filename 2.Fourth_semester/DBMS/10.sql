--labno : 10  INNER JOIN                          date : 2080/11/02
                                                   -- Utshav paudel
create table player
(
    ROLLNO numeric(5) primary key,
    NAMES varchar(10)
);

--inserting values
insert into player(ROLLNO, NAMES)
values(10,'Nischal'),
(20,'Aayush'),
(30,'Sudip'),
(40,'Utshav');

create table matches
(
    MATCHNO numeric(5),
    ROLLNO  numeric(5) REFERENCES player,
    MATCH_DATE DATE,
    OPPONENT varchar(10)
);

insert into matches(MATCHNO,ROLLNO,MATCH_DATE,OPPONENT)
values(1,20,'10-JAN-2009','RAJIV'),
(2,30,'10-FEB-2009','RAHUL'),
(3,20,'12-FEB-2009','RAJAT'),
(4,20,'10-JAN-2009', 'MAYUR');


--INNER JOIN
SELECT player.ROLLNO, NAMES, MATCH_DATE, OPPONENT
FROM player , matches
where player.ROLLNO = matches.ROLLNO;

