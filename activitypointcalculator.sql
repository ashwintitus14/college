-- DDL Commands

CREATE TABLE _teacher(
        Teacher_id INT PRIMARY KEY UNIQUE NOT NULL,
        Name_ VARCHAR NOT NULL,
        Designation VARCHAR NOT NULL,
        Branch VARCHAR NOT NULL,
        Email VARCHAR NOT NULL UNIQUE,
        Password_ VARCHAR NOT NULL
);
        
        
CREATE TABLE _admin(
        Admin_id INT PRIMARY KEY UNIQUE NOT NULL,
        Name_ VARCHAR NOT NULL,   
        Email VARCHAR NOT NULL UNIQUE,
        Password_ VARCHAR NOT NULL
);
        

CREATE TABLE _category(
        C_id SERIAL PRIMARY KEY UNIQUE NOT NULL,
        Activity_type VARCHAR NOT NULL,
        Level_ INT,
	Points INT,
        Max_points INT NOT NULL
);
        
CREATE TABLE _activity(
        A_id SERIAL PRIMARY KEY UNIQUE NOT NULL,
        Name_ VARCHAR NOT NULL,
        Category VARCHAR NOT NULL,
        Date_ DATE NOT NULL,
        Level_ INT NOT NULL,
        Points INT DEFAULT 0
);
       
CREATE TABLE _student(
        Roll_No INT NOT NULL PRIMARY KEY UNIQUE,
        Name_ VARCHAR NOT NULL,
        Branch VARCHAR NOT NULL,
        Year_of_Graduation INT NOT NULL,
        Points INT DEFAULT 0
);

CREATE TABLE _student_backup(
        Roll_No INT NOT NULL PRIMARY KEY UNIQUE,
        Name_ VARCHAR NOT NULL,
        Branch VARCHAR NOT NULL,
        Year_of_Graduation INT NOT NULL,
        Points INT DEFAULT 0
);

CREATE TABLE _student_del_backup(
        Roll_No INT NOT NULL PRIMARY KEY UNIQUE,
        Name_ VARCHAR NOT NULL,
        Branch VARCHAR NOT NULL,
        Year_of_Graduation INT NOT NULL,
        Points INT DEFAULT 0
);

-- Populating category table

INSERT INTO _category(Activity_type, Level_, Points, Max_points)
VALUES
    ('Sports', 0, 0, 60),
    ('Sports', 1, 8, 60),
    ('Sports', 2, 15, 60),
    ('Sports', 3, 25, 60),
    ('Sports', 4, 40, 60),
    ('Sports', 5, 60, 60),	
    ('Music', 0, 0, 60),
    ('Music', 1, 8, 60),
    ('Music', 2, 12, 60),
    ('Music', 3, 20, 60),
    ('Music', 4, 40, 60),
    ('Music', 5, 60, 60)
;

-- Functions

-- Function to add a new activity

CREATE OR REPLACE FUNCTION add_activity ( name_ VARCHAR, category VARCHAR, date_ DATE, level_ INT)
RETURNS VOID 
AS $$
BEGIN
        INSERT INTO _activity(Name_, Category, Date_, Level_) VALUES (name_, category, date_, level_);
        RAISE NOTICE 'Activity added successfully.';
END;
$$
LANGUAGE plpgsql;

-- Trigger to retrieve points of an activity

CREATE OR REPLACE FUNCTION get_points()
RETURNS TRIGGER
AS $$
BEGIN
        UPDATE _activity SET Points=((SELECT Points FROM _category AS c WHERE new.Category = c.Activity_type AND new.Level_ = c.Level_));
        RETURN new;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER get_points_trigger AFTER INSERT ON _activity
FOR EACH ROW EXECUTE PROCEDURE get_points();

-- To call add_activity

SELECT add_activity( 'Guitar'::VARCHAR, 'Music'::VARCHAR, '2018-02-12'::DATE, 3);

-- Function to add student details

CREATE OR REPLACE FUNCTION add_student( roll_no int, name_ varchar, branch varchar, year_of_graduation int)
RETURNS VOID
AS $$
BEGIN  
        INSERT INTO _student(Roll_No, Name_, Branch, Year_of_Graduation) VALUES (roll_no, name_, branch, year_of_graduation);
        RAISE NOTICE 'Student details added successfully.';
END;
$$
LANGUAGE plpgsql;


-- To call add_student

SELECT add_student(65, 'Vaisakh K'::varchar, 'IT'::varchar, 2020);

-- Function to update student's points

CREATE OR REPLACE FUNCTION update_points( roll_no int, activity varchar)
RETURNS VOID
AS $$
BEGIN  
		update _student set Points=Points+(select Points from _activity where activity=Name_);
        RAISE NOTICE 'student details updated successfully.';
END;
$$
LANGUAGE plpgsql;



--function to update teacher's details
CREATE OR REPLACE FUNCTION add_teacher( teacher_id int, name_ varchar, designation varchar, branch varchar,email varchar,password_ varchar)
RETURNS VOID
AS $$
BEGIN  
        INSERT INTO _teacher(Teacher_id, Name_, Designation, Branch, Email, Password_) VALUES (teacher_id, name_, designation, branch, email, 					password_);
        RAISE NOTICE 'Teacher details added successfully.';
END;
$$
LANGUAGE plpgsql;




--Function to add Admin's details

CREATE OR REPLACE FUNCTION add_admin( admin_id int, name_ varchar, email varchar, password_ varchar)
RETURNS VOID
AS $$
BEGIN  
        INSERT INTO _admin(Admin_id, Name_, Email, Password_) VALUES ( admin_id, name_, email, password_);
        RAISE NOTICE 'Admin details added successfully.';
END;
$$
LANGUAGE plpgsql;


--Function to update Student's name

CREATE OR REPLACE FUNCTION update_student_name( roll_no int, name_ varchar)
RETURNS VOID
AS $$
BEGIN  
 	update _student set Name_=name_ where Roll_No=roll_no; 
        RAISE NOTICE 'student name updated successfully.';
END;
$$
LANGUAGE plpgsql;

--function to backup student data

CREATE OR REPLACE FUNCTION backup()
RETURNS VOID AS
$$
DECLARE
    rec RECORD;
    cur CURSOR FOR SELECT * FROM _student;
BEGIN
    FOR rec IN cur
    LOOP
        insert into _student_backup(Roll_No, Name_, Branch, Year_of_Graduation, Points)
        values(rec.Roll_No, rec.Name_, rec.Branch, rec.Year_of_Graduation, rec.Points);
    END LOOP;
END;
$$
LANGUAGE plpgsql;


--function to backup student data when delete

create or replace function del_backup()
returns trigger as
$$
begin
insert into _student_del_backup(Roll_No, Name_, Branch, Year_of_Graduation, Points)
values(old.Roll_No, old.Name_, old.Branch, old.Year_of_Graduation, old.Points);
  return old;
end;
$$
language plpgsql;

create trigger del_backup after delete on _student
for each row execute PROCEDURE del_backup();



-- Function to update student branch

CREATE OR REPLACE FUNCTION update_student_branch( roll_no int, branch varchar)
RETURNS VOID
AS $$
BEGIN  
 	update _student set Branch=branch where Roll_No=roll_no; 
        RAISE NOTICE 'student branch updated successfully.';
END;
$$
LANGUAGE plpgsql;

-- Function to export student data to csv
CREATE OR REPLACE FUNCTION export_student_to_csv()
RETURNS VOID
AS $$
BEGIN
	Copy (Select * From _student) To '/tmp/student.csv' With CSV DELIMITER ','
	RAISE NOTICE 'Exported to CSV file at /tmp/student.csv';
END;
$$
LANGUAGE plpgsql;

















