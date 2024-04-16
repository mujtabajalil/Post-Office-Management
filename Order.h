#ifndef _ORDER_H_
#define _ORDER_H_ 
#include "MailService.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include "Customers.h"

using namespace std;


class Order
{
    public:
    string date;
    int amount;

    Order()
    {
        time_t now = time(0);
		char* dt = ctime(&now);
        date = dt;
        amount = 0;
    }
    

};

class OrderItems
{
    private:
    
    int quantity;

    public:
    MailService mail;
    Customer cust;
    void getItem(string c)
    {
        ifstream prod;
		prod.open("MailService.txt", ios::in);
		int pn;
		string pp;
		float pr;
		while (true)
		{
			prod >> pn >> pp >> pr;
			if (pp == c)
			{
				mail.setNumber(pn);
				mail.setName(pp);
				mail.setRate(pr);
				break;
			}
		}
    }
    void setQuantity(int x)
    {
        quantity = x;
    }
	int getAmount()
    {
        int r;
		r = mail.getRate();
		return ((r*quantity) + 75);
    }
	void printItemDet()
    {
        cout <<  "\t" << cust.sName;
        cout << "\t" << cust.sAddress;
        cout << "\t" << cust.rName;
        cout << "\t" << cust.rAddress;
		cout    <<  "\t" << setw(14) << mail.getNumber();
		cout 	<< "\t" << setw(12) << mail.getName();
		cout 	<< "\t" << setw(12) << mail.getRate();
		cout 	<< "\t" << setw(8) << quantity << "\t";
    }


    
    
};

#endif // !_ORDER_H
