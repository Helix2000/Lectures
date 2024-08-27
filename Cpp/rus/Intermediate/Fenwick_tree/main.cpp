#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

// Добавь к одному, сумма на отрезке
class FTAddSingleSumOnSegment {
private:
  int n;
  vector<int> fen;
public:
  void build(vector<int> &arr) {
    n = (int)arr.size();
    fen.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      fen[i] += arr[i - 1];
      int next = i + (i&-i);
      if (next <= n) {
        fen[next] += fen[i];
      }
    }
  }

  void add(int val, int i) {
    for (; i <= n; i += i & (-i)) {
      fen[i] += val;
    }
  }

  int get(int r) {
    int res = 0;
    for (; r > 0; r -= r & (-r)) {
      res += fen[r];
    }
    return res;
  }

  int sum(int l, int r) {
    return get(r) - get(l - 1);
  }
};

// Добавь на отрезке, скажи элемент
class FTAddToSegmentGetSingle {
private:
  int n;
  vector<int> fen;
public:
  void build(int n_) {
    n = n_;
    fen.assign(n + 1, 0);
  }
  void add(int v, int r) {
    for (; r > 0; r -= r&-r) {
      fen[r] += v;
    }
  }
  void add(int v, int l, int r) {
    add(v, r);
    add(-v, l - 1);
  }
  int get(int i) {
    int res = 0;
    for (; i <= n; i += i&-i) {
      res += fen[i];
    }
    return res;
  }
};

// Добавь к элементу, скажи сумму на подпрямоугольнике
class FT2D {
private:
  int n, m;
  vector<vector<int>> fen;
public:
  void build(int n_, int m_) {
    n = n_, m = m_;
    fen.assign(n + 1, vector<int>(m + 1, 0));
  }
  void add(int v, int i, int j) {
    for (int i1 = i; i1 <= n; i1 += i1&-i1) {
      for (int j1 = j; j1 <= m; j1 += j1&-j1) {
        fen[i1][j1] += v;
      }
    }
  }
  int get(int i, int j) {
    int res = 0;
    for (int i1 = i; i1 > 0; i1 -= i1&-i1) {
      for (int j1 = j; j1 > 0; j1 -= j1&-j1) {
        res += fen[i1][j1];
      }
    }
    return res;
  }
};

// Спуск в Фенвике
class FTree {
private:
  int n, l;
  vector<int> fen;
public:
  void build(int n_) {
    n = n_;
    fen.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      fen[i] = (i & -i);
    }
    l = __lg(n);
  }
  void add(int v, int ind) {
    for (int i = ind + 1; i <= n; i += i&-i) {
      fen[i] += v;
    }
  }
  int descend(int x) {
    int offset = 0;
    for (int p = l; p >= 0; --p) {
      // Не забывай выход за границы. А то спустишься вправо,
      // а там части дерева просто нет.
      if (offset + (1 << p) <= n && fen[offset + (1 << p)] <= x) {
        offset += (1 << p);
        x -= fen[offset];
      }
    }
    return offset;
  }
};

signed main() {
  // Задача. Есть массив из n чисел. Есть q запросов вида:
  // 1. Увеличь элемент на x;
  // 2. Скажи сумму на отрезке.
  // Мы знаем что такое префиксные суммы.
  // ps[i] = сумма первых i элементов.
  // Предпосчитав их, можно отвечать на второй запрос за O(1)
  // Но первый запрос всё портит, ведь чтобы пересчитать
  // префикс-суммы, нужно потратить O(n) операций и будет долго.
  // Посчитаем вместо этого Фенвик-суммы:
  // fen[i] = сумма последних f(i) элементов
  // f(i) = i&-i => взятие наименьшего единичного бита. Например,
  // f(12) = f(1100_2) = 100_2 = 4
  // Перепишем формально:
  // fen[i] = sum(i - f(i); i]
  // То есть i-й элемент включаем, i-f(i) не включаем
  // Данная структура будет выглядеть как дерево:

  //  4   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  //  3   xxxxxxxxxxxxxxxxxxxxxxx                       |     индексы, покрытые
  //  2   xxxxxxxxxxx           | xxxxxxxxxxx           |  <= иксами входят в
  //  1   xxxxx     | xxxxx     | xxxxx     | xxxxx     |     сумму для значения
  //  0   xx  | xx  | xx  | xx  | xx  | xx  | xx  | xx  |
  //    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 <= сам индекс
  // from  0  0  2  0  4  4  6  0  8  8 10  8 12 12 14  0 <= от какого индекса
  //   to  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 <= до какого индекса

  // Чтобы посчитать префикс-сумму через Фенвик-суммы, можно брать сумму
  // последних f(i) элементов, пока не дойдём до нуля. Иначе говоря,
  // мы берём fen[i], затем вычитаем из i наименьший бит f(i).
  // Можно записать формально:
  // ps[i] = fen[i] + fen[i - f(i)] + fen[i - f(i) - f(i - f(i))] + ...
  // ps[i] = sum(i - f(i); i] + sum(i - f(i) - f(i - f(i)); i - f(i)]
  // next_i = i - i&-i
  // Мы посмотрим не больше логарифма Фенвик-сумм, ведь в числе не больше
  // логарифма единичных бит.

  // Как же обновляться?
  // Для элемента, нужно найти все Фенвик-суммы, которые его покрывают.
  // Рассмотрим все такие Фенвик-суммы в порядке возрастания у них правой
  // границы. При этом левая граница буден находиться либо левее, либо там же,
  // где и у предыдущей Фенвик-суммы. Формально, есть Фенвик-суммы,
  // затрагивающие текущий элемент:
  // sum(i1 - f(i1), i1], sum(i2 - f(i2), i2], ...
  // Говорим, что будем рассматривать их в порядке увеличения правой границы.
  // i1 < i2 < ...
  // Тогда левая граница будет либо левее, либо там же, где у предыдущей
  // Фенвик-суммы:
  // i2 - f(i2) <= i1 - f(i1)
  // Перенесём индексы:
  // i2 - i1 <= f(i2) - f(i1)
  // i2 > i1. Значит, i2 - i1 > 0
  // 0 < i2 - i1 <= f(i2) - f(i1)
  // 0 < f(i2) - f(i1)
  // f(i2) > f(i1)
  // Это значит, что у следующей Фенвик-суммы наименьший единичный бит
  // должен быть строго больше, чем у предыдущей Фенвик-суммы. При этом
  // она должна быть минимально возможной, чтобы мы не пропустили ни одну
  // Фенвик-сумму, которая покрывает текущий элемент.
  // Этого можно достигнуть просто добавив к числу младший единичный бит!
  // next_i = i + i&-i
  // Не более логарифма Фенвик-сумм покрывают один элемент, ведь мы не
  // можем добавлять наименьший единичный бит к числу больше логарифма раз,
  // за границы выйдем.

  // Итого оба запроса будут работать за O(log(n))

  // Осталось научиться строить Дерево Фенвика. Можно это сделать за
  // O(n*log(n)) просто применив операцию добавления n раз, но можно за O(n).
  // Просто построим сначала префикс-суммы, а потом справа-налево посчитаем
  // Фенвик-суммы. Смотри реализацию в начале файла.

  // Очень похоже можно реализовать пару операций:
  // 1. Прибавь на отрезке
  // 2. Узнай элемент
  // Тогда мы будем хранить в fen[i] обновления для
  // последних f(i) элементов, а не сами суммы.
  // Чтобы обработать первый запрос, нужно увеличить префикс-сумму f[r]
  // и уменьшить перфикс-сумму f[l - 1].
  // Затем, когда придёт второй запрос, мы будем смотреть как его
  // обновили Фенвик-суммы.
  // элементы i < l обновятся сначала положительным изменением от f[r],
  // затем отрицательным изменением от f[l - 1]. Таким образом изменение
  // обнуляется и элемент не меняется.
  // элементы l <= i <= r изменятся от одного обновления f[r]
  // элементы r < i не будут затронуты.
  // Смотри пример реализации в начале файла.

  // Также можно реализовать пару операций:
  // 1. Увеличь число
  // 2. Скажи максимум на префиксе
  // Это будет работать только в такой связке потому что значения
  // либо увеличатся и значение обновится, либо ничего не поменяется.

  // Фенвик очень легко обобщается на несколько измерений. Для этого
  // нужно всего лишь написать ещё один точно такой же цикл
  // по второму измерению. Смотри реализацию в начале файла.

  // Есть техника "спуск по дереву". Её можно показать на примере
  // дерева Фенвика. Конкретно - мы хотим узнать где находится
  // последняя префиксная сумма, для которой выполняется ps <= sum.
  // Очень похоже на бинарный поиск.
  // Пускай мы построили дерево Фенвика на 16 единичных элементах и
  // хотим узнать на каком индексе сумма будет больше 11:
  //  4   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1
  //  3   xxxxxxxxxxxxxxxxxxxxxx2                       |
  //  2   xxxxxxxxxxx           | xxxxxxxxxx3           |
  //  1   xxxxx     | xxxxx     | xxxx4     | xxxxx     |
  //  0   xx  | xx  | xx  | xx  | xx  |  5  | xx  | xx  |
  //    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
  // Обойдём вершины в порядке как на рисунке.
  // Будем хранить:
  // p - текущая высота
  // offset - текущий отступ слева
  // rem = sum - сколько осталось "добрать" до нужной суммы
  // 1. p=4. fen[offset + 2^p] = 16
  // 16 > 11. Ничего не делаем. Спускаемся влево.

  // 2. p=3. fen[offset + 2^p] = 8
  // 8 <= 11. rem -= 8, offset += 2^p. Спускаемся вправо.
  // rem = 3, offset = 8

  // 3. p=2. fen[offset + 2^p] = 4
  // 3 > 4. Ничего не делаем. Спускаемся влево.

  // 4. p=1. fen[offset + 2^p] = 2
  // 3 >= 2. rem -= 2, offset += 2^p. Спускаемся вправо.
  // rem = 1, offset = 10

  // 5. p=0. fen[offset + 2^p] = 1
  // 1 >= 1. rem -= 1, offset += 2^p. Заканчиваем
  // rem = 0, offset = 11

  // offset это и есть ответ. Действительно 11-я префикс-сумма
  // равна 11 и она не меньше x=11.
  // Смотри пример в начале файла.

  return 0;
}
