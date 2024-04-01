UPDATE member SET phone_no = 7865466389 WHERE lname = 'Sneha';
UPDATE transaction SET issue_date = TO_DATE('24-07-93', 'DD-MM-YY') WHERE member_id = 'M01';
UPDATE books SET price = 1250 WHERE title = 'Data Structures Using C And C++';
DELETE FROM transaction WHERE t_id = 't08';
DELETE FROM transaction WHERE retum_date < TO_DATE('10-JUL-1993', 'DD-MON-YYYY');
UPDATE member SET area = 'DEL' WHERE member_id = 'M04';
UPDATE transaction SET retum_date = TO_DATE('16-08-93', 'DD-MM-YY') WHERE t_id = 't09';
