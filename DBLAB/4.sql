create table branch(
	b_id int primary key not null,
	bname varchar(25) not null,
	city varchar(25) not null);

create table customer(
	c_id int primary key not null,
	c_name varchar(25) not null,
	city varchar(25) not null);

create table deposit(
	acc_no int primary key not null,
	c_id int references customer(c_id),
	b_id int references branch(b_id),
	amount money,
	date date not null);

create table borrow(
	loan_no int primary key not null,
	c_id int references customer(c_id),
	b_id int references branch(b_id),
	amount money,
	date date not null);
	
insert into branch(b_id,bname,city) values
	('123', 'Chackai', 'Trivandrum'),
	('234', 'Pettah', 'Trivandrum'),
	('345', 'Pattoor', 'Trivandrum');

insert into customer(c_id, c_name, city) values
	('231', 'Saif', 'Tirur'),
	('432', 'Ahsan', 'Ramanaattukara'),
	('435', 'Midhun', 'Kaippamangalam');
	
insert into deposit(acc_no, c_id, b_id, amount, date) values
	('426','231','123','10000000','2018-05-05'),
	('2345','432','234','239999','2018-04-06'),
	('4243','435','234','500','2018-02-05');
