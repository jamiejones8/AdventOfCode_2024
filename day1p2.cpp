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

    int similarityScore = 0;

    for(int i = 0; i < SIZE; i++)
    {
        int counter = 0;

        for(int j = 0; j < SIZE; j++)
        {
            if(leftArr[i] == rightArr[j])
            {
                counter++;
            }
        }

        similarityScore += (leftArr[i] * counter);
    }

    cout << "Similarity score: " << similarityScore << endl;
}