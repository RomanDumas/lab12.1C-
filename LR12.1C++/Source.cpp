#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

double* Create(char* filename);
void Print(char* filename);
void Sort(double*& x);

int main() {
	srand((unsigned)time(NULL));
	char filename[50];
	char pos[] = "pos.dat";
	char neg[] = "neg.dat";
	cout << "enter the file name(text.dat) "; cin >> filename;
	double* x = new double[10];
	x = Create(filename);
	Print(filename);

	Sort(x);
	Print(pos);
	Print(neg);

	return 0;
}

double* Create(char* filename)
{
	double* x = new double[10];
	for (int i = 0; i < 10; i++)
		x[i] = -10.0 + rand() * 21.0 / RAND_MAX;
	ofstream f(filename, ios::binary);

	if (!(f.is_open())) {
		cout << "error";
		exit(1);
	}
	for(int i = 0; i < 10; i++)
		f.write((char*)&x[i], sizeof(x));
	f.close();
	return x;
}

void Sort(double*& x) {
	ofstream posf("pos.dat", ios::binary);
	ofstream negf("neg.dat", ios::binary);

	for (int i = 0; i < 10; i++) {
		if (x[i] < 0)
			negf.write((char*)&x[i], sizeof(x[i]));
		else
			posf.write((char*)&x[i], sizeof(x[i]));

	}
	posf.close();
	posf.close();

}

void Print(char* filename){
	fstream f(filename);
	double x;
	while (f.read((char*)&x, sizeof(x))) {
		cout << x << ' ';
	}
		
	cout << endl;
	f.close();
}