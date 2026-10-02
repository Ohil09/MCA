SET SERVEROUTPUT ON

DECLARE

    CURSOR c_proj IS SELECT dno, prj_no, prj_name FROM proj ORDER BY prj_no;

BEGIN

    FOR p IN c_proj
    LOOP

        DBMS_OUTPUT.PUT_LINE('Project: ' || p.prj_no ||' - ' || p.prj_name);

        FOR t IN (
            SELECT task_id, task_name, status FROM task WHERE dno = p.dno AND prj_id = p.prj_no ORDER BY task_id)
        LOOP

            DBMS_OUTPUT.PUT_LINE('   Task ' || t.task_id ||': ' || t.task_name ||' [' || t.status || ']');
            

        END LOOP;

    END LOOP;

END;
/