#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void FillArray(int *arr, string str, int size)
{
    for(int i = 0; i < size; i++){
        if(str.at(i) == ' ')
        {
            continue;
        }
        arr[i] = str.at(0);
    }
}
void ShowArray(int *arr, int size)
{
    for(int i = 0; i< size; i++)
    {
        cout << arr[i] << endl;
    }
}
int arrLen(char *arr)
{
    int counter = 0;
    while(arr[counter != '\0']){
        counter++;
    }
    return counter;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    string userNumbs1;
    string userNumbs2;
    cout << "Write 2 arrays of number with 'space' ";
    getline(cin, userNumbs1);
    getline(cin, userNumbs2);
    string userArray = userNumbs1 + " " + userNumbs2;
    vector<int> numbArray = {0};
    for (int i = 0; i < (int)userArray.size(); ++i) {
        if (userArray[i] == ' ') {
            numbArray.push_back(0); 
        } else {
            numbArray.back() *= 10; 
            numbArray.back() += userArray[i] - '0'; 
        }
    }
    int n = numbArray.size();
		
    for (int startIndex = 0; startIndex < n - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < n; ++currentIndex)
		{
			if (numbArray[currentIndex] < numbArray[smallestIndex])
				smallestIndex = currentIndex;
		}
		swap(numbArray[startIndex], numbArray[smallestIndex]);
	}
     for (int index = 0; index < n; ++index){
        cout << numbArray[index] << ' ';
    }
}
