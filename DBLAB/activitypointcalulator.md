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
SELECT add_student(65, 'Vaisakh K'::varchar, 'IT'::varchar, 2020);
SELECT add_student(44, 'Sarath A R'::varchar, 'IT'::varchar, 2020);
SELECT add_student(29, 'K Manikantan'::varchar, 'IT'::varchar, 2020);
SELECT add_student(42, 'Rahul R'::varchar, 'IT'::varchar, 2020);
SELECT add_student(11, 'Arjun T B'::varchar, 'IT'::varchar, 2020);
SELECT add_student(15, 'Ashwin Titus'::varchar, 'IT'::varchar, 2020);
```
* ### Add new teacher (add_teacher)

```sql
CREATE OR REPLACE FUNCTION add_teacher( teacher_id int, name_ varchar, designation varchar, branch varchar,email varchar,password_ varchar)
RETURNS VOID
AS $$
BEGIN  
        INSERT INTO _teacher(Teacher_id, Name_, Designation, Branch, Email, Password_) VALUES (teacher_id, name_, designation, branch, email, 					password_);
        RAISE NOTICE 'Teacher details added successfully.';
END;
$$
LANGUAGE plpgsql;
```
> Function call

```sql
SELECT add_teacher(1001,'Jiphi T S'::varchar,'Professor'::varchar,'IT'::varchar,'jiphits@gmail.com'::varchar,'asdfdfg21'::varchar);
```
* ### Add new admin (add_admin)

```sql
CREATE OR REPLACE FUNCTION add_admin( admin_id int, name_ varchar, email varchar, password_ varchar)
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
SELECT add_admin(1, 'Abhijith R', 'abhijithcr7@gmail.com', 'ronaldo123');
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

