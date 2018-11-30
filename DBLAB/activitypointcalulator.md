# Activity Point Calculator (Database Lab Project)

## **Setup**
### DDL Commands

```sql
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

```
### Populating the _category table with sample data

```sql
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
```
## **Functions**

* ### Add new activity (add_activity)

```sql
CREATE OR REPLACE FUNCTION add_activity ( name_ VARCHAR, category VARCHAR, date_ DATE, level_ INT)
RETURNS VOID 
AS $$
BEGIN
        INSERT INTO _activity(Name_, Category, Date_, Level_) VALUES (name_, category, date_, level_);
        RAISE NOTICE 'Activity added successfully.';
END;
$$
LANGUAGE plpgsql;
```
> Function call

```sql
SELECT FROM add_activity( 'Debate'::VARCHAR, 'Literary arts'::VARCHAR, '2018-02-12'::DATE, 3);
```
* ### Add new student (add_student)

```sql
CREATE OR REPLACE FUNCTION add_student( roll_no int, name_ varchar, branch varchar, year_of_graduation int)
RETURNS VOID
AS $$
BEGIN  
        INSERT INTO _student(Roll_No, Name_, Branch, Year_of_Graduation) VALUES (roll_no, name_, branch, year_of_graduation);
        RAISE NOTICE 'Student details added successfully.';
END;
$$
LANGUAGE plpgsql;
```
> Function call

```sql
SELECT add_student(65, 'Vaisakh K'::VARCHAR, 'IT'::VARCHAR, 2020);
SELECT add_student(44, 'Sarath A R'::VARCHAR, 'IT'::VARCHAR, 2020);
SELECT add_student(29, 'K Manikantan'::VARCHAR, 'IT'::VARCHAR, 2020);
SELECT add_student(42, 'Rahul R'::VARCHAR, 'IT'::VARCHAR, 2020);
SELECT add_student(11, 'Arjun T B'::VARCHAR, 'IT'::VARCHAR, 2020);
SELECT add_student(15, 'Aswin Titus'::VARCHAR, 'IT'::VARCHAR, 2020);
```
* ### Add new teacher (add_teacher)

```sql
CREATE OR REPLACE FUNCTION add_teacher( teacher_id INT, name_ VARCHAR, designation VARCHAR, branch VARCHAR,email VARCHAR,password_ VARCHAR)
RETURNS VOID
AS $$
BEGIN  
        INSERT INTO _teacher(Teacher_id, Name_, Designation, Branch, Email, Password_) VALUES (teacher_id, name_, designation, branch, email, password_);
        RAISE NOTICE 'Teacher details added successfully.';
END;
$$
LANGUAGE plpgsql;
```
> Function call

```sql
SELECT add_teacher(1001,'Jiphi T S'::VARCHAR,'Professor'::VARCHAR,'IT'::VARCHAR,'jiphits@gmail.com'::VARCHAR,'asdfdfg21'::VARCHAR);
```
* ### Add new admin (add_admin)

```sql
CREATE OR REPLACE FUNCTION add_admin( admin_id INT, name_ VARCHAR, email VARCHAR, password_ VARCHAR)
RETURNS VOID
AS $$
BEGIN  
        INSERT INTO _admin(Admin_id, Name_, Email, Password_) VALUES ( admin_id, name_, email, password_);
        RAISE NOTICE 'Admin details added successfully.';
END;
$$
LANGUAGE plpgsql;
```
> Function call

```sql
SELECT add_admin(1, 'Abhijith R'::VARCHAR, 'abhijithcr7@gmail.com'::VARCHAR, 'ronaldo123'::VARCHAR);
```

* ### Update student's points (update_points)

```sql
CREATE OR REPLACE FUNCTION update_points( roll_no int, activity varchar)
RETURNS VOID
AS $$
BEGIN  
		UPDATE _student SET Points=Points+(SELECT Points FROM _activity WHERE activity=Name_);
        RAISE NOTICE 'Student details updated successfully.';
END;
$$
LANGUAGE plpgsql;
```

> Function call

```sql
SELECT update_points( 29, 'Chess Zonal'::VARCHAR);
```
* ### Update student's name (update_student_name)
```sql
CREATE OR REPLACE FUNCTION update_student_name( roll_no int, name_ varchar)
RETURNS VOID
AS $$
BEGIN  
 	update _student set Name_=name_ where Roll_No=roll_no; 
        RAISE NOTICE 'student name updated successfully.';
END;
$$
LANGUAGE plpgsql;
```

> Function call
```sql
SELECT update_student_name(15,'Ashwin Titus'::VARCHAR);
```
* ### Update student's branch (update_student_branch)
```sql
CREATE OR REPLACE FUNCTION update_student_branch( roll_no int, branch varchar)
RETURNS VOID
AS $$
BEGIN  
 	update _student set Branch=branch where Roll_No=roll_no; 
        RAISE NOTICE 'student branch updated successfully.';
END;
$$
LANGUAGE plpgsql;
```
> Function call
```sql
SELECT update_student_branch( 42, 'ECE'::VARCHAR);
```
* ### Export student's database to a .csv file (export_student_to_csv)
```sql
CREATE OR REPLACE FUNCTION export_student_to_csv()
RETURNS VOID
AS $$
BEGIN
	COPY (SELECT * FROM _student) TO '/tmp/student.csv' WITH CSV DELIMITER ',';
	RAISE NOTICE 'Exported to CSV file at /tmp/student.csv';
END;
$$
LANGUAGE plpgsql;
```
> Function call
```sql
SELECT export_student_to_csv();
```

## **Triggers**

* ### Retrieve points of the activity from _category (get_points)
```sql
REATE OR REPLACE FUNCTION get_points()
RETURNS TRIGGER
AS $$
BEGIN
        INSERT INTO _activity(Points) VALUES ((SELECT Points FROM _category AS c WHERE new.Name_ = c.Activity_type))
        

END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER get_points_trigger AFTER INSERT ON _activity
FOR EACH ROW EXECUTE PROCEDURE get_points();
```

* ### Backs up each deleted record from _student (del_backup)
```sql
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
```

## **Cursor**

* ### Backs up the entire student table when called (backup)

```sql
CREATE OR REPLACE FUNCTION backup()
RETURNS VOID AS
$$
DECLARE
    rec RECORD;
    cur CURSOR FOR SELECT * FROM _student;
BEGIN
    FOR rec IN cur
    LOOP
        INSERT INTO _student_backup(Roll_No, Name_, Branch, Year_of_Graduation, Points)
        VALUES(rec.Roll_No, rec.Name_, rec.Branch, rec.Year_of_Graduation, rec.Points);
    END LOOP;
END;
$$
LANGUAGE plpgsql;
```
