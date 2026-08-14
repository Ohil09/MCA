create table dependent(
	depid number(2) primary key,
	empno number(3) references emp,
	dependent_name varchar(20) Not null,
	gender char(1) check(gender IN('M','F')),
	dobirth date Not null,
	relationship varchar(15) CONSTRAINT C_CHKREL check (relationship IN('SPOUSE','CHILD','PARENT')),
	nom_pct number(5,2) CONSTRAINT C_CHKNPCT check(nom_pct BETWEEN 0 AND 100),
	med_cover varchar(3) DEFAULT('NO') check(med_cover IN('YES','NO')) );
	
	