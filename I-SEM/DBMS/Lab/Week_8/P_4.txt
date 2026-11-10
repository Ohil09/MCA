CREATE OR REPLACE TRIGGER trg_sal_mod
AFTER UPDATE OF sal ON emp
FOR EACH ROW
DECLARE
    v_dname dept.dname%TYPE;
BEGIN
    SELECT dname INTO v_dname FROM dept WHERE dno = :OLD.deptno;

    INSERT INTO sal_mod
        (empno, dname, old_sal, mod_date, modifier)
    VALUES
        (:OLD.empno,v_dname,:OLD.sal,SYSDATE,USER);
END;
/


/*

CREATE TABLE sal_mod (
    empno     NUMBER,
    dname     VARCHAR2(20),
    old_sal   NUMBER,
    mod_date  DATE,
    modifier  VARCHAR2(30)
);

*/