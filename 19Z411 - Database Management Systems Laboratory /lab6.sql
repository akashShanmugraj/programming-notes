-- 1. Reverse a given number
DECLARE
    v_number NUMBER := 12345;
    v_reverse NUMBER := 0;
BEGIN
    WHILE v_number > 0 LOOP
        v_reverse := v_reverse * 10 + MOD(v_number, 10);
        v_number := FLOOR(v_number / 10);
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Reversed number: ' || v_reverse);
END;
/

-- OUTPUT
-- Reversed number: 54321

-- 2. Calculate factorial of a given number
DECLARE
    v_number NUMBER := 5;
    v_factorial NUMBER := 1;
BEGIN
    FOR i IN 1..v_number LOOP
        v_factorial := v_factorial * i;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Factorial of ' || v_number || ' is ' || v_factorial);
END;
/

-- OUTPUT
-- Factorial of 5 is 120

-- 3. Find the Maximum number from the given three numbers
DECLARE
    v_num1 NUMBER := 10;
    v_num2 NUMBER := 20;
    v_num3 NUMBER := 15;
    v_max NUMBER;
BEGIN
    v_max := GREATEST(v_num1, v_num2, v_num3);
    DBMS_OUTPUT.PUT_LINE('Maximum number is ' || v_max);
END;
/
-- OUTPUT
-- Maximum number is 20

-- 4. Find whether the given no is Prime no or not
DECLARE
    v_number NUMBER := 17;
    v_is_prime BOOLEAN := TRUE;
BEGIN
    FOR i IN 2..SQRT(v_number) LOOP
        IF MOD(v_number, i) = 0 THEN
            v_is_prime := FALSE;
            EXIT;
        END IF;
    END LOOP;
    IF v_is_prime AND v_number > 1 THEN
        DBMS_OUTPUT.PUT_LINE(v_number || ' is a prime number');
    ELSE
        DBMS_OUTPUT.PUT_LINE(v_number || ' is not a prime number');
    END IF;
END;
/

-- OUTPUT
-- 17 is a prime number

-- 5. Print fibonacci series for a user input
DECLARE
    v_n NUMBER := 10;
    v_fib1 NUMBER := 0;
    v_fib2 NUMBER := 1;
    v_next NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Fibonacci Series:');
    FOR i IN 1..v_n LOOP
        DBMS_OUTPUT.PUT(v_fib1 || ' ');
        v_next := v_fib1 + v_fib2;
        v_fib1 := v_fib2;
        v_fib2 := v_next;
    END LOOP;
END;
/

-- NO OUTPUT

-- 6. Find the sum of first 100 odd nos. and even nos.
DECLARE
    v_sum_odd NUMBER := 0;
    v_sum_even NUMBER := 0;
BEGIN
    FOR i IN 1..100 LOOP
        IF MOD(i, 2) = 0 THEN
            v_sum_even := v_sum_even + i;
        ELSE
            v_sum_odd := v_sum_odd + i;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Sum of first 100 odd numbers: ' || v_sum_odd);
    DBMS_OUTPUT.PUT_LINE('Sum of first 100 even numbers: ' || v_sum_even);
END;
/

-- OUTPUT
-- Sum of first 100 odd numbers: 2500
-- Sum of first 100 even numbers: 2550

-- 7. Find whether the given string is a palindrome or not.
DECLARE
    v_str VARCHAR2(100) := 'madam';
    v_reverse_str VARCHAR2(100);
BEGIN
    SELECT REVERSE(v_str) INTO v_reverse_str FROM DUAL;
    IF v_str = v_reverse_str THEN
        DBMS_OUTPUT.PUT_LINE(v_str || ' is a palindrome');
    ELSE
        DBMS_OUTPUT.PUT_LINE(v_str || ' is not a palindrome');
    END IF;
END;
/

-- OUTPUT
-- SSQQSS is a palindrome

-- 8. Display the Information of given student on following table Stud (sno, sname, address, city).
DECLARE
    v_sno NUMBER := 101;
    v_sname VARCHAR2(100);
    v_address VARCHAR2(100);
    v_city VARCHAR2(100);
BEGIN
    SELECT sname, address, city INTO v_sname, v_address, v_city
    FROM stud
    WHERE sno = v_sno;
    
    DBMS_OUTPUT.PUT_LINE('Student Information:');
    DBMS_OUTPUT.PUT_LINE('Name: ' || v_sname);
    DBMS_OUTPUT.PUT_LINE('Address: ' || v_address);
    DBMS_OUTPUT.PUT_LINE('City: ' || v_city);
END;
/

-- 9. Calculate the net salary from the basic and gross salary. Raise the gross salary by 20% and update the table
DECLARE
    v_basic_salary NUMBER := 5000;
    v_gross_salary NUMBER := 7000;
    v_deduction NUMBER := 500;
    v_net_salary NUMBER;
BEGIN
    v_net_salary := v_basic_salary + v_gross_salary - v_deduction;
    DBMS_OUTPUT.PUT_LINE('Net Salary: ' || v_net_salary);
    
    v_gross_salary := v_gross_salary * 1.20; -- Raise gross salary by 20%
    
    UPDATE emp
    SET gross_salary = v_gross_salary
    WHERE eno = 1001;
    
    DBMS_OUTPUT.PUT_LINE('Gross salary updated to: ' || v_gross_salary);
END;
/
