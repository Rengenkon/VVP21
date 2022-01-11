#include <iostream>
/*
Задание 21

1. Дана квадратная матрица A порядка M (M — нечетное число). Начиная с элемента A1,1 и перемещаясь против часовой стрелки, вывести все ее элементы по спирали: первый столбец, последняя строка, последний столбец в обратном порядке, первая строка в обратном порядке, оставшиеся элементы второго столбца и т. д.; последним выводится центральный элемент матрицы
2. Дана матрица размера M × N и целое число K (1 ≤ K ≤ M). Найти сумму и произведение элементов K-й строки данной матрицы.
3. Дана матрица размера M × N. Найти номер ее столбца с наименьшим произведением элементов и вывести данный номер, а также значение наименьшего произведения
4. Дана матрица размера M × N. В каждом ее столбце найти количество элементов, больших среднего арифметического всех элементов этого столбца
5. Дана целочисленная матрица размера M × N. Найти номер первого из ее столбцов, содержащих только нечетные числа. Если таких столбцов нет, то вывести 0.

Каждое задание сделанно в отдельном классе
*/


class z1
{
private:
    int n;
    int **a;

public:

    z1(int size = 9) {
        n = size;
        a = new int* [n];
        for (int i = 0; i < n; i++) {
            a[i] = new int [n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 10 * i + j + 1;
            }
        }
    }


    void print_arr() {
        int i = -1, j = 0, k = 0;
        while (k < n / 2 + 1) {
            if (i < n - 1 - k && j == k) {
                i++;
                std::cout << a[i][j] << ' ';
            }
            else if (j < n - 1 - k && i == n - 1- k) {
                j++;
                std::cout << a[i][j] << ' ';
            }
            else if (i > k && j == n - 1 - k) {
                i--;
                std::cout << a[i][j] << ' ';
            }
            else if (j > k + 1 && i == k) {
                j--;
                std::cout << a[i][j] << ' ';
            }
            else {
                k++;
                i++;
                std::cout << "\n";
            }
        }
        std::cout << "\n";
    }
};

class z2
{
private:
    int n, m, k;
    int** a;

public:

    z2(int mt = 9, int size = 9, int k = 1) {
        m = mt;
        n = size;
        a = new int* [m];
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 10 * i + j + 1;
            }
        }
    }


    void print_arr() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void foo() {
        int s = 0, p = 1;
        for (int i = 0; i < n; i++) {
            p = p * a[k][i];
            s = s + a[k][i];
        }
        std::cout << "Произведение " << p << "\nСумма " << s << "\n";
    }
};

class z3
{
private:
    int n, m;
    int** a;

public:

    z3(int mt = 9, int size = 9, int k = 1) {
        m = mt;
        n = size;
        a = new int* [m];
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 10 * i + j + 1;
            }
        }
    }


    void print_arr() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void foo() {
        int s = 0;
        unsigned long long int p = 1, k = -1;
        for (int i = 0; i < n; i++) {
            p = 1;
            for (int j = 0; j < m; j++) {
                p = p * a[j][i];
            }
            if (p < k) {
                s = i;
                k = p;
            }
        }
        std::cout << "Произведение " << k << "\nНомер столбца " << s + 1 << "\n";
    }
};

class z4
{
private:
    int n, m;
    int** a;

public:

    z4(int mt = 9, int size = 9, int k = 1) {
        m = mt;
        n = size;
        a = new int* [m];
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 10 * i + j + 1;
            }
        }
    }


    void print_arr() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void foo() {
        int s = 0, k = 0;
        for (int i = 0; i < n; i++) {
            k = 0;
            s = 0;
            for (int j = 0; j < m; j++) {
                s = s + a[j][i];
            }
            for (int j = 0; j < m; j++) {
                if ((double)a[j][i] > s * 1.0 / m) {
                    k++;
                }
            }
            std::cout << i + 1 << ": Количество элементов, больших среднего арифметического всех элементов этого столбца " << k << "\n";
        }
    }
};

class z5
{
private:
    int n, m;
    int** a;

public:

    z5(int mt = 9, int size = 9, int k = 1) {
        m = mt;
        n = size;
        a = new int* [m];
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 10 * i + j + 1;
            }
        }
    }


    void print_arr() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void foo() {
        int s = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[j][i] % 2 != 1) {
                    break;
                }
                if (j == m - 1) {
                    s = i;
                }
            }
            if (s != -1) {
                break;
            }
        }
        std::cout << "номер первого из ее столбцов, содержащих только нечетные числа " << s + 1 << "\n";
    }
};





int main()
{
    setlocale(LC_ALL, "rus");

    z5 first;
    first.print_arr();
    first.foo();

    std::cout << "Hello World!\n";
}