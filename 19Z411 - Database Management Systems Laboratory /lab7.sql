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

CREATE TABLE department (
    deptname VARCHAR(10),
    deptnumber NUMBER,
    managerssn NUMBER,
    constraint deptnumberpk PRIMARY KEY (deptnumber)
);

CREATE TABLE employee (
    empno NUMBER,
    empname VARCHAR(10),
    experience NUMBER,
    city VARCHAR(10),
    deptno NUMBER,
    constraint empnopk PRIMARY KEY (empno),
    constraint deptnofk FOREIGN KEY (deptno) REFERENCES department(deptnumber)
);

CREATE TABLE employeesalary (
    empno NUMBER,
    deduction NUMBER,
    basicsalary NUMBER,
    grosssalary NUMBER,
    constraint empnofk FOREIGN KEY(empno) REFERENCES employee(empno)
);

INSERT INTO department (deptname, deptnumber, managerssn) VALUES ('HR', 100, 123456789);
INSERT INTO department (deptname, deptnumber, managerssn) VALUES ('Sales', 200, 234567891);
INSERT INTO department (deptname, deptnumber, managerssn) VALUES ('Finance', 300, 345678912);
INSERT INTO department (deptname, deptnumber, managerssn) VALUES ('IT', 400, 456789123);

INSERT INTO employee (empno, empname, experience, city, deptno) VALUES (1, 'John', 5, 'New York', 100);
INSERT INTO employee (empno, empname, experience, city, deptno) VALUES (2, 'Jane', 3, 'Chicago', 200);
INSERT INTO employee (empno, empname, experience, city, deptno) VALUES (3, 'Bob', 7, 'SFO', 300);
INSERT INTO employee (empno, empname, experience, city, deptno) VALUES (4, 'Alice', 2, 'Boston', 400);

INSERT INTO employeesalary (empno, basicsalary, deduction, grosssalary) VALUES (1, 50000, 5000, 45000);
INSERT INTO employeesalary (empno, basicsalary, deduction, grosssalary) VALUES (2, 60000, 6000, 54000);
INSERT INTO employeesalary (empno, basicsalary, deduction, grosssalary) VALUES (3, 70000, 7000, 63000);
INSERT INTO employeesalary (empno, basicsalary, deduction, grosssalary) VALUES (4, 80000, 8000, 72000);

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

CREATE OR REPLACE FUNCTION findfactorial (
    targetnumber NUMBER
) RETURN NUMBER IS randomnumber NUMBER;
BEGIN
    IF targetnumber = 0 THEN
        RETURN 1;
    ELSE 
        RETURN targetnumber * findfactorial(targetnumber - 1);
    END IF;
RETURN 1;
END;
/
    
DECLARE 
    randomnumber NUMBER;
BEGIN
    randomnumber := findfactorial(6);
    DBMS_OUTPUT.PUT_LINE('Factorial is ' || randomnumber);
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
CREATE OR REPLACE FUNCTION updatedeptnumberfunction (
    currentemployeenumber NUMBER,
    newdepartmentnumber NUMBER
) RETURN NUMBER IS somenumber NUMBER;
BEGIN
    UPDATE employee SET deptno = newdepartmentnumber WHERE empno = currentemployeenumber;
	RETURN somenumber;
END;
/

DECLARE
    randomnumber NUMBER;
    
BEGIN
    randomnumber := updatedeptnumberfunction(2, 100);
END;
/

SELECT * FROM employee;

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

CREATE OR REPLACE PROCEDURE updateemployeesalary 
IS averagesalary NUMBER;
BEGIN
    SELECT AVG(basicsalary) INTO averagesalary FROM employeesalary;
    UPDATE employeesalary SET basicsalary = averagesalary WHERE basicsalary < averagesalary;
END;
/
    
BEGIN 
    updateemployeesalary;
END;


