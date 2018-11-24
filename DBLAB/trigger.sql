CREATE TABLE t1 (id INT PRIMARY KEY);

CREATE TABLE t1_log(
        id INT NOT NULL,
        logdate timestamp
);

CREATE OR REPLACE FUNCTION t1LogEntry()
RETURNS TRIGGER AS
$$
BEGIN
        INSERT INTO t1_log VALUES(NEW.id, now());
        RETURN NEW;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER t1_log_trigger BEFORE INSERT ON t1
FOR EACH ROW EXECUTE PROCEDURE t1LogEntry();

CREATE TABLE t1_backup(
        id INT NOT NULL,
        logdate timestamp
);

CREATE OR REPLACE FUNCTION t1Backup()
RETURNS TRIGGER AS
$$
BEGIN
        INSERT INTO t1_backup VALUES(OLD.id, now());
        RETURN OLD;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER t1_backup_trigger BEFORE DELETE ON t1
FOR EACH ROW EXECUTE PROCEDURE t1Backup();

SELECT tgname from pg_trigger;

BEFORE
AFTER
INSTEAD

