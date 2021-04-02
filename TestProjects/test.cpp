#include <iostream>
#include "test.h"
using namespace std;


void bookDisplay(bilgi a) {
	
		cout << "yazar adi:" << a.yazarAdiSoyad << endl;
		cout << "Sayfa sayisi " << a.sayfaSayisi << endl;
		cout << "Baski sayisi" << a.baskiSayisi << endl;
		cout << "Turu" << a.turu;
	
		

		

}

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

