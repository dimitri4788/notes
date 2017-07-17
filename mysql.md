# MySQL

## Command Line

``` bash
# Connect to mysql server
$ mysql -u root
```

## MySQL shell commands

``` bash
mysql> show databases;
mysql> create database dummy;
mysql> use dummy;
mysql> create table users (username text);
mysql> create table users (id int not null, username text);
mysql> create table users (id int primary key auto_increment, email text);
mysql> show tables;
mysql> desc users;
mysql> insert into users (username) values ('Deep');
mysql> insert into users (id, username) values (1, 'Bob');
mysql> select * from users;
mysql> drop table users;

# Storage engines are MySQL components that handle the SQL operations for different table types
# InnoDB is the default and most general-purpose storage engine
mysql> show engines;
mysql> show table status; # Additional information about a table
mysql> set default_storage_engine=MYISAM

mysql> quit
```

## MySQL Types

### Text Types

- text
- char
- varchar

### Numeric Types

- int
- float
- double
- decimal

### Bit Types

- bit

### Boolean

- bool

### Blobs (Binary Large Object)

- blob

### Time, Date & Year

- year
- date
- time

### Timestamp & Datetime

- timestamp
- datetime

### Enum

- enum

### Resources

- [Download MySQL Community Server](https://dev.mysql.com/downloads/mysql/)
- [MySQL Downloads](https://www.mysql.com/downloads/)
