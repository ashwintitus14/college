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


