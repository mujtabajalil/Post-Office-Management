#ifndef _MAILSERVICE_H_
#define _MAILSERVICE_H_ 

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;


class MailService
{
    private:
    int productNumber;
    string productName;
    int productRate;

    public:
    MailService()
    {
        productNumber = 0;
        productName = "\0";
        productRate = 0;
    }
    MailService(int pn, string pName, int rate)
	{
        productNumber = pn;
        productName = pName;
        productRate = rate;
        
        ofstream outProduct;
		outProduct.open("MailService.txt", ios::out | ios::app);
		outProduct
			<< productNumber
			<< ' '
			<< productName
			<< ' '
			<< productRate
			<<endl;
		cout << "\n\n\n\tPRODUCT CREATED SUCCESSFULLY";
	}
    // mutator and accessor functions 
    void setNumber(int x)
	{
		productNumber = x;
	}
	void setName(string x)
	{
		productName = x;
	}
	void setRate(int x)
	{
		productRate = x;
	}
    int getNumber()
	{
		return productNumber;
	}
	string getName()
	{
		return productName;
	}
	float getRate()
	{
		return productRate;
	}

};

#endif 