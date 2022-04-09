// 				CSC237-S1 Project 3: File Format Conversion Program
//	Student: 	Yenchi Kuo
//	Due Date:	Saturday, November 6, 2021
//	Description:
//		This program is a Finite State Machine simulator which involves
//		simulation of a car's speed and the distance traveled over a period of time


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

void helpText();
void printBanners();
void validateOutputFile(string& outputFileName, ofstream& outputFile);
void validateInputFile(string& inputFileName, ifstream& inputFile);
char getUserChoice();
int processPipedFile(ifstream& inputFile, ofstream& outputFile, const string TO_CSV_DELIMITER);
int processPipedFile(ifstream& inputFile, ofstream& outputFile, const string TO_PIPE_DELIMITER); // Overload Function 
int splitLineToArray(string inputString, const string TO_CSV_DELIMITER, string outputFieldArray[], const int NUMBER_OF_FIELDS);
int splitLineToArray(string inputString, const string TO_PIPE_DELIMITER, string outputFieldArray[], const int NUMBER_OF_FIELDS); // Overload Function 

const string
TO_CSV_DELIMITER = "|",		// Delimiter for converting pipes to comma
COMMA = ",",	// Delimiter for converting comma to pipes
DOUBLE_QUOTE = "\"";
const int NUMBER_OF_FIELDS = 20;

int main() {
	system("color 9E");
	system("title Project 3: File Format Conversion Program    by Yenchi Kuo");

	printBanners();
	int inputOpenTimes = 0;
	int outputOpenTimes = 0;
	char userChoice;
	string inputFileName;
	string outputFileName;
	ifstream inputFile;
	ofstream outputFile;
	bool fileProcessed = false;

	helpText();
	do {
		userChoice = getUserChoice();

		/*  Switch Case
		*	#1.Case CI	: Implicitly changed to character 'A'/'a' for easy implementation
		*				  Validates the number of input file open times and throw warnings
		*				  Closes input file and print out notice on the console
		*	#2.Case CO	: Implicitly changed to character 'B'/'b' for easy implementation
		*				  Validates the number of output file open times and throw warnings
		*				  Closes output file and print out notice on the console
		*	#3.Case H/h : Prints out list of commands
		*	#4.Case I/i : Opens and validates input file and increment the counter
		*	#5.Case O/o : Opens and validates output file and increment the counter
		*	#6.Case P/p : Process files by invoking processPipedFile function
		*	#7.Case Q/q : Exit program with state 0
		*/
		switch (userChoice) {
		case 'A':
		case 'a':
			if (inputOpenTimes < 1) {
				cout << "\n\tThere is no opened file to close.\n"
					<< "\tPlease refer to the help text for commands.\n" << endl;
				helpText(); break;
			}
			else {
				inputFile.close();
				inputOpenTimes--;
				cout << "\nInput file Closed.\n"; break;
			}
		case 'B':
		case 'b':
			if (outputOpenTimes < 1) {
				cout << "\n\tThere is no opened file to close.\n"
					<< "\tPlease refer to the help text for commands.\n" << endl;
				helpText(); break;
			}
			else {
				outputFile.close();
				outputOpenTimes--;
				cout << "\nOutput file Closed.\n"; break;
			}
		case 'H':
		case 'h': helpText(); break;
		case 'I':
		case 'i': validateInputFile(inputFileName, inputFile); inputOpenTimes++; break;
		case 'O':
		case 'o': validateOutputFile(outputFileName, outputFile); outputOpenTimes++; break;
		case 'P':
		case 'p':
			if (inputOpenTimes < 1) {
				cout << "You need an input file to process. Open the file first.\n"
					<< "Please refer to the command list and try again(case sensitive).\n\n";
				helpText();
				break;
			}
			else processPipedFile(inputFile, outputFile, TO_CSV_DELIMITER); fileProcessed = true; break;
		case 'Q':
		case 'q': exit(0);
		default:
			cout << "No such command.\n"
				<< "Please refer to the command list and try again(case sensitive).\n\n";
			helpText(); break;
		} // End of switch statement

		/* Prompting the user to close the files after processing them
		*  If there are files opened and they have been processed
		*  this prompt will appear on the console
		*  Variables: outputOpenTimes, inputOpenTimes, fileProcessed
		*  Data types:		int				int				bool
		*/
		if ((outputOpenTimes >= 1 && fileProcessed) || (inputOpenTimes >= 1 && fileProcessed)) {
			cout << "\nIt is a good practice to close the files AFTER processing them.\n"
				<< "Would you like to close them now? Enter CI or CO for closing input or output file.\n";
			if (!outputFile.is_open() && !inputFile.is_open()) fileProcessed = false; // Reset boolean value for future checking
		}
	} while (userChoice != 'q');

	system("pause>null");
	return 0;
}

// This function will print out a nicely-centered banner
void printBanners() {
	cout << "\n"
		<< "\t\t              This program converts file format which involves         \n"
		<< "\t\t       the mechanism to represent multiple fields per line of text     \n"
		<< "\t\t             without using any special, non-standard characters        \n"
		<< "\t\t                       File Format Conversion Program                  \n"
		<< "\t\t                              by   Yenchi Kuo                          \n\n";
}

// This function will print out the help text in the console.
void helpText() {
	cout << "Supported commands:\n"
		<< "\tCI" << "\tClose input file.\n"
		<< "\tCO" << "\tClose output file.\n"
		<< "\th" << "\tprint this help text.\n"
		<< "\ti" << "\topen file for input.\n"
		<< "\to" << "\topen file for output.\n"
		<< "\tp" << "\tConvert pipe-delimited to CSV format.\n"
		<< "\tq" << "\tquit.\n\n";
}

// ----------------------------------------------------------------------
// This function will get user's choice by reading string input,        *
// implicitly assigns the options CI and CO to characters 'a' and 'b,'  *
// and return the entered character back to main                        *
// return type: char                                                    *
// ----------------------------------------------------------------------
char getUserChoice() {
	string inputString;
	char userOption;

	cout << "Please enter a command: ";
	getline(cin, inputString);
	cin.clear();

	if (inputString.length() > 1 && inputString == "CI")
		userOption = 'a';
	else if (inputString.length() > 1 && inputString == "CO")
		userOption = 'b';
	else userOption = inputString[0];

	return userOption;
}

// ----------------------------------------------------------------------
// This function will get the input file's name and validates the name. *
// Prints a warning with possible error types if the name is invalid    *
// Returns the correct file name to main                                *
// Return type: string                                                  *
// ----------------------------------------------------------------------
void validateInputFile(string& inputFileName, ifstream& inputFile) {

	cout << "Please enter the name of the input file.\n"
		<< "Do not forget the file extension(.csv/.txt): ";
	cin >> ws;
	getline(cin, inputFileName);

	inputFile.open(inputFileName);
	while (inputFile.fail()) {
		system("color 7C");
		cout << "\n"
			<< "\t\a(line " << __LINE__ << ") Failed to open \"" << inputFileName << "\" for READING the data.\n"
			<< "\tPlease make sure the file filename does not contain illegal characters\n"
			<< "\tand it is not currently used by another application.\n"
			<< "\tDon't forget to include the filename extension: ";

		cin >> ws;
		getline(cin, inputFileName);
		inputFile.open(inputFileName);
	}
	system("color 9E");
	cout << "Input file opened successfully.\n" << endl;
}

// ----------------------------------------------------------------------
// This function will get the output file's name and validates the name.*
// Prints a warning with possible error types if the name is invalid    *
// Returns the correct file name to main                                *
// Return type: string                                                  *
// ----------------------------------------------------------------------
void validateOutputFile(string& outputFileName, ofstream& outputFile) {
	cout << "Please enter the name of the output file.\n"
		<< "Do not forget the file extension(.csv/.txt): ";
	cin >> ws;
	getline(cin, outputFileName);

	outputFile.open(outputFileName);
	while (outputFile.fail()) {
		system("color 7C");
		cout << "\t\a(line " << __LINE__ << ") Failed to open " << outputFileName << " for WRITING the data.\n"
			<< "\tPlease make sure the file filename does not contain illegal characters\n"
			<< "\tand it is not currently used by another application."
			<< "\tDon't forget to include the filename extension: ";

		cin >> ws;
		getline(cin, outputFileName);
		outputFile.open(outputFileName);
	}
	system("color 9E");
	cout << "Output file opened successfully.\n" << endl;
}

/*	Function Name	: processPipeFile
*	Data Type		: int
*	function invoked: splitLineToArray()
*	return data		: lineCount: int
*
*	Procedures		: #1.Read strings from input file
*					: #2.Invoke splitLineToArray function to get fieldCount
*					: #3.Process each segment of strings from each data field
*					: #4.Put double quotes at the begining and the end of strings 
*						 if the original strings contains a comma			 
*					: #5.If the original string has quotes within, put double quotes
*						 at the begining and the end of strings and next to the original quotes
*					: #6.If the conditions in #4 and #5 are not met, 
*						 simply put a comma at the end of each string, replacing the pipes.
*/
int processPipedFile(ifstream& inputFile, ofstream& outputFile, const string TO_CSV_DELIMITER) {
	int fieldCount = 0;
	int lineCount = 0;
	int startFieldPos = 0;
	int commaPosition, openQuotePos, closeQuotePos; // Store the location of comma and double quotes

	string inputBuffer;
	string textArray[NUMBER_OF_FIELDS];
	
	while (getline(inputFile, inputBuffer)) {
		fieldCount = splitLineToArray(inputBuffer, TO_CSV_DELIMITER, textArray, NUMBER_OF_FIELDS);
		lineCount++;

		for (int i = 0; i < fieldCount; i++) {
			string field = textArray[i];
			commaPosition = field.find(COMMA, startFieldPos);
			openQuotePos = field.find(DOUBLE_QUOTE, startFieldPos);
			closeQuotePos = field.find(DOUBLE_QUOTE, openQuotePos + 1);
			
			// If there is comma in the original string
			if (commaPosition >= 0) {
				outputFile << DOUBLE_QUOTE << field << DOUBLE_QUOTE << COMMA;
			}

			// If there are quotes in the original string
			else if (openQuotePos >= 0 && closeQuotePos >= 0) {
				outputFile << DOUBLE_QUOTE
					<< field.insert(openQuotePos + 1, DOUBLE_QUOTE).insert(closeQuotePos + 1, DOUBLE_QUOTE)
					<< DOUBLE_QUOTE << COMMA;
			}
			// No Commas nor quotes found in the original string
			else outputFile << field << COMMA;
		}
		outputFile << endl;
	}
	cout << "End of file encountered." << endl;
	return lineCount;
}

/* Function name	: SplitLineToArray
*  Data type		: int
*  return data		: fieldCount: int
* 
*  Procedures		: #1.Collect strings from the data field before each pipe delimiter
*					: #2.When reach the end of line, set delimiter position marker foundPosition
*						 to the length of the string, and collect the string from the last part
*					: #3.Print out the strings in each line from the input file on the console
*/ 
int splitLineToArray(string inputString, const string TO_CSV_DELIMITER, string outputFieldArray[], const int NUMBER_OF_FIELDS) {
	int nextFieldPosition = 0;
	int foundPosition = 0;
	int fieldCount = 0;
	bool endOfLine = false;
	string dataField;
	string tempData;

	while (!endOfLine) {
		// Starts at nextFieldPosition, ends at Delimiter and report position
		foundPosition = inputString.find(TO_CSV_DELIMITER, nextFieldPosition);

		// End of line reached
		if (foundPosition == string::npos) {
			endOfLine = true;
			foundPosition = inputString.length();

			if (foundPosition > nextFieldPosition) {
				dataField = inputString.substr(nextFieldPosition, foundPosition - nextFieldPosition);
				fieldCount++;
			}
			// Printing Original Data line by line
			cout << "Input data = " << inputString << endl;
		}
	
		// This else statement will replace all the pipe delimiter with commas
		else {
			dataField = inputString.substr(nextFieldPosition, foundPosition - nextFieldPosition);
			fieldCount++;
			nextFieldPosition = foundPosition + 1;
		}
		if (fieldCount > 0)
		{
			if (fieldCount > NUMBER_OF_FIELDS)
			{
				cout << "ERROR at line " << __LINE__ << ": too many input fields, fieldCount = "
					<< fieldCount << endl;
			}
			else
			{
				outputFieldArray[fieldCount - 1] = dataField;
			}
		}
	}
	return fieldCount;
}
