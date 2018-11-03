CREATE OR REPLACE FUNCTION inc(n INT)
RETURNS INT AS 
$BODY$
BEGIN
    RETURN n+1;
END;
$BODY$
LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION add(n INT, m INT)
RETURNS INT AS
$BODY$
BEGIN
    RETURN n+m;
END;
$BODY$
LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION fib(n INT)
RETURNS INT AS
$BODY$
DECLARE
    prev INT = 0;
    curr INT = 1;
    next INT;
    cnt INT = 0;
BEGIN
    LOOP
    EXIT WHEN cnt = n-1;
        next = prev+curr;
        prev = curr;
        curr = next;
        cnt = cnt+1;
    END LOOP;
    RETURN prev;
END;
$BODY$
LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION divide(n NUMERIC, m NUMERIC)
RETURNS NUMERIC AS
$BODY$
DECLARE
	res NUMERIC = 0;
BEGIN
	res = n/m;
	RETURN res;
END;
$BODY$
LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION lstCWSGT(n INT)
RETURNS TABLE(
c_name VARCHAR,
divis VARCHAR,
s_cnt INT
)
AS
$$
BEGIN
	RETURN QUERY SELECT class_name, division, st_cnt FROM class_
	WHERE st_cnt>n;
END;
$$
LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION names(name VARCHAR)
RETURNS TABLE(
id INT,
fname VARCHAR,
lname VARCHAR,
classid INT
)
AS
$$
BEGIN
	RETURN QUERY select * from student where st_fname LIKE name;
END;
$$
LANGUAGE plpgsql;


-- _ -> 1 character % -> wildcard 

SELECT DISTINCT s1.st_fname, s1.st_lname FROM student AS s1, student as s2
WHERE s1.st_fname LIKE s2.st_fname AND
s1.st_id != s2.st_id
ORDER BY(s1.st_fname);

CREATE OR REPLACE FUNCTION testCur()
RETURNS VOID AS
$$
DECLARE
	rec RECORD;
	cur CURSOR FOR SELECT st_fname, st_lname FROM studen LIMIT 5;
	BEGIN
		FOR rec IN cur
		LOOP
			RAISE NOTICE 'fname: %, lname: %', rec.st_fname, rec.st_lname;
		END LOOP;
END;
$$
LANGUAGE plpgsql;
