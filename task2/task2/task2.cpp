#include <iostream>
#include <cmath>

class Vector {
private:
    double data[3] = { 0, 0, 0 }; // Масив координат
    static int objectCount; // Лічильник об'єктів

public:
    Vector() { objectCount++; } // Конструктор без параметрів
    Vector(double value) { data[0] = data[1] = data[2] = value; objectCount++; } //Конструктор з одним параметром
    Vector(double x, double y, double z) { data[0] = x; data[1] = y; data[2] = z; objectCount++; } //
    Vector(const double* arr) { if (arr) for (int i = 0; i < 3; i++) data[i] = arr[i]; objectCount++; } //Конструктор з масивом
    ~Vector() { objectCount--; } //Деструктор зменшує лічильник об'єктів objectCount, коли об'єкт знищується

    void print() const { std::cout << "[" << data[0] << ", " << data[1] << ", " << data[2] << "]\n"; } //Функція друку: виводить координати вектора на екран
    Vector add(const Vector& v) const { return Vector(data[0] + v.data[0], data[1] + v.data[1], data[2] + v.data[2]); }
    Vector subtract(const Vector& v) const { return Vector(data[0] - v.data[0], data[1] - v.data[1], data[2] - v.data[2]); }
    Vector crossProduct(const Vector& v) const {
        return Vector(
            data[1] * v.data[2] - data[2] * v.data[1],
            data[2] * v.data[0] - data[0] * v.data[2],
            data[0] * v.data[1] - data[1] * v.data[0]
        );
    }
    Vector divide(short divisor) const { return divisor == 0 ? *this : Vector(data[0] / divisor, data[1] / divisor, data[2] / divisor); } //функція divide виконує ділення елементів вектора на ціле число divisor
    static int getObjectCount() { return objectCount; } //Лічильник об'єктів: функція getObjectCount повертає кількість створених об'єктів
};

int Vector::objectCount = 0;

int main() {
    Vector v1, v2(5.5), v3(1, 2, 3);

    double arr[] = { 4, 5, 6 }; //Оголошення масиву та ініціалізація вектора
    Vector v4(arr); // Правильна передача масиву

    Vector sum = v2.add(v3), diff = v2.subtract(v3), cross = v2.crossProduct(v3), divided = v3.divide(2);

    v1.print(); v2.print(); v3.print(); v4.print();
    sum.print(); diff.print(); cross.print(); divided.print();
    std::cout << "Vectors created: " << Vector::getObjectCount() << std::endl;

    return 0;
}
