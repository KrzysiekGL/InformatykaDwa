#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>

int main(int argc, const char * argv[]) {

	
	//Zadanie 1 i 2
	const int array[10] = { 0,1,2,3,4,5,6,7,8,9 };

	FILE *fp;
	/*
	fopen_s(&fp, "data.dat", "r+b");
	if (fp == NULL) {
		perror("Error Loading");
		fopen_s(&fp, "data.dat", "w+b");
		if (fp == NULL) {
			perror("Error Creating");
			return 1;
		}
	}

	if (fwrite(array, sizeof(int), 10, fp) < 10) {
		perror("Error");
		return 1;
	}

	fclose(fp);


	fopen_s(&fp, "data.dat", "r+");
	if (fp == NULL) {
		perror("Error");
		return 1;
	}

	int secondArray[10] = { 0 };

	if (fread(secondArray, sizeof(int), 10, fp) < 10) {
		perror("Error");
		return 1;
	}

	for (int i = 9; i >= 0; --i) {
		std::cout << secondArray[i] << "\t";
	}
	getchar();

	fclose(fp);

	//Zadanie 3
	fopen_s(&fp, "studenci.dat", "r+");
	if (fp == NULL) {
		perror("Error Loading");
		fopen_s(&fp, "studenci.dat", "w+");
		if (fp == NULL) {
			perror("Error Creating");
			return 1;
		}
	}

	struct Student {
		int indeks;
		char nazwisko[64];
		float ocena;
	};

	Student studenci[3];

	for (int i = 0; i < 3; ++i) {
		std::cout << "Wprwadz indeks, nazwisko, ocene: \n";
		std::cin >> studenci[i].indeks >> studenci[i].nazwisko >> studenci[i].ocena;
		
		std::string error = "N/A";
		if (fwrite(&studenci[i].indeks, sizeof(int), 1, fp) < 1) fwrite(&error, error.size(), 1, fp);
		if (fwrite(&studenci[i].nazwisko, 64, 1, fp) < 1) fwrite(&error, error.size(), 1, fp);
		if (fwrite(&studenci[i].ocena, sizeof(float), 1, fp) < 1) fwrite(&error, error.size(), 1, fp);
	}
	fclose(fp);

	fopen_s(&fp, "studenci.dat", "rb");
	if (fp == NULL) {
		perror("Error Loading");
		getchar();
		return 1;
	}

	Student readStudenci[3];

	for (int i = 0; i < 3; ++i) {
		if (fread(&readStudenci[i].indeks, sizeof(int), 1, fp) < 1) perror("Reading");
		if (fread(&readStudenci[i].nazwisko, 64, 1, fp) < 1) perror("Reading");
		if (fread(&readStudenci[i].ocena, sizeof(float), 1, fp) < 1) perror("Reading");

		std::cout << readStudenci[i].indeks << '\n' << readStudenci[i].nazwisko << '\n' << readStudenci[i].ocena << "\n\n";
	}

	fclose(fp);

	system("pause");
	*/
	//Zadanie 4
	
	struct SinC{
		float y;
		float x;
	};

	fopen_s(&fp, "sinus.dat", "w+b");
	if (fp == NULL) {
		perror("Error");
		getchar();
		return 1;
	}
	
	int N;
	std::cout << "How many points? (N): ";
	std::cin >> N;

	std::vector<SinC> values;
	values.push_back(SinC());

	std::cout << "First value of x? (between -1 and 1): ";
	do {
		std::cin >> values[0].x;
	} while (!(values[0].x >= -1 && values[0].x <= 1));

	values[0].y = asin(values[0].x);

	for (int i = 1; i < N; ++i) {
		values.push_back(SinC());
		values[i].y += float(i);
		values[i].x = sin(values[i].x);
	}

	if (fwrite(fp, sizeof(float), N, fp) < N) perror("Error");
	
	fclose(fp);

	fopen_s(&fp, "sinus.dat", "r+");
	if (fp == NULL) {
		perror("Error");
		return 1;
	}

	float bufferY=0;
	float bufferX=0;
	for (int i = 0; i < N; ++i) {
		SinC buffer;
		//fread(&bufferY, sizeof(float), 1, fp);
		//fread(&bufferX, sizeof(float), 1, fp);
		if (fread(&buffer, sizeof(SinC), 1, fp) < 1) perror("Error");
		std::cout << "Y: " << buffer.y << " X: " << buffer.x << '\n';
	}

	fclose(fp);

	system("pause");

	return 0;
}