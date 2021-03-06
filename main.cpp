#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>

using namespace std;

bool read(unsigned int &size) {
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	bool success = true;

	if (stream >> size) {

	}
	else {
		success = false;
	}

	return success;
}

bool create(double * & mass, unsigned int resultsize) {
	bool success = true;

	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	unsigned int size = 0;

	mass = new double[resultsize];
	for (int i = 0; i < resultsize; i++) {
		if (!(stream >> mass[i])) {
			success = false;
			break;
		}
		size++;
	}

	if (resultsize > size) {
		success = false;
	}

	return success;
}

void obmen(double * mass, unsigned int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (mass[j] > mass[j + 1]) {
				swap(mass[j], mass[j + 1]);
			}
		}
	}
}

void write(double * mass, unsigned int size) {
	for (int i = 0; i < size; i++) {
		cout << mass[i];
		if (i != size - 1) {
			cout << ' ';
		}
		else {
			cout << '\n';
		}
	}
}

void error() {
	cout << "An error has occured while reading input data.\n";
}

int main()
{
	unsigned int size = 0;
	double * mass = nullptr;

	unsigned int schet = 0;
	if (read(size)) {
		if (create(mass, size)) {
			obmen(mass, size);
			write(mass, size);
		}
		else {
			error();
		}
	}
	else {
		error();
	}

	system("pause"); 

    return 0;
}
