# Activity Point Calculator (Database Lab Project)

## **Setup**
### DDL Commands

```sql
CREATE TABLE _teacher(
        T_id INT PRIMARY KEY UNIQUE NOT NULL,
        Name_ VARCHAR NOT NULL,
        Designation VARCHAR NOT NULL,
        Branch VARCHAR NOT NULL,
        Email VARCHAR NOT NULL UNIQUE,
        Password_ VARCHAR NOT NULL
);
        
        
CREATE TABLE _admin(
        A_id INT PRIMARY KEY UNIQUE NOT NULL,
        Name_ VARCHAR NOT NULL,   
        Email VARCHAR NOT NULL UNIQUE,
        Password_ VARCHAR NOT NULL
);
        

CREATE TABLE _category(
        Activity VARCHAR NOT NULL,
        Level_0 INT, 
        Level_1 INT,
        Level_2 INT,
        Level_3 INT,
        Level_4 INT,
        Level_5 INT,
        Max_points INT NOT NULL
);
        
CREATE TABLE _activity(
        Name_ VARCHAR NOT NULL,
        Category VARCHAR NOT NULL,
        Date_ DATE NOT NULL,
        Level_ INT NOT NULL
);
       
CREATE TABLE _student(
        Roll_No INT NOT NULL PRIMARY KEY UNIQUE,
        Name_ VARCHAR NOT NULL,
        Branch VARCHAR NOT NULL,
        Year_of_Graduation INT NOT NULL,
        Points INT 
);
```
### Populating the _category table with sample data*

```sql
INSERT INTO _category(Activity_type, Level_0, Level_1, Level_2, Level_3, Level_4, Level_5,Max_points)
VALUES
    ('Sports', 0, 8, 15, 25, 40, 60, 60),
    ('Games', 0, 8, 15, 25, 40, 60, 60),
    ('Music', 0, 8, 12, 20, 40, 60, 60),
    ('Performing arts', 0, 8, 12, 20, 40, 60, 60),
    ('Literary arts', 0, 8, 12, 20, 40, 60, 60),
    ('Tech fest, Tech Quiz', 0, 10, 20, 30, 40, 50, 50),
    ('MOOC with final assessment certificate', 50, 0, 0, 0, 0, 0, 50)
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
SELECT FROM add_student(65, 'Vaisakh K'::varchar, 'IT'::varchar, 2020);
```
