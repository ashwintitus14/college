/*
STUDENT DATABASE
class_(class_id, clas_name, division, st_cnt)
student(st_id, st_fname, st_lname, addr, phone, email, class_id)
teacher(teacher_id, fname, lname, phone, subject)
student_class(st_id, class_id, teacher_id)
*/

CREATE TABLE class_(
  class_id SERIAL PRIMARY KEY,
  class_name VARCHAR(30) NOT NULL,
  division VARCHAR(2) NOT NULL DEFAULT 'A',
  st_cnt INT NOT NULL CHECK(st_cnt >= 0),
  UNIQUE( class_name, division)
 );
 
 INSERT INTO class_(class_name, st_cnt)
 VALUES ('Ten', 65);
 
 CREATE TABLE student(
   st_id SERIAL PRIMARY KEY,
   st_fname VARCHAR(30) NOT NULL,
   st_lname VARCHAR(30) NOT NULL,
   addr VARCHAR(30) NOT NULL,
   phone VARCHAR(13),
   email VARCHAR(30),
   class_id INT REFERENCES class_(class_id)
  );
