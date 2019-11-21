#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


struct Aeroflot
{
	char name[20];
	char num[10];
	char type[10];
};

void aero(Aeroflot* flot)
{
	for (int i = 0; i < 7; ++i)
	{
		cout << i + 1 << ':';
		cout << "Название пункта назначения: ";
		while (flot[i].name[0] == '\0' || flot[i].name[0] < 0)
		{
			cin.getline(flot[i].name, 64);
		}
		while (flot[i].num[0] == '\0' || flot[i].num[0] < 0)
		{
			cout << "Номер рейса: ";
			cin.getline(flot[i].num, 64);
		}
		cout << "Тип самолета: ";
		while (flot[i].type[0] == '\0' || flot[i].type[0] < 0)
		{
			cin.getline(flot[i].type, 10);
		}
		cout << endl;
	}

	char temp[20];
	char temp1[10];
	char temp2[10];
	for (int i = 0; i < 7; ++i)
	{
		for (int j = i; j < 7; ++j)
		{
			if (flot[j].name[0] < flot[i].name[0])
			{
				strcpy_s(temp, flot[j].name);
				strcpy_s(flot[j].name, flot[i].name);
				strcpy_s(flot[i].name, temp);
				strcpy_s(temp1, flot[j].num);
				strcpy_s(flot[j].num, flot[i].num);
				strcpy_s(flot[i].num, temp1);
				strcpy_s(temp2, flot[j].type);
				strcpy_s(flot[j].type, flot[i].type);
				strcpy_s(flot[i].type, temp2);
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << flot[i].name;
		cout << flot[i].num;
		cout << flot[i].type;
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Aeroflot flot[7];
	aero(flot);
	cout << endl;
	ofstream file("Aeroflot.doc");
	for (int i = 0; i < 7; ++i) {
		file.write((char*)& flot[i], sizeof(Aeroflot));
	}
	file.close();

	ifstream file1("Aeroflot.doc");
	cout << "Введите тип самолета" << endl;
	char type1[10];
	int count = 0;
	cin.getline(type1, 10);
	for (int i = 0; i < 7; ++i)
	{
		file1.read((char*)& flot[i], sizeof(Aeroflot));
		if (strcmp(type1, flot[i].type) == 0)
		{
			cout << endl;
			cout << i + 1 << ':';
			cout << "   Куда: ";
			cout << flot[i].name << endl;
			cout << "   Номер рейса: ";
			cout << flot[i].num << endl;
			count++;
		}

	}
	if (count == 0) { cout << endl << " Нет таких рейсов\n"; }
	file1.close();

	return 0;
}