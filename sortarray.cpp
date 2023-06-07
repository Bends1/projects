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
    cout << "Введите 2 массива из чисел через пробел ";
    getline(cin, userNumbs1);
    getline(cin, userNumbs2);
    string userArray = userNumbs1 + " " + userNumbs2;
    vector<int> numbArray = {0};
    for (int i = 0; i < (int)userArray.size(); ++i) {
        if (userArray[i] == ' ') {
            numbArray.push_back(0); // при пробеле, поймем, что началось новое число
        } else {
            numbArray.back() *= 10; 
            numbArray.back() += userArray[i] - '0'; // добавили новую цифру числа
        }
    }
    int n = numbArray.size();
		
    for (int startIndex = 0; startIndex < n - 1; ++startIndex)
	{
		// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
		// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		int smallestIndex = startIndex;
 
		// Затем ищем элемент поменьше в остальной части массива
		for (int currentIndex = startIndex + 1; currentIndex < n; ++currentIndex)
		{
			// Если мы нашли элемент, который меньше нашего наименьшего элемента,
			if (numbArray[currentIndex] < numbArray[smallestIndex])
				// то запоминаем его
				smallestIndex = currentIndex;
		}
 
		// smallestIndex теперь наименьший элемент. 
        // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
		swap(numbArray[startIndex], numbArray[smallestIndex]);
	}
 
	// Теперь, когда весь массив отсортирован - выводим его на экран
     for (int index = 0; index < n; ++index){
        cout << numbArray[index] << ' ';
    }


}