### 数据库系统-第一次作业

- 1.7 List four significant differences between a file-process system and a DBMS
  - DBMS can coordinate both physical and logical access of data, however a file-processing system can only coordinate physical access
  - DBMS can ensure data written is readable to all program avoiding duplication, but a file-processing system can't ensure that
  - DBMS provide a flexible access to data, yet a file-processing system with compiled programs has ony pre-determined ways of access
  - DBMS allow concurrently access by multiple users, but file-processing system can only allow 2 programs access data with read-only method 

- 1.8 Explain the concept of physical data independence, and its importance in database systems
  - Physical Data Independence is the ability to modify the physical schema without changing the logical schema
  - Importance:applications depend on the logical schema and don't care how data is structed and stored,so the modifications to physical schema is hidden from application's view

- 1.15 Describe at least 3 tables that might be used to store information in a social-networking system such as Facebook
  - *user* table stores the relation between ID, nickname and other personal infomation
  - *post* table stores the relation between ID and post_id
  - *Follow* table stores the relation between ID and ID(follower) 
