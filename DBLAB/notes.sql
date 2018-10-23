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
  st_cnt INT NOT NULL CHECK(st_cnt >= 0)
