SHOW DATABASES;
CREATE DATABASE IF NOT EXISTS Cafe_Database;
USE Cafe_Database;
SHOW tables;
CREATE TABLE Person (
  Name VARCHAR(255) NOT NULL PRIMARY KEY,
  Age INT NOT NULL,
  Gender VARCHAR(255) NOT NULL
);

CREATE TABLE Cafe (
  Cafe_name VARCHAR(255) NOT NULL PRIMARY KEY
);

CREATE TABLE Serves (
  Cafe_name VARCHAR(255) NOT NULL,
  Food_item VARCHAR(255) NOT NULL,
  Price DECIMAL(10,2) NOT NULL,
  FOREIGN KEY (Cafe_name) REFERENCES Cafe(Cafe_name)
);

CREATE TABLE Visits (
  Name VARCHAR(255) NOT NULL,
  Cafe_name VARCHAR(255) NOT NULL,
  Visits INT NOT NULL,
  FOREIGN KEY (Name) REFERENCES Person(Name),
  FOREIGN KEY (Cafe_name) REFERENCES Cafe(Cafe_name)
);

CREATE TABLE Orders (
  Name VARCHAR(255) NOT NULL,
  Food_item VARCHAR(255) NOT NULL,
  FOREIGN KEY (Name) REFERENCES Person(Name),
  FOREIGN KEY (Food_item) REFERENCES Serves(Food_item)
);

INSERT INTO Person (Name, Age, Gender)
VALUES ('Michael', 45, 'Male'),
       ('Sarah', 32, 'Female'),
       ('Emily', 28, 'Female'),
       ('David', 22, 'Male');

INSERT INTO Cafe (Cafe_name)
VALUES ('Cafe A'),
       ('Cafe B'),
       ('Cafe C'),
       ('Cafe D'),
       ('Cafe E');

INSERT INTO Serves (Cafe_name, Food_item, Price)
VALUES ('Cafe A', 'Pasta', 800.00),
       ('Cafe A', 'Salad', 650.00),
       ('Cafe A', 'Smoothie', 550.00),
       ('Cafe B', 'Burger', 750.00),
       ('Cafe B', 'Pizza', 1000.00),
       ('Cafe C', 'Ice Cream', 450.00),
       ('Cafe C', 'Pizza', 1000.00),
       ('Cafe D', 'Smoothie', 550.00),
       ('Cafe E', 'Pasta', 800.00);

INSERT INTO Visits (Name, Cafe_name, Visits)
VALUES ('Michael', 'Cafe A', 1),
       ('Sarah', 'Cafe A', 1),
       ('Emily', 'Cafe B', 1),
       ('David', 'Cafe C', 1);

INSERT INTO Orders (Name, Food_item)
VALUES ('Michael', 'Pasta'),
       ('Sarah', 'Salad'),
       ('Emily', 'Burger'),
       ('David', 'Pizza');