/*
Lane Pruisner
C++ Fall 2019
Due November 14, 2019
Lab #6 Binary to Decimal Conversion
Description: Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns with
appropriate headings.
*/
//Libraries I used
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//Function Prototypes
void layout(); //PreConditions:None PostConditions: outputs headings
void BinaryEnter();//PreConditions: Binary Numbers need to be inputted correctly, '0' until the first '1' need to be ignored 
				  //as well as letters ignored, If binary numbers are inputted correctly the base 10 number is calculated
                  //PostConditions: Outputs Binary numbers and base 10 numbers in two columns. While showing if a Binary number had a bad digit on input
void spacing(int space);//PreConditions: Needs a Binary number inputted, calculates spacing needed for each nnumber
						//PostConditions: Outputs spacing before and after Binary number
void decspacing(int decimal);//PreConditions: Base 10 number need to be calculated
							//PostConditions: Outputs spacing after void(spacing) and before Base 10 number

int main()
{
	//Function Calls
	layout();
	BinaryEnter();
	return 0;//Ends program
}
void layout()//Function definition
{
	cout << "          Binary Number                          Decimal Equivalent\n";//Outputs headings
}
void BinaryEnter()//Function definition
{
	char BiNum;//Binary Numbers taken in as characters
	int decimal;// integer for the base 10 number
	string inputBinaryfile = "C:/Users/PRUISNER1/source/repos/Lab6/BinaryIn.dat";//input file that hold all the binary numbers
	ifstream infile;
	ifstream infile2;
	//Opens two of the same file for calculating
	infile.open(inputBinaryfile);
	infile2.open(inputBinaryfile);
	infile >> BiNum;//priming read
	
	while (infile && BiNum != '1' && BiNum == ' ' || BiNum == '0')// While loop: while  The character and infile do not equal one, and the character
	{                                                             // is a space or a zero, it will grab another character from the file
		infile.get(BiNum);
	}
	while (infile)//while loop
	{
		int space = 1;//Integer space that is used to calculate spaces need before the Binary number
		int decimal = 0;//Integer decimal used to calculate the base 10 number
		bool TBinum = true;// Boolean value that stays true as long as the character is a '0' or a '1'

		while (infile && BiNum != '\n')//While loop: runs while the infile and character do not equal an end line
		{
			
			switch (BiNum)// Switch statement that takes in the character value and then uses that character to calculate the base 10 equivalent
			{
			case '0': decimal = (decimal * 2) + 0; break;// calculates base 10 number
			case '1': decimal = (decimal * 2) + 1; break;
			default: TBinum = false; //If the character is not a '0' or a '1' turns the boolean value false

			}
			space++;//adds to the integer space for calculating space needed
			infile.get(BiNum);// Gets another character from the infile
		}
		if (TBinum)//If boolean value stays true it runs spacing(space)
		{
			spacing(space);//Function call: spaces before the Binary number
		}
		infile2.ignore(100, '1');//ignores everything until it reaches a 1
		BiNum = '1';//stops ignoring everything from the infile so it doesn't ignore zero after the first '1'
		while (infile2 && BiNum != '\n')//While loop: runs while the second infile(same binary numbers) and characters from it do not equal an end line
		{

			if (TBinum)//If boolean value is true outputs binary number
			{
				cout << BiNum;
			}
			
			infile2.get(BiNum);//Grabs another character from the second infile

		}
		if (TBinum)//If boolean value is true, outputs more spacing after the binary numbers then a few tabs, outputs more spacing 
		{          //before the base 10 number to center them
			spacing(space);//Function call: spaces after Binary number
			cout << "\t\t";//tabs
			decspacing(decimal);//Funtcion call: spacing before base 10 numbers
			cout << decimal << endl;// Outputs base 10 numbers
		}
		if (TBinum != true)// if boolean value is false, outputs "Bad Digit on Input
		{
			cout << setw(25) << "Bad Digit on Input" << endl;
			
		}

		infile >> BiNum;//priming read
		while (infile && BiNum != '1' && BiNum == ' ' || BiNum == 0)// While loop: while  The character and infile do not equal one, and the character
																	 // is a space or a zero, it will grab another character from the file
		{
			infile.get(BiNum);//Gets another character from the infile
		}
	}
	
}

void spacing(int space)//Function definition
{
	int Bispace; //New integer to calculate spaces needed before Binary number
	Bispace = (32 - space) / 2; //Gives Bispspace new value
	for (int count = 1; count <= Bispace; count++)//For loop: Runs until count is larger than Bispace and outputs a space everytime it runs
	{
		cout << " ";
	}

}
void decspacing( int decimal_)//Function definition
{
	int decspace = 0;//New integer decspace set to equal 0
		for (int count = 10; decimal_ >= count; decimal_ = decimal_ / 10)//For loop: Runs until decimal value is less than count then adds value to decspace
		{
			decspace++;
		}
	
		decspace = (32 - decspace) / 2;//Takes value from previous loop and gives decspace a new value
		for (int count = 1; count<decspace; count++)// For loop: Runs until count is greater than decspace and outputs a space everytime it runs
		{
			cout << " ";
		}
}