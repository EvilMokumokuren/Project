/* Колпакова Е., Lesson 6, Visual Studio Code
1. Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить память. =) 
Разбить программу на функции.
2. Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand. Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
3. Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым). Имена файлов запросить 
у польлзователя.
4. * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
5. * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// #1
int* ptrArrTask1;

//#2
ofstream fout;
ifstream fin;

/* 
1. Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить память. =) 
Разбить программу на функции.
*/
void InitArrTask1(int* ptrArrTask1, int SizeTask1)
{
    for (int i = 0; i < SizeTask1; i++)
    {
        ptrArrTask1[i] = (i == 0) ? 1 : ptrArrTask1[i - 1] * 2;
        cout << ptrArrTask1[i] << " ";
    }
    cout << endl;

    return;
}

void Task1(int* ptrArrTask1, int SizeTask1)
{
    ptrArrTask1 = new (std::nothrow) int[SizeTask1];

    if (ptrArrTask1 != nullptr)
    {
        InitArrTask1(ptrArrTask1, SizeTask1);
        delete[] ptrArrTask1;
        ptrArrTask1 = nullptr;
    }
    else
    {
        cout << "Error! Can not allocate memory!";
    }

    return;
}

// 2. Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand. Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
int** AllocateMemory(size_t SizeT2_m, size_t SizeT2_n)
{
    int** ptrArrTask2 = new int* [SizeT2_m];
    for (size_t i = 0; i < SizeT2_m; i++) 
    {
        ptrArrTask2[i] = new int[SizeT2_n];
    }
    
    return ptrArrTask2;
}

void DeleteMemory(int ** ptrArrTask2, size_t SizeT2_m)
{
    for (size_t i = 0; i < SizeT2_m; i++) {
        delete[] ptrArrTask2[i];
    }
    delete[] ptrArrTask2;
    ptrArrTask2 = nullptr;

    return;
}

void Task2(int** ArrayTask2, size_t SizeT2_m, size_t SizeT2_n)
{
               
    for (size_t i = 0; i < SizeT2_m; i++)
    {
        for (size_t j = 0; j < SizeT2_n; j++)
        {
            ArrayTask2[i][j] = rand() % 100;
            if (ArrayTask2[i][j] < 10)   //делаю красивый вывод, иначе столбик едет
            {
                cout << " " << ArrayTask2[i][j] << " ";
            }
            else
            {
                cout << ArrayTask2[i][j] << " ";
            }            
        }
        cout << endl;
    }
    
   return;
}

/*
3. Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым). Имена файлов запросить
у пользователя.
*/
void CreateFileTXT(string FileName)
{
    FileName = FileName + ".txt";
    ofstream fout(FileName);
    return;
}

void FillFileTXT(string FileName, int NumberOfLines)
{
    char temp;
    FileName = FileName + ".txt";
    fout.open (FileName, std::ofstream::binary);
    fout << "File: ";
    if (fout.is_open())
    {
        for (int i = 0; i < (NumberOfLines - 5); i++)
        {
            temp = 'a' + rand() % ('z' - 'a');
            fout << temp << " ";
        }
    }
    else
    {
        cout << "Error. Can not open file.";
    }
    fout.close();
   return;
}

//4. * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
void MakeOneBigFile(string FileName, string OneOfFiles_1, string OneOfFiles_2)
{
    FileName = FileName + ".txt";
    OneOfFiles_1 = OneOfFiles_1 + ".txt";
    OneOfFiles_2 = OneOfFiles_2 + ".txt";
    

    fin.open(OneOfFiles_1, std::ifstream::binary);
    fout.open(FileName);
    
        if (fin.is_open())
            if (fout.is_open())
            {
                {
                    fout << "Fin: "; // без этой строки кодировка едет. не смогла разобраться как сделать ее красивой при открытии ручками
                    
                    //подсмотрела в интернете, определяет, сколько символов в файле, что б не передавать лишнего
                    fin.seekg(0, fin.end); 
                    int length = fin.tellg(); 
                    fin.seekg(0, fin.beg);

                    char* temp = new char[length];
                    fin.read(temp, length);
                    fout.write(temp, length);
                    fin.close();
                    delete[] temp;
                }
            fin.close();
            }
        else
        {
            cout << "Error. Can not open file.";
        }
                      
        fin.open(OneOfFiles_2, std::ifstream::binary);
        if (fin.is_open())
            if (fout.is_open())
            {
                {
                    //подсмотрела в интернете, определяет, сколько символов в файле, что б не передавать лишнего
                    fin.seekg(0, fin.end);
                    int length = fin.tellg();
                    fin.seekg(0, fin.beg);

                    char* temp = new char[length];
                    fin.read(temp, length);
                    fout.write(temp, length);
                    fin.close();
                    delete[] temp;
                }
                fin.close();
                fout.close();
            }
            else
            {
                cout << "Error. Can not open file.";
            }
        return;
}

// 5. * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
void FindTheWord(string FileName, string Word)
{
    string str;
    FileName = FileName + ".txt";

    fin.open(FileName);
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> str;

            std::regex r(Word); 
            std::smatch m;

            if (std::regex_search(str, m, r))
            {
                cout << "Word was found! ";                
            }
                        
        }
    }

    cin.get();
    return;
 }


int main()
{
    cout << "Hello!" << endl;
    
    //#1
    cout << "Task #1" << endl;
     
    int SizeTask1;
    
    do
    {
        cout << "Please, enter size of your Array: ";
        cin >> SizeTask1;
    } while (SizeTask1 <= 0);

    cout << "Answer Task1: ";
    Task1(ptrArrTask1, SizeTask1);

    // #2
    cout << "Task #2" << endl;
    
    int SizeT2_m, SizeT2_n;

    cout << "Input array size:" << endl;
    do
    {
    cout << "Input rows: ";
    cin >> SizeT2_m;
    } while (SizeT2_m <= 0);
    do
    {
    cout << "Input colums: ";
    cin >> SizeT2_n;
    } while (SizeT2_n <= 0);

    AllocateMemory (SizeT2_m, SizeT2_n);
    
    cout << "Answer Task2: " << endl;

    int** ArrayTask2 = AllocateMemory(SizeT2_m, SizeT2_n); // выделение памяти для массива
    Task2 (ArrayTask2, SizeT2_m, SizeT2_n); // заполнить рандомно
    DeleteMemory(ArrayTask2, SizeT2_m); //удалить выделенную память
    cout << endl;

    //#3
    cout << "Task #3" << endl;

    string FileName1, FileName2;
    int NumberOfLines;

    cout << "Input File 1 name: ";
    cin >> FileName1;
    cout << "Input File 2 name: ";
    cin >> FileName2;

    CreateFileTXT(FileName1);
    CreateFileTXT(FileName2);

    do
    {
    cout << "Input NumberOfLines (50-100 symbols): ";
    cin >> NumberOfLines;
    } while ((NumberOfLines < 50) || (NumberOfLines > 100));

    FillFileTXT(FileName1, NumberOfLines);
    FillFileTXT(FileName2, NumberOfLines);
    
    cout << endl;

    //#4
    cout << "Task #4" << endl;

    string FileName3;
    
    cout << "Input general File name: ";
    cin >> FileName3;
    
    CreateFileTXT(FileName3);
    MakeOneBigFile(FileName3, FileName1, FileName2);

    //#5
    cout << endl << "Task #5" << endl;

    string Word, FileNameTask5;
    cout << "Input File name (only txt files): ";
    cin >> FileNameTask5;
    cout << "Input searching word: ";
    cin >> Word;

    FindTheWord(FileNameTask5, Word);
    
    cin.get();
    return 0;
}
