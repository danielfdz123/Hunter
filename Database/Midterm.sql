-- Drop the existing database if it exists
DROP DATABASE IF EXISTS company;

-- Create a new database called 'company'
CREATE DATABASE company;

-- Use the newly created database
USE company;

-- Create the PRODUCT table
CREATE TABLE Product  (
    ProductID INT PRIMARY KEY,       -- Primary key
    Name VARCHAR(50),
    Price INT,
    Description VARCHAR(50)
);

-- Create the CUSTOMER table
CREATE TABLE Customer (
    CustomerID INT PRIMARY KEY,       -- Primary key
    Name VARCHAR(50),
    Email VARCHAR(50),
    ShippingAddress VARCHAR(50),
    PaymentMethod VARCHAR(50)
);

-- Create the ORDER table
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,       -- Primary key
    OrderDate VARCHAR(50),
    TotalAmount INT,
    ShippingStatus VARCHAR(50),
    CustomerID INT,   				 -- Foreign Key (References Customer Table)
    NumberOfItems INT,
    ProductID INT,      			-- Foreign KEY (References Product Table)
    FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID),
    FOREIGN KEY (ProductID) REFERENCES Product(ProductID)
);

-- Insert data into the ORDER table
INSERT INTO Product (ProductID, Name, Price, Description) VALUES
(100, 'ItemA', '10', 'Good'),
(101, 'ItemB', '20', 'Very Good'),
(102, 'ItemC', '100', 'Super Good');

INSERT INTO Customer (CustomerID, Name, Email, ShippingAddress, PaymentMethod) VALUES
(01, 'Bob', 'b123@aol.com', '123 Main St', 'Debit'),
(02, 'Gabe', 'gabe@gmail.com', '68 Lexington Ave', 'Debit'),
(03, 'Rachel', 'rae@yahoo.com', '100 Broadway', 'Debit');

INSERT INTO Orders (OrderID, OrderDate, TotalAmount, ShippingStatus, CustomerID, NumberOfItems, ProductID) VALUES
(1200, '10/1/2024', 10, 'Recieved', 01, 1, 100),
(1300, '10/9/2024', '50', 'Shipped', 02, 5, 100),
(1400, '10/30/2024', 100, 'Delivered', 03, 5, 102);

-- Querying
-- Query 1: Select all columns from the Product table
SELECT * FROM Product;

-- Query 2: Select only the product names and prices
SELECT Name, Price FROM Product;

-- Query 3: Retrieve all employees working in the 'Finance' department
SELECT e.Name, e.Age, d.DName 
FROM employee e
JOIN department d ON e.DNo = d.DNo
WHERE d.DName = 'Finance';

-- Query 4: Find employees whose age is greater than 30
SELECT Name, Age FROM employee
WHERE Age > 30;

-- Query 5: Retrieve the department name and location where 'Harry' works
SELECT d.DName, d.Location 
FROM employee e
JOIN department d ON e.DNo = d.DNo
WHERE e.Name = 'Harry';

-- Perform some update operations that violate constraints

-- Entity Integrity Violation (inserting a null value into EmpID which is a primary key)
INSERT INTO employee (EmpID, Name, Age, Phone, DNo) VALUES
(NULL, 'Jessica', 28, '659874123', 2);

-- Referential Integrity Violation (inserting a DNo that doesn't exist in the department table)
INSERT INTO employee (EmpID, Name, Age, Phone, DNo) VALUES
(1333, 'John', 40, '658745213', 10);

-- Domain Integrity Violation (inserting an invalid age value that violates domain constraints)
INSERT INTO employee (EmpID, Name, Age, Phone, DNo) VALUES
(1334, 'Peter', -5, '652145698', 1);

-- Query the tables again to see the violations
SELECT * FROM employee;
SELECT * FROM department;