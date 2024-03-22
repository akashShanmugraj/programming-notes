CREATE TABLE transaction (
    t_id varchar2(3) primary key,
    book_id varchar2(10),
    member_id varchar2(5),
    issue_date date,
    retum_date date
);

INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t01', 'B00004', 'M01', TO_DATE('22-JUN-19', 'DD-MON-YY'), TO_DATE('25-AUG-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t02', 'B00003', 'M02', TO_DATE('12-AUG-19', 'DD-MON-YY'), TO_DATE('15-AUG-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t03', 'B00001', 'M02', TO_DATE('15-AUG-19', 'DD-MON-YY'), TO_DATE('18-AUG-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t04', 'B00006', 'M03', TO_DATE('10-SEP-19', 'DD-MON-YY'), TO_DATE('13-SEP-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t05', 'B00007', 'M04', TO_DATE('05-AUG-19', 'DD-MON-YY'), TO_DATE('08-AUG-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t06', 'B00002', 'M06', TO_DATE('18-SEP-19', 'DD-MON-YY'), TO_DATE('21-SEP-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t07', 'B00009', 'M05', TO_DATE('07-JUL-19', 'DD-MON-YY'), TO_DATE('10-JUL-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t08', 'B00009', 'M01', TO_DATE('11-AUG-19', 'DD-MON-YY'), TO_DATE('14-AUG-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t09', 'B00005', 'M03', TO_DATE('06-JUL-19', 'DD-MON-YY'), TO_DATE('09-JUL-19', 'DD-MON-YY'));
INSERT INTO transaction (t_id, book_id, member_id, issue_date, retum_date) VALUES ('t10', 'B00008', 'M06', TO_DATE('03-SEP-19', 'DD-MON-YY'), TO_DATE('06-SEP-19', 'DD-MON-YY'));

CREATE TABLE member (
    member_id VARCHAR2(5) PRIMARY KEY,
    lname VARCHAR2(15),
    fname VARCHAR2(15),
    area VARCHAR2(20),
    phone_no NUMBER(10)
);

INSERT INTO member VALUES ('M01', 'George', 'Mathew', 'MAS', 9988776600);
INSERT INTO member VALUES ('M02', 'Sneha', 'Sawanth', 'CBE', 9843267123);
INSERT INTO member VALUES ('M03', 'Jeeva', 'Pramod', 'DEL', 9956754257);
INSERT INTO member VALUES ('M04', 'Neeraj', 'Basu', 'HSR', 8093373978);
INSERT INTO member VALUES ('M05', 'Sreeram', 'Kumar', 'MYL', NULL);
INSERT INTO member VALUES ('M06', NULL, 'Sri', 'CBE', 9873484635);

CREATE TABLE books (
    book_id VARCHAR2(10) PRIMARY KEY,
    title VARCHAR2(80),
    type CHAR(3),
    author VARCHAR2(20),
    price NUMBER(9, 2)
);

INSERT INTO books (book_id, title, type, author, price) VALUES ('B00001', 'The Essential Client/Server Survival Guide', 'CSE', 'Robert Orfali', 5000);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00002', 'Data Structures Using C And C++', 'CSE', 'Aaron.M.Tenenbaum', 1000);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00003', 'Digital Design', 'ECE', 'M Morris Mano', 2500);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00004', 'The C Odyssey Unix - The Open, Boundless C', 'CSE', 'Meeta Gandhi', 7300);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00005', 'Computer System Architecture', 'IC', 'M Morris Mano', 3500);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00006', 'An Introduction To Distributed And Parallel Computing', 'IT', 'Joel M Crichlow', 4200);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00007', 'Type And Learn C++ Today', 'ECE', 'Martin L Rinehart', 1500);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00008', 'Pc Buyers Survival Guide', 'IC', 'Harald Babiel', 4560);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00009', 'Digital Electronics And Microprocessors Problems And Solutions', 'ECE', 'R P Jain', 3500);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00010', 'Easy To Build Electronic Alarms', 'ECE', 'M C Sharma', 1900);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00011', 'Unix Network Programming', 'CSE', 'W Richard Stevens', 2200);
INSERT INTO books (book_id, title, type, author, price) VALUES ('B00012', 'C++ Programming Language', 'IT', 'Bjarne Stroustrup', 345);

DESC transaction;
DESC member;
DESC books;

24. SELECT COUNT(DISTINCT member_id) AS COUNT FROM member
25. SELECT SUM(price) FROM Books;
26. SELECT AVG(price) FROM Books;
27. SELECT MAX(price) AS max_price, MIN(price) AS min_price FROM books;
28. SELECT COUNT(*) as COUNT FROM books WHERE PRICE >= 1500;
29. SELECT 'Transaction ID of the Member ID ' || member_id || ' is ' || t_id AS 30. MESSAGE FROM transaction;
31. SELECT member_id || ' has taken the Book number ' || book_id || ' on ' || ISSUE_DATE || ' and will return on ' || RETUM_DATE as MESSAGE FROM transaction;
32. SELECT type, avg(price) from books group by type;
33. SELECT type, COUNT(*) as BC from books group by type;
34. SELECT type, COUNT(*) as BC from books HAVING type IN ('CSE', 'IC') group by type;
35. SELECT type, AVG(price) as AP from books HAVING MAX(price) <= 3500 group by type;
36. SELECT AVG(price) as AP from books WHERE type in ('ECE', 'IT') and price >= 1500;
37. SELECT t_id, EXTRACT(DAY from ISSUE_DATE) as DAY from transaction;
38. SELECT t_ID, TO_CHAR(RETURN_DATE, 'month') from transaction;
39. SELECT t_ID, TO_CHAR(RETUM_DATE, 'MONTH') as MONTH from transaction;
40. SELECT TO_CHAR(ISSUE_DATE, 'DD-month-YY') as ID from transaction;
41. SELECT SYSDATE + 15 from DUAL;
42. SELECT RETUM_DATE - SYSDATE as REM from transaction, dual;
