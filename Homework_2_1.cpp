#include <iostream>
#include <fstream>


int main()
{
    setlocale(LC_ALL, "Russian");


    std::ifstream inFile("in.txt");
    if (!inFile.is_open())
    {
        std::cout << "Не удалось открыть файл для ввода" << std::endl;

        return 1;
    }

    int firstArrSize = 0;
    inFile >> firstArrSize;
    int* firstArr = new int[firstArrSize] {};
    
    inFile >> firstArr[firstArrSize - 1];
    for (int i = 0; i < firstArrSize - 1; ++i)
    {
        inFile >> firstArr[i];
    }


    int secondArrSize = 0;
    inFile >> secondArrSize;
    int* secondArr = new int[secondArrSize] {};

    for (int i = 1; i < secondArrSize; ++i)
    {
        inFile >> secondArr[i];
    }
    inFile >> secondArr[0];

    inFile.close();


    std::ofstream outFile("out.txt");
    if (!outFile.is_open())
    {
        std::cout << "Не удалось открыть файл для вывода" << std::endl;

        return 1;
    }

    outFile << secondArrSize << "\n";
    for (int i = 0; i < secondArrSize; ++i)
    {
        outFile << secondArr[i] << " ";
    }
    outFile << "\n";

    outFile << firstArrSize << "\n";
    for (int i = 0; i < firstArrSize; ++i)
    {
        outFile << firstArr[i] << " ";
    }
    outFile << "\n";

    outFile.close();

    delete[] firstArr;
    delete[] secondArr;
}