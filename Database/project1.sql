-- Drop the existing database if it exists
DROP DATABASE IF EXISTS socialmedia;
-- Create a new database called 'company'
CREATE DATABASE socialmedia;
-- Use the newly created database
USE socialmedia;
-- Create the Profile table
CREATE TABLE profile (
    UserID INT,
    Username VARCHAR(50) PRIMARY KEY,
    -- Primary Key
    Email VARCHAR(50),
    Password VARCHAR(50),
    Location VARCHAR(50),
    Privacy VARCHAR(50)
);
-- Create the Posts table
CREATE TABLE posts (
    Media VARCHAR(50),
    PostID VARCHAR(50) PRIMARY KEY,
    -- Primary Key
    Username VARCHAR(50),
    -- Foreign Key
    Timestamp VARCHAR(50),
    Location VARCHAR(50),
    Visibility VARCHAR(50),
    LikeCount INT,
    FOREIGN KEY (Username) REFERENCES profile(Username)
);
-- Create the Engagements table for LIKES
CREATE TABLE likes (
    LikeID VARCHAR(50) PRIMARY KEY,
    -- Primary Key
    PostID VARCHAR(50),
    -- Foregin Key
    Username VARCHAR(50),
    -- Foreign Key
    Timestamp VARCHAR(50),
    FOREIGN KEY (PostID) REFERENCES posts(PostID),
    FOREIGN KEY (Username) REFERENCES profile(Username)
);
-- Create the Engagements table for COMMENTS
CREATE TABLE comments (
    CommentID VARCHAR(50) PRIMARY KEY,
    -- Primary Key
    PostID VARCHAR(50),
    -- Foreign Key
    Username VARCHAR(50),
    -- Foreign Key
    CommentText VARCHAR(150),
    Timestamp VARCHAR(50),
    FOREIGN KEY (PostID) REFERENCES posts(PostID),
    FOREIGN KEY (Username) REFERENCES profile(Username)
);
-- Create the Friendship table
CREATE TABLE friendship (
    FriendshipID VARCHAR(50) PRIMARY KEY,
    -- Primary Key
    Username_S VARCHAR(50),
    -- Foreign Key (Sender)
    Username_R VARCHAR(50),
    -- Foreign Key (Receiver)
    RequestStatus VARCHAR(50),
    Status VARCHAR(50),
    FOREIGN KEY (Username_S) REFERENCES profile(Username),
    FOREIGN KEY (Username_R) REFERENCES profile(Username)
);
CREATE TABLE messages (
    MessageID VARCHAR(50) PRIMARY KEY,
    -- Primary Key
    Username_S VARCHAR(50),
    -- Foreign Key (Sender)
    Username_R VARCHAR(50),
    -- Foreign Key (Reciever)
    MessageText VARCHAR(500),
    Timestamp VARCHAR(50),
    Status VARCHAR(50),
    -- Read/Unread
    FOREIGN KEY (Username_S) REFERENCES profile(Username),
    FOREIGN KEY (Username_R) REFERENCES profile(Username)
);
-- Create the Notifications table
CREATE TABLE notis (
    NotiID VARCHAR(50) PRIMARY KEY,
    -- Primary Key
    Username VARCHAR(50),
    -- Foreign Key
    NotiType VARCHAR(50),
    Timestamp VARCHAR(50),
    FOREIGN KEY(Username) REFERENCES Profile(Username)
);
-- GROUP CHAT STUFF
CREATE TABLE gc (
    GroupID VARCHAR(50) PRIMARY KEY,
    GroupName VARCHAR(50),
    Privacy VARCHAR(50)
);
CREATE TABLE gcMembers (
    UserID INT,
    GroupID VARCHAR(50),
    Role VARCHAR(50)
);
-- Insert data into the Profile table
INSERT INTO PROFILE (
        UserID,
        Username,
        Email,
        Password,
        Location,
        Privacy
    )
VALUES (
        '1',
        'Billy Jones',
        'billyjones@gmail.com',
        'ithurtlikeabill',
        'New York',
        'Private'
    ),
    (
        '2',
        'Carl Jr',
        'carljr@gmail.com',
        'carolknowsitall',
        'Chicago',
        'Private'
    ),
    (
        '3',
        'Stewy',
        'stwey10@gmail.com',
        'connorstewy',
        'Pennsylvania',
        'Public'
    ),
    (
        '4',
        'Bob',
        'bob123@gmail.com',
        'bibilybob123',
        'New York',
        'Public'
    ),
    (
        '5',
        'Nick',
        'nick231@gmail.com',
        'nickelpickle',
        'New York',
        'Public'
    );
-- Insert data into the Posts table
INSERT INTO POSTS (
        Media,
        PostID,
        Username,
        Timestamp,
        Location,
        Visibility,
        LikeCount
    )
VALUES (
        'Image',
        'P-01',
        'Carl Jr',
        '5:20 PM',
        'Chicago',
        'Public',
        2
    ),
    (
        'Video',
        'P-02',
        'Nick',
        '2:23 PM',
        'New York',
        'Friends Only',
        1
    ),
    (
        'Image',
        'P-03',
        'Billy Jones',
        '9:43 PM',
        'New York',
        'Public',
        1
    ),
    (
        'Image',
        'P-04',
        'Stewy',
        '10:15 AM',
        'Pennsylvania',
        'Private',
        1
    ),
    (
        'Video',
        'P-05',
        'Carl Jr',
        '3:09 AM',
        'Chicago',
        'Private',
        0
    );
-- Insert data into the Engagements - LIKES table
INSERT INTO LIKES (LikeID, PostID, Username, Timestamp)
VALUES ('L-01', 'P-01', 'Billy Jones', '5:43 PM'),
    ('L-02', 'P-02', 'Stewy', '3:39 PM'),
    ('L-03', 'P-01', 'Nick', '11:21 PM'),
    ('L-04', 'P-03', 'Carl Jr', '9:44 AM'),
    ('L-05', 'P-04', 'Billy Jones', '7:20 PM');
-- Insert data into the Engagements - COMMENTS table
INSERT INTO COMMENTS (
        CommentID,
        PostID,
        Username,
        CommentText,
        Timestamp
    )
VALUES (
        'C-01',
        'P-01',
        'Billy Jones',
        '"Wow, that’s incredible!”',
        '5:44 PM'
    ),
    (
        'C-02',
        'P-02',
        'Stewy',
        '“Loving the vibe here!”',
        '3:40 PM'
    ),
    (
        'C-03',
        'P-01',
        'Nick',
        '“I cant stop laughing”',
        '11:22 PM'
    ),
    (
        'C-04',
        'P-03',
        'Carl Jr',
        '“This is awesome!“',
        '9:45 AM'
    ),
    (
        'C-05',
        'P-04',
        'Billy Jones',
        '“I need this right now!”',
        '7:21 PM'
    );
-- Insert data into the FRIENDSHIP
INSERT INTO FRIENDSHIP (
        FriendshipID,
        Username_S,
        Username_R,
        RequestStatus,
        Status
    )
VALUES (
        'F-01',
        'Billy Jones',
        'Stewy',
        'Send',
        'Pending'
    ),
    ('F-02', 'Carl Jr', 'Bob', 'Send', 'Accepted'),
    -- Carl JR & Bob are friends
    (
        'F-03',
        'Stewy',
        'Billy Jones',
        'Send',
        'Blocked'
    ),
    ('F-04', 'Bob', 'Carl Jr', 'Send', 'Pending'),
    ('F-05', 'Nick', 'Carl Jr', 'Send', 'Accepted');
-- Nick & Carl Jr are friends
-- Insert data into the MESSAGES table
INSERT INTO MESSAGES (
        MessageID,
        Username_S,
        Username_R,
        MessageText,
        Timestamp,
        Status
    )
VALUES (
        'M-01',
        'Billy Jones',
        'Nick',
        'Yo, we need to hang soon!',
        '1:26 PM',
        'Read'
    ),
    (
        'M-02',
        'Stewy',
        'Carl Jr',
        'Heyyy, how is it going?',
        '7:15 PM',
        'Read'
    ),
    (
        'M-03',
        'Bob',
        'Billy Jones',
        'Hope you are having an amazing day!',
        '3:53 PM',
        'Unread'
    ),
    (
        'M-04',
        'Carl Jr',
        'Stewy',
        'If you could travel anywhere right now, where would you go?',
        '12:15 AM',
        'Read'
    ),
    (
        'M-05',
        'Nick',
        'Bob',
        'This made my day',
        '4:20 PM',
        'Unread'
    );
-- Insert data into the NOTIFICATIONS table
INSERT INTO NOTIS (NotiID, Username, NotiType, Timestamp)
VALUES ('N-01', 'Billy Jones', 'Message', '11:51 AM'),
    ('N-02', 'Carl Jr', 'Friend Request', '5:50 PM'),
    ('N-03', 'Stewy', 'Like', '1:43 PM'),
    ('N-04', 'Bob', 'Message', '8:06 AM'),
    ('N-05', 'Nick', 'Comment', '2:00 PM');
-- Insert data into the GROUP CHAT table
INSERT INTO GC (GroupID, GroupName, Privacy)
VALUES ('G-01', 'CSCI 435', 'Public'),
    ('G-02', 'The Triplets', 'Private'),
    ('G-03', 'Dudes doing dude stuff', 'Private'),
    ('G-04', 'dink', 'Public'),
    ('G-05', 'boop', 'Public');
-- Insert data into the GROUP CHAT (MEMBERS) table
INSERT INTO GCMEMBERS (UserID, GroupID, Role)
VALUES (1, 'G-02', 'Admin'),
    (2, 'G-02', 'Member'),
    (3, 'G-04', 'Admin'),
    (4, 'G-01', 'Admin'),
    (5, 'G-03', 'Admin');
-- Querying
-- Query 1: Retrieve profile information for a specific user by username. (* = select all)
SELECT *
FROM profile
WHERE Username = 'Carl Jr';
-- Query 2: List all posts created by a particular user. ( * = select all)
SELECT *
FROM posts
WHERE Username = 'Nick';
-- Query 3: Get all comments on a specific post.
SELECT CommentText
FROM comments
WHERE PostID = 'P-01';
-- Query 4: Count the number of likes on a particular post.
SELECT LikeCount
FROM posts
WHERE PostID = 'P-01';
-- Query 5: List all friends of a specific user. (p = profile, f = friendships)
SELECT p.Username
FROM profile p
    JOIN friendship f ON p.Username = f.Username_S
    OR p.Username = f.Username_R
WHERE (
        f.Username_S = 'Carl JR'
        OR f.Username_R = 'Carl JR'
    )
    AND p.Username != 'Carl JR'
    AND f.Status = 'Accepted';
-- Query 6. Find all unread messages for a user.
SELECT Username_S,
    MessageText,
    Timestamp
FROM messages
WHERE Username_R = 'Bob'
    AND Status = 'Unread';
-- Query 7: Retrieve all notifications for a user.
SELECT NotiType
FROM notis
WHERE Username = 'Bob';
-- Query 8: List all members of a particular group. (gcM = groupMembers, p = profile)
SELECT p.Username
FROM profile p
    JOIN gcMembers gcM ON p.UserID = gcM.UserID -- UserID from profiles & gcMembers are LINKED, essentially merging the two tables
WHERE gcM.GroupID = 'G-01';
-- Query 9: Find the most popular posts with a certain minimum number of likes. (* = select all)
SELECT *
FROM posts
WHERE LikeCount >= 1;
-- Query 10. Retrieve all posts tagged with a specific location.
SELECT PostID,
    Username,
    Media
FROM posts
WHERE Location = 'Pennsylvania';