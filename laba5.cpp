#include <iostream>
#include<random>
#include<ctime>

bool is_correct(int&);
bool is_natural(int);
bool prov_type(int&);
bool prov_row(int&);
bool prov_col(int&);
int** Make(int, int);
bool Fill_mas_rand(int**, int, int);
bool Fill_mas(int**, int, int);
void Free_mas(int**, int);
void print_Arr(int, int, int**);
void sort(int**, int, int);
void anothersort(int**, int, int);
int sum_elem_with_zero(int**, int, int);
int main()
{
    try
    {
        int row{ 0 };
        int col{ 0 };
        if (!prov_row(row))
        {
            throw false;
        }
        if (!prov_col(col))
        {
            throw false;
        }
        int** mas = Make(row, col);
        int type{ 0 };
        if (!prov_type(type))
        {
            throw false;
        }
        if (type == 1) //random
        {
            Fill_mas_rand(mas, row, col);
        }
        if (type ==2)
        {
            if (!Fill_mas(mas, row, col))
            {
                throw false;
            }
        }
        if (type != 1 && type != 2)
        {
            throw false;
        }
        std::cout << "sum of elements in columns with at least one zero = " << sum_elem_with_zero(mas, row, col);
        std::cout << std::endl;
        anothersort(mas, row, col);
        sort(mas, row, col);
        std::cout << "sort array " << '\n';
        print_Arr(row, col, mas);
        Free_mas(mas, row);
    }
    catch (bool)
    {
        std::cout << "mistake";
    }
    return 0;
}

bool Fill_mas(int** mas, int row, int col)
{
    std::cout << "Input elements of the array:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "Element [" << i << "][" << j << "]: ";
            if (!is_correct(mas[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}
bool Fill_mas_rand(int** mas, int row, int col)
{
    std::cout << "input min and max numbers" << '\n';
    int min{0};
    int max{0};
    is_correct(min);
    is_correct(max);
    srand(time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "Element [" << i << "][" << j << "]: ";
            mas[i][j] = rand()%(max-min+1)+min;
            std::cout << mas[i][j];
            std::cout << std::endl;
        }
    }
    return true;
}
void Free_mas(int** mas, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] mas[i];
    }
    delete[] mas;
}
bool is_correct(int& number)
{
    return(std::cin >> number) ? true : false;
}
bool is_natural(int number)
{
    return(number > 0) ? true : false;
}
int** Make(int row, int col)
{

    int** mas = new int* [row];

    for (int i = 0; i < row; i++)
    {
        mas[i] = new int[col];
    }
    return mas;
}

bool prov_row(int& row)
{
    std::cout << "Input the size of a two-dimensional array\n";
    std::cout << "Number of rows: ";
    if (is_correct(row) && is_natural(row))
    {
        return 1;
    }
    return 0;
}
bool prov_col(int& col)
{
    std::cout << "Number of columns: ";
    if (is_correct(col) && is_natural(col))
    {
        return 1;
    }
    return 0;
}
bool prov_type(int& type)
{
    std::cout << "input 1 if you wont random numbers, input 2 if you wont input numbers in array"<<'\n';
    if (is_correct(type) && is_natural(type) && type ==1 || type ==2)
    {
        return 1;
    }
    return 0;
}

void print_Arr(int row, int col, int** arr)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void sort(int** arr1, int row, int col)
{
    for (int i = 0; i < row; i += 2)
    {
        //std::cout << i << std::endl;
        for (int j = 1; j < col; j++)
        {
            int key = arr1[i][j];
            int k = j-1;
            while (k >= 0 && arr1[i][k] > key)
            {
                arr1[i][k + 1] = arr1[i][k];
                k--;
            }
            arr1[i][k + 1] = key;
        }
    }
}
int sum_elem_with_zero(int** arr, int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i ++)
    {
        int prov = 1;
        for (int j = 0; j < col; j++)
        {
            if (prov == 1)
            {
                if (arr[i][j] == 0)
                {
                    for (int k = 0; k < col; k++)
                    {
                        sum += arr[i][k];
                        prov = 0;
                    }
                }
            }
        }
    }
    return sum;
}
void anothersort(int** arr1, int row, int col)
{
    for (int i = 1; i < row; i += 2)
    {
        for (int j = 1; j < col; j++)
        {
            int key = arr1[i][j];
            int k = j-1;
            while (k >= 0 && arr1[i][k] < key)
            {
                arr1[i][k + 1] = arr1[i][k];
                k--;
            }
            arr1[i][k + 1] = key;
        }
    }
}