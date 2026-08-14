create table proj(
	dno char(3) CONSTRAINT C_FKDEPT references dept(dno),
	prj_no char(3) Not null CONSTRAINT C_PRJNO check(prj_no like('P%')),
	prj_name varchar(20) not null,
	prj_credit number(2) CONSTRAINT C_PCREDIT check(prj_credit > 0 AND prj_credit < 11),
	strt_date date Not null,
	end_date date,
	CONSTRAINT C_ENDATE check(end_date > strt_date));
	