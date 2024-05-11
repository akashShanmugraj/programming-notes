SELECT * FROM member WHERE member_id IN (SELECT t.member_id FROM transaction t WHERE t.book_id=’B00009’);

SELECT m.fname, m.lname, area FROM member m
WHERE member_id IN (
    SELECT member_id
    FROM transaction
    WHERE t_id = 't06'
);

SELECT fname, lname, phone_no
FROM member
WHERE member_id IN (
    SELECT member_id
    FROM transaction
    WHERE issue_date < TO_DATE('01-AUG-19', 'DD-MON-YY')
);

SELECT title
FROM books
WHERE book_id IN (
    SELECT book_id
    FROM transaction
    WHERE member_id IN (
        SELECT member_id
        FROM member
        WHERE lname IN ('George', 'Basu')
    )
);

SELECT type, book_id
FROM books
WHERE book_id IN (
    SELECT book_id
    FROM transaction
    WHERE member_id IN ('M01', 'M06')
);

SELECT member_id
FROM transaction
WHERE book_id IN (
    SELECT book_id
    FROM books
    WHERE author = 'R P Jain'
);

SELECT lname, fname
FROM member
WHERE member_id IN (
    SELECT member_id
    FROM transaction WHERE issue_date IS NOT NULL
);

UPDATE member SET phone_no = 7865466389 WHERE lname = 'Sneha';
UPDATE transaction SET issue_date = TO_DATE('24-07-93', 'DD-MM-YY') WHERE member_id = 'M01';
UPDATE books SET price = 1250 WHERE title = 'Data Structures Using C And C++';
DELETE FROM transaction WHERE t_id = 't08';
DELETE FROM transaction WHERE retum_date < TO_DATE('10-JUL-1993', 'DD-MON-YYYY');
UPDATE member SET area = 'DEL' WHERE member_id = 'M04';
UPDATE transaction SET retum_date = TO_DATE('16-08-93', 'DD-MM-YY') WHERE t_id = 't09';
