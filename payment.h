#include <iostream>
#include <string>
using namespace std;

#ifndef Payment_h
#define Payment_h

class Payment 
{
    private:
    int paymentNum;
    string customerName;
    double amount;
    string paymentType;
    string date;

    public:
    // Constructor
    Payment() 
    {
        paymentNum = 0;
        customerName = "\0";
        amount = 0.0;
        paymentType = "\0";
        date = "\0";
    }
    void setValues(int num, string name, double newAmount, string type, string newDate) {
        paymentNum = num;
        customerName = name;
        amount = newAmount;
        paymentType = type;
        date = newDate;
    }
    
    // Displays all the payment information
    void displayPayment() 
    {
        cout << endl << "Payment Num: #" << paymentNum;
        cout << endl << "Customer Name - " << customerName;
        cout << endl << "Amount: Rs" << amount;
        cout << endl << "Payment Type: " << paymentType;
        cout << endl << "Date: " << date << endl;
    }

    // Accessors
    int getPaymentNum()
    { return paymentNum; }
    
    string getCustomerName()
    { return customerName; }
    
    double getAmount()
    { return amount; }
    
    string getPaymentType()
    { return paymentType; }
    
    string getDate()
    { return date; }
    
    // Mutators
    void setPaymentNum(int num)
    { paymentNum = num; }
    
    void setCustomerName(string name)
    { customerName = name; }
    
    void setPaymentType(string type)
    { paymentType = type; }
    
    void setAmount(double newAmount)
    { amount = newAmount; }
    
    void setDate(string newDate)
    { date = newDate; }
};

#endif