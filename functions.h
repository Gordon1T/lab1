#pragma once
int len(char* arr);

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

word* resize(word* arr, int size);

class sentence // Заводим класс "Предложение" в котором будем обрабатывать массивы со словами определенными
							// в предыдущем классе
{
public:
	sentence() {
		Words = new word[length];
		char* temp = new char[2]{ '.','\0' };
		word Word;
		Word.append(temp);
		Words[length - 1] = Word;
		length++;
		Words = resize(Words, length);
		delete[] temp;
	}
	void append(word Word) {
		int i = length;
		Words[i - 1] = Word;
		length++;
		Words = resize(Words, length);
	}
	void print() {
		std::cout << "Amount of the long words in the sentence: " << countlongwords() << std::endl;
	}
	int countlongwords() {
		int longwords = 0;
		for (int i = 0; i < length; i++)
		{
			if (Words[i].size() > 5)
			{
				longwords++;
			}
		}
		return longwords;
	}
private:
	int length = 1;
	word* Words;
};
