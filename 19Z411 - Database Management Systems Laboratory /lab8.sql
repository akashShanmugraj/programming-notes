-- 1
DECLARE
    CURSOR top_employees_cur IS
        SELECT EMP_NUMBER, E_NAME, BASIC
        FROM (
            SELECT EMP_NUMBER, E_NAME, BASIC,
                   RANK() OVER (ORDER BY BASIC DESC) AS ranking
            FROM EMP_SAL natural join employee
        )
        WHERE ranking <= 5;

    emp_no EMP_SAL.EMP_NUMBER%TYPE;
    e_name EMPLOYEE.E_NAME%TYPE;
    basic EMP_SAL.BASIC%TYPE;
BEGIN
    OPEN top_employees_cur;
    LOOP
        FETCH top_employees_cur INTO emp_no, e_name, basic;
        EXIT WHEN top_employees_cur%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Employee Number: ' || emp_no || ', Name: ' || e_name || ', Basic: ' || basic);
    END LOOP;
    CLOSE top_employees_cur;
END;
/



-- 2
DECLARE
    avg_salary NUMBER;
    emp_basic EMP_SAL.BASIC%TYPE;
    emp_id EMPLOYEE.EMP_NUMBER%TYPE;
    CURSOR emp_cursor IS
        SELECT EMP_NUMBER, BASIC
        FROM EMP_SAL;
BEGIN
    -- Calculate the average salary
    SELECT AVG(BASIC) INTO avg_salary FROM EMP_SAL;

    FOR emp_rec IN emp_cursor LOOP
        emp_id := emp_rec.EMP_NUMBER;
        emp_basic := emp_rec.BASIC;

        -- Update the salary of employees earning less than the average
        IF emp_basic < avg_salary THEN
            UPDATE EMP_SAL
            SET BASIC = BASIC + (avg_salary - BASIC)
            WHERE EMP_NUMBER = emp_id;
            
            -- Fetch and print the modified row
            FOR updated_row IN (SELECT * FROM EMP_SAL WHERE EMP_NUMBER = emp_id) LOOP
                DBMS_OUTPUT.PUT_LINE('Employee Number: ' || updated_row.EMP_NUMBER || ', Basic: ' || updated_row.BASIC);
            END LOOP;
        END IF;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('Salary updated for employees earning less than the average.');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No employees found.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/




-- 3
DECLARE
	eno Employee.empno%type;
	ename Employee.empname%type;
	CURSOR exp_less2 IS SELECT empno,empname FROM Employee WHERE exp<2;
BEGIN 
	OPEN exp_less2;
	DBMS_OUTPUT.PUT_LINE('Employees less than 2 years experience:');
	LOOP
		FETCH exp_less2 INTO eno,ename;
		EXIT WHEN exp_less2%NOTFOUND;
		DBMS_OUTPUT.PUT_LINE(eno||' '||ename);
		DELETE FROM EmpSalary WHERE empno=eno;
		DELETE FROM Employee WHERE empno=eno;
	END LOOP;
	CLOSE exp_less2;
END;
/


-- 4
CREATE OR REPLACE TRIGGER display_ename_changes
BEFORE UPDATE ON Employee
FOR EACH ROW
BEGIN
    IF :OLD.E_NAME != :NEW.E_NAME THEN
        DBMS_OUTPUT.PUT_LINE('Employee Name is being updated:');
        DBMS_OUTPUT.PUT_LINE('Old Name: ' || :OLD.E_NAME);
        DBMS_OUTPUT.PUT_LINE('New Name: ' || :NEW.E_NAME);
    END IF;
END;
/

 Update Employee set E_name='Vihaan' where Emp_number=4;




-- 5

create table Backup_Sal
(
Emp_number number(5) primary key,
Basic float(10),
Deduction float(10),
Gross_Salary float(10)
);



CREATE OR REPLACE TRIGGER insert_salary_backup
BEFORE DELETE ON EMP_SAL
FOR EACH ROW
BEGIN
    INSERT INTO BACKUP_SAL (EMP_NUMBER, BASIC, DEDUCTION, GROSS_SALARY)
    VALUES (:OLD.EMP_NUMBER, :OLD.BASIC, :OLD.DEDUCTION, :OLD.GROSS_SALARY);
END;
/


 delete from Emp_Sal where Emp_number=1;

 select *from backup_sal;
