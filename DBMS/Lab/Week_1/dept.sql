create table dept(
	dno char(3) CONSTRAINT C_DNO_UQ Unique CONSTRAINT C_D_UQ check(dno like ('D%')),
	dname varchar(15) Not null CONSTRAINT C_DNAME_UQ Unique,
	location char(3) CONSTRAINT C_LOC check(location IN('MUB','HYD','BNG','MNG','CHN')));
