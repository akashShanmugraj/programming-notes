-- Student_Course (Roll_No, Course name, Course_Code, Sem, Total_Marks,
-- Percentage)

CREATE TABLE StudCourse
(
	rollno int,
	coursename varchar(5),
	coursecode int,
	sem int,
	totalmarks int,
	percentage int
);

INSERT INTO StudCourse VALUES(1,'AAA',101,3,90,90);
INSERT INTO StudCourse VALUES(2,'AAA',101,3,50,50);
INSERT INTO StudCourse VALUES(3,'BBB',102,3,65,65);
INSERT INTO StudCourse VALUES(4,'AAA',101,3,85,85);
INSERT INTO StudCourse VALUES(5,'BBB',102,3,97,97);
INSERT INTO StudCourse VALUES(6,'AAA',101,3,64,64);
INSERT INTO StudCourse VALUES(7,'BBB',102,3,55,55);
INSERT INTO StudCourse VALUES(8,'AAA',101,3,41,41);



-- 1.
CREATE OR REPLACE PROCEDURE Calculate_Student_Percentages(
    p_course_name IN VARCHAR2,
    p_course_code IN VARCHAR2
) AS
    v_total_students NUMBER;
    v_100_70 NUMBER := 0; 
    v_69_60 NUMBER := 0; 
    v_59_50 NUMBER := 0;
    v_below_49 NUMBER := 0;

BEGIN
   
    SELECT COUNT(*)
    INTO v_total_students
    FROM Student_Course
    WHERE Course_Name = p_course_name
    AND Course_Code = p_course_code;

    SELECT COUNT(*)
    INTO v_100_70
    FROM Student_Course
    WHERE Course_Name = p_course_name
    AND Course_Code = p_course_code
    AND Percentage BETWEEN 70 AND 100;

    SELECT COUNT(*)
    INTO v_69_60
    FROM Student_Course
    WHERE Course_Name = p_course_name
    AND Course_Code = p_course_code
    AND Percentage BETWEEN 60 AND 69;

    SELECT COUNT(*)
    INTO v_59_50
    FROM Student_Course
    WHERE Course_Name = p_course_name
    AND Course_Code = p_course_code
    AND Percentage BETWEEN 50 AND 59;

    SELECT COUNT(*)
    INTO v_below_49
    FROM Student_Course
    WHERE Course_Name = p_course_name
    AND Course_Code = p_course_code
    AND Percentage < 50;

    DBMS_OUTPUT.PUT_LINE('Course: ' || p_course_name || ' (' || p_course_code || ')');
    DBMS_OUTPUT.PUT_LINE('100-70%: ' || v_100_70 || ' students');
    DBMS_OUTPUT.PUT_LINE('69-60%: ' || v_69_60 || ' students');
    DBMS_OUTPUT.PUT_LINE('59-50%: ' || v_59_50 || ' students');
    DBMS_OUTPUT.PUT_LINE('Below 49%: ' || v_below_49 || ' students');
    DBMS_OUTPUT.PUT_LINE('Total Students: ' || v_total_students);
    DBMS_OUTPUT.PUT_LINE(CHR(10));
END;
/



BEGIN
    Calculate_Student_Percentages('MATHS', 'Z401');
    Calculate_Student_Percentages('DSA', 'Z302');
    Calculate_Student_Percentages('DAA', 'Z402');
    Calculate_Student_Percentages('CHEM', 'Z203');
    Calculate_Student_Percentages('PHY', 'Z202');
END;
/



-- 2.
DECLARE
	n number;
	factorial number;
FUNCTION fact(x number)
RETURN number
IS
	f number;
BEGIN
	IF x=0 or x=1 THEN
		f := 1;
	ELSE
		f := x * fact(x-1);
	END IF;
RETURN f;
END;
BEGIN
	n:= &n;
	factorial := fact(n);
	dbms_output.put_line(' Factorial of '|| n || ' is ' || factorial);
END;
/

-- 3.
CREATE OR REPLACE PROCEDURE Update_Employee_Dno(
    p_emp_no IN Employee.Emp_number%TYPE,
    p_new_dno IN Employee.D_no%TYPE
) AS
BEGIN
    UPDATE Employee
    SET D_no = p_new_dno
    WHERE Emp_number = p_emp_no;
    COMMIT;
    DBMS_OUTPUT.PUT_LINE('Employee ' || p_emp_no || ' D_no updated successfully.');
END;
/



DECLARE
    v_emp_no Employee.Emp_number%TYPE := 001;
    v_new_dno Employee.D_no%TYPE := 1;
BEGIN
    Update_Employee_Dno(v_emp_no, v_new_dno);
END;
/


-- 4.

CREATE OR REPLACE FUNCTION Count_Employees(
    p_dno IN Department1.Dnumber%TYPE
) RETURN NUMBER AS
    v_count NUMBER;
BEGIN
    SELECT COUNT(*)
    INTO v_count
    FROM Employee
    WHERE D_no = p_dno;
    
    RETURN v_count;
END;
/



DECLARE
    v_dno Department1.Dnumber%TYPE :=1;
    v_employee_count NUMBER;
BEGIN
    v_employee_count := Count_Employees(v_dno);
    DBMS_OUTPUT.PUT_LINE('Number of employees in department ' || v_dno || ': ' || v_employee_count);
END;
/             

-- 5.

CREATE OR REPLACE PROCEDURE Update_Salary_Below_Average AS
    v_avg_salary float(10);
BEGIN
   
    SELECT AVG(Basic)
    INTO v_avg_salary
    FROM Emp_Sal;

    UPDATE Emp_Sal
    SET Basic = Basic + (v_avg_salary - Basic)
    WHERE Basic < v_avg_salary;
    COMMIT;

    DBMS_OUTPUT.PUT_LINE('Salary updated successfully.');
END;
/

BEGIN
    Update_Salary_Below_Average;
END;
/

