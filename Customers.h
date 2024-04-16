#ifndef _CUSTOMERS_H_
#define _CUSTOMERS_H_ 

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class Customer
{
    public:
    string sName;
    string sAddress;
    string rName;
    string rAddress;
    public:
    Customer()
    {
        sName = " ";
        sAddress = "\0";
        rName = "\0";
        rAddress = "\0";
    }
    Customer(string sn, string sd, string rn, string rd)
	{
        sName = sn;
        sAddress = sd;
        rName = sd;
        rAddress = rd;
        
        ofstream outProduct;
		outProduct.open("Customer.txt", ios::out | ios::app);
		outProduct
        << "Senders Name: "
			<< sName
			<< ' '
            <<  "Senders Address: "
			<< sAddress
			<< ' '
            << "Recievers Name: "
			<< rName
            << ' '
            << "Receievers Address: "
            << rAddress
            << " "
			<<endl;
		cout << "\n\n\n\tCustomer created successfully";
	}


    

    void listOfCustomers()
    {
        ifstream myfile ("Customer.txt");
        if ( myfile.is_open() ) {     while ( myfile.good() ) 
            myfile >> sName >>  sAddress >> rName >>  rAddress;
            cout<<"\n"<<sName<<"\t\t"<< sAddress<<"\t\t"<<rName << "\t\t" << rAddress;
        }  

    }
    /*void showDetails()
    {
        FILE *file;
            string custName;
            cout<<"\n\nEnter Employee ID: ";
            cin>>custName;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %s", &sName, &sAddress , &rName, &rAddress )!= EOF)
             {   int x = custName.compare(sName);
                 if(x = 0 )
                {
                	cout<<"\nCustomer Name: "<<sName;
                    cout<<"\nCustomers Address: "<<sAddress;
                    cout<<"\nReciever Name: "<<rName;
                    cout << "\nRecievers Address" << rAddress;
                }
             }
            fclose(file);
    } */
   
    
  
    public:
        void CustomerMenu()
        { 
                
                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>>  POST OFFICE CUSTOMERS  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Customers";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Customer Details";

                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";

                int choice;
                cin>>choice;
                switch (choice) 
                {
                    case 1:
                        listOfCustomers();
                        break;
                    //case 2:
                       // showDetails();
                        //break;
                    default:
                        cout<<"\n Please enter valid menu number.\n";
                        break;
                }

        }
        


};

#endif