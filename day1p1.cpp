#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

const int SIZE = 1000;

void sortLeftArray(int leftArr[], int SIZE)
{
    sort(leftArr, leftArr + SIZE);
}

void sortRightArray(int rightArr[], int SIZE)
{
    sort(rightArr, rightArr + SIZE);
}

int main()
{
    ifstream fin;
    fin.open("day1input.txt");

    if(!fin)
    {
        cout << "Error opening file. Terminating program." << endl;

        return -1;
    }

    int leftArr[SIZE];
    int rightArr[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        fin >> leftArr[i];
        fin >> rightArr[i];
    }

    sortLeftArray(leftArr, SIZE);
    sortRightArray(rightArr, SIZE);

    int totalDistance = 0;

    for(int i = 0; i < SIZE; i++)
    {
        int difference = leftArr[i] - rightArr[i];
    
        totalDistance += fabs(difference);
    }

    cout << "Total Distance: " << totalDistance << endl;
}