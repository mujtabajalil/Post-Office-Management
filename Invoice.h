#ifndef _INVOICE_H_
#define _INVOICE_H_ 

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include "MailService.h"
#include "Order.h"

class Invoice: public Order 
{
    private:
    int numOfItems;
    OrderItems item[50];

};

#endif