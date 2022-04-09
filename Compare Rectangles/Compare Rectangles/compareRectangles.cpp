// 				CSC237-S1 Project 1: Compare Rectangles
//	Student: 	Yenchi Kuo
//	Due Date:	September 25, Saturday
//	Description:
//		This program calculates the area of two rectangles,
//		and tells the user which rectangle has the larger area

#include <iostream>
#include <iomanip>
using namespace std;

void printBanners();
double getPositiveNum();
double calculateArea(double, double);
double getPercentage(double, double);
void compareAreas(double, double, double);



int main() {
	// Banners and console configurations
	system("title Compare Rectangles \tby Yenchi Kuo");
	system("color 9E");
	printBanners();

	// Get diameters of the 1st rectangle
	cout << "Please enter the width of the 1st rectangle: ";
	double rectangleWidth_first = getPositiveNum();
	cout << "Please enter the length of the 1st rectangle: ";
	double rectangleLength_first = getPositiveNum();
	// Calculate the area of the first rectangle
	double rectangleArea_first = calculateArea(rectangleWidth_first, rectangleLength_first);

	// Get diameters of the 2nd rectangle
	cout << "Please enter the width of the 2nd rectangle: ";
	double rectangleWidth_second = getPositiveNum();
	cout << "Please enter the length of the 2nd rectangle: ";
	double rectangleLength_second = getPositiveNum();
	// Calculate the area of the second rectangle
	double rectangleArea_second = calculateArea(rectangleWidth_second, rectangleLength_second);

	/* Now compare the rectangles*/
	cout << setw(6) << fixed << setprecision(1)
		<< "Area of rectangle 1: " << rectangleArea_first << ".\n"
		<< "Area of rectangle 2: " << rectangleArea_second << ".\n\n";

	double percentageDiffernce = getPercentage(rectangleArea_first, rectangleArea_second);
	compareAreas(rectangleArea_first, rectangleArea_second, percentageDiffernce);

	return 0;
}

/*	Function Definition area:
*	Definitions consist of:
*	1.Banners
*	2.getPositiveNum
*	3.calculateArea
*	4.getPercentage
*	5.compareAreas
*/

// Print out nicely centered banners
void printBanners() {
	cout << "\n"
		<< "\t\t     This program calculates the area of two rectangles,   \n"
		<< "\t\t   and tells the user which rectangle has the larger area. \n"
		<< "\t\t                     Compare Rectangles                    \n"
		<< "\t\t                       by  Yenchi Kuo                      \n\n";
}

// Ensure the diameters input are positive numbers
double getPositiveNum() {
	double inputNum;
	cin >> inputNum;
	cin.ignore(100, '\n');

	while (inputNum <= 0) {
		cout << "Your entry must be a POSITIVE number. Try again: ";
		cin >> inputNum;
		cin.ignore(100, '\n');
	}
	return inputNum;
}

// Takes diameters and calculate area
double calculateArea(double width, double length) {
	double area = width * length;
	return area;
}

// Calculate the difference percentage of two areas and multiplies by 100 for percentage display
double getPercentage(double areaOne, double areaTwo) {
	if (areaOne > areaTwo)
		return (100 * ((areaOne - areaTwo) / areaTwo));
	else
		return (100 * ((areaTwo - areaOne) / areaOne));
}

// Takes two areas and compare them
void compareAreas(double areaOne, double areaTwo, double percentage)
{
	if (areaOne != areaTwo) {
		cout << setw(6) << fixed << setprecision(1)
			<< "Area of " << (areaOne > areaTwo ? "Rectangle 1 is " : "Rectangle 2 is ")
			<< percentage << "% greater than area of"
			<< (areaOne > areaTwo ? " Rectangle 2.\n" : " Rectangle 1.\n");
		//	Display the comparison of the areas in the fashion below :
		//	Area of A is X% greater than area of B.
	}
	else
		cout << "The areas are the same." << endl;
}
