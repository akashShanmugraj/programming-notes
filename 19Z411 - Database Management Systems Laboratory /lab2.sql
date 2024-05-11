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


SELECT fname, lname FROM member;
SELECT * FROM member;
SELECT fname, area FROM member;
SELECT DISTINCT type FROM books;
SELECT fname FROM member WHERE SUBSTR(fname, 2, 1) = 'a';
SELECT lname FROM member WHERE lname LIKE 's%' OR lname LIKE 'j%';
SELECT * FROM member WHERE SUBSTR(area, 2, 1) = 'B';
SELECT * FROM member WHERE area IN ('MYL', 'CBE', 'DEL');
SELECT * FROM member WHERE phone_no > 9800000000;
SELECT * FROM transaction WHERE EXTRACT(MONTH FROM issue_date) = 9;
SELECT * FROM transaction WHERE member_id IN ('M03', 'M04');
SELECT * FROM books WHERE type IN ('CSE', 'ECE');
SELECT * FROM books WHERE price > 3500 AND price <= 5000;
SELECT *, price * 15 AS newprice FROM books WHERE price > 5000;
SELECT *, price * 15 AS new_price FROM books WHERE price > 5000;
SELECT * FROM books ORDER BY title;
SELECT title, type FROM books WHERE type != 'IC';
SELECT title, SQRT(price) AS square_root_price FROM books;
SELECT title, price / (price - 1000) AS result FROM books WHERE title = 'Digital Design';
SELECT fname, lname, area, member_id FROM member WHERE phone_no IS NULL;
SELECT fname FROM member WHERE lname IS NULL;
SELECT book_id, title, type FROM books WHERE author LIKE 'M%';
SELECT book_id, t_id FROM transaction WHERE t_id < 't05';
