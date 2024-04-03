#include <iostream>
#include <iostream>
#include <fstream>

int len(char* arr) { //Функция, вычисляющая длину конкретного слова, передаваемого как аргумент
	int counter = 0;
	for (int i = 0; arr[i] != '\0'; i++) // Поскольку мы считываем СЛОВА(тип const char*), а не БУКВЫ(тип char),
											//то в конце всегда будет нулевой символ '\0', добавляемый компиллятором
	{
		counter++;
	}
	return counter;
}
class word //Заводим класс "Слово", в котором будут обрабатываться непосредственно слова
{
public:
	word(int size) {                             // Конструктор, сразу в скобках при создании слова задаём его длину
		length = size;
		letters = new char[size];
	}
	word() {
	}
	void append(char* arr) {
		letters = arr;
	}
	char lastsymbol() {
		for (int i = 0; letters[i] != '\0'; i++)
		{
			if (letters[i + 1] == '\0') {
				return letters[i];
			}
		}
	}
	int size() {
		return length;
	}
private:
	int length;
	char* letters;
};
word* resize(word* arr, int size) {
	word* arr1 = new word[size];
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr[i];
	}
	delete[] arr;
	return arr1;
}



