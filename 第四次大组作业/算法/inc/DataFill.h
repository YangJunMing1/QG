#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include "qgsort.h"

class DataFill
{
public:
	void Creatdata(int* a, int size);
	void Creatdata_Color(int* a, int size, std::string FillName);		//ÑÕÉ«ÅÅĞòËùÓÃ
	bool Getdata(int* a, int &size, std::string FillName);
	void Savedata(int* a, int size, int diff, std::string FillName, std::string method);
};

