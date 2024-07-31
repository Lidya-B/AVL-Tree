//*****************************************************************************************************
//
//		File:					stock.cpp
//
//		Student:				Lidya Belew
//
//		Assignment:				assigment 8
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					03/04/2024
//
//
//		This program will impliment and test a array list  class.
//	
//		Other files required: 
//         1. none 
//			
//*****************************************************************************************************
#include"stock.h"
#include<iostream>
using namespace std;

Stock::Stock(const std::string& n, const std::string& s, double p)
{
    companyName = n;
    stockSymbol = s;
    price = p;
}

//*****************************************************************************************************

Stock::Stock(const Stock& s)
{
    companyName = s.companyName;
    stockSymbol = s.stockSymbol;
    price = s.price;
}

//*****************************************************************************************************

void Stock::display() const
{
    cout << "Company Name: " << companyName << endl;
    cout << "Stock Symbol: " << stockSymbol << endl;
    cout << "Price: " << price << endl;
}

//*****************************************************************************************************

std::ostream& operator<<(std::ostream& os, const Stock& stock)
{
    os << "Company Name: " << stock.companyName << std::endl;
    os << "Stock Symbol: " << stock.stockSymbol << std::endl;
    os << "Price: " << stock.price << std::endl;
    return os;
}
