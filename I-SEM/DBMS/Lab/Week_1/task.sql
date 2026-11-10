create table task(
	prj_id char(3),
	dno char(3),
	task_id number(3),
	task_name varchar(30) Not null,
	s_date date Not null,
	e_date date,
	status varchar(12),
	CONSTRAINT C_TEDATE check(e_date > s_date));