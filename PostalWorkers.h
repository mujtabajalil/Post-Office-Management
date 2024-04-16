#ifndef _POSTALWORKER_H_
#define _POSTALWORKER_H_ 

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class PostalWorker
{
    private:
    char name[30];
    char id[5];
    char designation[10];

    

    void listPostalWorkers()
    {
        FILE *file;
        file = fopen("data.txt", "r");
         while(fscanf(file, "%s %s %s", &name[0], &id[0] , &designation[0])!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            fclose(file);
    }
    void showDetails()
    {
        FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s", &name[0], &id[0] , &designation[0])!=EOF)
                if(strcmp(checkId,id)==0)
                {
                	cout<<"\nName: "<<name;
                    cout<<"\nId: "<<id;
                    cout<<"\nDesignation: "<<designation;
                }
            fclose(file);
    }
    void editExisting()
    {
         char checkId[5];
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            char newDesignation[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s", &name[0], &id[0] , &designation[0])!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s \n", name, id, newDesignation);
                else
                    fprintf(tempfile, "%s %s %s \n", name, id, designation);
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
    }
    void addNewEmployee()
    {
            cout<<"\n Enter First Name of Employee: ";
            cin>>name;
            
            cout<<"\n Enter Employee ID [max 4 digits]: ";
            cin>>id;
            
            cout<<"\n Enter Designation: ";
            cin>>designation;
            

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s\n", name, id, designation);
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();
    }
    void deleteEmployeeDetails()
    {
         char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s", &name[0], &id[0] , &designation[0])!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s\n", name, id, designation);
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
            }
            else
                deleteEmployeeDetails();
    }
    public:
        void PostOfficeEmployeeMenu()
        { 
                
                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>>  POST OFFICE EMPLOYEES  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Employees";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add New Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";

                // Taking the action input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice) 
                {
                    case 1:
                        listPostalWorkers();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    default:
                        cout<<"\n Please enter valid menu number.\n";
                        break;
                }

        }
        


};

#endif