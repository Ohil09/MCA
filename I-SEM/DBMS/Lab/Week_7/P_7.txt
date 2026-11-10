SET SERVEROUTPUT ON
DECLARE
	CURSOR c_emp(v_job emp.job%TYPE, v_deptno emp.deptno%TYPE)IS SELECT empno,ename,job,deptno,sal from emp where job = v_job AND deptno = v_deptno;

	
BEGIN

	
	FOR e IN c_emp('&Emp_job','&Dept_no')
	LOOP
		DBMS_OUTPUT.PUT_LINE('Employee Number : ' || e.empno);
		DBMS_OUTPUT.PUT_LINE('Employee Name : ' || e.ename);
		DBMS_OUTPUT.PUT_LINE('Employee Job : ' || e.job);
		DBMS_OUTPUT.PUT_LINE('Employee Dept no : ' || e.deptno);
		DBMS_OUTPUT.PUT_LINE('Employee Salary : ' || e.sal ||CHR(10));
	END LOOP;
END;
/
