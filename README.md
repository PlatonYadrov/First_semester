# [First_contest](https://github.com/PlatonYadrov/First_semester/tree/main/first_contest)
## [A. Жизнь в квадрате](https://github.com/PlatonYadrov/First_semester/blob/main/first_contest/A.cpp "Задача A")
В некоторых клетках квадрата N×N живут микроорганизмы (не более одного в одной клетке). Каждую секунду происходит следующее: -- все микроорганизмы, у которых менее 2-х соседей, умирают от скуки (соседями называются микроорганизмы, живущие в клетках, имеющих общую сторону или вершину); -- все микроорганизмы, у которых более 3-х соседей, умирают от перенаселенности; -- на всех пустых клетках, у которых ровно в трех соседних клетках жили микроорганизмы, появляются новые микроорганизмы. Все изменения происходят одновременно, то есть для каждой клетки сначала выясняется ее судьба, а затем происходят изменения сразу во всех клетках. Требуется по данной конфигурации определить, во что она превратится через T секунд.
### Формат ввода
В первой строке вводятся два натуральных числа -- N (1 ≤ N ≤ 10) и T (1 ≤ T ≤ 100). Далее записано N строчек по N чисел, описывающих начальную конфигурацию (0 -- пустая клетка, 1 -- микроорганизм). Числа в строках разделены пробелами.
### Формат вывода
Требуется вывести N строк по N чисел -- описание конфигурации через T секунд (в том же формате, как и во входных данных).
## [B. Тетрадка](https://github.com/PlatonYadrov/First_semester/blob/main/first_contest/B.cpp)
Проектная работа Виталика по компьютерному зрению заключается в распознавании типа тетрадки по небольшому ее участку (в клетку, в линейку, в вертикальную линейку). Однако времени обучать нейросеть у Виталика нет, поэтому он попросил вас помочь ему написать программу на C++, которая бы делала это без привлечения искусственного интеллекта (почему вы согласились на это, и почему эта задача обязательна, легенда умалчивает).
Часть тетрадки представляет собой двумерную таблицу из нулей и единиц, где единица — закрашенный участок, а нуль — незакрашенный. Вертикальной линией считается столбец, в котором стоят только единицы, горизонтальной — строка, второй стоят только единицы. Гарантируется, что тетрадь изначально пустая, то есть единица обязательно является частью какой-то линии.
Тетрадь в горизонтальную линейку состоит только из горизонтальных линий, в вертикальную линейку — только из вертикальных линий, в клетку — из линий обоих типов. Причем расстояния между всеми параллельными линиями одинаковы (клетки - обязательно квадраты), и между ними обязательно есть пустоты (не могут располагаться вплотную).
По заданному участку выведите тип тетради, если его возможно однозначно определить.
### Формат ввода
В первой строке даны целые числа n и m (1 ≤ n, m ≤ 1 000) — количество строк и столбцов в видимом участке. Далле следует n строк по m целых чисел a <sub> i,j <sub> (0 ≤ a~i,j~ ≤ 1) — видимый участок тетради.
### Формат вывода
В качестве ответа выведите:
«Square», если тетрадка в клетку; «Line», если тетрадка в линейку; «Vertical line», если тетрадка в вертикальную линейку; «?», если невозможно однозначно определить, к какому типу относится данная тетрадь.
