#include <iostream>
#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE

using namespace std;

struct shoeNode {
	int sizeOfShoe;
	int numberOfShoes;
	shoeNode* nextNode;
	shoeNode* prev;
};

struct ShoeStruct {

	shoeNode* head;
	int numberOfTotalShoes;

	void create();
	void addShoeToDepo(int);
	void soldedShoe(int);
	void showDepo();
	shoeNode* checkDepo(int);
	void deleteNodes();
} *head;


void ShoeStruct::create() {
	shoeNode* newNode = NULL;
	head = newNode;
};
//adds a pair of shoe to the stock list in an increasing order
void ShoeStruct::addShoeToDepo(int shoeNumber) {
	bool alreadyExist = false;
	shoeNode* newNode = new shoeNode;
	if ((newNode = checkDepo(shoeNumber))) {
		newNode->numberOfShoes++;
		alreadyExist = true;
	}
	else {
		newNode = new shoeNode;
		newNode->sizeOfShoe = shoeNumber;
		newNode->numberOfShoes = 1;
	}
	numberOfTotalShoes++;
	if (head == NULL || numberOfTotalShoes == 0) {
		newNode->nextNode = NULL;
		newNode->prev = NULL;
		head = newNode;
	}
	else {
		if (!alreadyExist) {
			shoeNode* current = head;
			shoeNode* previousNode = NULL;
			while (current != NULL && current->sizeOfShoe < newNode->sizeOfShoe) {
				previousNode = current;
				current = current->nextNode;
			}
			if (current == head) {
				newNode->nextNode = head;
				newNode->prev = head->prev;
				head->prev = newNode;
				head = newNode;
			}
			else {
				newNode->prev = previousNode;
				newNode->nextNode = previousNode->nextNode;
				if (previousNode->nextNode != NULL) {
					previousNode->nextNode->prev = newNode;
				}
				previousNode->nextNode = newNode;
			}
		}
	}
};
void ShoeStruct::soldedShoe(int shoeNumber) {
	shoeNode* current;
	if ((current = checkDepo(shoeNumber))) {
		if (current->numberOfShoes == 1) {
			if (current == head) {
				head = current->nextNode;
				head->prev = NULL;
				delete current;
			}
			else {
				current->prev->nextNode = current->nextNode;
				if (current->nextNode != NULL) {
					current->nextNode->prev = current->prev;
				}
				delete current;
			}
		}
		else {
			current->numberOfShoes--;
			//std::cout << current->numberOfShoes << std::endl;
			//std::cout <<"shoe deleted"<<std::endl;
		}
		numberOfTotalShoes--;
		//std::cout << numberOfTotalShoes << std::endl;
	}
	else {
		std::cout << "NO_STOCK" << std::endl;
	}
}

void ShoeStruct::showDepo() {
	shoeNode* current = head;
	if (head == NULL || numberOfTotalShoes == 0) {
		return;
	}
	while (current != NULL) {
		std::cout << current->sizeOfShoe << ":" << current->numberOfShoes << std::endl;
		current = current->nextNode;
	}
};
void ShoeStruct::deleteNodes() {
	shoeNode* current = head;
	shoeNode* previousNode = head;
	do {
		current = current->nextNode;
		delete previousNode;
		previousNode = current;
	} while (current != NULL);
	numberOfTotalShoes = 0;
};
shoeNode* ShoeStruct::checkDepo(int shoeNumber) {
	shoeNode* current = head;
	while (current != NULL) {
		if (current->sizeOfShoe == shoeNumber) {
			return current;
		}
		current = current->nextNode;
	}
	if (current == NULL) {
		return NULL;
	}
	else {
		return current;
	}
};


#endif


#pragma once
