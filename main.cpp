#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
#include<fstream>
#include<ctime>
using namespace std;
ifstream fin2;
ofstream fout2;
class Employee{
    private:
        // Variables for employee details
        char firstName[30];
        char lastName[30];
        char id[5];
        char empTitle[10];
        char empStreetAddress[45];
        char empEmail[50];
        int empNumber;
        int age;
        int ctc;
        int experience;

        // Functions to perform desired actions
        void listEmployees(void);
        void showDetails(void);
        void editExisting(void);
        void addNewEmployee(void);
        void deleteEmployeeDetails(void);

    public:


        // Function to serve as end point
        void options(void);
        void login(); //login declaration

}st1;
// time show
void time_out(){
                time_t curr_time;
	            curr_time = time(NULL);
	            char *tm = ctime(&curr_time);
	            cout << "\n\t\t\t\t\t\t " << tm;
}
// Function to serve as end point
void Employee::options(void){ //menu
        system("cls");

                login();//login screen
            while(true){
                system("cls");
                time_out();
                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>>  HR Department SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   1:   To view list of employees.";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   2:   To view employee's details.";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   3:   To modify existed employee's details.";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   4:   To add new employee's details.";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   5:   To remove an employee's details.";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   0:   To exit     ";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\n\t\t\t   Please, enter your choice: ";

                // Taking the action input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice) {
                    case 0:
                    	system("CLS");
//                        cout<<"\n\nTHANK YOU FOR USING OUR PROGRAM \n\n <<<<AMIGOS>>>\n\n      :)\n\n\n\n";
                        Sleep(10);
                        return;
                    case 1:
                        listEmployees();
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
                        cout<<"\n Sorry! I don't understand that! \n";
                        break;
                }

            }
        }

// Utility functions
        waitForEnter(void){
            cout<<"\n\n\n Press enter to go back. \n\n";
            cin.get();
            cin.get();
            }
////////////////////////////////////////////////////////////////////////////////
        ///Functions to perform desired actions
        void Employee::listEmployees(void){ //To list total employees with Name, Id and Designation
            system("cls");
            time_out();
            int i=1;
            fin2.open("data.dat",ios::binary|ios::in);
            cout<<"\n\t      List of Employees\n";
            cout<<"\n------------------------------------------------------------------------";
            cout<<"\n NAME                    |     ID     |     DESIGNATION     |    AGE\n";
            cout<<"------------------------------------------------------------------------";
            while(!fin2.eof())
            {
                fin2.read((char*)&st1,sizeof(Employee));
                if(!fin2.eof())
            if(fin2.tellg()<0)
            {	i=0; break;}
            {
                cout<<"\n"<<firstName<<" "<<lastName<<"\t\t"<<id<<"\t\t"<<empTitle<<"\t\t  "<<age;;
            }
            }
            if(i==0)
            {	cout<<"\n\n\t\t\tEmpty record room!!";
            }
            fin2.close();
            waitForEnter();
        }
////////////////////////////////////////////////////////////////////////////////
        void Employee::showDetails(void){ //Displays all details according to Employee's id
            system("cls");
            time_out();
            char checkId[5];
            char outt[]="xx";
            cout<<"\n\nEnter employee's ID: ";
            cin>>checkId;
            int i=1;
            fin2.open("data.dat",ios::binary|ios::in);
            cout<<"\n\t      Employees' details\n";
            cout<<"\n-------------------------";
            cout<<"\n NAME        \t|Details\n";
            cout<<"-------------------------";
            while(!fin2.eof())
            {
                fin2.read((char*)&st1,sizeof(Employee));
                 if(strcmp(checkId,id)==0)
            {
                if(fin2.tellg()<0)
                {	i=0; break;}
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Name:         \t|"<<firstName<<" "<<lastName;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n ID:           \t|"<<id;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Designation:  \t|"<<empTitle;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Age:          \t|"<<age;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Phone Number  \t|"<<empNumber;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Street Address\t|"<<empStreetAddress;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n E-mail        \t|"<<empEmail;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n CTC:          \t|"<<ctc;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Experience:   \t|"<<experience;
                    cout<<"\n-------------------------------------------";
                }

            }
            if(i==0)
            {	cout<<"\n\n\t\t\tEmpty record room!!";

            }
            fin2.close();
            cout<<"\n\nWrong ID or no such ID exists!";
            waitForEnter();

        }
////////////////////////////////////////////////////////////////////////////////
        void Employee::editExisting(void){ //edits Designation and CTC of an employee
            system("cls");
            time_out();
            char checkId[5];
            cout<<"\nEnter employee's ID: ";
            cin>>checkId;
            char newempTitle[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newempTitle;

            int newPhoneNumber;
            cout<<"\n-----------------------------";
            cout<<"\nEnter new phone number: ";
            cin>>newPhoneNumber;

            char newStreetAddress[45];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new street address: ";
            cin>>newStreetAddress;
            char newEmail[50];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new employee's e-mail: ";
            cin>>newEmail;

            int newCtc;
            cout<<"------------------------------";
            cout<<"\nEnter new CTC: ";
            cin>>newCtc;
            int i=0;
            fout2.open("temp.dat",ios::binary);
            fin2.open("data.dat",ios::binary);
            while(!fin2.eof())
            {
            fin2.read((char*)&st1,sizeof(Employee));
            if(!fin2.eof())
            if(strcmp(checkId, id)==0)
            {
                cout<<"\n\n\t\tRecord is modified.";
                for(int i=0;i<10;i++)
                {empTitle[i]=newempTitle[i]; }
                for(int i=0;i<45;i++)
                {empStreetAddress[i]=newStreetAddress[i]; }
                for(int i=0;i<50;i++)
                {empEmail[i]=newEmail[i]; }
                ctc=newCtc;
                empNumber=newPhoneNumber;
                fout2.write((char*)&st1,sizeof(Employee));
                i++;
            }else
                {fout2.write((char*)&st1,sizeof(Employee));}
                }
            if(i==0)
            cout<<"\n\nRecord is not found!!";
            fin2.close();
            fout2.close();
            remove("data.dat");
            rename("temp.dat","data.dat");
            waitForEnter();
        }
////////////////////////////////////////////////////////////////////////////////
        void Employee::addNewEmployee(void){ //adding records
            system("cls");
            time_out();
            fout2.open("data.dat",ios::binary|ios::app);
                if(fout2.is_open()){
                cout<<"\n----------------------------------------";
                cout<<"\n Enter employee's first name: ";
                cin>>firstName;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter employee's last name: ";
                cin>>lastName;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter employee's ID [max 4 digits]: ";
                cin>>id;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter designation: ";
                cin>>empTitle;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter phone number: ";
                cin>>empNumber;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter street address: ";
                cin>>empStreetAddress;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter e-mail: ";
                cin>>empEmail;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter employee's age: ";
                cin>>age;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter employee's CTC: ";
                cin>>ctc;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter employee's experience: ";
                cin>>experience;
                cout<<"\n----------------------------------------";
                char ch;
                cout<<"\nPress 'y' to save above information.\n";
                cin>>ch;
                if(ch=='y'){
                fout2.write((char*)&st1,sizeof(Employee));
                fout2.close();}

            }
            else
                addNewEmployee();
            waitForEnter();
        }
////////////////////////////////////////////////////////////////////////////////
        void Employee::deleteEmployeeDetails(void){ //removing records
            system("cls");
            time_out();
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter employee's ID to remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nPress 'y' to confirm deletion. \n";
            cin>>ch;
            int i=0;
            if(ch=='y')
            {
                    fout2.open("temp.dat",ios::binary);
                    fin2.open("data.dat",ios::binary);
                    while(!fin2.eof())
                    {
                    fin2.read((char*)&st1,sizeof(Employee));
                    if(!fin2.eof())
                    if(strcmp(checkId, id)==0)
                    {
                    cout<<"\n\n\t\tRecord is deleted.";
                    i++;
                    }
                    else
                    fout2.write((char*)&st1,sizeof(Employee));
                    }
                    if(i==0)
                    cout<<"\n\nRecord is not found!!";
                    fin2.close();
                    fout2.close();
                    remove("data.dat");
                    rename("temp.dat","data.dat");
                    waitForEnter();
            }else
                {deleteEmployeeDetails();}
        }
////////////////////////////////////////////////////////////////////////////////
void Employee::login(){ //login procedure
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tHR Department System";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter the password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";

      system("PAUSE");
      system("CLS");
   }else{
      cout << "\nAccess Aborted...\n";
      login();
   }
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
    char name[20],pass[10];
	int pr,sell,quant;
public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);
    void withd(int qty);
    void refil(int qty);
}st;
void stock::withd(int qty)
{
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStock is updated.\n";
		cout<<"\n\nTotal price to be paid: "<<sell*qty;
    }
	else
	   cout<<"\n\nInsufficient stock!";
	    _getch();
}
void stock::refil(int qty)
{
		quant+=qty;
		cout<<"\n\nStock is updated.";
	    _getch();
}
int stock::stchk(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else
	return 1;
}
void stock::get()
{
	cin>>name>>pr>>quant;

}
void stock::get2()
{
	cin>>name>>quant;
}

void stock::show()
{
     sell=pr+(pr*0.1);
	cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr<<"\t\t\t"<<sell;
}
void addnew()
{
    system("cls");
	disp();
	_getch();
	system("cls");
	cout<<"\nEnter the number of products that you wish to add: ";
    cin>>n;
    if (n!=0)
    {
	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	{
		cout<<"\n\nEnter the name, price, quantity, supplier's name, and production year of the item respectively: \n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nItem is updated.";
		cin.get();
    }
    cout<<"\n\nStock is updated.";
    fout.close();
    cin.get();
    system("cls");
    disp();
}
	else
{
	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNumbers of items to be added: ";
}
}
void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product's name:\n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity:\n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\nRecord is not found!!";
     fio.close();
    cin.get();
    system("cls");
	 disp();
	_getch();
}
void disp()
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\tPRICE \t\t\tSelling price";
	cout<<"\n\n=====================================================================================\n";
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     st.show();
	  }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\tEmpty record room!!";
	_getch();
     }
     fin.close();
}
void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product's name:\n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity:\n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {

		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\nRecord is not found!!";
     fio.close();
    system("cls");
    cin.get();
	 disp(); cin.get();
}
void remove()
{
	system("cls");
	 int i=0;
     char temp[30];
     cout<<"\n\t\t\t\tDelete Record!";
     cout<<"\n\nEnter the product's name: ";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stchk(temp)==0)
	    {
		  st.show();
		  cout<<"\n\n\t\tRecord is deleted.";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       cout<<"\n\nRecord is not found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
}
int dealermenu()
{
    system("cls");
    int i;
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your choice :\t";
	cin>>i;
	return i;
}
int	custmenu(){
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your choice :\t";
	cin>>i;return i;
	}
int empmenu(){
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Exit";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your choice :\t";
	cin>>i;return i;
	}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
ofstream fout3;
ifstream fin3;
class Customer{
private:
    char cusFirstname[20];
    char cusLastname[20];
    char cusEmail[50];
    char cusCity[20];
    char cusStreet[20];
    int cusPhone;
    int cusId;
    void addCustomer();
    void removeCustomer();
    void showCustomer();
public:
    void cahOptions();
    void logincah();//login declaration
}st3;
void Customer::logincah(){ //login procedure
   system("cls");
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tCASHIER SYSTEM";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter the password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";

      system("PAUSE");
      system("CLS");
   }else{
      cout << "\nAccess Aborted...\n";
      logincah();
   }
}
void Customer::cahOptions(void){ //menu
         logincah();//login screen
            while(true){
                system("cls");
                time_out();
                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>>  CASHIER SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   1:    To add new customer account";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   2:   To view customer account";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   3:   To remove a customer account";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\t\t\tENTER   0:   To exit     ";
                cout<<"\n\t\t\t________________________________________________\n";
                cout<<"\n\n\t\t\t   Please enter your choice: ";

                // Taking the action input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice) {
                    case 0:
                    	system("CLS");
                        cout<<"\n\nTHANK YOU FOR USING OUR PROGRAM \n\n <<<<AMIGOS>>>\n\n      :)\n\n\n\n";
                        Sleep(10);
                        return;
                    case 1:
                        addCustomer();
                        break;
                    case 2:
                        showCustomer();
                        break;
                    case 3:
                        removeCustomer();
                        break;
                    default:
                        cout<<"\n Sorry! I don't understand that! \n";
                        break;
                }

            }
        }
void Customer::addCustomer(){ //adding records
            system("cls");
            time_out();
            fout3.open("customer.dat",ios::binary|ios::app);
                if(fout3.is_open()){
                cout<<"\n----------------------------------------";
                cout<<"\n Enter customer's first name: ";
                cin>>cusFirstname;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter customer's last name: ";
                cin>>cusLastname;
                cout<<"\n----------------------------------------";
                srand(time(0));/* to change the value that we will get from rand
                 if you do not use srand as above rand function will give you
                 the same value every time you run the code
                 id=rand()%1000+10000;/// I just use it to test rand function */
                cusId=rand()%1000+10000;
                cout<<"\n The customer's ID: "<<cusId;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter customer's city: ";
                cin>>cusCity;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter the phone number: ";
                cin>>cusPhone;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter the street address: ";
                cin>>cusStreet;
                cout<<"\n----------------------------------------";
                cout<<"\n Enter customer's e-mail: ";
                cin>>cusEmail;
                cout<<"\n----------------------------------------";
                char ch;
                cout<<"\nPress 'y' to save above information\n";
                cin>>ch;
                if(ch=='y'){
                fout3.write((char*)&st3,sizeof(Customer));
                fout3.close();}

            }
            else
                addCustomer();
            waitForEnter();
        }
////////////////////////////////////////////////////////////////////////////////
void Customer::showCustomer(){ //Displays all details according to Employee's id
            system("cls");
            time_out();
            int checkId;
            cout<<"\n\nEnter employee's ID: ";
            cin>>checkId;
            int i=1;
            fin3.open("customer.dat",ios::in);
            cout<<"\n\t      Customer Acount\n";
            cout<<"\n-------------------------";
            cout<<"\n NAME        \t|Details\n";
            cout<<"-------------------------";
            while(!fin3.eof())
            {
                fin3.read((char*)&st3,sizeof(Customer));
                if(checkId==cusId)
            {
                if(fin3.tellg()<0)
                {	i=0; break;}
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Name:         \t|"<<cusFirstname<<" "<<cusLastname;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n ID:           \t|"<<cusId;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n City:  \t|"<<cusCity;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Phone Number  \t|"<<cusPhone;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n Street Address\t|"<<cusStreet;
                    cout<<"\n-------------------------------------------";
                    cout<<"\n E-mail        \t|"<<cusEmail;
                    cout<<"\n-------------------------------------------";
                }


            }
            if(i==0)
            {	cout<<"\n\n\t\t\tEmpty record room!!";
            }
            fin3.close();
            waitForEnter();
        }
////////////////////////////////////////////////////////////////////////////////
void Customer::removeCustomer(){ //removing records
            system("cls");
            time_out();
            int checkCuId;
            cout<<"\n----------------------------------";
            cout<<"\nEnter employee's ID to remove: ";
            cin>>checkCuId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nPress 'y' to confirm deletion. \n";
            cin>>ch;
            int i=0;
            if(ch=='y')
            {
                    fout3.open("temp.dat",ios::binary);
                    fin3.open("customer.dat",ios::binary);
                    while(!fin3.eof())
                    {
                    fin3.read((char*)&st3,sizeof(Customer));
                    if(!fin3.eof())
                    if(checkCuId==cusId)
                    {
                    cout<<"\n\n\t\tRecord is deleted.";
                    i++;
                    }
                    else
                    fout3.write((char*)&st3,sizeof(st3));
                    }
                    if(i==0)
                    cout<<"\n\nRecord is not found!!";
                    fin3.close();
                    fout3.close();
                    remove("customer.dat");
                    rename("temp2.dat","customer.dat");
                    waitForEnter();
            }else
                {   cout<<"Wrong customer's ID!";
                    removeCustomer();}
        }

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
int loginMain(int x);

int main()
{
    int mainv=1;
    while(mainv==1){
            system("cls");
    cout<<"\n\n\n\n\t\t\t\tWelcome To Amigos Program :)";
    cout<<"\n\t\t\t________________________________________________\n";
    cout<<"\n\t\t\tENTER   1:   HR Department";
    cout<<"\n\t\t\t________________________________________________\n";
    cout<<"\n\t\t\tENTER   2:   Warehouse";
    cout<<"\n\t\t\t________________________________________________\n";
    cout<<"\n\t\t\tENTER   3:   Cashier";
    cout<<"\n\t\t\t________________________________________________\n";
    cout<<"\n\t\t\tENTER   0:   To exit     ";
    cout<<"\n\t\t\t________________________________________________\n";
    cout<<"\n\n\t\t\t   Please enter your choice: ";
    int choiceMain;
    cin>>choiceMain;
    mainv=loginMain(choiceMain);
    }
    return 0;
}

int loginMain(int x)
{
    switch (x) {
                    case 0:{
                    	system("CLS");
                        cout<<"\n\n\n\n\t\t\t\tTHANK YOU FOR USING OUR PROGRAM"
                        <<"\n\n\t\t\t\t\t<<<<<AMIGOS>>>>>"
                        <<"\n\n\t\t\t\t\t      :)\n\n\n\n";
                        Sleep(10);
                        return 0;
                        }
                    case 1:
                        {
                            st1.options();

                        }

                        break;
                    case 2:
                        {
                            system("cls");

                        string pass="",pass2="";
	char ch;
	int i,j;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t|============ WELCOME TO STORE MANAGEMENT SYSTEM ============|";
	_getch();
	system("cls");
	cout<<"\n\t\t   STORE MANAGEMENT SYSTEM\n";
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>j;
	if(j==1)
	{
	system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\tEnter the password: ";
	ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
	if(pass=="admin")
	{
i=dealermenu();
while(i>=1&&i<=4)
{
    system("cls");
	switch (i)
	{
    case 1:
        {
		addnew();_getch();
        i=dealermenu();
        break;
        }
    case 2:
        {system("cls");
    	disp();_getch();
    	i=dealermenu();
        break;
	}
	case 3:
	    {
	    refill();i=dealermenu();
        break;
	    }
    case 4:
        {
        remove();_getch();i=dealermenu();
        break;
        }
    default:
        {
		system("cls");
	cout<<"\n\n\n\t\t\tThank You!";
	_getch();
	exit(0);
        }
        }
    }
}
else
{
	cout<<"\n\n\nAuthorized personnel only!!\n\n";
	_getch();
	exit(0);
}
}

	if(j==2)
	{
	    i=custmenu();

while(i>=1 && i<=2)
{
    system("cls");


	switch (i)
	{
    case 1:
        {
		withdraw();_getch();i=custmenu();
        break;
        }
    case 2:
        {system("cls");
	disp();_getch();
    	i=custmenu();
        break;
	}
    default:
        {
		system("cls");
	cout<<"\n\n\n\t\t\tThank You!";
	_getch();
	exit(0);
        }
        }
    }
}
if(j==3)

{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t\tEnter the password: ";
    ch='0';
	ch = _getch();
   while(ch != 13){//character 13 is enter
      pass2.push_back(ch);
      cout << '*';
      ch = _getch();
   }

	if(pass2=="usr")
	{i=empmenu();
while(i>=1&&i<=4)
{
    system("cls");


	switch (i)
	{
    case 1:
        {
		system("cls");
	disp();_getch();
    	i=empmenu();
        break;
        }
    case 2:
        {system("cls");
        refill();i=empmenu();
        break;
	}
    default:
        {
		system("cls");
	cout<<"\n\n\n\t\t\tThank You!";
	_getch();
	exit(0);
        }
        }
    }
}
else
{
	cout<<"\n\nSorry!! Access Denied..\n\n";
	_getch();
	exit(0);
}
	_getch();
}
}
                        break;
                    case 3:
                        st3.cahOptions();
                        break;

                    default:
                        cout<<"\n Sorry! I don't understand that! \n"
                            <<"press Enter to re-enter again.";
                            _getch();
                        break;
                }
                return 1;

}
