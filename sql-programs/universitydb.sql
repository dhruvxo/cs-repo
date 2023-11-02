SHOW DATABASES;
CREATE DATABASE IF NOT EXISTS Fest_Database;
USE Fest_Database;

CREATE TABLE fest(
	fest_id VARCHAR(5),
	fest_name VARCHAR(25) UNIQUE NOT NULL,
	year YEAR,
	head_teamID VARCHAR(5) UNIQUE,
	PRIMARY KEY (fest_id)
	);
-- DESC fest;

CREATE TABLE team(
	team_id VARCHAR(5),
	team_name VARCHAR(25) NOT NULL,
	team_type ENUM('MNG','ORG') DEFAULT 'ORG',
	fest_id VARCHAR(5),
	PRIMARY KEY (team_id),
	FOREIGN KEY (fest_id) REFERENCES fest(fest_id)
	);
-- DESC team;

ALTER TABLE fest ADD CONSTRAINT fest_head_name FOREIGN KEY(head_teamID) REFERENCES team(team_id);
-- DESC fest;

CREATE TABLE member(
	mem_id VARCHAR(5),
	mem_name VARCHAR(25) NOT NULL,
	DOB DATE,
	super_memID VARCHAR(5),
	team_id VARCHAR(5),
	PRIMARY KEY (mem_id),
	FOREIGN KEY (super_memID) REFERENCES member(mem_id),
	FOREIGN KEY (team_id) REFERENCES team(team_id)
	);
-- DESC member;

CREATE TABLE event(
	event_id VARCHAR(5),
	event_name VARCHAR(25) NOT NULL,
	building VARCHAR(15),
	floor VARCHAR(10),
	room_no INT,
	price DECIMAL(10,2),
	team_id VARCHAR(5),
	PRIMARY KEY (event_id),
	CHECK (price <= 1500.00),
	FOREIGN KEY (team_id) REFERENCES team(team_id) ON DELETE CASCADE
	);
-- DESC event;
-- SHOW CREATE TABLE event;

CREATE TABLE event_conduction(
	event_id VARCHAR(5),
	date_of_conduction DATE,
	PRIMARY KEY(event_id,date_of_conduction),
	FOREIGN KEY (event_id) REFERENCES event(event_id)
	);
-- DESC event_conduction;

CREATE TABLE participant(
	SRN VARCHAR(10),
	name VARCHAR(25) NOT NULL,
	department VARCHAR(20),
	semester INT,
	gender ENUM('Male','Female'),
	PRIMARY KEY (SRN)
	);
-- DESC participant;

CREATE TABLE visitor(
	SRN VARCHAR(10),
	name VARCHAR(25),
	age INT,
	gender ENUM('Male','Female'),
	PRIMARY KEY (SRN,name),
	FOREIGN KEY (SRN) REFERENCES participant(SRN)
	);
-- DESC visitor;

CREATE TABLE registration(
	event_id VARCHAR(5),
	SRN VARCHAR(10),
	registration_id VARCHAR(5) NOT NULL,
	PRIMARY KEY (event_id,SRN),
	FOREIGN KEY (event_id) REFERENCES event(event_id),
	FOREIGN KEY (SRN) REFERENCES participant(SRN)
	);
-- DESC registration;

CREATE TABLE stall(
	stall_id VARCHAR(5),
	name VARCHAR(25) UNIQUE NOT NULL,
	fest_id VARCHAR(5),
	PRIMARY KEY (stall_id),
	FOREIGN KEY (fest_id) REFERENCES fest(fest_id)
	);
-- DESC stall;

CREATE TABLE item(
	name VARCHAR(25),
	type ENUM('Veg','Non-Veg'),
	PRIMARY KEY (name)
	);
-- DESC item;

CREATE TABLE stall_items(
	stall_id VARCHAR(5),
	item_name VARCHAR(25),
	price_per_unit DECIMAL(10,2),
	total_quantity INT,
	PRIMARY KEY (stall_id,item_name),
	FOREIGN KEY (stall_id) REFERENCES stall(stall_id),
	FOREIGN KEY (item_name) REFERENCES item(name)
	);
-- DESC stall_items;

CREATE TABLE purchased(
	SRN VARCHAR(10),
	stall_id VARCHAR(5),
	item_name VARCHAR(25),
	timestamp TIMESTAMP,
	quantity INT,
	PRIMARY KEY (SRN,stall_id,item_name,timestamp),
	FOREIGN KEY (SRN) REFERENCES participant(SRN),
	FOREIGN KEY (stall_id) REFERENCES stall(stall_id),
	FOREIGN KEY (item_name) REFERENCES item(name)
	);
-- DESC purchased;

-- INSERTION STATEMENTS

USE Fest_database;

-- inserting values into Fest table
INSERT INTO fest(fest_id, fest_name, year) VALUES('F101', "Atmatrisha", 2023),
												('F102', "Samarpana", 2022),
												('F201', "Graduation", 2022),
												('F202', "Annual day", 2021);

-- inserting values into Teams table
INSERT INTO team VALUES('T1', "Leads", "MNG", 'F101'),
						('T2', "logistics_atm", "MNG", 'F101'),
						('T3', "Crazy hunters", "ORG", 'F101'),
						('T4', "Techno", "ORG", 'F101'),
						('T5', "The Heads", "MNG", 'F102'),
						('T6', "Eutopians", "ORG", 'F102'),
						('T7', "Managers", "MNG", 'F102'),
						('T8', "Cultural", "ORG", 'F102'),
						('T9', "Tech buzzers", "ORG", 'F102'),
						('T10', "Grad_head", "MNG", 'F201'),
						('T11', "Arts", "MNG", 'F201'),
						('T12', "Conduction", "ORG",'F201'),
						('T13', "Fest Heads", "MNG", 'F202'),
						('T14', "Cul team", "ORG", 'F202'),
						('T15', "Dystopia", "ORG", 'F202');

-- adding the head teams into the fest table
UPDATE fest SET head_teamID = CASE WHEN fest_id = 'F101' THEN 'T1'
								   WHEN fest_id = 'F102' THEN 'T5'
                                   WHEN fest_id = 'F201' THEN 'T10'
                                   WHEN fest_id = 'F202' THEN 'T13'
                                   END;


-- adding values into Members
INSERT INTO member (mem_id, mem_name, DOB, super_memID, team_id)
VALUES
  ('M1', 'John Doe', '1995-05-10', NULL, 'T1'),
  ('M2', 'Alice Smith', '1996-08-15', 'M1', 'T1'),
  ('M3', 'Michael Johnson', '1997-11-20', 'M1', 'T1'),
  ('M4', 'Emily Davis', '1998-03-25', 'M1', 'T1'),
  ('M5', 'Robert Wilson', '1994-07-05', 'M1', 'T1'),
  ('M7', 'Christopher Brown', '1996-01-18', NULL, 'T2'),
  ('M6', 'Sarah Thompson', '1995-10-12', 'M7', 'T2'),
  ('M8', 'Jessica Anderson', '1997-04-24', 'M7', 'T2'),
  ('M9', 'David Anderson', '1994-04-12', 'M8', 'T2'),
  ('M10', 'Jessica Brown', '1995-07-18', 'M8', 'T2'),
  ('M11', 'Christopher Wilson', '1996-10-22', NULL, 'T3'),
  ('M12', 'Sophia Taylor', '1997-01-30', 'M11', 'T3'),
  ('M13', 'William Moore', '1993-06-08', 'M11', 'T3'),
  ('M14', 'Olivia Clark', '1994-09-14', 'M11', 'T3'),
  ('M15', 'Andrew Lee', '1995-12-20', 'M14', 'T3'),
  ('M16', 'Emma Martinez', '1996-03-28', 'M11', 'T3'),
  ('M17', 'Matthew Harris', '1994-02-05', 'M14', 'T3'),
  ('M18', 'Olivia Adams', '1995-05-11', 'M14', 'T3'),
  ('M22', 'Daniel Clark', '1996-08-16', NULL, 'T4'),
  ('M20', 'Sophia Hall', '1997-11-21', 'M22', 'T4'),
  ('M21', 'Michael Turner', '1993-10-02', 'M22', 'T4'),
  ('M19', 'Emily Walker', '1994-12-08', 'M21', 'T4'),
  ('M23', 'Jacob Lewis', '1996-03-15', 'M21', 'T4'),
  ('M24', 'Mia Rodriguez', '1997-06-21', 'M22', 'T4'),
  ('M25', 'Daniel Robinson', '1993-09-01', 'M23', 'T4'),
  ('M26', 'Ava Walker', '1994-12-06', 'M23', 'T4'),
  ('M27', 'William Turner', '1995-03-13', NULL, 'T5'),
  ('M28', 'Sophia Williams', '1996-06-19', 'M27', 'T5'),
  ('M29', 'Jacob Anderson', '1997-09-25', 'M27', 'T5'),
  ('M30', 'Olivia Moore', '1998-12-31', 'M29', 'T5'),
  ('M31', 'Ethan Thompson', '1994-02-07', 'M29', 'T5'),
  ('M32', 'Emily Clark', '1995-05-14', NULL, 'T6'),
  ('M33', 'Jacob Lewis', '1996-08-20', 'M32', 'T6'),
  ('M34', 'Mia Rodriguez', '1997-11-26', 'M32', 'T6'),
  ('M35', 'Daniel Robinson', '1993-09-03', 'M32', 'T6'),
  ('M36', 'Ava Walker', '1994-12-09', 'M34', 'T6'),
  ('M37', 'William Turner', '1995-03-16', 'M34', 'T6'),
  ('M38', 'Sophia Williams', '1996-06-22', 'M34', 'T6'),
  ('M39', 'Jacob Anderson', '1997-09-28', 'M35', 'T6'),
  ('M44', 'Olivia Moore', '1998-01-03', NULL, 'T7'),
  ('M41', 'Ethan Thompson', '1994-02-10', 'M44', 'T7'),
  ('M42', 'Emily Clark', '1995-05-16', 'M44', 'T7'),
  ('M43', 'Jacob Lewis', '1996-08-22', 'M41', 'T7'),
  ('M40', 'Mia Rodriguez', '1997-11-28', 'M42', 'T7'),
  ('M45', 'Daniel Robinson', '1993-09-05', NULL, 'T8'),
  ('M46', 'Ava Walker', '1994-12-11', 'M45', 'T8'),
  ('M47', 'William Turner', '1995-03-18', 'M45', 'T8'),
  ('M48', 'Sophia Williams', '1996-06-24', 'M45', 'T8'),
  ('M49', 'Jacob Anderson', '1997-09-30', 'M46', 'T8'),
  ('M50', 'Olivia Moore', '1998-01-05', 'M46', 'T8'),
  ('M51', 'Ethan Thompson', '1994-02-12', 'M47', 'T8'),
  ('M52', 'Emily Clark', '1995-05-18', 'M48', 'T8'),
  ('M53', 'Jacob Lewis', '1996-08-26', NULL, 'T9'),
  ('M54', 'Mia Rodriguez', '1997-11-02', 'M53', 'T9'),
  ('M55', 'Daniel Robinson', '1993-09-07', 'M53', 'T9'),
  ('M56', 'Ava Walker', '1994-12-13', 'M54', 'T9'),
  ('M57', 'William Turner', '1995-03-20', 'M54', 'T9'),
  ('M58', 'Sophia Williams', '1996-06-26', 'M54', 'T9'),
  ('M59', 'Jacob Anderson', '1997-09-02', 'M55', 'T9'),
  ('M60', 'Olivia Moore', '1998-01-07', 'M55', 'T9'),
  ('M61', 'Emily Clark', '1995-05-20', NULL, 'T12'),
  ('M62', 'Jacob Lewis', '1996-08-28', 'M61', 'T12'),
  ('M63', 'Mia Rodriguez', '1997-11-04', 'M61', 'T12'),
  ('M64', 'Daniel Robinson', '1993-09-09', 'M62', 'T12'),
  ('M65', 'Ava Walker', '1994-12-15', 'M62', 'T12'),
  ('M66', 'William Turner', '1995-03-22', 'M63', 'T12'),
  ('M67', 'Sophia Williams', '1996-06-28', 'M63', 'T12'),
  ('M68', 'Jacob Anderson', '1997-09-04', 'M63', 'T12'),
  ('M69', 'Olivia Moore', '1998-01-09', NULL, 'T14'),
  ('M70', 'Ethan Thompson', '1994-02-14', 'M69', 'T14'),
  ('M71', 'Emily Clark', '1995-05-22', 'M69', 'T14'),
  ('M72', 'Jacob Lewis', '1996-08-30', 'M69', 'T14'),
  ('M73', 'Mia Rodriguez', '1997-11-06', 'M71', 'T14'),
  ('M74', 'Daniel Robinson', '1993-09-11', 'M71', 'T14'),
  ('M75', 'Ava Walker', '1994-12-17', 'M72', 'T14'),
  ('M76', 'William Turner', '1995-03-24', 'M72', 'T14'),
  ('M77', 'Sophia Williams', '1996-06-30', NULL, 'T15'),
  ('M78', 'Jacob Anderson', '1997-09-06', 'M77', 'T15'),
  ('M79', 'Olivia Moore', '1998-01-11', 'M77', 'T15'),
  ('M80', 'Ethan Thompson', '1994-02-16', 'M79', 'T15'),
  ('M81', 'Emily Clark', '1995-05-24', 'M79', 'T15'),
  ('M82', 'Jacob Lewis', '1996-09-02', 'M76', 'T15'),
  ('M83', 'Mia Rodriguez', '1997-11-08', 'M76', 'T15'),
  ('M84', 'Daniel Robinson', '1993-09-13', 'M76', 'T15');


-- adding into Event table
INSERT INTO event (event_id, event_name, building, floor, room_no, price, team_id)
VALUES 
  -- Team 3: Crazy hunters
  ('E1', 'Adventure Trek', 'Outdoors', '1', 101, 200.00, 'T3'),
  ('E2', 'Paintball Tournament', 'Sports Comp%ex', '2', 201, 150.00, 'T3'),
  ('E3', 'Escape Room Challenge', 'M@in Building', '1', 102, 120.00, 'T3'),
  -- Team 4: Techno
  ('E4', 'Photography Contest', '@udi%orium', '2', 202, 850.00, 'T4'),
  ('E5', 'Code Jam', '@Computer%Lab%', '1', 101, 100.00, 'T4'),
  ('E6', 'Robot Wars', 'Robotics Arena', '1', 201, 100.00, 'T4'),
  ('E7', 'Tech Expo', 'M@in Building', '2', 203, 550.00, 'T4'),
  ('E8', 'Gaming Tournament', 'Sports Comp%ex', '1', 103, 800.00, 'T4'),
  -- Team 6: Eutopians
  ('E9', 'Drama Play', '@udi%orium', '1', 102, 100.00, 'T6'),
  ('E10', 'Music Concert', 'Amphi%he@ter', '2', 202, 120.00, 'T6'),
  ('E11', 'Art Workshop', 'M@in Building', '1', 101, 150.00, 'T6'),
  ('E12', 'Film Screening', 'Theater', '2', 203, 500.00, 'T6'),
  -- Team 8: Cultural
  ('E13', 'Traditional Dance wars', '@udi%orium', '1', 102, 850.00, 'T8'),
  ('E14', 'Singing Contest', 'M@in Building', '2', 203, 500.00, 'T8'),
  ('E15', 'Fashion Exhibition', 'Sports Comp%ex', '1', 103, 120.00, 'T8'),
  ('E16', 'Poetry Slam', 'Amphi%he@ter', '2', 201, 100.00, 'T8'),
  -- Team 9: Tech buzzers
  ('E17', 'Quiz Competition', '@udi%orium', '1', 102, 100.00, 'T9'),
  ('E18', 'Tech Talk', 'Seminar Hall', '1', 101, 200.00, 'T9'),
  ('E19', 'Web Design Contest', '@Computer%Lab%', '2', 202, 890.00, 'T9'),
  ('E20', 'Hackathon', 'M@in Building', '1', 103, 650.00, 'T9'),
  -- Team 12: Conduction
  ('E21', 'Stage Setup', 'M@in Building', '2', 203, 900.00, 'T12'),
  ('E22', 'Sound and Lighting', '@udi%orium', '1', 102, 250.00, 'T12'),
  ('E23', 'Event Coordination', 'Sports Comp%ex', '1', 103, 500.00, 'T12'),
  ('E24', 'Volunteer Management', 'M@in Building', '3', 303, 600.00, 'T12'),
  -- Team 14: Cul team
  ('E25', 'Baking Competition', 'Kitchen', '1', 101, 850.00, 'T14'),
  ('E26', 'Food Tasting', 'Cafeteria', '2', 202, 500.00, 'T14'),
  ('E27', 'Cooking Workshop', 'M@in Building', '1', 102, 120.00, 'T14'),
  -- Team 15: Dystopia
  ('E29', 'Short Film Screening', 'Theater', '1', 103, 400.00, 'T15'),
  ('E30', 'Literary Debate', 'Seminar Hall', '1', 101, 550.00, 'T15'),
  ('E31', 'Writing Competition', 'Library', '2', 202, 950.00, 'T15'),
  ('E32', 'Poetry Recitation', 'Amphi%he@ter', '1', 102, 100.00, 'T15');

-- Adding values into Participants table
INSERT INTO Participant (SRN, name, department, semester, gender)
VALUES
  ('P1001', 'John Smith', 'Computer Science', 5, 'Male'),
  ('P1002', 'Emily Johnson', 'Electrical', 6, 'Female'),
  ('P1003', 'Michael Williams', 'Mechanical', 4, 'Male'),
  ('P1004', 'Sophia Brown', 'Civil', 7, 'Female'),
  ('P1005', 'Jacob Jones', 'Chemical', 5, 'Male'),
  ('P1006', 'Olivia Davis', 'Computer Science', 6, 'Female'),
  ('P1007', 'Ethan Miller', 'Electrical', 4, 'Male'),
  ('P1008', 'Ava Wilson', 'Mechanical', 7, 'Female'),
  ('P1009', 'William Taylor', 'Civil', 5, 'Male'),
  ('P1010', 'Emma Anderson', 'Chemical', 6, 'Female'),
  ('P1011', 'Liam Martinez', 'Computer Science', 5, 'Male'),
  ('P1012', 'Isabella Thompson', 'Electrical', 6, 'Female'),
  ('P1013', 'James Harris', 'Mechanical', 4, 'Male'),
  ('P1014', 'Mia Davis', 'Civil', 7, 'Female'),
  ('P1015', 'Benjamin Clark', 'Chemical', 5, 'Male'),
  ('P1016', 'Charlotte Baker', 'Computer Science', 6, 'Female'),
  ('P1017', 'Daniel Lopez', 'Electrical', 4, 'Male'),
  ('P1018', 'Amelia Turner', 'Mechanical', 7, 'Female'),
  ('P1019', 'Henry Hill', 'Civil', 5, 'Male'),
  ('P1020', 'Victoria Young', 'Chemical', 6, 'Female'),
  ('P1021', 'David Lee', 'Computer Science', 5, 'Male'),
  ('P1022', 'Sofia Green', 'Electrical', 6, 'Female'),
  ('P1023', 'Christopher Moore', 'Mechanical', 4, 'Male'),
  ('P1024', 'Scarlett Evans', 'Civil', 7, 'Female'),
  ('P1025', 'Andrew Martinez', 'Chemical', 5, 'Male');


  
-- values for registration table
INSERT INTO Registration (event_id, SRN, registration_id)
VALUES
  ('E1', 'P1001', 'R1'),
  ('E1', 'P1002', 'R2'),
  ('E1', 'P1003', 'R3'),
  ('E1', 'P1004', 'R4'),
  ('E1', 'P1005', 'R5'),
  ('E1', 'P1006', 'R1'),
  ('E1', 'P1017', 'R2'),
  ('E1', 'P1022', 'R3'),
  ('E1', 'P1025', 'R4'),
  ('E1', 'P1008', 'R5'),
  ('E2', 'P1006', 'R6'),
  ('E2', 'P1007', 'R7'),
  ('E2', 'P1008', 'R8'),
  ('E2', 'P1009', 'R9'),
  ('E2', 'P1010', 'R10'),
  ('E3', 'P1011', 'R11'),
  ('E3', 'P1012', 'R12'),
  ('E3', 'P1013', 'R13'),
  ('E3', 'P1014', 'R14'),
  ('E3', 'P1015', 'R15'),
  ('E3', 'P1001', 'R11'),
  ('E3', 'P1002', 'R12'),
  ('E3', 'P1023', 'R13'),
  ('E3', 'P1024', 'R14'),
  ('E3', 'P1025', 'R15'),
  ('E4', 'P1016', 'R16'),
  ('E4', 'P1017', 'R17'),
  ('E4', 'P1018', 'R18'),
  ('E4', 'P1019', 'R19'),
  ('E4', 'P1020', 'R20'),
  ('E5', 'P1021', 'R21'),
  ('E5', 'P1022', 'R22'),
  ('E5', 'P1023', 'R23'),
  ('E5', 'P1024', 'R24'),
  ('E5', 'P1025', 'R25'),
  ('E5', 'P1004', 'R24'),
  ('E5', 'P1005', 'R25'),
  ('E6', 'P1001', 'R26'),
  ('E6', 'P1002', 'R27'),
  ('E6', 'P1003', 'R28'),
  ('E6', 'P1004', 'R29'),
  ('E6', 'P1005', 'R30'),
  ('E7', 'P1006', 'R31'),
  ('E7', 'P1007', 'R32'),
  ('E7', 'P1008', 'R33'),
  ('E7', 'P1009', 'R34'),
  ('E7', 'P1010', 'R35'),
  ('E7', 'P1001', 'R33'),
  ('E7', 'P1002', 'R34'),
  ('E7', 'P1020', 'R35'),
  ('E8', 'P1011', 'R36'),
  ('E8', 'P1012', 'R37'),
  ('E8', 'P1013', 'R38'),
  ('E8', 'P1014', 'R39'),
  ('E8', 'P1015', 'R40'),
  ('E9', 'P1016', 'R41'),
  ('E9', 'P1017', 'R42'),
  ('E9', 'P1018', 'R43'),
  ('E9', 'P1019', 'R44'),
  ('E9', 'P1020', 'R45'),
  ('E9', 'P1024', 'R43'),
  ('E9', 'P1022', 'R44'),
  ('E9', 'P1001', 'R45'),
  ('E9', 'P1004', 'R43'),
  ('E9', 'P1005', 'R44'),
  ('E9', 'P1025', 'R45'),
  ('E10', 'P1021', 'R46'),
  ('E10', 'P1022', 'R47'),
  ('E10', 'P1023', 'R48'),
  ('E10', 'P1024', 'R49'),
  ('E10', 'P1025', 'R50'),
  ('E10', 'P1001', 'R49'),
  ('E10', 'P1005', 'R50'),
  ('E11', 'P1001', 'R51'),
  ('E11', 'P1002', 'R52'),
  ('E11', 'P1003', 'R53'),
  ('E11', 'P1004', 'R54'),
  ('E11', 'P1005', 'R55'),
  ('E11', 'P1021', 'R56'),
  ('E11', 'P1022', 'R57'),
  ('E11', 'P1023', 'R58'),
  ('E11', 'P1024', 'R59'),
  ('E11', 'P1025', 'R60'),
  ('E12', 'P1006', 'R56'),
  ('E12', 'P1007', 'R57'),
  ('E12', 'P1008', 'R58'),
  ('E12', 'P1009', 'R59'),
  ('E12', 'P1010', 'R60'),
  ('E13', 'P1011', 'R61'),
  ('E13', 'P1012', 'R62'),
  ('E13', 'P1013', 'R63'),
  ('E13', 'P1014', 'R64'),
  ('E13', 'P1015', 'R65'),
  ('E14', 'P1016', 'R66'),
  ('E14', 'P1017', 'R67'),
  ('E14', 'P1018', 'R68'),
  ('E14', 'P1019', 'R69'),
  ('E14', 'P1020', 'R70'),
  ('E15', 'P1021', 'R71'),
  ('E15', 'P1022', 'R72'),
  ('E15', 'P1023', 'R73'),
  ('E15', 'P1024', 'R74'),
  ('E15', 'P1025', 'R75'),
  ('E16', 'P1001', 'R76'),
  ('E16', 'P1002', 'R77'),
  ('E16', 'P1003', 'R78'),
  ('E16', 'P1004', 'R79'),
  ('E16', 'P1005', 'R80'),
  ('E16', 'P1021', 'R71'),
  ('E16', 'P1022', 'R72'),
  ('E16', 'P1023', 'R73'),
  ('E16', 'P1024', 'R74'),
  ('E16', 'P1025', 'R75'),
  ('E17', 'P1006', 'R81'),
  ('E17', 'P1007', 'R82'),
  ('E17', 'P1008', 'R83'),
  ('E17', 'P1009', 'R84'),
  ('E17', 'P1010', 'R85'),
  ('E17', 'P1011', 'R86'),
  ('E17', 'P1012', 'R87'),
  ('E17', 'P1013', 'R88'),
  ('E17', 'P1021', 'R89'),
  ('E17', 'P1023', 'R90'),
  ('E17', 'P1025', 'R91'),
  ('E18', 'P1011', 'R86'),
  ('E18', 'P1012', 'R87'),
  ('E18', 'P1013', 'R88'),
  ('E18', 'P1014', 'R89'),
  ('E18', 'P1015', 'R90'),
  ('E19', 'P1016', 'R91'),
  ('E19', 'P1017', 'R92'),
  ('E19', 'P1018', 'R93'),
  ('E19', 'P1019', 'R94'),
  ('E19', 'P1020', 'R95'),
  ('E20', 'P1021', 'R96'),
  ('E20', 'P1022', 'R97'),
  ('E20', 'P1023', 'R98'),
  ('E20', 'P1024', 'R99'),
  ('E20', 'P1025', 'R100'),
  ('E20', 'P1001', 'R98'),
  ('E20', 'P1004', 'R99'),
  ('E20', 'P1005', 'R100'),
  ('E21', 'P1001', 'R101'),
  ('E21', 'P1002', 'R102'),
  ('E21', 'P1003', 'R103'),
  ('E21', 'P1004', 'R104'),
  ('E21', 'P1005', 'R105'),
  ('E22', 'P1006', 'R106'),
  ('E22', 'P1007', 'R107'),
  ('E22', 'P1008', 'R108'),
  ('E22', 'P1009', 'R109'),
  ('E22', 'P1010', 'R110'),
  ('E22', 'P1020', 'R108'),
  ('E22', 'P1022', 'R109'),
  ('E22', 'P1025', 'R110'),
  ('E23', 'P1001', 'R101'),
  ('E23', 'P1002', 'R102'),
  ('E23', 'P1003', 'R103'),
  ('E23', 'P1004', 'R104'),
  ('E23', 'P1005', 'R105'),
  ('E23', 'P1011', 'R111'),
  ('E23', 'P1012', 'R112'),
  ('E23', 'P1013', 'R113'),
  ('E23', 'P1014', 'R114'),
  ('E23', 'P1015', 'R115'),
  ('E24', 'P1016', 'R116'),
  ('E24', 'P1017', 'R117'),
  ('E24', 'P1018', 'R118'),
  ('E24', 'P1019', 'R119'),
  ('E24', 'P1020', 'R120'),
  ('E25', 'P1021', 'R121'),
  ('E25', 'P1022', 'R122'),
  ('E25', 'P1023', 'R123'),
  ('E25', 'P1024', 'R124'),
  ('E25', 'P1025', 'R125'),
  ('E26', 'P1001', 'R126'),
  ('E26', 'P1002', 'R127'),
  ('E26', 'P1003', 'R128'),
  ('E26', 'P1004', 'R129'),
  ('E26', 'P1005', 'R130'),
  ('E27', 'P1006', 'R131'),
  ('E27', 'P1007', 'R132'),
  ('E27', 'P1008', 'R133'),
  ('E27', 'P1009', 'R134'),
  ('E27', 'P1010', 'R135'),
  ('E29', 'P1016', 'R141'),
  ('E29', 'P1017', 'R142'),
  ('E29', 'P1018', 'R143'),
  ('E29', 'P1019', 'R144'),
  ('E29', 'P1020', 'R145'),
  ('E30', 'P1021', 'R146'),
  ('E30', 'P1022', 'R147'),
  ('E30', 'P1023', 'R148'),
  ('E30', 'P1024', 'R149'),
  ('E30', 'P1025', 'R150'),
  ('E31', 'P1001', 'R151'),
  ('E31', 'P1002', 'R152'),
  ('E31', 'P1003', 'R153'),
  ('E31', 'P1004', 'R154'),
  ('E31', 'P1005', 'R155'),
  ('E32', 'P1016', 'R141'),
  ('E32', 'P1017', 'R142'),
  ('E32', 'P1018', 'R143'),
  ('E32', 'P1019', 'R144'),
  ('E32', 'P1020', 'R145'),
  ('E32', 'P1001', 'R151'),
  ('E32', 'P1002', 'R152'),
  ('E32', 'P1003', 'R153'),
  ('E32', 'P1004', 'R154'),
  ('E32', 'P1006', 'R156'),
  ('E32', 'P1007', 'R157'),
  ('E32', 'P1008', 'R158'),
  ('E32', 'P1009', 'R159'),
  ('E32', 'P1010', 'R160');

-- event conduction table 
INSERT INTO Event_conduction (event_id, date_of_conduction)
VALUES
  ('E1', '2023-04-15'),
  ('E2', '2023-04-16'),
  ('E3', '2023-04-17'),
  ('E4', '2023-04-18'),
  ('E5', '2023-04-19'),
  ('E6', '2023-04-15'),
  ('E7', '2023-04-16'),
  ('E8', '2023-04-17'),
  ('E9', '2022-04-15'),
  ('E9', '2022-04-16'),
  ('E10', '2022-04-17'),
  ('E11', '2022-04-18'),
  ('E12', '2022-04-19'),
  ('E13', '2022-04-15'),
  ('E14', '2022-04-16'),
  ('E15', '2022-04-17'),
  ('E16', '2022-04-18'),
  ('E17', '2022-04-19'),
  ('E17', '2022-04-20'),
  ('E18', '2022-04-15'),
  ('E19', '2022-04-16'),
  ('E20', '2022-04-17'),
  ('E21', '2022-04-18'),
  ('E22', '2022-04-19'),
  ('E23', '2022-04-15'),
  ('E24', '2022-04-16'),
  ('E25', '2021-04-15'),
  ('E26', '2021-04-16'),
  ('E27', '2021-04-17'),
  ('E29', '2021-04-19'),
  ('E30', '2021-04-15'),
  ('E31', '2021-04-16'),
  ('E32', '2021-04-17'),
  ('E32', '2021-04-18');


-- visitors table values
INSERT INTO Visitor (SRN, name, age, gender)
VALUES
  ('P1001', 'John Doe', 25, 'Male'),
  ('P1002', 'Jane Smith', 30, 'Female'),
  ('P1001', 'Michael Johnson', 22, 'Male'),
  ('P1014', 'Emily Davis', 28, 'Female'),
  ('P1001', 'David Wilson', 35, 'Male'),
  ('P1014', 'Sophia Brown', 27, 'Female'),
  ('P1003', 'Daniel Taylor', 23, 'Male'),
  ('P1016', 'Olivia Anderson', 29, 'Female'),
  ('P1003', 'Andrew Thomas', 26, 'Male'),
  ('P1016', 'Isabella Martinez', 31, 'Female');
  
  -- stall table entries
  INSERT INTO stall VALUES('S1', "Flavor Fusion", 'F101'),
			('S2', "TasteBud Oasis", 'F101'),
			('S3', "Munchie Magic", 'F101'),
			('S4', "Culinary Haven", 'F102'),
			('S5', "Savory Delights", 'F102'),
			('S6', "SpiceHub", 'F102'),
			('S7', "YumBliss Café", 'F201'),
			('S8', "BiteStreet", 'F201'),
			('S9', "FlavorCraft", 'F101');

-- item table values
INSERT INTO item (name, Type) VALUES
('Veggie Wrap', 'VEG'),
('Chicken Noodle Soup', 'NON-VEG'),
('Classic Caesar Salad', 'VEG'),
('BBQ Chicken Sandwich', 'NON-VEG'),
('Mushroom Risotto', 'VEG'),
('Grilled Steak', 'NON-VEG'),
('Spinach and Feta Omelette', 'VEG'),
('Fish Tacos', 'NON-VEG'),
('Margherita Pizza', 'VEG'),
('Mutton Stroganoff', 'NON-VEG'),
('Caprese Salad', 'VEG'),
('Shrimp Scampi', 'NON-VEG'),
('Vegetable Stir-Fry', 'VEG'),
('Bacon-Wrapped Shrimp', 'NON-VEG'),
('Vegetable Pad Thai', 'VEG');

-- stall_items values
INSERT INTO stall_items (stall_id, item_name, price_per_unit, total_quantity) VALUES
('S1', 'Veggie Wrap', 399.00, 50),
('S2', 'Veggie Wrap', 429.00, 40),
('S3', 'Veggie Wrap', 379.00, 55),
('S7', 'Veggie Wrap', 412.50, 45),
('S5', 'Veggie Wrap', 400.00, 60),

('S2', 'Chicken Noodle Soup', 529.00, 30),
('S3', 'Chicken Noodle Soup', 564.50, 25),
('S4', 'Chicken Noodle Soup', 519.75, 35),
('S6', 'Chicken Noodle Soup', 550.00, 28),
('S8', 'Chicken Noodle Soup', 525.00, 32),
('S9', 'Chicken Noodle Soup', 590.00, 32),

('S1', 'Classic Caesar Salad', 349.50, 45),
('S7', 'Classic Caesar Salad', 382.50, 38),
('S5', 'Classic Caesar Salad', 349.25, 50),
('S9', 'Classic Caesar Salad', 360.00, 48),

('S4', 'BBQ Chicken Sandwich', 489.00, 20),
('S9', 'BBQ Chicken Sandwich', 524.50, 18),
('S7', 'BBQ Chicken Sandwich', 510.00, 16),
('S8', 'BBQ Chicken Sandwich', 490.00, 24),

('S1', 'Mushroom Risotto', 359.00, 30),
('S2', 'Mushroom Risotto', 387.00, 28),
('S3', 'Mushroom Risotto', 349.00, 35),
('S7', 'Mushroom Risotto', 378.50, 32),
('S5', 'Mushroom Risotto', 360.00, 38),
('S9', 'Mushroom Risotto', 378.50, 40),

('S8', 'Grilled Steak', 589.00, 15),
('S6', 'Grilled Steak', 622.50, 14),
('S4', 'Grilled Steak', 573.75, 17),

('S1', 'Spinach and Feta Omelette', 259.00, 40),
('S3', 'Spinach and Feta Omelette', 282.50, 38),
('S9', 'Spinach and Feta Omelette', 257.25, 45),

('S2', 'Fish Tacos', 449.00, 25),
('S3', 'Fish Tacos', 481.50, 23),
('S4', 'Fish Tacos', 470.00, 28),
('S6', 'Fish Tacos', 470.00, 26),
('S7', 'Fish Tacos', 450.00, 30),
('S8', 'Fish Tacos', 450.00, 30),
('S9', 'Fish Tacos', 470.00, 30),

('S1', 'Margherita Pizza', 350.00, 25),
('S5', 'Margherita Pizza', 349.00, 25),
('S7', 'Margherita Pizza', 375.00, 23),
('S9', 'Margherita Pizza', 339.00, 28),

('S9', 'Mutton Stroganoff', 559.00, 20),
('S7', 'Mutton Stroganoff', 594.50, 18),

('S1', 'Caprese Salad', 249.00, 35),

('S4', 'Shrimp Scampi', 419.00, 20),
('S6', 'Shrimp Scampi', 412.75, 22),
('S8', 'Shrimp Scampi', 420.00, 24),

('S1', 'Vegetable Stir-Fry', 299.00, 30),
('S2', 'Vegetable Stir-Fry', 322.00, 28),
('S3', 'Vegetable Stir-Fry', 293.00, 35),
('S7', 'Vegetable Stir-Fry', 318.50, 32),
('S9', 'Vegetable Stir-Fry', 300.00, 38),

('S9', 'Bacon-Wrapped Shrimp', 589.00, 15),

('S1', 'Vegetable Pad Thai', 329.00, 25),
('S5', 'Vegetable Pad Thai', 324.25, 28),
('S9', 'Vegetable Pad Thai', 340.00, 32);

-- inserting values into the purchased table
INSERT INTO purchased VALUES
('P1001', 'S1', 'Veggie Wrap', '2023-04-15 12:00:00', 2),
('P1001', 'S1', 'Mushroom Risotto', '2023-04-15 13:00:05', 3),
('P1005', 'S2', 'Fish Tacos', '2023-04-16 10:30:00', 4),
('P1005', 'S3', 'Chicken Noodle Soup', '2023-04-16 11:05:00', 2),
('P1005', 'S3', 'Fish Tacos', '2023-04-16 12:15:00', 5),
('P1005', 'S9', 'Mutton Stroganoff', '2023-04-16 13:35:00', 1),
('P1017', 'S1', 'Spinach and Feta Omelette', '2023-04-16 10:05:00', 2),
('P1017', 'S1', 'Classic Caesar Salad', '2023-04-16 10:05:00', 3),
('P1017', 'S3', 'Chicken Noodle Soup', '2023-04-16 12:25:00', 3),
('P1017', 'S3', 'Vegetable Stir-Fry', '2023-04-16 12:25:00', 4),
('P1017', 'S2', 'Fish Tacos', '2023-04-16 16:00:00', 5),
('P1017', 'S9', 'Bacon-Wrapped Shrimp', '2023-04-16 17:30:00', 2),
('P1002', 'S9', 'Margherita Pizza', '2023-04-16 12:30:00', 1),
('P1002', 'S1', 'Caprese Salad', '2023-04-16 13:33:00', 3),
('P1002', 'S1', 'Classic Caesar Salad', '2023-04-16 13:33:00', 3),
('P1002', 'S9', 'Vegetable Stir-Fry', '2023-04-16 17:19:00', 5),
('P1006', 'S9', 'Vegetable Stir-Fry', '2023-04-16 10:45:00', 2),
('P1006', 'S1', 'Margherita Pizza', '2023-04-16 14:50:00', 1),
('P1006', 'S2', 'Fish Tacos', '2023-04-16 15:55:00', 1),
('P1010', 'S9', 'Mutton Stroganoff', '2023-04-16 13:10:00', 1),
('P1010', 'S9', 'Spinach and Feta Omelette', '2023-04-16 13:10:00', 1),
-- 2022 
('P1001', 'S5', 'Veggie Wrap', '2022-04-17 10:10:00', 3),
('P1001', 'S5', 'Classic Caesar Salad', '2022-04-17 10:10:00', 2),
('P1005', 'S4', 'Fish Tacos', '2022-04-17 12:50:00', 3),
('P1005', 'S4', 'BBQ Chicken Sandwich', '2022-04-17 13:20:00', 2),
('P1005', 'S4', 'Chicken Noodle Soup', '2022-04-17 13:20:00', 1),
('P1005', 'S4', 'Grilled Steak', '2022-04-17 14:30:00', 2),
('P1005', 'S4', 'Shrimp Scampi', '2022-04-17 14:30:00', 1),
('P1024', 'S6', 'Shrimp Scampi', '2022-04-17 11:05:00', 3),
('P1024', 'S6', 'Grilled Steak', '2022-04-17 11:05:00', 2),
('P1024', 'S4', 'Chicken Noodle Soup', '2022-04-17 13:15:00', 1),
('P1024', 'S5', 'Vegetable Pad Thai', '2022-04-17 15:00:00', 2),
('P1008', 'S6', 'Fish Tacos', '2022-04-17 10:45:00', 3),
('P1008', 'S6', 'Grilled Steak', '2022-04-17 10:45:00', 2),
('P1008', 'S5', 'Mushroom Risotto', '2022-04-17 15:00:00', 3),
('P1008', 'S5', 'Vegetable Pad Thai', '2022-04-17 15:00:00', 1),
('P1008', 'S4', 'BBQ Chicken Sandwich', '2022-04-17 15:10:00', 1),
('P1010', 'S4', 'Chicken Noodle Soup', '2022-04-17 13:05:00', 3),
('P1010', 'S5', 'Mushroom Risotto', '2022-04-17 17:15:00', 1),
('P1010', 'S6', 'Shrimp Scampi', '2022-04-17 17:20:00', 2),
('P1003', 'S7', 'Fish Tacos', '2022-04-19 11:25:00', 2),
('P1003', 'S8', 'Shrimp Scampi', '2022-04-19 12:25:00', 2),
('P1003', 'S8', 'Fish Tacos', '2022-04-19 12:25:00', 1),
('P1003', 'S7', 'Veggie Wrap', '2022-04-19 14:00:00', 1),
('P1004', 'S7', 'Veggie Wrap', '2022-04-19 11:00:00', 4),
('P1004', 'S7', 'Margherita Pizza', '2022-04-19 11:00:00', 2);