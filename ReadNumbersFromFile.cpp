// McKade Umbenhower
// Lab 01
// 9-11-17
// Reading numbers from a file and printing the count, first two, and last two numbers

#include <fstream>
using std::ifstream;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;
#include <string>
using std::string;

int main()
{
	string fileName = "";
	int count = 0;
	double firstNum, secondNum, secondToLastNum, lastNum;

	// Obtain some file name to open
	cout << "Please enter the file name: ";
	cin >> fileName;
	// Open the file
	ifstream inputFile(fileName);

	// Check if the file was opened correctly
	if (inputFile.fail())
	{
		// Tell the user the file could not be opened, and do nothing else
		cout << "File could not be opened." << endl;
	}
	else
	{
		// The file is open
		cout << "File opened.\n------------------------------" << endl;

		// Store the first two numbers from the file
		inputFile >> firstNum;
		inputFile >> secondNum;

		// Set count to 2 because the first two numbers were just stored
		count = 2;

		// Get the total amount of numbers in the file by
		// cycling through the rest of the numbers and adding one
		// to count each time.
		while (!inputFile.eof() && inputFile >> lastNum)
		{
			count++;
		}

		// Clear the end of file state on the file and
		// set the read file pointer to the beginning 
		// of the file
		inputFile.clear();
		inputFile.seekg(0, ios::beg);

		// Find the second to last number by cycling through
		// all of the numbers except the last one
		for (int i = 0; i < count - 1; i++)
		{
			inputFile >> secondToLastNum;
		}

		// Display the first, second, second to last, and last number 
		// as well as the total amount of numbers in the file
		cout << "First Number: " << firstNum << "\nSecond Number: " << secondNum << "\nSecond to last number: " 
			<< secondToLastNum << "\nLast Number: " << lastNum << "\nCount: " << count << endl;
	}

	// Close the file before exiting the program
	inputFile.close();
	cout << "------------------------------\nFile Closed." << endl;

	return 0;
}