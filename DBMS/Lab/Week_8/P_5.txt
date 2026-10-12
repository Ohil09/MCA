CREATE OR REPLACE TRIGGER fund_eligibility
BEFORE UPDATE OF prj_fund ON proj
FOR EACH ROW
DECLARE
    v_current_date DATE := TO_DATE('&current_date', 'DD-MM-YYYY');
    v_total_days   NUMBER;
    v_lapsed_days  NUMBER;
    v_add_fund     NUMBER;
    v_eligible     NUMBER;
BEGIN
    v_total_days := :OLD.end_date - :OLD.strt_date;
    v_lapsed_days := v_current_date - :OLD.strt_date;
    v_add_fund := :NEW.prj_fund - :OLD.prj_fund;

    IF v_lapsed_days < v_total_days * 0.50 THEN
        v_eligible := v_add_fund * 0.70;
    ELSE
        v_eligible := v_add_fund * 0.40;
    END IF;

    DBMS_OUTPUT.PUT_LINE(
        'You are eligible for Rs. ' || v_eligible
    );
END;
/