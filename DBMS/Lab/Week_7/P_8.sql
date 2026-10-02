SET SERVEROUTPUT ON
DECLARE
	CURSOR c_emp(v_prj_id emp.proj_id%TYPE)IS SELECT ename, sal, dname FROM (SELECT e.ename,e.sal,d.dname from emp e JOIN dept d ON e.deptno = d.dno where e.proj_id = v_prj_id ORDER BY e.sal DESC)WHERE ROWNUM <= 2;
	/*
	CURSOR c_emp(v_prj_id emp.proj_id%TYPE) IS
        SELECT e.ename, e.sal, d.dname
        FROM emp e
        JOIN dept d
        ON e.deptno = d.dno
        WHERE e.proj_id = v_prj_id
        ORDER BY e.sal DESC
        FETCH FIRST 2 ROWS ONLY;
	*/
BEGIN
	FOR e IN c_emp('&Proj_id')
	LOOP
		DBMS_OUTPUT.PUT_LINE('Employee Name : ' || e.ename);
		DBMS_OUTPUT.PUT_LINE('Employee Salary : ' || e.sal);
		DBMS_OUTPUT.PUT_LINE('Employee Department : ' || e.dname ||CHR(10));
	END LOOP;
END;
/
