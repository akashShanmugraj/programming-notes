-- Sample Code:
DECLARE
    CURSOR samplecursor IS SELECT empname FROM employee;
    currentempname employee.empname%TYPE;
BEGIN
    OPEN samplecursor;
    
    LOOP
        FETCH samplecursor INTO currentempname;
        EXIT when samplecursor%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Hello, ' || currentempname ||'! Welcome to the team!');
    END LOOP;
END;
/

-- 1

DECLARE 
    CURSOR emprankcursor IS SELECT employee.empname, employee.empno, employeesalary.grosssalary FROM employee, employeesalary WHERE employee.empno = employeesalary.empno ORDER BY employeesalary.grosssalary DESC;
    currentempno employee.empno%TYPE;
    currentempname employee.empname%TYPE;
    currentgrosssalary employeesalary.grosssalary%TYPE;
    rankcounter NUMBER;
BEGIN
    OPEN emprankcursor;
    rankcounter := 1;
    LOOP
        FETCH emprankcursor INTO currentempname, currentempno, currentgrosssalary;
        EXIT WHEN emprankcursor%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Rank #' || rankcounter || ' - ' || 'EMPNO ' || currentempno || ' EMPNAME ' || currentempname || ' GSALARY ' || currentgrosssalary);
        rankcounter := rankcounter + 1;
    END LOOP;
END;


-- 2

DECLARE 
    CURSOR updatesalarycursor IS SELECT empno, basicsalary FROM employeesalary;
    currentemployeenumber employeesalary.empno%TYPE;
    currentbasicsalary employeesalary.basicsalary%TYPE;
    averagesalary employeesalary.basicsalary%TYPE;
BEGIN
    
    SELECT AVG(basicsalary) INTO averagesalary FROM employeesalary;
    
    OPEN updatesalarycursor;
    
    LOOP
        FETCH updatesalarycursor INTO currentemployeenumber, currentbasicsalary;
        EXIT WHEN updatesalarycursor%NOTFOUND;
        IF currentbasicsalary < averagesalary THEN
            DBMS_OUTPUT.PUT_LINE('Update basicsalary from ' || currentbasicsalary || ' to ' || averagesalary || ' for ' || currentemployeenumber);
            UPDATE employeesalary SET basicsalary = averagesalary WHERE empno = currentemployeenumber;
        END IF;
    END LOOP;
    
END;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No employees found.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/

-- 3

DECLARE
    CURSOR employeedeletecursor IS SELECT empno FROM employee WHERE experience < 2;
    currentemployeeno employee.empno%TYPE;
BEGIN
    OPEN employeedeletecursor;

    LOOP
        FETCH employeedeletecursor INTO currentemployeeno;
        EXIT WHEN employeedeletecursor%NOTFOUND;
        DELETE FROM employee WHERE empno = currentemployeeno;
    END LOOP;
END;
/

-- 4

CREATE OR REPLACE TRIGGER triggeremployeenameupdate 
BEFORE UPDATE ON employee
FOR EACH ROW
BEGIN
    DBMS_OUTPUT.PUT_LINE('ename change from ' || :OLD.empname || ' to ' || :NEW.empname);
END;
/

UPDATE employee SET empname = 'AAB' WHERE empno = 1;

-- 5

CREATE TABLE backupemployeesalary (
    empno NUMBER,
    deduction NUMBER,
    basicsalary NUMBER,
    grosssalary NUMBER
)

CREATE OR REPLACE TRIGGER deleteprotectiontrigger 
BEFORE DELETE ON employeesalary 
FOR EACH ROW

BEGIN
    INSERT INTO backupemployeesalary VALUES (:OLD.empno, :OLD.deduction, :OLD.basicsalary, :OLD.grosssalary);
    DBMS_OUTPUT.PUT_LINE('Backed up the record of ' || :OLD.empno || ' from employeesalary table');
END;