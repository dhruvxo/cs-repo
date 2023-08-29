create database dhruv;
show databases;
use dhruv;

create table dhruvfac (
sid integer NOT NULL,
sname varchar(10) NOT NULL,
sage integer DEFAULT 20,
fac_ad integer,
PRIMARY KEY (sid),
FOREIGN KEY(fac_ad) REFERENCES public.faculty(fid)
);