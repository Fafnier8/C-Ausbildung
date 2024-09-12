-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Aug 23, 2024 at 10:58 AM
-- Server version: 10.5.23-MariaDB-0+deb11u1
-- PHP Version: 7.4.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `lieblingsKfz`
--

-- --------------------------------------------------------

--
-- Table structure for table `LKW`
--

CREATE TABLE `LKW` (
  `marke` varchar(255) DEFAULT NULL,
  `typ` varchar(255) DEFAULT NULL,
  `Baujahr` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `LKW`
--

INSERT INTO `LKW` (`marke`, `typ`, `Baujahr`) VALUES
('test', 'test', 'test');

-- --------------------------------------------------------

--
-- Table structure for table `pkw`
--

CREATE TABLE `pkw` (
  `IfdNr` int(11) NOT NULL,
  `marke` varchar(15) DEFAULT NULL,
  `typ` varchar(15) DEFAULT NULL,
  `baujahr` int(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pkw`
--

INSERT INTO `pkw` (`IfdNr`, `marke`, `typ`, `baujahr`) VALUES
(1, 'Hyundai', 'Hatchback', 2018),
(2, 'Opel', 'Rocks Electric', 2022),
(3, 'Opel', 'Corsa Electric', 2023);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `pkw`
--
ALTER TABLE `pkw`
  ADD PRIMARY KEY (`IfdNr`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `pkw`
--
ALTER TABLE `pkw`
  MODIFY `IfdNr` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
