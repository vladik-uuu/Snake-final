#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	int fieldwidth, fieldheight;

	do {
		system("cls");
		cout << "¬ведите ширину пол€: ";
		cin >> fieldwidth;
		cout << "¬ведите высоту пол€:";
		cin >> fieldheight;
	
	} while ((fieldwidth <= 2) or (fieldheight <= 2));










}