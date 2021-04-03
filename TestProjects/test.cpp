#include "test.h"
#include <iostream>
#include <random>     // std::random_device, std::mt19937, std::uniform_real_distribution
#include <math.h>     // std::round
#include <iomanip>    // std::setw


/**
 Column constructor
 */
Dataset::Column::Column(std::string colname, size_t firstIdx) : colname{ colname }, firstIdx{ firstIdx } {}

/**
 Fill dataset with random values

 @param rows number of rows
 @param xvars number of columns not including y column
 @param yClasses number of possible y classes
 */
void Dataset::load_random(size_t rows, size_t xvars, int yClasses) {

    // Check the inputs
    if (rows < 1) throw "rows must be >= 1";
    if (xvars < 1) throw "xvars must be >= 1";
    if (yClasses < 1) throw "yClasses must be >= 1";

    // Initialize random device, distribution
    std::random_device rd;
    std::mt19937 mt{ rd() }; // seed the PRNG
    std::uniform_real_distribution<double> distX{ 0, 1 };
    std::uniform_int_distribution<int> distY{ 0, (yClasses - 1) };

    // Reserve enough memory for the data vector to hold all data
    size_t numValues = rows * (xvars + 1);
    this->data.reserve(numValues);

    // Insert the y column values first
    for (size_t i = 0; i < rows; ++i) this->data.emplace_back(distY(mt));

    // Insert the explanatory column values last
    for (size_t i = rows; i < numValues; ++i) this->data.emplace_back(distX(mt));

    // Store the column names
    this->colnames.reserve(xvars + 1);
    this->colnames.emplace_back("Y");
    for (size_t i = 1; i <= xvars; ++i) {
        std::string colname = "X" + std::to_string(i);
        this->colnames.emplace_back(colname);
    }

    // Store the dataset dimensions
    this->numrows = rows;
    this->numcols = (xvars + 1);

    // Set up Columm objects
    this->ycol = Dataset::Column{ "Y", 0 };
    this->xcols.reserve(xvars);
    for (size_t i = 1; i <= xvars; ++i) {
        std::string colname = "X" + std::to_string(i);
        this->xcols.emplace_back(colname, i * rows);
    }
}

/**
 Print a preview of the current dataset with the Y column first

 @param numrows maximum number of rows to print
 */
void Dataset::preview(size_t numrows) {
    if (numrows == -1) numrows = this->numrows;

    // Get the x and y columns
    auto xcols = this->get_x_cols();
    auto ycol = this->get_y_col();

    // Print the column names
    std::cout << std::setw(3) << ycol.colname;
    for (auto& xcol : xcols) std::cout << std::setw(10) << xcol.colname;
    std::cout << std::endl;

    // Determine how many rows to print
    size_t printRows = std::min(numrows, this->numrows);

    // Print the values
    for (size_t r = 0; r < printRows; ++r) {
        std::cout << std::setw(3) << this->data[ycol.firstIdx + r];
        for (auto& xcol : xcols) std::cout << std::setw(10) << this->data[xcol.firstIdx + r];
        std::cout << std::endl;
    }

    // If we only printed a subset of rows, print ellipses to indicate that
    if (printRows < this->numrows) {
        for (size_t c = 0; c < this->numcols; ++c) {
            std::cout << std::setw((c == 0) ? 3 : 10) << "...";
        }
    }
    std::cout << std::endl;
}

/**
 Access data by (row index, column index)

 @param row row index
 @param col column index
 @return data value
 */
double Dataset::operator()(size_t row, size_t col) const {
    return this->data[this->numrows * col + row];
}

/**
 Access data by (row index, column name)

 @param row row index
 @param col column name
 @return data value
 */
double Dataset::operator()(size_t row, std::string col) const {
    // Get the index of the desired column name
    size_t colIdx = std::find(this->colnames.begin(), this->colnames.end(), col) - this->colnames.begin();
    if (colIdx >= this->colnames.size()) throw "colname not found";
    return this->operator()(row, colIdx);
}

// === Getters =============================================================================

const std::vector<std::string> Dataset::get_colnames() {
    return this->colnames;
}

size_t Dataset::get_numcols() const {
    return this->numcols;
}

size_t Dataset::get_numrows() const {
    return this->numrows;
}

Dataset::Column Dataset::get_y_col() const {
    return this->ycol;
}

std::vector<Dataset::Column> Dataset::get_x_cols() const {
    return this->xcols;
}
/*
void bookDisplay(bilgi a) {
	
		cout << "yazar adi:" << a.yazarAdiSoyad << endl;
		cout << "Sayfa sayisi " << a.sayfaSayisi << endl;
		cout << "Baski sayisi" << a.baskiSayisi << endl;
		cout << "Turu" << a.turu;
	
		

		

}
*/
/******************************************************************/

//int myToplama() {
//	int number, negative_sum = 0, positive_sum = 0, sum = 0, average_neg = 0,
//		average_pos = 0, average = 0;
//	int count = 0, positiveCount = 0, negativeCount = 0;
//	cout << "Please Input 10 whole numbers(Each number should be separated by space or       Enter)\n";
//
//	for (int i = 0; i < 10; i++)
//	{
//
//		//cout<<"i is"<<i<<endl;
//		cin >> number;
//
//		if (number >= 0)
//		{
//			positive_sum += number;
//			positiveCount++;  count++;
//		}
//
//		else
//		{
//			negative_sum += number;
//			negativeCount++; count++;
//		}
//	}
//	if (positiveCount > 0)
//	{
//		average_pos = positive_sum / positiveCount;
//	}
//
//	if (negativeCount > 0)
//	{
//		average_neg = negative_sum / negativeCount;
//	}
//
//	sum = positive_sum + negative_sum;
//
//	if (count > 0)
//	{
//		average = sum / count;
//	}
//
//	cout << average_pos;
//	cout << "The Total sum of Positive Numbers is " << positive_sum << " and the average of   \nThe postive numbers entered is ";
//	cout << average_pos << endl;
//	cout << "The Total sum of Negative Numbers is " << negative_sum << " and the average of  \nThe negative numbers entered is ";
//	cout << average_neg << endl;
//	cout << "The Total sum of numbers entered is " << sum << " and its average is " << average << endl;
//
//	system("PAUSE");
//	return 0;
//}

/******************************************************************/
//bool isParalel(point p1, point p2, point p3, point p4) {
//	double m1 = (p2.y - p1.y) / (p2.x - p1.x);
//	double m2 = (p4.y - p4.y) / (p3.x - p3.x);
//	if (m1 == m2)
//	{
//		cout << "Paraleldir" << endl;
//		return true;
//	}
//	else
//	{
//		cout << "Paralel degil" << endl;
//		return false;
//	}
//	return false;
//
//}

/******************************************************************/
//point midlePointer(double x1, double x2, double y1, double y2) {
//	point middlePoint;
//	middlePoint.x = (x1 + x2) / 2;
//	middlePoint.y = (y1 + y2) / 2;
//	return middlePoint;
//}

/******************************************************************/

//double lengthCalculate(double x1, double x2, double y1, double y2) {
//	double  length;
//	length = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
//	return length;
//}

