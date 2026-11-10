CREATE OR REPLACE TRIGGER check_salary
BEFORE UPDATE OF sal ON emp
FOR EACH ROW

BEGIN
    IF :NEW.sal < :OLD.sal THEN
        RAISE_APPLICATION_ERROR(
            -20001,
            'Error: Employee salary cannot be reduced.'
        );
    END IF;
END;
/