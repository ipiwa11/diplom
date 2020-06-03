-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Июн 03 2020 г., 15:07
-- Версия сервера: 10.1.38-MariaDB
-- Версия PHP: 5.6.40

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `stidio_photograph`
--

-- --------------------------------------------------------

--
-- Структура таблицы `location`
--

CREATE TABLE `location` (
  `Location_ID` int(4) NOT NULL,
  `Address` varchar(200) NOT NULL,
  `Longitude` double(8,6) NOT NULL,
  `Latitude` double(8,6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Дамп данных таблицы `location`
--

INSERT INTO `location` (`Location_ID`, `Address`, `Longitude`, `Latitude`) VALUES
(1, 'Lesoparkovaya, 7a', 55.156238, 61.368219),
(2, 'Hudyakova, 12a', 55.148769, 61.374369),
(3, 'Brothers Kashirinyh, 12496 office; 12 floor', 55.174333, 61.303702),
(4, 'Shadrinskaya, 34/2', 55.187750, 61.434674),
(5, 'Molodogvardeitsev, 7, k5, 1 floor', 55.206125, 61.326157),
(6, 'Komarovskogo, 4a', 55.242523, 61.376906),
(7, 'Troitskaya, 1v', 55.124394, 61.372853),
(8, 'Truda, 82a', 55.168888, 61.405396),
(9, 'Kopeiskoe Shosse, 40', 55.131402, 61.477325),
(10, 'Barbyusa, 18', 55.144425, 61.435196);

-- --------------------------------------------------------

--
-- Структура таблицы `type_users`
--

CREATE TABLE `type_users` (
  `Type_ID` int(4) NOT NULL,
  `Type_User` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Дамп данных таблицы `type_users`
--

INSERT INTO `type_users` (`Type_ID`, `Type_User`) VALUES
(1, 'Photograph'),
(2, 'Studio');

-- --------------------------------------------------------

--
-- Структура таблицы `user`
--

CREATE TABLE `user` (
  `User_ID` int(4) NOT NULL,
  `Full_Name_Or_Title` varchar(200) NOT NULL,
  `Type_ID` int(4) NOT NULL,
  `Location_ID` int(4) NOT NULL,
  `Free` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Дамп данных таблицы `user`
--

INSERT INTO `user` (`User_ID`, `Full_Name_Or_Title`, `Type_ID`, `Location_ID`, `Free`) VALUES
(1, 'Pobeda', 2, 1, 1),
(2, 'Van Gog', 2, 2, 1),
(3, 'La Maison', 2, 3, 1),
(4, 'Milk', 2, 4, 1),
(5, 'Yurta Samray', 2, 5, 1),
(6, 'Moskalev Dmitriy ', 1, 6, 1),
(7, 'Denisova Alena', 1, 7, 1),
(8, 'Porubov Andrey', 1, 8, 1),
(9, 'Kosintsev Alexandr', 1, 9, 1),
(10, 'Lomonosovskii Pavel', 1, 10, 1);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `location`
--
ALTER TABLE `location`
  ADD PRIMARY KEY (`Location_ID`);

--
-- Индексы таблицы `type_users`
--
ALTER TABLE `type_users`
  ADD PRIMARY KEY (`Type_ID`);

--
-- Индексы таблицы `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`User_ID`),
  ADD KEY `Location_ID` (`Location_ID`),
  ADD KEY `Type_ID` (`Type_ID`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `location`
--
ALTER TABLE `location`
  MODIFY `Location_ID` int(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT для таблицы `type_users`
--
ALTER TABLE `type_users`
  MODIFY `Type_ID` int(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT для таблицы `user`
--
ALTER TABLE `user`
  MODIFY `User_ID` int(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `user`
--
ALTER TABLE `user`
  ADD CONSTRAINT `user_ibfk_1` FOREIGN KEY (`Location_ID`) REFERENCES `location` (`Location_ID`),
  ADD CONSTRAINT `user_ibfk_2` FOREIGN KEY (`Type_ID`) REFERENCES `type_users` (`Type_ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
