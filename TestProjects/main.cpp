#include <iostream>
#include "test.h"
#include <vector>

using namespace std;


int main()
{


	   
      	
		vector<bilgi> bookListe;

		for (int i = 0; i < 2; i++)
		{
			bilgi x;
			cin >> x.yazarAdiSoyad;
			cin >> x.sayfaSayisi;
			cin >> x.baskiSayisi;
			cin >> x.turu;

			 bookListe.push_back(x);
		}

		
		for (int i = 0; i <bookListe.size(); i++)
		{
		
			bookDisplay(bookListe[i]);
		}

		
		

	/******************************************************************/

	/*cout << "Benim dgerlendirma sonucum:"<< myToplama();*/

	/******************************************************************/

	/******************************************************************/ 	/*int A[10];
	int i, c = 0, t = 0;

	cout << "10 number" << endl;
	for (i = 0; i < 10; i++)
		cin >> A[i];
	for (i = 0; i < 10; i++)

	{
		if (A[i] % 2 == 0)

		{
			c++;
		}
		t++;
	}
	cout << c << endl;
	cout << t << endl;
	cout << c * t * t;*/

	/******************************************************************/   

	//point p1, p2, p3, p4;
	//cout << "Birinci Sayi x1 : ";
	//cin >> p1.x;
	//cout << "Birinci Sayi x2: ";
	//cin >> p2.x;
	//cout << "Birinci Sayi y1: ";
	//cin >> p3.y;
	//cout << "Birinci Sayi y2: ";
	//cin >> p4.y;
	//cout << "Sonuc : " << isParalel(p1, p2, p3, p4) << endl;

	/******************************************************************/

	/*double x1, x2, y1, y2;
	cout << "Sayi girin : ";
	cin >> x1;
	cout << "Sayi girin : ";
	cin >> x2;
	cout << "Sayi girin : ";
	cin >> y1;
	cout << "Sayi girin : ";
	cin >> y2;
	double uzunluk = lengthCalculate(x1, x2, y1, y2);
	cout << "uzunluk : " << uzunluk << endl;*/

	/******************************************************************/

	/*point  midel = midlePointer(x1, x2, y1, y2);
	cout << "ortaNokta : " << midel.x << " " << midel.y<<endl;
	*/

}

