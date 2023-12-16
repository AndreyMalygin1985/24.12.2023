#include <iostream>
#include <Windows.h>
#include <exception>

using namespace std;

// Создайте иерархию пользовательских классов-исключений.В ней должны быть классы для
// разных ситуаций.В качестве предметной области используйте ваши практические и 
// домашние задания.Например, должны присутствовать классы для обработки всевозможных
// математических ошибок, нехватки памяти, проблемам по работе с файлами и т.д.

class FileException : public exception
{
    string message;
public:
    explicit FileException(const string& message) : message(message) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileNotFoundException : public FileException
{
public:
    explicit FileNotFoundException(const string& filename) : 
        FileException("Файл не найден: " + filename) {}
};

class IOException : public FileException
{
public:
    explicit IOException(const string& message) : 
        FileException("Исключение ввода-вывода: " + message) {}
};

class MathException : public exception 
{
    string message;
public:
    explicit MathException(const string& message) : message(message) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }    
};

class DivideByZeroException : public MathException 
{
public:
    explicit DivideByZeroException() : MathException("Ошибка деления на ноль") {}
};

class MemoryException : public exception 
{
    string message;
public:
    explicit MemoryException(const string& message) : message(message) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    } 
};

class OutOfMemoryException : public MemoryException 
{
public:
    OutOfMemoryException() : MemoryException("Недостаточно памяти") {}
};

int main()
{
    SetConsoleOutputCP(1251);

    try {
        throw FileNotFoundException("example.txt");
    }
    catch (exception& ex) {
        cout << "Пойманное исключение: " << ex.what() << endl;
    }

    try {
        throw DivideByZeroException();
    }
    catch (exception& ex) {
        cout << "Пойманное исключение: " << ex.what() << endl;
    }

    try {
        throw OutOfMemoryException();
    }
    catch (exception& ex) {
        cout << "Пойманное исключение: " << ex.what() << endl;
    }

    return 0;
}