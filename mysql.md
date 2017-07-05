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
mysql> show tables;
mysql> desc users;
mysql> insert into users (username) values ("Deep");
mysql> insert into users (username) values ("Bob");
mysql> select * from users;


mysql> quit
```


### Resources

- [Download MySQL Community Server](https://dev.mysql.com/downloads/mysql/)
- [MySQL Downloads](https://www.mysql.com/downloads/)
