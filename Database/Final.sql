-- Drop the existing database if it exists
DROP DATABASE IF EXISTS finalexam;

-- Create a new database called 'company'
CREATE DATABASE finalexam;

-- Use the newly created database
USE finalexam;

-- ------------------------------------------------------------------------------------------------
-- PART 4a: Write the SQL code to create the four tables (Customers, Orders, Products, Payments) --
-- ------------------------------------------------------------------------------------------------

-- Create the Customers table
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    Name VARCHAR(50),
    Email VARCHAR(50),
    City VARCHAR(50)
);

-- Create the Orders table
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY, 		-- Primary Key
    CustomerID INT,			-- Foreign Key    
    Product VARCHAR(50),                                
    Quantity INT,
    Price VARCHAR(50),
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

-- Create the Products table
CREATE TABLE Products (
    ProductID INT PRIMARY KEY,		-- Primary Key                
    ProductName VARCHAR(50),                                    
    Category VARCHAR(50)                                
);

-- Create the Payments table
CREATE TABLE Payments (
    PaymentID INT PRIMARY KEY,		-- Primary Key
    OrderID INT,					-- Foreign Key                                    
    PaymentMethod VARCHAR(50),
    Amount VARCHAR(50),
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID)
);

-- --------------------------------------------------------------------------
-- PART 4b: Write the SQL code to populate the tables with the given data. --
-- --------------------------------------------------------------------------

-- Insert data into the Customers table
INSERT INTO Customers (CustomerID, Name, Email, City) VALUES
(101, 'Alice Johnson', 'alice@example.com', 'New York'),
(102, 'Bob Smith', 'bobsmith@example.com', 'Los Angeles'),
(103, 'Carol Adams', 'carol.adams@example.com', 'Chicago');

-- Insert data into the Orders table
INSERT INTO Orders (OrderID, CustomerID, Product, Quantity, Price) VALUES
(201, 101, 'Laptop', 1, '1200.00'),
(202, 102, 'Smartphone', 2, '800.00'),
(203, 103, 'Tablet', 1, '400.00'),
(204, 101, 'Headphones', 3, '150.00'),
(205, 102, 'Keyboard', 1, '100.00');

-- Insert data into the Products table
INSERT INTO Products (ProductID, ProductName, Category) VALUES
(1, 'Laptop', 'Electronics'),
(2, 'Smartphone', 'Electronics'),
(3, 'Tablet', 'Electronics'),
(4, 'Headphones', 'Accessories'),
(5, 'Keyboard', 'Accessories');

-- Insert data into the Payments table
INSERT INTO Payments (PaymentID, OrderID, PaymentMethod, Amount) VALUES
(1001, 201, 'Credit Card', '1200.00'),
(1002, 202, 'PayPal', '1600.00'),
(1003, 203, 'Credit Card', '400.00'),
(1004, 204, 'Debit Card', '450.00'),
(1005, 205, 'Credit Card', '100.00');

-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- PART 4c: Write the SQL code to retrieve the total amount spent by each customer, along with their name and email, for all orders they have made. --
-- ---------------------------------------------------------------------------------------------------------------------------------------------------

SELECT c.Name, c.Email, SUM(p.Amount) AS Total
FROM Customers c
JOIN Orders o ON c.CustomerID = o.CustomerID
JOIN Payments p ON o.OrderID = p.OrderID
GROUP BY c.CustomerID, c.Name, c.Email;

-- c = customers
-- o = orders
-- p = product