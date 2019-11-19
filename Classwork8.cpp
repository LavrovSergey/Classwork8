#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


struct Aeroflot
{
	char name[64];
	int num;
	char type[10];
};

void aero(Aeroflot*flot)
{
	for (int i = 0; i < 7; ++i) 
	{
		cout << i + 1 << ':';
		cout << "Название пункта назначения: ";
		while (flot[i].name[0] == '\0' || flot[i].name[0] < 0) 
		{
			cin.getline(flot[i].name, 64);
		}
		while (flot[i].num <= 0/*||isalpha(flot[i].num)*/)
		{
			flot[i].num = 0;
			cout << "Номер рейса: ";
			cin >> flot[i].num;
		}
		cout << "Тип самолета: ";
		while (flot[i].type[0] == '\0' || flot[i].type[0] < 0)
		{
		    cin.getline(flot[i].type,10);
		} 	
		cout << endl;
	}

	char temp[64];
	char temp2[64];
	for (int i = 0; i < 7; ++i) 
	{
		for (int j = i; j < 7; ++j) 
		{
			if (flot[j].name[0] > flot[i].name[0]) 
			{
				strcpy_s(temp, flot[i].name);
				strcpy_s(flot[i].name, flot[j].name);
				strcpy_s(flot[j].name, temp);
				int temp1 = flot[i].num;
				flot[i].num = flot[j].num;
				flot[j].num = temp1;
				strcpy_s(temp2, flot[i].type);
				strcpy_s(flot[i].type, flot[j].type);
				strcpy_s(flot[j].type, temp2);
			}
		}
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
	cout << "Введите тип самолета"<<endl;
	char type1[10];
	cin.getline(type1,10);
	for (int i = 0; i < 7; ++i) {
		file1.read((char*)& flot[i], sizeof(Aeroflot));
		if (strcmp(type1, flot[i].type)) 
		{
			cout << endl;
			cout << i + 1 << ':' << endl;
			cout << "   Куда: ";
			cout << flot[i].name << endl;
			cout << "   Номер рейса: ";
			cout << flot[i].num << endl;
		}
	}
	file1.close();
	delete[] type1;
	delete[] flot;
	return 0;
}