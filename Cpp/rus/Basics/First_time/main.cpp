// С двух символов '/' начинается комментарий. Он на код не влияет
// Подключаю библиотеку ввода-вывода в c++
#include <iostream> // input-output stream
// Вводим контекст, что используем стандартные имена функций
using namespace std;

// Главная (main) функция, точка входа в программу
int main() {
  // Переменная - это как коробка, где что-то лежит.
  // У коробки есть "тип данных".
  // Тип говорит о том, какая сущность лежит в коробке.

  // Стандарт C++ говорит, что:
  // short <= int <= long long

  // Есть следующие типы данных:
  // Целые числа
  // [-2^15; 2^15)
  // 2 байта
  short short_integer = 0;
  // [-2^31; 2^31)
  // 2 * 10 ^ 9 помещается
  // 4 байта
  int integer = 0;
  // [-2^63; 2^63)
  // 9 * 10 ^ 18
  // 8 байт
  long long long_integer = 0;
  // Чаще всего следует использовать long long

  // Дробные числа
  // 1.23e-4 = 1.23 * 10^(-4)
  // Такая нотация называется экспоненциальной записью.
  // "Scientific notation" на английском.

  // Чтобы записать 2 миллиарда можно написать:
  // 2e9

  // Минимум это значение наиболее близкое к нулю
  // lowest => -3.40282e+38
  // min    => 1.17549e-38
  // max    => 3.40282e+38
  // 2 байта
  float floating_point_number = 3.14;

  // lowest => -1.79769e+308
  // min    => 2.22507e-308
  // max    => 1.79769e+308
  // 4 байта
  double double_precision = 3.1415;
  // Используй этот

  // lowest => -1.18973e+4932
  // min    => 3.3621e-4932
  // max    => 1.18973e+4932
  // 8 байт
  long double long_double_precision = 3.1415926535;
  // или этот, но в Visual Studio long double это double на самом деле

  // [-2^7; 2^7)
  // 1 байт
  char character = 'a';

  // Все типы выше могут иметь префикс signed или unsigned,
  // что обозначает "знаковый" и "беззнаковый" соответственно
  // если ты не пишешь ни signed, ни unsigned, то компилятор
  // считает, что переменная signed, то есть знаковая.
  // Если ты напишешь unsigned, то не сможешь нормально хранить
  // отрицательные числа, но сможешь хранить в 2 раза больше положительных значений
  // например, значения int сдвинутся так:
  // [-2^31; 2^31) => [0, 2^32)

  // [false, true]
  bool boolean = true;
  // Любопытно, что этот тип данных занимает 1 байт памяти,
  // хотя использует всего один бит из этого байта.
  // Это происходит потому что у бита нет адреса в памяти, а у байта есть.

  // Если операция проходит с двумя разными типами, то
  // обычно тип с меньшей точностью приводится к типу с большей точностью
  // без твоего непосредственного участия.
  // Такие преобразования называются "неявными", так как компилятор
  // сам преобразует типы по строгому набору правил.
  // Любые операции с char в результате дадут int.
  // Если есть signed и unsigned, то приведётся к unsigned типу.
  // У операции с дробным и целым типом будет дробный результат.

  // int + long long = long long
  // int + float = float
  // double + float = double
  // signed int + unsigned int = unsigned int
  // char + char = int

  int o = 15;
  // Если хочешь явно сказать компилятору какой тип использовать, то
  // используй явное преобразование:
  long long m = (long long)o;
  double k = double(o);

  string s = "kappa";

  // ввод/вывод
  // "cout << что-то;" - выводит что-то в консоль
  // endl выводит символ конца строки
  // читается "си аут"
  cout << "Hello, World!" << endl; // console output
  // "cin >> куда-то;" - считывает из консоли значение куда-то
  // читается "си ин"
  cin >> integer; // console input

  // У каждого символа есть код. Вот таблица символов и их кодов:
  for (int i = 0; i < 256; ++i) {
    cout << i << ": " << char(i) << endl;
  }
  cout << endl;
  // Все буквы и цифры в таблице идут по порядку
  cout << "All digits:" << endl;
  for (char c = '0'; c <= '9'; ++c) {
    cout << c;
  }
  cout << endl << endl;
  cout << "All capital letters:" << endl;
  for (char c = 'A'; c <= 'Z'; ++c) {
    cout << c;
  }
  cout << endl << endl;
  cout << "All lowercase letters:" << endl;
  for (char c = 'a'; c <= 'z'; ++c) {
    cout << c;
  }
  cout << endl << endl;
  // То есть чтобы получить из СИМВОЛА цифры число, нужно написать:
  char symbol = '5';
  cout << "5 as a symbol: " << symbol << endl;
  int num = symbol - '0';
  cout << "5 as a number: " << num << endl;
  // Аналогично для букв можно получить их номер (начиная с нуля) в алфавите:
  symbol = 'p';
  num = symbol - 'a';
  cout << "Letter 'p' has index " << num << " in the alphabet" << endl;
  // Для заглавных тоже самое:
  symbol = 'K';
  num = symbol - 'A';
  cout << "Letter 'K' has index " << num << " in the alphabet" << endl;
  // Аналогично можно получить букву по её индексу (номеру с нуля)
  // Только нужно явно преобразовать к чару, чтобы компилятор не ругался:
  num = 13;
  symbol = char('a' + 13);
  cout << symbol << " has index " << num << " in the alphabet" << endl;
  cout << endl;

  // Арифметические операторы:
  // Бинарные:
  // '+' '-' '*' '/' '%' - сложение, вычитание, умножение, деление, остаток от деления
  int one = 9, other = 3;
  cout << "one   = " << one << endl;
  cout << "other = " << other << endl;
  cout << "one + other = " << (one + other) << endl;
  cout << "one - other = " << (one - other) << endl;
  cout << "one * other = " << (one * other) << endl;
  cout << "one / other = " << (one / other) << endl;
  cout << "one % other = " << (one % other) << endl;
  // Унарныей '-'
  cout << "-one = " << (-one) << endl;
  cout << endl;

  // Логические операции:
  // '&&' '||' - логические И и ИЛИ
  // and   or  - можно писать так
  bool student = false;
  bool smart = true;
  cout << "student = " << student << endl;
  cout << "smart   = " << smart << endl;
  cout << "student AND smart = " << (student and smart) << endl;
  cout << "student OR smart = " << (student or smart) << endl;

  // '!' - инверсия, логическое отрицание
  cout << "NOT student = " << (!student) << endl;
  cout << "NOT smart = " << not smart << endl;
  cout << endl;

  // Операции сравнения
  // '<', '>', '<=', '>=', '==', '!=' - соответственно
  // меньше, больше, меньше или равно, больше или равно, равно, не равно
  // результатом сравнения является логическое значение (true/false)
  cout << "one   = " << one << endl;
  cout << "other = " << other << endl;
  cout << "one < other = " << (one < other) << endl;
  cout << "one > other = " << (one > other) << endl;
  cout << "one <= other = " << (one <= other) << endl;
  cout << "one >= other = " << (one >= other) << endl;
  cout << "one == other = " << (one == other) << endl;
  cout << "one != other = " << (one != other) << endl;
  cout << endl;

  // Условный оператор if
  int a = 123, b = 234;
  if (a < b) { // Если выполняется условие, то заходим в {}
    a = b;
  } else if (a > b) { // Если не выполнилось первое, то аналогично с другим условием
    b = a;
  } else { // Если ни одно не выполнилось, то заходим сюда
    // Блок может быть пустым
  }

  // В c++ нет тернарных сравнений:
  // a < b < c       так нельзя
  // a < b && b < c  так можно

  // Цикл while
  a = 0, b = 123; // a и b уже объявлены, не нужно писать int
  while (a < b) { // Пока выполняется условие
    a += 1; // увеличиваем переменную a на 1.
    // Возвращаемся в начало цикла, на проверку условия.
  }

  // Цикл for
  // for (объявление переменных, внутри цикла; условие; действие после цикла)
  for (int i = 0; i < 123; ++i) {
    // Объявляем целое число i, оно равно 0.
    // Пока оно меньше, чем 123, идём в цикл и
    a += a; // прибавляем к a значение a.
    // Действие после цикла (++i) - увеличиваем переменную i на 1.
  }

  // Инкремент
  a = 0;
  // Префиксный инкремент, предынкремент:
  int c = ++a; // a = 1, c = 1

  // b = ++a:
  // a = a + 1
  // b = a

  // Суффиксный инкремент, постинкремент:
  int d = a++; // d = 1, a = 2

  // b = a++:
  // b = a
  // a = a + 1

  // Цепочка операций выполняется справа-налево:
  int e = a += 1; // a = 3, e = 3
  c = d = e = a;

  // main() должен вернуть 0, если программа успешно завершилась.
  return 0;
}
