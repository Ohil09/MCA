SET SERVEROUTPUT ON

DECLARE

    CURSOR c_proj IS SELECT dno, prj_no, prj_fund, prj_credit FROM proj WHERE prj_fund IS NOT NULL;

CURSOR c_emp(p_dno emp.deptno%TYPE, p_prj_id emp.proj_id%TYPE) IS SELECT empno, ename FROM emp WHERE deptno = p_dno AND proj_id = p_prj_id;

    v_amt        NUMBER(12,2);
    v_per        NUMBER(12,2);
    v_emp_share  NUMBER(12,2);
    v_emp_count  NUMBER;

BEGIN

    FOR p IN c_proj
    LOOP
	
	IF p.prj_credit = 1 THEN 
		v_per := 0.10;
	ELSIF p.prj_credit = 2 THEN
		v_per := 0.20;
	ELSIF p.prj_credit = 3 THEN 
		v_per := 0.30;
	ELSE
		v_per := 0.40;
	END IF;
        v_amt := p.prj_fund * v_per;


        SELECT COUNT(*) INTO v_emp_count FROM emp WHERE deptno = p.dno AND proj_id = p.prj_no;

        IF v_emp_count > 0 THEN
            v_emp_share := (v_amt * 0.70 ) / v_emp_count;

            FOR e IN c_emp(p.dno, p.prj_no)
            LOOP
                DBMS_OUTPUT.PUT_LINE(CHR(10)||
                    'Employee : ' || e.ename ||
                    ' | Incentive : ' || v_emp_share
                );
            END LOOP;

        END IF;


        UPDATE dept SET dept_budget = NVL(dept_budget, 0)+ (v_amt * 0.30 ) WHERE dno = p.dno;

        DBMS_OUTPUT.PUT_LINE('Project: ' || p.prj_no ||' | Department: ' || p.dno ||' | Total Allocation: ' || v_amt);
	DBMS_OUTPUT.PUT_LINE('-----------------------------------------------------------------------------------------------------');

    END LOOP;

    COMMIT;

END;
/