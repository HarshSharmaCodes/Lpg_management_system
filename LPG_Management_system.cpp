// LPG MANAGEMENT SYSTEM BY - Harsh Sharma //
#include<iostream>
#include<iomanip>
#include<string>
#include<windows.h>
#include<fstream>
#include<conio.h>
#define TOTAL_GAS 400

using namespace std;

class lpg_management
{
    // ===> FOR CUSTOMER LOGIN <=== //
    protected:
    string username;
    string password;
    string usn;

    // ===> FOR DATE <=== //
    int dd,mm,yy;

    // ===> FOR ADMIN TO UPDATE STOCK <=== //
    int sum_stock = 0;
    int add, comp;

    // ===> FOR REGISTRATION THROUGH ADMIN <=== //
    char name[100];
    char gender;
    char complaint[1000];
    char address[70];
    int age;
    string adhaar;
    string phone_no;

    public:

        // ===> LOGIN MODULES <=== //
        void menu();            // 61-96
        void admin();           // 98-152
        void admin_password();  // 154-206
        void customer();        // 208-242
        void cust_password();   // 244-325

        // ADMIN MODULES //
        void Stock();               // 329-384
        void new_connection();      // 386-499
        void display_data();        // 501-539
        void show_data();           // 541-555
        void update_customer_data();// 557-709
        void delete_customer_data();// 711-759
        void show_bookings();       // 762-817
        void show_complaints();     // 820-878
        void show_issue();          // 880-891

        // CUSTOMER MODULES //
        void booking();      // 895-945
        void report_issue(); // 947-989
};

// Menu Module //
void lpg_management::menu()
{
    system("cls");
    int choice;
    do
        {
            system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    // Main Menu //
    cout << "\n\n\t\t -->> MAIN MENU <<--";
    cout << "\n\n\t\t -->>1. ADMIN";
    cout << "\n\n\t\t -->>2. CUSTOMER";
    cout << "\n\n\t\t -->>3. EXIT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
        admin();
        break;
    case 2:
        customer();
        break;
    case 3:
        cout << "\n\n\t\t\t\t\t YOU'VE BEEN EXITED..! \n\n\t\t\t";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... Press Try Again.. \n ";
    }
    cin.ignore();
    cin.get();
    }while(choice!=3);
}

// ADMIN MENU //
void lpg_management::admin()
{
    system("cls");
    admin_password();
    int admin_choice;
    do{
        system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    //----------ADMIN MENU OPTIONS----------//
    cout << "\n\n\t\t-->> ADMIN MENU <<--";
    cout << "\n\n\t\t 1. Stock Details";
    cout << "\n\n\t\t 2. Apply For A Connection ";
    cout << "\n\n\t\t 3. Show Customer Details ";
    cout << "\n\n\t\t 4. Update/Modify Details ";
    cout << "\n\n\t\t 5. Delete Customer Data";
    cout << "\n\n\t\t 6. Show Bookings";
    cout << "\n\n\t\t 7. Show Customer Complaints";
    cout << "\n\n\t\t 8. Log Out";
    cout << "\n\n\t\t Enter Choice : ";
    cin >> admin_choice;
    switch(admin_choice)
    {
    case 1:
        Stock();
        break;
    case 2:
        new_connection();
        break;
    case 3:
        display_data();
        break;
    case 4:
        update_customer_data();
        break;
    case 5:
        delete_customer_data();
        break;
    case 6:
        show_bookings();
        break;
    case 7:
        show_complaints();
        break;
    case 8:
        menu();
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        getch();
        break;
    }
    }while(admin_choice!=8);
}

// ADMIN LOGIN //
void lpg_management::admin_password()
{
    system("cls");
    char a_name[20];
    char a_password[20];
    int ch,i=0,capt=0,otp=0;
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\n\t\t -->> ADMIN LOGIN <<--";
    cout << "\n\n\t\tEnter Your Name : ";
    cin >> a_name;
    cout << "\n\t\tEnter Password : ";
    while((ch = getch()) != 13)
    {
        cout << "*";
        a_password[i]=ch;
        i++;
    }
    a_password[i]='\0';
    srand(time(0));
    capt = rand();
    cout << "\n\n\t\tOTP : "<< capt;
    cout << "\n\n\t\tEnter the OTP : ";
    cin >> otp;
    if((strcmp(a_name,"harsh") == 0) && (strcmp(a_password, "admin") == 0) && (capt == otp) || (strcmp(a_name,"himanshi") == 0) && (strcmp(a_password, "admin") == 0) && (capt == otp))
    {
        cout << "\n\n\n\t\t\t\t\t| VERIFYING ADMIN |\n\t\t\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(400);
            cout << "...";
        }
        cout << "\n\n\t\tAccess Granted..\n\n";
        system("PAUSE");
        system("cls");
    }
    else
    {
        cout << "\n\n\n\t\t\t\t\t| VERIFYING ADMIN |\n\t\t\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(400);
            cout << "...";
        }
        cout << "\n\n\t\tAccess Not Granted..\n\n";
        system("PAUSE");
        system("cls");
        menu();
    }
}

// CUSTOMER MENU //
void lpg_management::customer()
{
    cust_password();
    system("cls");
    int c;
    do{
        system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    //----------CUSTOMER MENU OPTIONS--------------//
    cout << "\n\n\t\t -->> Customer Main Menu <<--";
    cout << "\n\n\t\t1.Booking ";
    cout << "\n\n\t\t2.Report Issue ";
    cout << "\n\n\t\t3.Logout ";
    cout << "\n\n\t\tChoose Any Option : ";
    cin >> c;
    switch(c)
    {
    case 1:
        booking();
        break;
    case 2:
        report_issue();
        break;
    case 3:
        menu();
    default:
        cout << "\n\n\t\t Invalid Choice...Please Try Again...";
    }
    cin.ignore();
    cin.get();
    }while(c!=3);
}

// CUSTOMER LOGIN //
void lpg_management::cust_password()
{
    system("cls");
    int cust_choice;
    string fname,usern,addr,phn;
    ofstream file1;
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\n\t\t -->> Customer Menu <<--";
    cout << "\n\n\t\t 1. Create Account";
    cout << "\n\n\t\t 2. Login";
    cout << "\n\n\t\t 3. Back";
    cout << "\n\n\t\t Enter Choice : ";
    cin >> cust_choice;
    if(cust_choice == 1)
    {
        system("cls");
        cout << "\n\n\t\t -->> REGISTRATION USER <<--";
        cout << "\n\n\t\tEnter Your Name : ";
        cin.ignore();
        getline(cin, username);
        cout << "\n\t\tEnter Your Username : ";
        cin >> usn;
        cout << "\n\t\tEnter your Password : ";
        cin >> password;
        fname=usn+".txt";
        file1.open(fname.c_str());
        file1<<usn<<endl
             <<username<<endl
             <<password<<endl;
        cout << "\n\n\tYou are successfully registered.. ";
        cout << "\n\n\tPress Any key to continue ..";
        getch();
        file1.close();
        customer();
    }
    else if(cust_choice == 2)
    {
        system("cls");
        ifstream file2;
        string u_name, u_pass;
        //---------LOGIN CUSTOMER---------//
        cout << "\n\n\t\t -->> LOGIN USER <<--";
        cout << "\n\n\t\tEnter Your Username : ";
        cin >> u_name;
        cout << "\n\t\tEnter Your Password : ";
        cin >> u_pass;
        fname = u_name + ".txt";
        file2.open(fname.c_str());
        if (!file2.is_open() && file2.fail())
        {
            cout << "\n\n\t\tYou are not registered, please register before logging in.\n";
            file2.close();
            getch();
            cust_password();
        }
        getline(file2, usern);
        getline(file2, u_pass);
        if (u_name == usn && u_pass == password)
        {
            cout << "\n\n\t\tYou are successfully logged in..!";
            cout << "\n\n\t\tPress Enter..";
            Sleep(500);
            getch();
            customer();
        }
    }

    else if(cust_choice==3)
    {
        menu();
    }

    else
    {
        cout << "\n\n\t\t Invalid Choice...Please Try Again...";
        getch();
        cust_password();
    }
}

//===> ADMIN MODULES <===//

// STOCK MODULE //
void lpg_management::Stock()
{
    fstream file;
    system("cls");
    cout << "\n\n\t\t-->> STOCK IN COMPANY <<--";
    cout << "\n\n\t\t1. Update Or Add the Stock ";
    cout << "\n\n\t\t2. Display the stock ";
    cout << "\n\n\t\t3. Back";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> comp;
    if(comp == 1)
    {
        system("cls");
        file.open("company1.txt", ios::out);
        cout << "\n\t\t -->> STOCK <<--";
        cout << "\n\n\tEnter Number Of Gas You Want To Add To Their Warehouse : ";
        cin >> add;
        sum_stock = sum_stock + add;
        file << sum_stock;
        file.close();
        cout << "\n\n\tStock Just Updated : " << sum_stock;
        cout << "\n\n\t\tSUCCESSFULLY ADDED STOCK TO THE INDANE";
        cout << "\n\n\nPress Any Key To Continue..";
        getch();
     }
     else if(comp == 2)
     {
        system("cls");
        ifstream ind;
        fstream file1;
        cout << "\n\n\t\t->> Available Gas Stock <<--\n";
        int i = 0;
        file1.open("company1.txt"); // Open Company
        file1 >> sum_stock;
        ind.open("Customer_Data.txt"); // Data take from file
        ind.seekg(0, ios::beg);
        while (ind.read((char *)this, sizeof(lpg_management)));
        {
            i++;
        }
        ind.close();
        int s = TOTAL_GAS + sum_stock - i;
        file1.close();
        cout << "\n\n\t\tAvailable Number Of GAS are: " << s;
        cout << "\n\n\t\tPress Any Key To Continue !";
        getch();
    }

    else
    {
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        getch();
        Stock();
    }
}

// REGISTER NEW CUSTOMER //
void lpg_management::new_connection()
{
    int index, check = 0;
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\n\t\t-->> CUSTOMER REGISTRATION <<--";
V:
    cout << "\n\n\t\tEnter Name: ";
    fflush(stdin);
    cin.getline(name, 100);
    // for loop to traverse the whole string

    for (index = 0; name[index]; index++)
        {
            for (index = 0; name[index]; index++)
            {
        // if condition to check if the string Have Alphabet
        if ((name[index] >= 'A' && name[index] <= 'Z') || (name[index] >= 'a' && name[index] <= 'z') || (name[index] == 32))
        {
          check++;
        }
        else
        {
          check = 0;
          break;
        }
            }//Inner For Loop Ends Here//
        if (check != 0)
        {
        cout << "\n\t\tValid Name";
        break;
        }
      else
        {
        cout << "\n\t\tInvalid Name";
        goto V;
        break;
        }
    }
C:
    cout << "\n\n\t\tEnter Aadhar Number : ";
    cin >> adhaar;
    if (adhaar.length() != 12)
    {
        cout << "\n\t\tInvalid Aadhar Card Number !";
        goto C;
    }
    else
    {
        // The first letter should not start with 0
        if (adhaar[0] == '0')
        {
            cout << "\n\t\tInvalid Aadhar Card Number";
            goto C;
        }
        else
        {
            cout << "\n\t\tValid Aadhar Card Number";
        }
    }
B:
    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> phone_no;
    if (phone_no.length() != 10)
    {
        cout << "\n\t\tInvalid Phone Number";
        goto B;
    }
    else
    {
        // The First letter should not start with 0 or 1
        if (phone_no[0] == '0' || phone_no[0] == '1')
        {
            cout << "\n\t\tInvalid Phone Number";
            goto B;
        }
        else
        {
            cout << "\n\t\tValid Phone Number";
        }
    }
GEN:
    cout << "\n\n\t\tEnter Gender (M/F/T): ";
    cin >> gender;
    if( gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f' || gender == 'T' || gender == 't' )
    {
        cout << "\n\t\tValid Gender";
    }
    else
    {
        cout << "\n\t\tInvalid Gender";
        goto GEN;
    }
G:
    cout << "\n\n\t\tEnter Age: ";
    cin >> age;
    if(age < 12 || age > 100)
    {
        cout << "\n\n\t\tInvalid Age";
        goto G;
    }
    cout << "\n\t\tEnter Permanent Address: ";
    fflush(stdin);
    cin.getline(address, 70);
    file.open("customer_Data.txt", ios::app );
    file.write((char *)this, sizeof(lpg_management));
    cout << "\n\t\tYOU HAVE SUCCESSFULLY APPLIED FOR A NEW CONNECTION !";
    cout << "\n\n\t\tPress Any Key To Continue !";
    file.close();
    getch();
}

// DISPLAY DATA OF THE REGISTERED CUSTOMER //
void lpg_management::display_data()
{
    int count = 0;
    string vadhaar;
    fstream file;
    file.open("customer_Data.txt", ios::in );
    system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\n\t\t-->> SEARCH DATA BY AADHAR <<--";
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> vadhaar;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(lpg_management));
    }
    while (!file.eof())
    {
        if (vadhaar.compare(adhaar) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(lpg_management));
    }
    if (count == 0)
    {
        cout << "\n\t\tRecord Not Found!";
    }
    file.close();
    cout << "\n\n\t\tPress Any Key To Continue !";
    getch();
}

// MODULE TO READ DATA FROM FILE (USED IN DISPLAY MODULE) //
void lpg_management::show_data()
{
    system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\n\t\tThe Details are shown below..!";
    cout << "\n\n\t\tName : " << name;
    cout << "\n\n\t\tAadhar No.: " << adhaar;
    cout << "\n\n\t\tMobile No.: " << phone_no;
    cout << "\n\n\t\tGender : " << gender;
    cout << "\n\n\t\tAge : " << age;
    cout << "\n\n\t\tAddress : " << address;
}

// MODULE TO MODIFY OR UPDATE THE DETAILS OF CUSTOMER //
void lpg_management::update_customer_data()
{
    system("cls");
    int choice;
    int index, check = 0;
    string uadhaar;
    int found = 0;
    fstream file, file1;
    file.open("customer_data.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tFile Not Found!";
        getch();
        file.close();
    }
    else
    {
        cout << "\n\t\t\t\t-----------------------------------------";
        cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t-----------------------------------------";
        cout << "\n\n\t\t-->> SEARCH DATA BY AADHAR NO. TO MODIFY <<--";
        cout << "\n\n\t\tEnter Aadhar No.: ";
        cin >> uadhaar;
        file1.open("record.txt", ios::app | ios::out);
        file.read((char *)this, sizeof(lpg_management));
        while (!file.eof())
        {
            if (uadhaar!=adhaar)
            {
             file1.write((char *)this, sizeof(lpg_management));
            }
            else
            {
                cout << "\n\t\tWhat Do You Want To Update ?";
                cout << "\n\t\t1.Name";
                cout << "\n\t\t2.Mobile Number";
                cout << "\n\t\t3.Gender";
                cout << "\n\t\t4.Age";
                cout << "\n\t\t5.Address";
                cout << "\n\t\tEnter Choice : ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    NAME:
                    cout << "\n\n\t\tEnter Name: ";
                    fflush(stdin);
                    cin.getline(name, 100);
                    // for loop to traverse the whole string
                    for (index = 0; name[index]; index++)
                    {
                        for (index = 0; name[index]; index++)
                            {
                                // if condition to check if the string Have Alphabet
                                if ((name[index] >= 'A' && name[index] <= 'Z') || (name[index] >= 'a' && name[index] <= 'z') || (name[index] == 32))
                                    {
                                        check++;
                                    }
                                else
                                    {
                                        check = 0;
                                        break;
                                    }
                            }
                            if (check != 0)
                                {
                                    cout << "\n\t\tValid Name";
                                    break;
                                }
                            else
                                {
                                    cout << "\n\t\tInvalid Name";
                                    goto NAME;
                                    break;
                                }
                    }
                    break;
                case 2:
                    PHN:
                    cout << "\n\t\t Enter Mobile No.: ";
                    cin >> phone_no;
                    if (phone_no.length() != 10)
                        {
                            cout << "\n\t\tInvalid Phone Number";
                            goto PHN;
                        }
                    else
                        {
                            // The First letter should not start with 0 or 1
                            if (phone_no[0] == '0' || phone_no[0] == '1')
                            {
                                cout << "\n\t\tInvalid Phone Number";
                                goto PHN;
                            }
                            else
                            {
                                cout << "\n\t\tValid Phone Number";
                            }
                        }
                    break;
                case 3:
                    GENDER:
                    cout << "\n\t\t Enter Gender (M/F): ";
                    cin >> gender;
                    if( gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f' || gender == 'T' || gender == 't' )
                        {
                            cout << "\n\t\tValid Gender";
                        }
                    else
                        {
                            cout << "\n\t\tInvalid Gender";
                            goto GENDER;
                        }
                    break;
                case 4:
                    AGE:
                    cout << "\n\t\t Enter Age : ";
                    cin >> age;
                    if(age < 12 || age > 100)
                    {
                        cout << "\n\n\t\tInvalid Age";
                        goto AGE;
                    }
                    break;
                case 5:
                    cout << "\n\t\t Enter Address : ";
                    fflush(stdin);
                    cin.getline(address, 70);
                    break;
                default:
                    cout << "\n\t\tInvalid choice .... Please Try Again";
                    getch();
                    break;
                }
                cout << "\n\n\t\tSuccessfully Modified Details Of Customer !";
                getch();
                file1.write((char *)this, sizeof(lpg_management));
                found++;
            }
            file.read((char *)this, sizeof(lpg_management));
        }
        if (found == 0)
        {
            cout << "\n\n\t\tRecord Not Found!";
            getch();
        }
        file1.close();
        file.close();
        remove("customer_data.txt");
        rename("record.txt", "customer_data.txt");
    }
}

// MODULE TO DELETE DATA OF CUSTOMER //
void lpg_management::delete_customer_data()
{
    system("cls");
    string dadhaar;
    int found = 0;
    fstream file, file1;
    file.open("customer_data.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tFile Not Found!";
        file.close();
        getch();
    }
    else
    {
        cout << "\n\t\t\t\t-----------------------------------------";
        cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t-----------------------------------------";
        cout << "\n\n\t\t-->> SEARCH DATA BY AADHAR NO. TO DELETE <<--";
        cout << "\n\n\t\tEnter Aadhar No.: ";
        cin >> dadhaar;
        file1.open("record.txt", ios::app | ios::out);
        file.read((char *)this, sizeof(lpg_management));
        while (!file.eof())
        {
            if (dadhaar!=adhaar)
            {
             file1.write((char *)this, sizeof(lpg_management));
            }
            else
            {
                found++;
                cout << "\n\n\t\t SUCCESSFULLY DELETED..!";
                getch();
            }
            file.read((char *)this, sizeof(lpg_management));
        }
        if (found == 0)
        {
            cout << "\n\n\t\tRecord Not Found!";
            getch();
        }
        file1.close();
        file.close();
        remove("customer_data.txt");
        rename("record.txt", "customer_data.txt");
    }
}

// MODULE TO DISPLAY CUSTOMER WHO HAVE BOOKED //
void lpg_management::show_bookings()
{
    fstream file;
    string mob;
    int count = 0;
    file.open("book_Data.txt", ios::in );
    system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\n\t\t-->> CHECK BOOKINGS BY MOBILE NUMBER <<--";
    cout << "\n\n\t\tEnter Mobile Number : ";
    cin >> mob;
    if (!file)
    {
        cout << "\n\n\t\tFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(lpg_management));
        while (!file.eof())
            {
                if (mob.compare(phone_no) == 0)
                {
                    count++;
                    cout << "\n\n\t\t\t\t\t| CHECKING | \n\t\t\t\t\t  ";
                    for (int a = 1; a < 5; a++)
                    {
                        Sleep(600);
                        cout << "...";
                    }
                    if (mob.compare(phone_no) == 0)
                    {
                        cout << "\n\n\t\tGAS BOOKED ";
                    }
                    else
                    {
                        cout << "\n\n\t\tNOT BOOKED";
                    }
                }
                else
                {
                    cout << "\n\n\t\t Record Doesn't Exist !! \n\n\t\t";
                    system("pause");
                }
                file.read((char *)this, sizeof(lpg_management));
            }
    }
    file.close();
    getch();
}


// MODULE TO DISPLAY COMPLAINTS OF THE CUSTOMERS //
void lpg_management::show_complaints()
{
    system("cls");
    fstream file;
    file.open("complaints.txt", ios::in );
    int count = 0;
    int date,month,year;
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t-->> Enter Date To Search Complaints <<--\n";
    J:
    cout << "\n\t\t Enter Date : ";
    cin >> date;
    if( date > 31)
    {
        cout << "\n\t\tInvalid Date ";
        goto J;
    }
    K:
    cout << "\n\t\t Enter Month : ";
    cin >> month;
    if( month > 12)
    {
        cout << "\n\t\tInvalid Month ";
        goto K;
    }
    L:
    cout << "\n\t\t Enter Year : ";
    cin >> year;
    if( year < 2022 )
    {
        cout << "\n\t\tInvalid Year ";
        goto L;
    }
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(lpg_management));
    }
    while (!file.eof())
    {
        if (date == dd && month == mm && year == yy)
        {
            count++;
            show_issue();
        }
        file.read((char *)this, sizeof(lpg_management));
    }
    if (count == 0)
    {
        cout << "\n\n\t\tRecord Not Found!";
    }
    file.close();
}

// MODULE TO READ DATA FROM FILE (USED IN SHOW COMPLAINT MODULE) //
void lpg_management::show_issue()
{
    system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\n\t\t Date : " << dd << "/" << mm << "/" << yy ;
    cout << "\n\n\t\t The Complaints Are Shown Below !";
    cout << "\n\n\t\t ===> " << complaint << endl <<"\n\n\n\t";
    system("pause");
}

// ===> CUSTOMER MODULES <=== //

// MODULE FOR CUSTOMER TO BOOK GAS //
void lpg_management::booking()
{
    system("cls");
    display_data();
    char a,b;
    fstream file;
    cout << "\n\n\t\tDo you want to Book Gas ? [y/n] -> ";
    cin >> a;
    if (a == 'y' || a == 'Y')
    {
        cout << "\n\t\tOnly 1 Gas Can be Booked at a Time !";
    }
    else
    {
        customer();
    }
    cout << "\n\n\t\tDo You Want to Continue ? [y/n] -> ";
    cin >> b;
    if (b == 'y' || b == 'Y')
    {
        cout << "\n\n\t\t Your Gas is Booked ..!";
    }
    P:
    cout << "\n\n\t\tEnter your Registered Mobile Number for Further Updates --> ";
    cin >> phone_no;
    if (phone_no.length() != 10)
    {
        cout << "\n\t\tInvalid Phone Number";
        goto P;
    }
    else
    {
        // The First letter should not start with 0 or 1
        if (phone_no[0] == '0' || phone_no[0] == '1')
        {
            cout << "\n\t\tInvalid Phone Number";
            goto P;
        }
        else
        {
            cout << "\n\t\tValid Phone Number";
        }
    }
    file.open("book_Data.txt", ios::app );
    file.write((char *)this, sizeof(lpg_management));
    cout << "\n\n\t\tYOU HAVE SUCCESSFULLY BOOKED !";
    cout << "\n\n\t\tPress Any Key To Continue !";
    file.close();
    getch();
}

// MODULE FOR CUSTOMER TO REPORT THEIR COMPLAINTS //
void lpg_management::report_issue()
{
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t     *    LPG MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t-----------------------------------------";
    cout << "\n\n\t\t-->> REPORT ISSUE <<--";
    D:
    cout << "\n\n\t\tEnter Today's Date : ";
    cin >> dd;
    if( dd > 31)
    {
        cout << "\n\t\tInvalid Date ";
        goto D;
    }
    M:
    cout << "\n\t\tEnter Current Month : ";
    cin >> mm ;
    if( mm > 12)
    {
        cout << "\n\t\tInvalid Month ";
        goto M;
    }
    Y:
    cout << "\n\t\tEnter Current Year : ";
    cin >> yy;
    if( yy < 2022)
    {
        cout << "\n\t\tInvalid Year ";
        goto Y;
    }
    cout << "\n\t\t Entered Date : " << dd << "/" << mm << "/" << yy ;
    cout <<"\n\n\t\tWrite Your Complaint : ";
    cin.ignore();
    cin.getline(complaint,1000);
    file.open("complaints.txt", ios::app );
    file.write((char *)this, sizeof(lpg_management));
    cout << "\n\n\t\tWe Are Sorry to hear about this!!!\n\t\tYour complaint has been registered successfully and We shall revert you soon !!";
    cout << "\n\n\t\tPress Any Key To Continue ! ";
    file.close();
}

int main()
{
    system("color E");
    lpg_management system;
    system.menu();
}
