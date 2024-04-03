#include <iostream>
#include <fstream>
#include "functions.h"

int main() {
	int size = 1000000; // Костыль, берём размер массива с запасом
	char* arr = new char[size];
	float textlongwords = 0;
	float textwords = 0;
	std::string filename = "t.txt";
	std::ifstream fin;
	fin.open(filename);
	if (fin.is_open()) // Открываем файл как обычно
	{
		while (!fin.eof()) {
			{
				sentence Sentence;
				do
				{
					fin >> arr; // Считываем отдельно слова в массив с чарами
					word container(len(arr)); // Создаём контейнер(смотреть подсказку по конструктору)
					container.append(arr);			// Добавляем в контейнер слово используя специальный метод класа
					textwords++;
					if (container.lastsymbol() == '.')
					{
						char* temp = new char[len(arr)];  // Создаем временный контейнер такого же размера как слово
						for (int i = 0; i < len(arr); i++) // Перебираем все символы слова
						{
							temp[i] = arr[i];              // По буквам склеиваем новое слово
							if (i == len(arr) - 1)              // Если нашли последний символ, добавляем \0 вместо точки
							{
								temp[i] = '\0';
							}
						}
						container.append(temp);
						Sentence.append(container);			// Закидываем полученное слово в предложение
						textlongwords += Sentence.countlongwords();
						delete[] temp;                       // Чистим память
						Sentence.print();
						break;
					}
					else {
						Sentence.append(container);
					}
				} while (true);
			}
		}
		std::cout << "Percentage of the long words: " << textlongwords / textwords * 100;
	}
	delete[] arr;
}
