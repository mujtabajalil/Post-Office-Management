#ifndef _MENU_H_
#define _MENU_H_ 


#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include "MailService.h"
#include "Order.h"
#include "PostalWorkers.h"
#include "Invoice.h"
#include "Customers.h"

class Menu
{
    public:

    //void customer();
    //void admin();


    void user()
    {
        int ch;
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1. CUSTOMER";
		cout << "\n\n\t2. ADMINISTRATOR";
		cout << "\n\n\t3. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		cin >> ch;
		switch (ch)
		{
		case 1: customer(); break;
		case 2: admin(); break;
		case 3: exit(0);
		}

    }
	void customer()
	{
		
		string sname, sadd, rname, radd;
		cout << "\nPlease type your name: \n";
		getline(cin, sname);
		cout << "\nPlease type your address: \n";
		getline(cin, sadd);
		cout << "\nType recievers Name: \n";
		getline(cin, rname);
		cout << "\nType in recievers address: \n";
		getline(cin,radd);
		Customer cu(sname, sadd, rname, radd);
		int numItems;
		OrderItems orderMail[10];
		cout << "Enter items: \n";
		cin >> numItems;
		displayMailService();
		string c;
		int q;
		int i = 0;
		fstream orders;
		orders.open("OrderHistory.txt", ios::app);

		while (i < numItems)
		{
			cout << "\n\tENTER ITEM CODE:" << endl;
			cin >> c;
			orders << c << ",";
			orderMail[i].getItem(c);
			cout << "\n\tENTER ITEM QUANTITY:" << endl;
			cin >> q;
			orders << q << ",";
			orderMail[i].setQuantity(q);
			i++;
		}
		int j;
		Order fBill;
		for (int j = 0; j < numItems; j++)
		{
			fBill.amount+=orderMail[j].getAmount();
		}
		//printing out the bill
		system("cls");
		cout << "\n\n\tINVOICE\t\t\tDate/Time:" << fBill.date << endl;
		cout << "\tProduct Number\tProduct Name\tProduct Rate\tQuantity\tAmount" << endl;
		for (int i = 0; i < numItems; i++)
		{

			orderMail[i].printItemDet();
			cout << setw(6) << orderMail[i].getAmount() << endl;
			orders <<orderMail[i].cust.sName << orderMail[i].cust.sAddress 
			<< orderMail[i].cust.rName << orderMail[i].cust.rAddress
			<<orderMail[i].mail.getName() << "," 
			<< orderMail[i].mail.getNumber()<< "," << orderMail[i].mail.getRate();
		}
		cout << "\n\n\t\t\t\tTOTAL AMOUNT + Tax(Rs 75): " << fBill.amount;
		cout << "\n\tThank You for using the services of Post Office" << endl;
		cout << "\n\tPress any key to continue...";

	}


    void admin()
	{
		while (1)
		{
			int ch;
			cout << "\n\n\n\tADMIN MENU";
			cout << "\n\n\t1.CREATE PRODUCT";
			cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
			cout << "\n\n\t3.POST OFFICE EMPLOYEES";
			cout << "\n\n\t4.POST OFFICE CUSTOMER DATABASE";
			cout << "\n\n\t5.BACK TO MAIN MENU";
			cout << "\n\n\tPlease Enter Your Choice (1-5) ";
			cin >> ch;
			switch (ch)
			{
			case 1:createProduct(); break;
			case 2:displayMailService(); break;
			case 3:PostOfficeWorkers();
			case 4:CustomerDataBase();
			case 5: user();
			default: break;
			}
		}
	}
	void createProduct()
	{
		system("cls");
		int n;
		string p;
		int  r;
		cout << "\n\n\tENTER THE DETAILS OF THE PRODUCT" << endl;
		cout << "\n\tENTER THE PRODUCT NUMBER" << endl;
		getline(cin, p);
		cout << "\n\tENTER THE PRODUCT NAME" << endl;
		cin >> p;
		cout << "\n\tENTER THE PRODUCT RATE" << endl;
		cin >> r;
		MailService mail(n,p,r);
	}
	void displayMailService()
	{
		ifstream dispMailService;
		dispMailService.open("MailService.txt", ios::in);
		int n, r;
		string p;
		cout << "Mail Services Offered by POST OFFICE: \n";
		while(true)
		{
			dispMailService >> n;
			if (dispMailService.eof())
				break;
			dispMailService >> p >> r;
			cout << "\n\tPRODUCT NUMBER : " << n;
			cout << "\n\tPRODUCT NAME : " << p;
			cout << "\n\tRATE OF PRODUCT : " << r;
		}

	}
	void PostOfficeWorkers()
	{
		PostalWorker p;
		cout << "\n\n\n\tPOST OFFICE EMPLOYEE DATABASE";
		p.PostOfficeEmployeeMenu();

	}
	void CustomerDataBase()
	{
		Customer c;
		cout << "\n\n\n\tPOST OFFICE CUSTOMER DATABASE";
		c.CustomerMenu();
	}


};

#endif
