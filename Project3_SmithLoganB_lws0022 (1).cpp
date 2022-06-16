//============================================================================
// Name        : Project3_SmithLoganB_lws0022.cpp
// Author      : Logan Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;
const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream& instream);

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);

void writefile(int outputArray[], int outputArray_size, ofstream& outStream);


int main() {
	/*initialize variables*/
	ifstream inStream1;
	ofstream outStream;
	std::string file1 = "";

	std::string file2 = "";

	std::string outputfile="";

	int Array1[MAX_SIZE];
	int Array2[MAX_SIZE];
	int outputArray[MAX_SIZE];
	int Array1_size;
	int Array2_size;
	int output_size;

	/*header statemnt for the file sorting program*/
	cout <<"*** Welcome to Logan's sorting program ***\n";
	cout << "Enter the first input file name: ";
	cin >> file1;

	inStream1.open((char*)file1.c_str());
	if (inStream1.fail()) {
		cout << "Input file opening failed.";
		exit(1);
	}

	Array1_size = readfile(Array1, inStream1);
	inStream1.close();
	inStream1.clear();
	/* iterate through file 1*/
	cout << "The list of "<< Array1_size << " numbers in file "<< file1 << " is:\n";
	for(int i=0; i < Array1_size; i++){
		cout << Array1[i];
		cout << "\n";
	}
/*prompt for second file1 and print file array*/
	cout << "\nEnter the second input file name: ";
	cin >> file2;

	inStream1.open((char*)file2.c_str());
		if(inStream1.fail()) {
			cout << "Input file opening failed.";
			exit(1);
		}

		Array2_size = readfile(Array2, inStream1);
		inStream1.close();
		inStream1.clear();
/*iterate thorugh file 2 and print file array*/
		cout << "The list of ";
		cout << Array2_size <<" numbers in file ";
		cout << file2 <<" is:\n";
		for(int i =0; i < Array2_size; i++){
			cout << Array2[i];
			cout << "\n";
		}
		cout << "\n";

		output_size = sort(Array1, Array1_size, Array2, Array2_size, outputArray);
/*iterate and print output file array*/
		cout <<"The sorted list of "<< output_size << " numbers is: ";
		for(int i =0; i < output_size; i++) {
			cout << " " << outputArray[i] << "";
		}
/*name the output file created*/
		cout << "\nEnter the output file name: ";
		cin >> outputfile;

		outStream.open((char*)outputfile.c_str());
		if(outStream.fail()) {
			cout << "Output file opening failed.";
			exit(1);
		}

		writefile(outputArray, output_size, outStream);
		cout << "*** Please check the new file - " << outputfile << " ***\n";
		cout << "*** Goodbye ***";
		return 0;
}

int readfile(int inputArray[], ifstream& inStream) {
	int i =0;
	inStream >> inputArray[i];
	while(! inStream.eof()) {
		i++;
		inStream >> inputArray[i];
	}
	return i;
}

/* replaces the merge function*/
int sort(int inputArray1[], int inputArray1_size,int inputArray2[],int inputArray2_size,int outputArray[]){
	int outputArray_size = inputArray1_size + inputArray2_size;
	int i1, i2, i3;
	i1 = i2 = i3 = 0;

	while(i1 < inputArray1_size && i2 < inputArray2_size) {
		if(inputArray1[i1] < inputArray2[i2]){
			outputArray[i3] = inputArray1[i1];
			i1++;
			i3++;

		}
		else {
			outputArray[i3] = inputArray2[i2];
			i2++;
			i3++;
		}

	}

	if(i1 == inputArray1_size) {
		while(i2 < inputArray2_size) {
			outputArray[i3] = inputArray2[i2];
			i2++;
			i3++;
		}
	}
	else {
		while(i1 < inputArray1_size){
			outputArray[i3] = inputArray1[i1];
			i1++;
			i3++;
		}
	}

	assert(i3 == outputArray_size);
	return outputArray_size;
}
/*makes an outputfile from outputArray[i]*/
void writefile(int outputArray[], int outputArray_size, ofstream& outstream){
	for(int i = 0; i < outputArray_size; i++){
		outstream << outputArray[i] << endl;
	}
}
