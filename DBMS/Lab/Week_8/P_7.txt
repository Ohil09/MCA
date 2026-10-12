/*CREATE TABLE DEPENDENT_LOG (
    DEPID NUMBER,
    EMPNO NUMBER,
    DEPENDENT_NAME VARCHAR2(30),
    DELETED_DATE DATE
);

*/

CREATE OR REPLACE TRIGGER log_removed_dependents
AFTER DELETE ON dependent
FOR EACH ROW
BEGIN
    INSERT INTO dependent_log
    VALUES (
        :OLD.depid,
        :OLD.empno,
        :OLD.dependent_name,
        SYSDATE
    );
END;
/