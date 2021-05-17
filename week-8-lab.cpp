// week-8-lab.cpp : Defines the entry point for the console application.
// Author: Sylvan Avery Dekker 2/28/2017
// Program: Week 8 Lab
// Sources: daniweb.com, github.com, stackoverflow.com

#include "stdafx.h"
#include <iostream>

using namespace std;

const int ARR_LENGTH = 10; //Determines number of integers in array

int smallestIndex(int numArray[], int arrLength); //Function prototype

int main()
{
	int testArr[ARR_LENGTH];	//Initializes
	int arrLength, index;		//variables

	//Prompt user to input 10 integers
	cout << "Please enter a list of " << ARR_LENGTH << " integers, one at a time." << endl;

	for (index = 0; index < ARR_LENGTH; index++) //Program prompts again until 10
												 //integers have been entered into 'testArr' 
	{
		cin >> testArr[index];

		while (!cin) //If an error occurs when taking input fron 'cin,' this stmnt 
					 //outputs an error message if an integer is not entered,
					 //and proceeds to prompt for another input
		{
			cout << "Input invalid. Please enter an integer." << endl; //error msg
			cin.clear(); //clears error flag on 'cin' so future I/O ops work
			cin.ignore(); //skips to newline
			cin >> testArr[index]; //reprompt user input of int
		}
	}

	cout << endl;

	cout << "The list is: ";

	//Prints numbers in array
	for (index = 0; index < ARR_LENGTH; index++)
		cout << testArr[index] << " ";

	cout << endl;
	
	//Utilizes smallestIndex function using current variables
	int smallestPosition = smallestIndex(testArr, ARR_LENGTH);

	//Prints useful info regarding array
	cout << "\nThe smallest index is position " << smallestPosition; 
	cout << " with a value of " << testArr[smallestPosition] << ".\n" << endl;

	system("pause");
	return 0;
}

//Simple counting system function comparing 'i' and 'smallest' until equal,
//then returns 'smallest' as int to be used in main function
int smallestIndex(int numArray[], int arrLength)
{
	int smallest = 0;

	for (int i = 0; i < arrLength - 1; i++)
	{
		if (numArray[i] < numArray[smallest])
		{
			smallest = i;
		}
	}
	return smallest;
}