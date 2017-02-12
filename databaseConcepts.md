Database Concepts
=================

Indexes
-------
- Primary mechanism to get improved performance on a database
- Persistent data structure, stored in database. Underlying data structures:
    - Balanced trees (B trees, B+ trees)
    - Hash tables
- Many DBMS's build indexes automatically on PRIMARY KEY (and sometimes UNIQUE) attributes
- SQL Syntax
    - Create Index IndexName on Table(Attribute)
    - Create Index IndexName on T(A1, A2, ..., An)
    - Drop Index IndexName

#### Downsides of Indexes
- **Extra space**: marginal downside
- **Index creation**: medium downside
- **Index maintenance**: can offset benefits

#### Picking which indexes to create
- Benefit of an index depends on:
    - Size of table (and possibly layout)
    - Data distributions
    - Query vs. update load

Transactions
------------
- A transaction is a sequence of one or more SQL operations treated as a unit
- Transactions appear to run in isolation
- If the system fails, each transaction's changes are reflected either entirely or not at all
- Motivated by two independent requirements:
    - Concurrent database access
    - Resilience to system failures
- ACID: Atomicity, Consistency, Isolation, Durability

Constraints
-----------
- Constraints constrain allowable database states
- Integrity Constraints
    - Impose restrictions on allowable data, beyond those imposed by structure and types
    - 0.0 < GPA <= 4.0, for example
    - Types:
        - Non-null constraints
        - Key constraints
        - Attribute-based and tuple-based constraints
        - General assertions
- Why use them?
    - Data entry errors
    - Correctness criteria
    - Enforce consistency
    - Tell system about data
- Referential Integrity (or Foreign Key Constraints)
    - Integrity of references or No "dangling pointers"
    - Referencing attribute is called foreign key
    - Referenced attribute must be a primary key or at least unique
    - Multi-attribute foreign keys are allowed

Triggers
--------
- Triggers monitor database changes, check conditions and initiate actions
- enrollment > 35,000 => reject all applicants, for example
- Why use them?
    - Move logic from apps into DBMS
    - To enforce constraints

Views
-----
- Why use views?
    - Hide some data from some users
    - Make some queries easier / more natural
    - Modularity of database access

Stored Procedures
-----------------
- Collection of MySQL statements that can be run all together
- Some benefits include:
    - **Maintainability**: you can change the logic in the procedure without needing to edit app1, app2 and app3 calls.
    - **Security/Access Control**: it's easier to worry about who can call a predefined procedure than it is to control who can access which tables or which table rows.
    - **Performance**: if your app is not situated on the same server as your DB, and what you're doing involves multiple queries, using a procedure reduces the network overhead by involving a single call to the database, rather than as many calls as there are queries.
    - **Performance**: stored procedures are compiled once and stored in executable form, so procedure calls are quick and efficient. Executable code is automatically cached and shared among users. This lowers memory requirements and invocation overhead. 
