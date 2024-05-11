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

CREATE TABLE Employee (
    empnumber NUMBER PRIMARY KEY,
    empname VARCHAR2(50),
    empsalary NUMBER,
    deptnumber NUMBER
);

INSERT INTO Employee (empnumber, empname, empsalary, deptnumber) VALUES (1, 'AAA', 50000, 100);
INSERT INTO Employee (empnumber, empname, empsalary, deptnumber) VALUES (2, 'BBB', 60000, 200);
INSERT INTO Employee (empnumber, empname, empsalary, deptnumber) VALUES (3, 'CCC', 70000, 300);
INSERT INTO Employee (empnumber, empname, empsalary, deptnumber) VALUES (4, 'DDD', 80000, 400);

-- 1.
CREATE OR REPLACE PROCEDURE calpercentage(
    coursename IN VARCHAR2,
    coursecode in VARCHAR2
) AS
    totalstudents NUMBER;
    slot1 NUMBER := 0;
    slot2 NUMBER := 0;
    slot3 NUMBER := 0;
    slot4 NUMBER := 0;

BEGIN
    SELECT COUNT(*) into totalstudents FROM StudCourse WHERE coursename = coursename AND coursecode = coursecode;

    SELECT COUNT(*) into slot1 from StudCourse WHERE coursename = coursename AND coursecode = coursecode AND PERCENTAGE BETWEEN 70 AND 100;

    SELECT COUNT(*) INTO slot2 FROM StudCourse WHERE coursename = coursename AND coursecode = coursecode AND PERCENTAGE BETWEEN 60 AND 69;

    SELECT COUNT(*) INTO slot3 FROM StudCourse WHERE coursename = coursename and coursecode = coursecode AND PERCENTAGE BETWEEN 50 and 59;

    SELECT COUNT(*) INTO slot4 FROM StudCourse WHERE coursename = coursename and coursecode = coursecode AND PERCENTAGE <= 50;

    DBMS_OUTPUT.PUT_LINE(slot1 || ' ' || slot2 || ' ' || slot3 || ' ' || slot4 );

END; 

-- 2.

DECLARE 
    n NUMBER;
    factorial NUMBER;

FUNCTION findfactorial(targetnumber NUMBER) RETURN NUMBER IS
    f NUMBER;
BEGIN 
    IF targetnumber = 0 or targetnumber = 1 THEN
        RETURN 1;
    ELSE
        RETURN factorial * findfactorial(targetnumber-1);
    END IF;

END;

DECLARE
    inputnumber NUMBER;
    factorialnumber NUMBER;
BEGIN
    inputnumber := 5;
    factorialnumber := findfactorial(inputnumber);

    DBMS_OUTPUT.PUT_LINE('Factorial of ' || inputnumber || ' is ' || factorialnumber);
END;

-- 3.

CREATE OR REPLACE PROCEDURE updatedeptnumber (
    empnumber IN Employee.empnumber%TYPE,
    newdeptnumber IN Employee.deptnumber%TYPE
) AS 
BEGIN 
    UPDATE Employee SET deptnumber = newdeptnumber WHERE empnumber = empnumber;
    DBMS_OUTPUT.PUT_LINE('Updated Employee Number');

END;
/

BEGIN
    updatedeptnumber(2, 100);
END;

-- approach using functions
DECLARE
    v_empnumber Employee.empnumber%type;
    v_newdeptnumber Employee.deptnumber%type;
    v_result NUMBER;
FUNCTION updatedeptnumber (p_empnumber Employee.empnumber%type, p_newdeptnumber Employee.deptnumber%type) RETURN NUMBER IS
BEGIN
    UPDATE employee SET deptnumber = p_newdeptnumber WHERE empnumber = p_empnumber;
    DBMS_OUTPUT.PUT_LINE('Updated Employee Number');
    RETURN 1;
END;

BEGIN
    v_result := updatedeptnumber(2, 600);
    DBMS_OUTPUT.PUT_LINE('OUTPUT ' || v_result)
END;
/

-- 4.

CREATE or REPLACE FUNCTION countemployees(targetdeptnumber Employee.deptnumber%TYPE) RETURN NUMBER IS
    empcounter NUMBER;
BEGIN 
    SELECT COUNT(*) INTO empcounter FROM employee WHERE deptnumber = targetdeptnumber;
    RETURN empcounter;
END;
/
DECLARE
    empcounter NUMBER;
BEGIN
    empcounter := countemployees(100);
    DBMS_OUTPUT.PUT_LINE(empcounter);
END;

-- 5.

CREATE or REPLACE PROCEDURE updatebelowaveragesalary AS 
    averagesalary float(10);

BEGIN

    SELECT AVG(empsalary) INTO averagesalary FROM employee;

    UPDATE employee 
    SET empsalary = averagesalary WHERE empsalary < averagesalary;

    COMMIT;

END;
/

BEGIN
    updatebelowaveragesalary;
END;


