/*
Name : Muhammet Arslan
Number : 150160031
Instructor : Gülþen Eryiðit
Date : 14.10.2019
*/
#include<iostream>
#include<fstream>
#include <stdlib.h>		
#include <cstdlib>
#include "shoe.h"

void shoeFunction(int shoeNumber, ShoeStruct& shoeStructTemp) {
	if (shoeNumber == 0) {
		shoeStructTemp.showDepo();
	}
	else if (shoeNumber < 0) {
		shoeStructTemp.soldedShoe(-1 * shoeNumber);
	}
	else if (shoeNumber > 0) {
		shoeStructTemp.addShoeToDepo(shoeNumber);
	}
}

int main(int argc, char* argv[])
{
	ShoeStruct myShoeList;
	myShoeList.create();// new struct created
	const char *content = argv[1];
	std::ifstream shoeFile;
	shoeFile.open(content);
	if (!shoeFile) {
		return -1;
	}
	int shoeArray[10000]; //max shoes 10000
	int counter = 0;
	while (!shoeFile.eof()) {
		shoeFile >> shoeArray[counter];
		//std::cout << shoeArray[counter] << std::endl;
		shoeFunction(shoeArray[counter], myShoeList);
		counter++;
	}

	return EXIT_SUCCESS;

}
