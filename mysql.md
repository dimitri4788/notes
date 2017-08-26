# MySQL

## Command Line

``` bash
# Connect to mysql server
$ mysql -h host -u user -p ******
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

# Disconnect any time by typing QUIT (or \q)
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

## Database Engine / Storage Engine

A database engine (or storage engine) is the underlying software component that a database management system (DBMS) uses to create, read, update and delete (CRUD) data from a database.

MySQL supports InnoDB as well as MyISAM storage engines.

- InnoDB has row-level locking, MyISAM can only do full table-level locking.
- InnoDB has better crash recovery.
- MyISAM has full-text search indexes, InnoDB did not until MySQL 5.6 (Feb 2013).
- InnoDB implements transactions, foreign keys and relationship constraints, MyISAM does not.
- InnoDB is the default storage engine for new tables. In practice, the advanced InnoDB performance features mean that InnoDB tables often outperform the simpler MyISAM tables, especially for a busy database.

## Optimization

Database performance depends on several factors at the database level, such as tables, queries, and configuration settings.

### Optimizing at the Database Level

The most important factor in making a database application fast is its basic design:

- **Are the tables structured properly?** For example, applications that perform frequent updates often have many tables with few columns, while applications that analyze large amounts of data often have few tables with many columns.
- **Are the right indexes in place to make queries efficient?**
- **Are you using the appropriate storage engine for each table?** In particular, the choice of a transactional storage engine such as InnoDB or a nontransactional one such as MyISAM can be very important for performance and scalability.
- **Does each table use an appropriate row format?** This choice also depends on the storage engine used for the table. In particular, compressed tables use less disk space and so require less disk I/O to read and write the data. Compression is available for all kinds of workloads with InnoDB tables, and for read-only MyISAM tables.
- **Does the application use an appropriate locking strategy?** For example, by allowing shared access when possible so that database operations can run concurrently, and requesting exclusive access when appropriate so that critical operations get top priority. The InnoDB storage engine handles most locking issues, allowing for better concurrency in the database.
- **Are all memory areas used for caching sized correctly?** That is, large enough to hold frequently accessed data, but not so large that they overload physical memory and cause paging. The main memory areas to configure are the InnoDB buffer pool, the MyISAM key cache, and the MySQL query cache.

### Optimizing at the SQL Queries Level

- Learn How to Create Indexes Properly
- Only Retrieve the Data You Really Need
    - `SELECT * FROM users WHERE age > 20;` vs `SELECT id, last_name, sex, age FROM users WHERE age > 20;`
    - `SELECT name, price FROM products;` vs `SELECT name, price FROM products LIMIT 10;`
- Avoid Functions on the Left Hand-Side of the Operator
    - Bad: `SELECT nickname FROM users WHERE DATEDIFF(MONTH, appointment_date, '2015-04-28') < 0;`, instead
    - Good: `SELECT nickname FROM users WHERE appointment_date > '2016-04-30';`
- Consider Getting Rid of Correlated Subqueries
    - A correlated subquery is a subquery which depends on the outer query
    - It uses the data obtained from the outer query in its WHERE clause
- Avoid Wildcard Characters at the Beginning of a LIKE Pattern
    - Avoid this `SELECT * FROM users WHERE name LIKE '%bar%';`

## MySQL vs MongoDB

MySQL is a popular open-source relational database management system (RDBMS) that is developed, distributed and supported by Oracle Corporation. Like other relational systems, MySQL stores data in tables and uses structured query language (SQL) for database access. In MySQL, you pre-define your database schema based on your requirements and set up rules to govern the relationships between fields in your tables. In MySQL, related information may be stored in separate tables, but associated through the use of joins. In this way, data duplication is minimized.

MongoDB is an open-source database developed by MongoDB, Inc. MongoDB stores data in JSON-like documents that can vary in structure. Related information is stored together for fast query access through the MongoDB query language. MongoDB uses dynamic schemas, meaning that you can create records without first defining the structure, such as the fields or the types of their values. You can change the structure of records (which we call documents) simply by adding new fields or deleting existing ones. This data model give you the ability to represent hierarchical relationships, to store arrays, and other more complex structures easily. Documents in a collection need not have an identical set of fields and denormalization of data is common. MongoDB was also designed with high availability and scalability in mind, and includes out-of-the-box replication and auto-sharding.

MySQL | MongoDB
--- | ---
Table | Collection
Row | Document
Column | Field
Joins | Embedded documents, linking



### Resources

- [Download MySQL Community Server](https://dev.mysql.com/downloads/mysql/)
- [MySQL Downloads](https://www.mysql.com/downloads/)
