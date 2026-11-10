SET SERVEROUTPUT ON

DECLARE
	CURSOR c_emp IS SELECT e.empno, e.ename, d.dname FROM emp e JOIN dept d ON e.deptno = d.dno ORDER BY e.deptno; 
	v_empno emp.empno%TYPE;
	v_ename emp.ename%TYPE;
	v_dname dept.dname%TYPE;
BEGIN
	OPEN c_emp;
	LOOP
		FETCH c_emp INTO v_empno, v_ename, v_dname;
	EXIT WHEN c_emp%NOTFOUND;
		DBMS_OUTPUT.PUT_LINE(v_empno||'    '||v_ename||'   	 '||v_dname);
	END LOOP;
CLOSE c_emp;
END;
/