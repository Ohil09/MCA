create table emp(
	empno number(3) primary key,
	ename varchar(15) Not null,
	job varchar(15) CONSTRAINT C_JOBCHK check(job IN('MGR','A.MGR','CLK','DEV','ENG','CEO','GM')),
 	mgrid number(3)CONSTRAINT C_FK_MGRID references emp,
	date_birth date,
	sal number(10,2) CONSTRAINT C_SALCHK check(sal > 20000),
	comm number(10,2) DEFAULT(1000),
	deptno char(3) references dept(dno) ON DELETE CASCADE,
	date_join date,
	CONSTRAINT C_DB check(date_birth < date_join),
	CONSTRAINT C_DJ check(date_join > date_birth));
	