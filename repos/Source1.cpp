#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	int fieldwidth, fieldheight;

	do {
		system("cls");
		cout << "������� ������ ����: ";
		cin >> fieldwidth;
		cout << "������� ������ ����:";
		cin >> fieldheight;
	
	} while ((fieldwidth <= 2) or (fieldheight <= 2));










}