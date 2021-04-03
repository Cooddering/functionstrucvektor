#include <iostream>
using namespace std;
#ifndef Dataset_hpp
#define Dataset_hpp

#include <vector>
#include <string>

/**
 Dataset class

 Represents a 2d dataset that, for now..
 - has 1 y column and 1 or more x columns
 - y column represents categorical data
 - has all double values
 - has no missing values
 */
class Dataset
{
public:
    Dataset() = default;

    // Methods
    void load_random(size_t rows, size_t xvars, int yClasses = 2);
    void preview(size_t numrows = 10);
    double operator()(size_t row, size_t col) const;
    double operator()(size_t row, std::string col) const;

    // Getters
    size_t get_numrows() const;
    size_t get_numcols() const;

    // Headers
    const std::vector<std::string> get_colnames();

private:

    /**
     Column struct
     Purpose is to make it easier to keep track of column data
     */
    struct Column
    {
        // Constructor
        Column() = default;
        Column(std::string colname, size_t firstIdx);

        // Member vars
        std::string colname;
        size_t firstIdx; // data index of this column's first element
    };

    // Member vars
    size_t numrows;
    size_t numcols;
    std::vector<std::string> colnames;
    std::vector<double> data;
    std::vector<Column> xcols;
    Column ycol;

public:
    std::vector<Column> get_x_cols() const;
    Column get_y_col() const;
};

#endif /* Dataset_hpp */
/*
struct bilgi
{
	string yazarAdiSoyad;
	int  sayfaSayisi;
	int baskiSayisi;
	string turu;


};
void bookDisplay(bilgi a);
*/
//int myToplama();
//struct point
//{
//	double x, y;
//};
//
//double lengthCalculate(double x1, double x2, double y1, double y2);
//point midlePointer(double x1, double x2, double y1, double y2);
//bool isParalel(point p1, point p2, point p3, point p4);
//
//int doubleCalculate();
//


	



