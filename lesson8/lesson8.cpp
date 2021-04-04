#include <iostream>
#include <cstdlib>

    // 2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра.
    // Написать класс Bar, хранящий вещественное число y(конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a.
    // Если y + a > 100, возбуждается исключение типа Ex с данными ay, иначе в y заносится значение a.
class Ex
{
public:
    double x;
    Ex(const double& x_) :x(x_) {}
    ~Ex() {}
  
};

class Bar
{
private:
    double y;

public:
    Bar() { y = 0; }
    ~Bar() {}
    void set(const double& a)
    {
        if (y + a <= 100)
        {
            y = a;
        }
        else throw 111;
    }
};



// 3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию.
// Эти методы должны запускать исключение OffTheField, если робот должен уйти с сетки, и IllegalCommand, 
// если подана неверная команда(направление не находится в нужном диапазоне).
// Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.

class Robot
{
private:
    int x = 1;
    int y = 1;
public:
    Robot() {}
    ~Robot() {}
    void move(char command)
    {
        switch (command) 
        {
         case 'u':
            if (y >= 2)
            {
                --y;
            }
            else throw "y < 0.";
            break;
         case 'd':
            if (y <= 9)
            {
                ++y;
            }
            else throw "y > 10.";
            break;
         case 'r':
            if (x <= 9)
            {
                ++x;
            }
            else throw "x > 10";
            break;
         case 'l':
            if (x >= 2)
            {
                --x;
            }
            else throw "x < 0";
            break;
        default:
            throw 100;
            break;
        }
        
    };

    int getX() { return x; };
    int getY() { return y; };
};



int main()
{
    // 1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, если второй параметр равен 0. 
    // В функции main выводить результат вызова функции div в консоль, а также ловить исключения.

    std::cout << "Task 1." << '\n' << std::endl;
    int first;
    int second;
    std::cout << "Enter the first integer number:" << std::endl;
    std::cin >> first;
    std::cout << "Enter the second integer number:" << std::endl;
    std::cin >> second;
   
    try 
    {
        if (second == 0)
        throw "DivisionByZero";
        div_t divresult;
        divresult = div(first, second);
        std::cout << first <<" / " << second << ".  Quotient is "  << divresult.quot << ", remainder is " << divresult.rem<< "."<<std::endl;
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << std::endl;
    }
   
    std::cout << '\n' << std::endl;
    // 2. В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
    // Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
    // В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.

    std::cout << "Task 2." << '\n' << std::endl;
    Bar bar;
    int x{};
    do
    {
        try
        {
            bar.set(x);
        }
        catch (int)
        {
            if (111)
            std::cerr << "exception: y + a > 100." << std::endl;
        }
        std::cout << "Enter the number: ";
    }
    while (std::cin >> x && x != 0);


    // Task 3. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую подробную информацию
    // о всех возникающих ошибках.

    std::cout << '\n' << std::endl;
    std::cout << "Task 3." << '\n' << std::endl;

    Robot R2D2;
    char command{};
    
    while (1)
    {
        std::cout << "R2D2 is located on the cell with the coordinates x = " << R2D2.getX() << ", y = " << R2D2.getY() << "." << std::endl;
        std::cout << "Enter the command (q - quit, u - up, d - down, r - right, l - left): " << std::endl;
        std::cin >> command;
        if (command == 'q') break;

        try
        {
            R2D2.move(command);
        }
        catch (const char* n)
        {
            std::cerr << "Exeption OffTheField: " << n << "."<< std::endl;

        }
        catch (int)
        {
            if (100)
                std::cerr << "Exeption IllegalCommand." << std::endl;
        }
        
    };

    return 0;
}
