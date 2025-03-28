#include <iostream>
#include <cstdlib>  // Для rand()
#include <ctime>    // Для srand()



class Vector {
private:
    double data[3] = { 0, 0, 0 };  // Масив координат вектора
    static int objectCount;      // Лічильник створених об'єктів

public:
    // Конструктор без параметрів (усі координати = 0)
    Vector() {
        objectCount++;
    }

    // Конструктор з одним параметром (усі координати = value)
    Vector(double value) {
        data[0] = data[1] = data[2] = value;
        objectCount++;
    }

    // Конструктор з трьома параметрами (задає x, y, z)
    Vector(double x, double y, double z) {
        data[0] = x; data[1] = y; data[2] = z;
        objectCount++;
    }

    // Конструктор з масивом
    Vector(const double* arr) {
        if (arr) {
            for (int i = 0; i < 3; i++)
                data[i] = arr[i];
        }
        objectCount++;
    }

    // Деструктор з виведенням інформації про стан вектора
    ~Vector() {
        std::cout << "Вектор [" << data[0] << ", " << data[1] << ", " << data[2]
            << "] знищено. Всього векторів: " << --objectCount << std::endl;
    }

    // Введення координат вектора вручну
    void input() {
        std::cout << "Введіть координати x, y, z: ";
        std::cin >> data[0] >> data[1] >> data[2];
    }

    // Генерація випадкового вектора (значення від -10 до 10)
    void randomize() {
        data[0] = (rand() % 21) - 10;  // Генерує число від -10 до 10
        data[1] = (rand() % 21) - 10;
        data[2] = (rand() % 21) - 10;
    }

    // Метод друку вектора
    void print() const {
        std::cout << "[" << data[0] << ", " << data[1] << ", " << data[2] << "]\n";
    }

    // Функція додавання векторів
    Vector add(const Vector& v) const {
        return Vector(data[0] + v.data[0], data[1] + v.data[1], data[2] + v.data[2]);
    }

    // Функція віднімання векторів
    Vector subtract(const Vector& v) const {
        return Vector(data[0] - v.data[0], data[1] - v.data[1], data[2] - v.data[2]);
    }

    // Векторний добуток
    Vector crossProduct(const Vector& v) const {
        return Vector(
            data[1] * v.data[2] - data[2] * v.data[1],
            data[2] * v.data[0] - data[0] * v.data[2],
            data[0] * v.data[1] - data[1] * v.data[0]
        );
    }

    // Функція ділення на число (захист від ділення на 0)
    Vector divide(short divisor) const {
        return (divisor == 0) ? *this : Vector(data[0] / divisor, data[1] / divisor, data[2] / divisor);
    }

    // Отримання кількості створених векторів
    static int getObjectCount() {
        return objectCount;
    }
};

// Ініціалізація статичної змінної (лічильник векторів)
int Vector::objectCount = 0;

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

  setlocale(LC_ALL, "ukr");  // Встановлення української мови для консолі

    std::cout << "Виберіть спосіб створення вектора:\n";
    std::cout << "1 - Ввести вручну\n";
    std::cout << "2 - Генерація випадкового вектора\n";
    int choice;
    std::cin >> choice;

    Vector v1;  // Порожній вектор

    if (choice == 1) {
        v1.input();  // Введення вручну
    }
    else if (choice == 2) {
        v1.randomize();  // Генерація випадкових значень
    }
    else {
        std::cout << "Некоректний вибір!\n";
        return 1;
    }

    std::cout << "Ваш вектор: ";
    v1.print();

    std::cout << "Створення ще двох випадкових векторів...\n";
    Vector v2, v3;
    v2.randomize();
    v3.randomize();

    std::cout << "Вектор 2: "; v2.print();
    std::cout << "Вектор 3: "; v3.print();

    Vector sum = v1.add(v2);
    Vector diff = v1.subtract(v3);
    Vector cross = v2.crossProduct(v3);
    Vector divided = v3.divide(2);

    std::cout << "Сума v1 + v2: "; sum.print();
    std::cout << "Різниця v1 - v3: "; diff.print();
    std::cout << "Векторний добуток v2 × v3: "; cross.print();
    std::cout << "Ділення v3 на 2: "; divided.print();