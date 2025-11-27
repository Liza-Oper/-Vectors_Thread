# -Vectors_Thread

**Данный код реализован в рамках данной задачи:**
1. Создать вектор из миллиона элементов. Наполнить его случайными числами.
2. Посчитать сумму этого вектора на одном потоке. То есть просто в цикле, как обычно.
3. Замерить время работы программы.
4. Посчитать сумму вектора по частям, закинув каждую часть в отдельный поток.
5. Замерить время работы программы и сравнить с предыдущим.

**Как итог проект реализован следующим образом:**
Генерируются рандомные числа от 0 до 99,далее заполняется вектор данными значениями.
После того как вектор был создан, происходит вычисление суммы вектора двумя способами:
1. Обычным циклом проходимся по элементами и последовательно вычисляем сумму
2. Мы делим вектор на 4 части и параллельно вычисляем суммы этих кусочков, после чего их суммируем
После каждого метода мы вычисляем время

**Результат работы:**
Мы должны показать, что многопоточный метод работает быстрее, чем однопоточный на больших векторах
Для одного потока: n=1000000, time=0.0027
Для четырех потоков: n=1000000, time=0.0032
Для десяти потоков: n=1000000, time=0.0013

**This code was implemented for the following task:**
1. Create a vector of one million elements and fill it with random numbers.
2. Compute the sum of this vector in a single thread (i.e., using a regular loop).
3. Measure the execution time of the program.
4. Compute the sum of the vector in parts, assigning each part to a separate thread.
5. Measure the execution time and compare it with the previous method.

**As a result, the project is implemented as follows:**
Random numbers from 0 to 99 are generated and used to fill the vector.
Once the vector is created, its sum is computed in two ways:
1. Using a standard loop to iterate through the elements and calculate the sum sequentially.
2. Dividing the vector into four parts and calculating the sums of these parts in parallel threads, then combining the results.
After each method, the execution time is measured.


**Expected outcome:**
The goal is to demonstrate that the multi-threaded method performs faster than the single-threaded method for large vectors.
1 thread: n=1000000, time=0.0027
4 threads: n=1000000, time=0.0032
10 threads: n=1000000, time=0.0013
