-- Drop the existing database if it exists
DROP DATABASE IF EXISTS school;
-- Create a new database called 'company'
CREATE DATABASE school;
-- Use the newly created database
USE school;
-- Create the STUDENT table
CREATE TABLE student (
	Name VARCHAR(50),
	Student_Number INT PRIMARY KEY,
	-- Primary Key
	Class INT,
	Major VARCHAR(50)
);
-- Create the COURSE table
CREATE TABLE course (
	Course_Name VARCHAR(50),
	Course_Number VARCHAR(50) PRIMARY KEY,
	-- Primary Key
	Credit_Hours INT,
	Department VARCHAR(50)
);
-- Create the SECTION table
CREATE TABLE section (
	Section_Identifier INT PRIMARY KEY,
	-- Primary Key
	Course_Number VARCHAR(50),
	-- Foreign Key
	Semester VARCHAR(50),
	Year INT,
	Instructor VARCHAR(50),
	FOREIGN KEY (Course_Number) REFERENCES course(Course_Number)
);
-- Create the GRADE_REPORT table
CREATE TABLE grade_report (
	Student_Number INT,
	-- Foreign Key
	Section_Identifier INT,
	-- Foreign Key
	Grade VARCHAR(50),
	FOREIGN KEY (Student_Number) REFERENCES STUDENT(Student_Number),
	FOREIGN KEY (Section_Identifier) REFERENCES SECTION(Section_Identifier)
);
-- Create the PREREQUISITE table
CREATE TABLE prerequisite (
	Course_Number VARCHAR(50),
	-- Foreign Key
	Prerequisite_Number VARCHAR(50),
	FOREIGN KEY (Course_Number) REFERENCES COURSE(Course_Number)
);
-- Insert data into the student table
INSERT INTO STUDENT (Name, Student_Number, Class, Major)
VALUES ('Smith', 17, 1, 'CS'),
	('Brown', 8, 2, 'CS');
-- Insert data into the course table
INSERT INTO COURSE (
		Course_Name,
		Course_Number,
		Credit_Hours,
		Department
	)
VALUES ('Intro to Computer Science', 'CS1310', 4, 'CS'),
	('Data Structures', 'CS3320', 4, 'CS'),
	('Discrete Mathematics', 'MATH2410', 3, 'MATH'),
	('Database', 'CS3380', 3, 'CS');
-- Insert data into the section table
INSERT INTO SECTION(
		Section_Identifier,
		Course_Number,
		Semester,
		Year,
		Instructor
	)
VALUES (85, 'MATH2410', 'Fall', 07, 'King'),
	(92, 'CS1310', 'Fall', 07, 'Anderson'),
	(102, 'CS3320', 'Spring', 08, 'Knuth'),
	(112, 'MATH2410', 'Fall', 08, 'Chang'),
	(119, 'CS1310', 'Fall', 08, 'Anderson'),
	(135, 'CS3380', 'Fall', 08, 'Stone');
-- Insert data into the GRADE table
INSERT INTO GRADE_REPORT (Student_Number, Section_Identifier, Grade)
VALUES (17, 112, 'B'),
	(17, 119, 'C'),
	(8, 85, 'A'),
	(8, 92, 'A'),
	(8, 102, 'B'),
	(8, 135, 'A');
-- Insert data into the PREREQUISITE table
INSERT INTO PREREQUISITE (Course_Number, Prerequisite_Number)
VALUES ('CS3380', 'CS3320'),
	('CS3380', 'MATH2410'),
	('CS3320', 'CS1310');
-- Querying
-- Query 1: Retrieve the names of all students who are enrolled in the course ’Intro to Computer Science’. (s = student, gr = grade report, sec = section, c = course)
SELECT s.Name
FROM student s
	JOIN grade_report gr ON s.Student_Number = gr.Student_Number
	JOIN section sec ON gr.Section_Identifier = sec.Section_Identifier
	JOIN course c ON sec.Course_Number = c.Course_Number
WHERE c.Course_Name = 'Intro to Computer Science';
-- Query 2: Find the names of students who have received a grade of ’A’ in any course ( s = student, gr = grade report)
SELECT s.Name
FROM student s
	JOIN grade_report gr ON s.Student_Number = gr.Student_Number
WHERE gr.Grade = 'A';
-- Query 3: List all the courses offered by the CS department. (c = course)
SELECT c.Course_name
FROM course c
WHERE c.Department = 'CS';
-- Query 4: Display the grade report for student number 8. (c = course,, gr = grade report, sec = section)
SELECT gr.Student_Number,
	sec.Course_Number,
	c.Course_Name,
	gr.Grade
FROM grade_report gr
	JOIN section sec ON gr.Section_Identifier = sec.Section_Identifier
	JOIN course c ON sec.Course_Number = c.Course_Number
WHERE gr.Student_Number = 8;
-- Query 5: Retrieve the prerequisite courses for ’Database’ - CS3380 (preq = prerequisite)
SELECT c.Course_Number,
	c.Course_Name
FROM PREREQUISITE p
	JOIN COURSE c on p.Prerequisite_Number = c.Course_Number
WHERE p.Course_Number = 'CS3380';