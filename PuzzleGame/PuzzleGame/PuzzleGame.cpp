// PuzzleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Bu program soz oyunudur.Puzzle şəklində qarışıq hərflər verilmişdir,
//bu hərflərin arasında sözlər qoyulub.Hər sözü tapdıqda siz bal qazanırsız.Programı hazırlayan:
// Maniyeva Sima KE021S

#include <iostream>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <cstdlib> //rand();

using namespace std;
void display();
int GameFunction();
int main()
{
	string name;
	cout << "Enter input name :  ";
	cin >> name;
	cout << endl;
	int score = 0;
	char input;
	do {
		//OYUN KODU
		system("cls");
		display();
		score += GameFunction();

		cout << "  Would you like to play again     Y/N  :     "; //Oyuncudan yeniden oynayib oynamadigini sorusur.
		cin >> input;
		cout << endl;
	} while (input != 'n'); //y!=n //unput- yes oldugu muddetde do dovru ise salinir.
	cout << name << "your score is    " << score;
	cout << endl << endl << endl;
	cout << "************************************************************************************" << endl;

}
void display() { //display funksiyasi ekranda gorunus ucundur.
	cout << "*************************************** Word-Puzzle Game ************************************\n\n" << endl;
	cout << "You have to guess a hidden correct" << endl;
	cout << "For each correct guessing you will get one score" << endl << endl;
}
int GameFunction() {
	// array[index][i];
	string array[10] = { "book","pen","word","code","like","fine","flames","sima","cpp" };//Puzzle'da tapilmasi lazim olan sozler massiv seklinde veririk.

	char matrix[50][50];
	int r;
	char c;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			r = rand() % 26;  //r=0
			//aralığında təsadüfi ədədlər əmələ gətirir
			c = 'a' + r; //c=97+0=97='a'
			matrix[i][j] = c;
		}
	}
	int index = rand() % 10; //0
	string output = array[index];
	if (array[index].length() % 2 == 0) {
		//horizontal
		int row = rand() % 10;
		int col = rand() % 3;
		for (int i = 0; array[index][i] != '\0'; i++, col++)
		{
			matrix[row][col] = array[index][i];
		}
	}
	else
	{
		//vertical

		int row = rand() % 3;
		int col = rand() % 10;
		for (int i = 0; array[index][i] != '\0'; i++, row++)
		{
			matrix[row][col] = array[index][i];
		}
	}
	cout << "                            Puzzle" << endl << endl;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			cout << matrix[i][j] << " ";
	
		}
		cout << "\n";

	}
	cout << "\n";
	cout << "\n";

	string guess;//texmin etdiyi say
	int hint;
	cout << "Press 1 for direct guess input  " << endl;//Birbaşa təxmin daxil etmək üçün 1 düyməsini basın
	cout << "Press 2 for firstly see hint and then enter guess input" << endl;
a:
	cout << "Enter input   :";
	cin >> hint;
	cout << endl;
	if (hint == 1)
	{
		cout << "Enter guessing word    :    ";//Texmin etdiyin sozu yaz
		cin >> guess;
		cout << endl;

	}
	else if (hint == 2) {
		cout << "The guessing word size is" << output.length() << endl;//Texmin edilen sozun olcusu nece herf tutdugu
	}
	else
	{
		cout << "Enter valid input" << endl;
		goto a;//Yeniden a'ya qayidir.Proses tekrarlanir.
	}


	if (output == guess) {
		cout << "Congratulations! You guessed the right word in the puzzle!" << endl;
		return 1;
	}
	else
	{
		cout << "Sorry you guessed the wrong word" << endl;
		return 0;
	}

}

