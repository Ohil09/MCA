CREATE OR REPLACE TRIGGER prevent_salary_decrease
BEFORE UPDATE OF sal ON emp
FOR EACH ROW
BEGIN
    IF :NEW.sal < :OLD.sal THEN
        RAISE_APPLICATION_ERROR(-20001, 'Salary cannot be decreased');
    END IF;
END;
/