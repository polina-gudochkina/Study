// Study.SearchElementArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int getNumberInDiaposone(int start, int end, char coordName)
{
    std::string input = "";
    int result = start - 1;
    int strToIntResult;
    do
    {
        printf("Введите координату %c от %d до %d\n", coordName, start, end);
        cin >> input;
        
        // Пытаемся строку конвертировать числу, если удалосб, то конвертируем ее в результат
        if (sscanf_s(input.c_str(), "%d", &strToIntResult) == 1)
        {
            result = strToIntResult;
        }

    } while (!(result >= start && result <= end));

    return result;
}

int main()
{
    setlocale(LC_ALL, "ru");
    const int xLength = 15;
    const int yLength = 15;
    const int zLength = 15;

    std::string arr[xLength][yLength][zLength] = {};

    for (int z = 0; z < zLength; z++)
    { 
        for (int y = 0; y < yLength; y++)
        {
            for (int x = 0; x < xLength; x++)
            {
                // в ячейках храним адрес ячейки, для проверки правильности выполнения программы
                std:: string str = "z:" + std::to_string(z) + "_y:" + std::to_string(y) + "_x:" + std::to_string(x);
                arr[z][y][x] = str;
            }

        }
    }
   
    int z = getNumberInDiaposone(0, zLength, 'z');

    int y = getNumberInDiaposone(0, zLength, 'y');

    int x = getNumberInDiaposone(0, zLength, 'x');

    printf("По координатам %d %d %d находится число %s", z, y, x, arr[z][y][x].c_str());

    return 0;

  }

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
