-- phpMyAdmin SQL Dump
-- version 4.0.10.6
-- http://www.phpmyadmin.net
--
-- Host: mysql1.alwaysdata.com
-- Generation Time: Apr 10, 2016 at 10:50 PM
-- Server version: 5.1.66-0+squeeze1
-- PHP Version: 5.6.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `rush00_database`
--

-- --------------------------------------------------------

--
-- Table structure for table `categories`
--

CREATE TABLE IF NOT EXISTS `categories` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(150) NOT NULL,
  `description` text NOT NULL,
  `image_url` varchar(200) NOT NULL,
  `categorie-master` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `categories`
--

INSERT INTO `categories` (`id`, `name`, `description`, `image_url`, `categorie-master`) VALUES
(1, 'Guitares', '', '', 1),
(2, 'top', '', '', 0),
(3, 'Vent', '', '', 1),
(4, 'Piano', '', '', 1),
(5, 'Rock', '', '', 3),
(6, 'Pop', '', '', 3),
(7, 'Ampli', '', '', 2),
(8, 'Entretien', '', '', 2);

-- --------------------------------------------------------

--
-- Table structure for table `command`
--

CREATE TABLE IF NOT EXISTS `command` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `price` int(11) NOT NULL,
  `date` date NOT NULL,
  `user` varchar(45) NOT NULL,
  `item_count` int(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=31 ;

--
-- Dumping data for table `command`
--

INSERT INTO `command` (`id`, `price`, `date`, `user`, `item_count`) VALUES
(28, 0, '0000-00-00', '', 0),
(29, 0, '0000-00-00', '', 0),
(30, 0, '0000-00-00', '', 0);

-- --------------------------------------------------------

--
-- Table structure for table `items`
--

CREATE TABLE IF NOT EXISTS `items` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(150) NOT NULL,
  `description` text NOT NULL,
  `categories` varchar(50) NOT NULL,
  `price` double NOT NULL,
  `image_url` varchar(250) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=54 ;

--
-- Dumping data for table `items`
--

INSERT INTO `items` (`id`, `name`, `description`, `categories`, `price`, `image_url`) VALUES
(29, 'Guitare folk', '', 'Guitares', 369.99, 'img/guitare.jpeg'),
(30, 'Guitare Electrique', '', 'Guitares', 149.99, 'img/guitar_elec.jpeg'),
(31, 'Basse', '', 'Guitares', 1179.99, 'img/basse.jpeg'),
(32, 'Saxophone', '', 'Vent;top', 268.99, 'img/saxo.jpeg'),
(33, 'Flute', '', 'Vent', 298.99, 'img/flute.jpeg'),
(34, 'Trombone', '', 'Vent', 459.99, 'img/trombone.jpeg'),
(35, 'Red hot chili Pepper', '', 'Rock', 5.99, 'img/redhot.jpeg'),
(36, 'AC-DC', '', 'Rock', 5.99, 'img/acdc.jpeg'),
(38, 'Madonna', '', 'Pop', 5.99, 'img/madonna.jpeg'),
(39, 'Elvis', '', 'Pop', 5.99, 'img/elvis.jpeg'),
(43, 'Michael Jackson', '', 'Pop;Rock;top', 5.99, 'img/mj.jpeg'),
(44, 'The Beetles', '', 'Pop;Rock', 5.99, 'img/beetles.jpeg'),
(45, 'Piano classique', '', 'Piano', 1299.99, 'img/piano.jpeg'),
(46, 'Synthe', '', 'Piano;top', 2599.99, 'img/synthe.jpeg'),
(47, 'piano a queue', '', 'Piano;top', 5999.99, 'img/piano_queue.jpeg'),
(48, 'Ampli Marshall', '', 'Ampli', 399.99, 'img/ampli.jpeg'),
(49, 'Ampli Fender', '', 'Ampli;top', 499.99, 'img/ampli_fender.jpeg'),
(50, 'Cordes deluxe', '', 'Entretien;top', 19.99, 'img/cordes.jpeg'),
(51, 'Cordes', '', 'Entretien', 5.99, 'img/cordes.jpeg');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL,
  `password` varchar(200) NOT NULL,
  `super_user` tinyint(4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=22 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `super_user`) VALUES
(3, 'bkabbas', 'admin', 1),
(6, 'hcherchi', 'hcherchi77', 1);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
