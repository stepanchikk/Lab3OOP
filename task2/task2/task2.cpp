#include <iostream>

class Vector {
private:
    double data[3] = {0, 0, 0};  // Масив координат вектора
    static int objectCount;      // Лічильник створених об'єктів

public:
    // Конструктор без параметрів (всі координати = 0)
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
    std::cout << "Створення векторів...\n";
    
    Vector v1, v2(5.5), v3(1, 2, 3);
    
    double arr[] = { 4, 5, 6 };
    Vector v4(arr);

    Vector sum = v2.add(v3);
    Vector diff = v2.subtract(v3);
    Vector cross = v2.crossProduct(v3);
    Vector divided = v3.divide(2);

    v1.print();
    v2.print();
    v3.print();
    v4.print();
    sum.print();
    diff.print();
    cross.print();
    divided.print();

    std::cout << "Всього створено векторів: " << Vector::getObjectCount() << std::endl;
    
    std::cout << "Завершення програми...\n";

    return 0;  // Тут всі об'єкти будуть знищені, і деструктор виведе інформацію
}