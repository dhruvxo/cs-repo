create user u1 @localhost;

create database demo_db;
use demo_db;
create table sample(id numeric(2),name char(10), age numeric(2));
drop table sample;
desc sample;

SET autocommit = 0;

insert into sample values(1,'Dhruv',19);
insert into sample values(2,'Ares',43);
insert into sample values(3,'Bose',21);
insert into sample values(4,'Cara',23);
select * from sample;

grant all privileges on sample to u1;

savepoint s1;
start transaction;