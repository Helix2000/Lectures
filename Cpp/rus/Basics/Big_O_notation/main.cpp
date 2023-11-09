// Это включает все стандартные библиотека c++:
#include <bits/stdc++.h>
// Это просто файл в директории "bits", который содержит много-много инструкций
// "include". Можешь сам посмотреть по ссылке:
// https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/precompiled/stdc%2B%2B.h
// Чтобы использовать это в Visual studio, иди в
// visual studio -> версия -> VC -> tools -> MSVC -> ver -> include
// Создай папку с именем "bits" и помести туда stdc++.h файл.
// Возможно, придётся написать #include "bits/stdtc++.h"

using namespace std;

// Функция (в математике) - это зависимость одной переменной от другой.
// y = f(x) = k*x + b
// Можно сказать, что это отображение одних значений в другие.

// В программировании функция - это вызываемый участок кода.
// В отличии от математики, функция в программировании
// не обязана что-то возвращать.
// Такие функции иногда называют процедурами.

// Функции в программировании нужны, чтобы:
// 1. Использовать один и тот же код несколько раз;
// 2. Декомпозировать программу (разбивать её на логически законченные части)
// 3. Использовать уже написанный за тебя код как с функцией sort().

// Можно объявлять свои функции следующим образом:
// возвращаемый_тип название_функции(аргументы) {**код**}
// Аргументы - перечисление переменных, которые нужны функции, чтобы исполниться.
// Разные функции имеют либо разные названия, либо разные типы аргументов.
// Тип возвращаемых данных не говорит компилятору, что функции разные,
// если имя и аргументы одинаковые.

int square(int x) {
  int res = x * x;
  return res;
}

// Существует особый тип данных "void"
// Он говорит, что функция ничего не возвращает.
// На самом деле она буквально возвращает ничего.
void print(string something) {
  cout << something << endl;
  // Можешь использовать return, если хочешь.
  // return;
}

// Асимптотика, сложность, "О большое" - это функция от функции, которую
// если домножить на константу и прибавить константу, то она будет больше, чем
// исходная функция для любого входного числа.
// O(f(n)) = g(n): э(C0, C1): g(n) * C1 + C0 > f(n) v(n)
// Обычно стараются найти наименьшую такую функцию.
// Асимптотика O(n^2) по времени означает, что время, которое алгоритм тратит
// на свою работу не превышает n^2, домноженное на константу.

// Временная сложность пропорциональна количеству итераций, которое делает программа.
// Так что если посчитать асимптотику количества итераций, то можно будет
// оценить время работы алгоритма, т.к. считаем, что все простые операции
// работают за константное время. Простые - это сложение, умножение, обращение
// по индексу, разыменование, и другие.

// Итого, чтобы посчитать асимтотику:
// 1. Считаешь общее количество итераций;
//    (во всей программе, в функции, в блоке кода, где нужно)
// 2. Разбиваешь на слагаемые; (n*(n-1)/2 = n*n/2 - n/2)
// 3. Выбираешь самое большое слагаемое; (n^2 > n)
// 4. Убираешь все константы. (n^2/2 = n^2,
//    n^2 = n^2, 2 - не константа, а форма записи)
// O(n*(n-1)/2) = O(n*n/2 - n/2) = O(n*n/2) = O(n*n) = O(n^2)

// Чтобы узнать, пройдёт ли у тебя по времени, то подставь самые большие
// числа из входных данных в O(..).
// На C++ в одну секунду проходит 3*10^7, в две 6*10^7.
// O(n^2), n = 2*10^5;
// (2*10^5)^2 = 4*10^10.

// Обычно, когда люди изучают асимптотику, им показывают несколько
// алгоритмов сортировки, чтобы они поняли как её считать.
// Пузырьковая сортировка:
void bubble_sort(vector<int> &arr) {
  // Символ '&' показывает, что мы получим значение "по ссылке" и будем
  // работать с переменной извне.
  // Если не использовать этот символ, то программа сначала создаст новую
  // переменную и запишет туда копию того, что передали.
  // В этом случае говорят, что мы передаём переменную "по значению".

  // Явное преобразование к int, т.к. arr.size() возвращает unsigned long long.
  int n = (int)arr.size();

  // Первый цикл сделает n итераций.
  for (int i = 0; i < n; ++i) { // [0, n)
    // Второй всегда делает n - 1 итерацию
    // на каждую итерацию внешнего цикла.
    for (int j = 1; j < n; ++j) { // [1, n)
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  // Один цикл вложен в другой и не зависит от него, поэтому
  // можно просто перемножить количество итераций.
  // O(n) * O(n - 1) = O(n^2 - n) = O(n^2)

  // Асимптотика по времени O(n^2)
  // Асимптотика по памяти O(1)

  // Потому что мы не использовали дополнительную память пропорционально n.
}

// "быстрая" пузырьковая сортировка:
void fast_bubble_sort(vector<int> &arr) {
  int n = (int)arr.size();

  // Первый цикл сделает n - 1 итерацию.
  for (int i = 0; i < n - 1; ++i) {
    // Второй цикл сделает n-1, n-2, ..., 2, 1 итерацию.
    for (int j = 1; j < (n - i); ++j) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  // Считаем суммарное количество итераций:
  // (n - 1) + (n - 2) + ... + 1
  // 1 + 2 + ... + (n - 1)
  // Это же арифметическая прогрессия.

  // Арифметическая прогрессия - последовательность чисел, в которой
  // разность любых двух последовательных членов постоянна и равна d.

  // Первый элемент суммы равен 1. Последний элемент суммы равен (n - 1).
  // Сумма первого и последнего элемента равна 1 + (n - 1) = n.
  // Если увеличить первый элемент на d=1 и уменьшить последнее на d=1,
  // то сумма не изменится. Сделаем так столько раз,
  // сколько членов в последовательности. Но каждую пару мы посчитали
  // дважды, поэтому поделим на два. Получается:
  // Сумма = (первый + последний) * количество_членов / 2
  // В нашем случае:
  // (1 + (n-1)) * (n-1) / 2 = n * (n-1) / 2
  // O(n * (n-1) / 2) = O(n^2)

  // Асимптотика по времени O(n^2)
  // Асимптотика по памяти O(1)
}

// Обезьянья сортировка:
void bogo_sort(vector<int> &arr) {
  int n = (int)arr.size();
  // Считаем, что массив изначально не отсортирован.
  bool sorted = false;
  while (!sorted) {
    // Существует n! = n * (n-1) * (n-2) * ... * 2 * 1 возможных перестановок
    // массива размера n.

    // Во-первых, перемешаем массив:
    for (int i = n - 1; i > 0; --i) {
      // функция rand() возвращает случайное число
      // из отрезка [0, RAND_MAX], где RAND_MAX - константа,
      // для каждого компьютера своя
      // это ПЛОХАЯ функция для генерации случайных чисел,
      // но достаточно простая для примера.

      int j = rand() % i;
      swap(arr[i], arr[j]);
    }
    sorted = true;
    // Проверяем, что массив отсортирован:
    for (int i = 1; i < n; ++i) {
      if (arr[i] > arr[i - 1]) {
        sorted = false;
      }
    }
  }
  // Существует n! возможных перестановок и для каждой из них
  // (О большое рассматривает худший случай) мы должны перемешать
  // и проверить на отсортированность. Предполагая, что каждый раз
  // мы получим другой массив, что не является правдой в общем случае, получаем:
  // n! * ((n-1) + (n-1)) = n! * 2(n-1)
  // O(n! * 2(n-1)) = O(n! * n)

  // Асимптотика по времени O(n! * n)
  // Асимптотика по памяти O(1)
}

// Рекурсивная функция, это функция, которая вызывает саму себя.
// Это вспомогательная функция, потому что её сигнатура (список аргументов)
// отличается от остальных функций:
vector<int> merge(vector<int> &arr, int start, int finish) {
  vector<int> res;
  if (finish - start == 1) {
    // Если всего один элемент:
    res.push_back(arr[start]);
    return res;
  }
  // Вычисляем середину полуинтервала [start, finish):
  int mid = start + (finish - start) / 2;
  // Сортируем рекурсивно левую и правую части:
  vector<int> left = merge(arr, start, mid);
  vector<int> right = merge(arr, mid, finish);
  // "left" и "right" теперь отсортированы.
  // p1 - указатель на левую часть.
  // p2 - указатель на правую часть.
  int p1 = 0, p2 = 0;
  // Явное преобразование:
  int n_left = (int)left.size();
  int n_right = (int)right.size();
  // Пока есть элементы в обеих частях:
  while (p1 < n_left && p2 < n_right) {
    // Добавляем меньший из них:
    if (left[p1] <= right[p2]) {
      res.push_back(left[p1]);
      ++p1;
    } else {
      res.push_back(right[p2]);
      ++p2;
    }
  }
  // Если остались элементы в левой половине:
  while (p1 < n_left) {
    res.push_back(left[p1]);
    ++p1;
  }
  // Или в правой:
  while (p2 < n_right) {
    res.push_back(right[p2]);
    ++p2;
  }
  // На каждом шаге рекурсии количество оставшихся элементов уменьшается
  // в два раза. Если начальная глубина равна 0, то на глубине k длина будет
  // равна n / 2^k.
  // Когда останется один элемент, то рекурсия остановится.
  // n / 2^k = 1
  // n = 2^k
  // log_2(n) = k
  // k = log(n)
  // Значит, глубина рекурсии не превышает log_2(n).
  // На каждой глубине рекурсии элементов не прибавляется и не убавляется.
  // Это значит, что на каждом слое рекурсии ровно n элементов.
  // Операция слияния линейная, потому что на каждый элемент она смотрит
  // всего один раз. Поэтому можно перемножить n и log_2(n)

  // Асимптотика по времени O(n * log(n))
  // Асимптотика по памяти O(n * log(n))

  // В асимптотике не пишут основание у логарифма из-за формулы перехода
  // к новому основанию:
  // log_b(n) = log_c(n) / log_c(b)
  // log_c(b) - это константа, так что от неё можно избавиться. Это значит,
  // что мы можем написать любое основание и это не противоречит определению.
  // Поэтому никто не пишет основание логарифма в асимптотике.

  // Так как мы должны сохранять промежуточные результаты слияния, то
  // такая реализация сортировки слиянием потратит дополнительно O(n*log(n))
  // памяти. Можно написать аккуратнее за O(n).
  return res;
}

// Это просто функция с правильным списком аргументов:
void merge_sort(vector<int> &arr) {
  // заметь - это единственная сортировка, которая не трогает исходный массив
  // она "вычисляет" отсортированный и возвращает его тебе
  // я не буду его тут возвращать, но ты имей в виду
  arr = merge(arr, 0, (int)arr.size());
}

// Сортировка подсчётом:
void count_sort(vector<int> &arr) {
  // Это не совсем алгоритм сортировки, потому что он использует
  // тот факт, что на вход даны неотрицательные целые числа.
  int max = *max_element(arr.begin(), arr.end());
  // Объявляем массив:
  vector<int> counts(max + 1, 0);
  // Считаем сколько раз каждый элемент встретился:
  for (int i = 0; i < (int)arr.size(); ++i) {
    ++counts[arr[i]];
  }
  arr.clear();
  // Для каждого элемента, который мог быть в массиве:
  for (int i = 0; i <= max; ++i) {
    // Добавляем его столько раз, сколько до этого насчитали:
    for (int j = 0; j < counts[i]; ++j) {
      arr.push_back(i);
    }
  }
  // Вложенный цикл сделает n итераций за все итерации внешнего.

  // Асимптотика по времени O(n + max_element) = O(max(n, max_element))
  // Асимптотика по памяти O(max_element)
}

// Это всё примеры того, как считать асимптотику по времени и по памяти.
// Если тебе нужна функция сортировки, то скорее всего тебе нужна стандартная:
// sort(arr.begin(), arr.end());
// Компилятор GCC использует интроспективную сортировку, которая смешивает
// быструю сортировку и сортировку кучей.
// Асимптотика по времени O(n*log(n))
// Асимптотика по памяти O(log(n)) из-за рекурсии быстрой сортировки
// https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/bits/stl_algo.h#L1948
// https://ru.wikipedia.org/wiki/Introsort

// Отношения O:
// 1 < log < log^2 < sqrt < n < n*log < n*log^2 < n*sqrt(n) < n^2 < 2^n < n! < n^n

void static_count_sort(vector<int> &arr) {
  // Статические переменные остаются после завершения функции.
  // Так что при следующем вызове этот массив останется таким же, каким
  // был на момент завершения предыдущего вызова:
  static vector<int> counts;
  int max = *max_element(arr.begin(), arr.end());
  counts.resize(max + 1);
  for (int i = 0; i < (int)arr.size(); ++i) {
    ++counts[arr[i]];
  }
  arr.clear();
  for (int i = 0; i <= max; ++i) {
    for (int j = 0; j < counts[i]; ++j) {
      arr.push_back(i);
    }
    // Не забудем "очистить" массив "counts":
    counts[i] = 0;
  }
  // Асимптотика не отличается от обычной сортировки подсчётом.
}

// Не обращай особого внимания, просто получаю случайную перестановку.
vector<int> get_random_array(int size, mt19937 rngesus) {
  vector<int> res(size);
  iota(res.begin(), res.end(), 0);
  shuffle(res.begin(), res.end(), rngesus);
  return res;
}

// Функции можно передавать как аргумент и использовать
// auto вместо типа аргумента и ничего не сломается.
void test_sort(int n, int tests, int seed, auto f, string name) {
  mt19937 rngesus(seed);
  cout << "Testing " << name << endl;
  clock_t start = clock();
  for (int test = 0; test < tests; ++test) {
    vector<int> arr = get_random_array(n, rngesus);
    f(arr);
  }
  clock_t finish = clock();
  double diff = double(finish - start);
  cout << diff / (CLOCKS_PER_SEC * tests) << "s per single test" << endl;
  cout << diff / CLOCKS_PER_SEC << "s total" << endl;
  cout << "===========================================================" << endl;
}

int main() {
  const int SEED = 42;
  cout << fixed << setprecision(8);
  int n = 10, tests = 10;
  cout << "n = " << n << "; tests = " << tests << endl << endl;
  test_sort(10, 10, SEED, bogo_sort, "bogo sort");
  cout << endl;

  n = 1000, tests = 100;
  cout << "n = " << n << "; tests = " << tests << endl << endl;
  test_sort(n, tests, SEED, bubble_sort, "bubble sort");
  test_sort(n, tests, SEED, fast_bubble_sort, "fast bubble sort");
  test_sort(n, tests, SEED, merge_sort, "merge sort");
  test_sort(n, tests, SEED, count_sort, "count sort");
  test_sort(n, tests, SEED, static_count_sort, "static count sort");
  cout << endl;

  // ' <= это разделитель чисел начиная с C++14 и далее.
  n = 10'000, tests = 100;
  cout << "n = " << n << "; tests = " << tests << endl << endl;
  test_sort(n, tests, SEED, bubble_sort, "bubble sort");
  test_sort(n, tests, SEED, fast_bubble_sort, "fast bubble sort");
  test_sort(n, tests, SEED, merge_sort, "merge sort");
  test_sort(n, tests, SEED, count_sort, "count sort");
  test_sort(n, tests, SEED, static_count_sort, "static count sort");
  cout << endl;
  return 0;
}

/*
Спецификация железа:
Linux userpc 5.13.0-39-generic #44~20.04.1-Ubuntu SMP Thu Mar 24 16:43:35 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
Intel(R) Core(TM) i5-3450 CPU @ 3.10GHz

Спецификация компилятора:
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
-O2 -fconcepts

Результаты:

n = 10; tests = 10

Testing bogo sort
1.10456510s за один тест
11.04565100s всего
===========================================================

n = 1000; tests = 100

Testing bubble sort
0.00998971s за один тест
0.99897100s всего
===========================================================
Testing fast bubble sort
0.00728111s за один тест
0.72811100s всего
===========================================================
Testing merge sort
0.00106512s за один тест
0.10651200s всего
===========================================================
Testing count sort
0.00011819s за один тест
0.01181900s всего
===========================================================
Testing static count sort
0.00011803s за один тест
0.01180300s всего
===========================================================

n = 10000; tests = 100

Testing bubble sort
1.01583518s за один тест
101.58351800s всего
===========================================================
Testing fast bubble sort
0.74302695s за один тест
74.30269500s всего
===========================================================
Testing merge sort
0.01229034s за один тест
1.22903400s всего
===========================================================
Testing count sort
0.00121320s за один тест
0.12132000s всего
===========================================================
Testing static count sort
0.00120476s за один тест
0.12047600s всего
===========================================================
*/
