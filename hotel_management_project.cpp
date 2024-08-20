#include<iostream>
#include <fstream>
#include <iostream>
#include <cstring>  
#include <cstdlib>  
using namespace std;

void intro() {
    cout << "\n\n\t            ";
    cout << "     C++ Project On Hotel Management System";
    cout << "\n\n\t\t\t\t     MADE BY";
    cout << "\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\tRohan Rote\t\t\t      ||";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\t\t\t  \t\t\t\t      ||";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
}

void head() {
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "\n\t\t\t\t\t\t\t\t       ";
    cout << "\n\t\t\t\t   XYZ Group of Hotels\t\t\t       ";
    cout << "\n\t\t\t\t\t\t\t\t       ";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
}

void time() {
    int i = 0;
    long long j;
    cout << "	\n\n\n	Connecting to Server\n 	Syncing Data";
    while (i < 10) {
        for (j = 0; j < 100000000; j++) {}
        cout << ".";
        ++i;
    }
}

class hotel {
    private:
        int room_no;
        char name[30];
        char address[50];
        char phone[15];
        int days;
        float fare;
    public:
        void main_menu();
        void add();
        void display();
        void rooms();
        void edit();
        int check(int);
        void modify(int);
        void delete_rec(int);
};

void hotel::main_menu() {
    int choice = 0;
    while (choice != 5) {
        system("cls");
        head();
        cout << "\n\t\t\t\t*****";
        cout << "\n\t\t\t\t* MAIN MENU *";
        cout << "\n\t\t\t\t*****";
        cout << "\n\n\n\t\t\t1. Book A Room";
        cout << "\n\t\t\t2. Customer Record";
        cout << "\n\t\t\t3. Rooms Allotted";
        cout << "\n\t\t\t4. Edit Record";
        cout << "\n\t\t\t5. Exit";
        cout << "\n\n\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: add();
                    break;
            case 2: display();
                    break;
            case 3: rooms();
                    break;
            case 4: edit();
                    break;
            case 5: break;
            default: {
                cout << "\n\n\t\t\tWrong choice.....!!!";
                cout << "\n\t\t\tPress any key to continue....!!";
                cin.ignore().get();
            }
        }
    }
}

void hotel::add() {
    system("cls");
    head();
    int r, flag;
    ofstream fout("Record.dat", ios::app | ios::binary);
    cout << "\n Enter Customer Details";
    cout << "\n ----------------------";
    cout << "\n\n Room no: ";
    cin >> r;
    flag = check(r);
    if (flag)
        cout << "\n Sorry..!!! Room is already booked";
    else {
        room_no = r;
        cout << " Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << " Address: ";
        cin.getline(address, 50);
        cout << " Phone No: ";
        cin.getline(phone, 15);
        cout << " No of Days to Checkout: ";
        cin >> days;
        fare = days * 900;
        fout.write(reinterpret_cast<char*>(this), sizeof(hotel));
        cout << "\n Room is booked...!!!";
    }

    cout << "\n Press any key to continue.....!!";
    cin.ignore().get();
    fout.close();
}

void hotel::display() {
    system("cls");
    head();
    ifstream fin("Record.dat", ios::in | ios::binary);
    int r, flag = 0;
    cout << "\n Enter room no: ";
    cin >> r;
    while (fin.read(reinterpret_cast<char*>(this), sizeof(hotel))) {
        if (room_no == r) {
            system("cls");
            head();
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone no: " << phone;
            cout << "\n Days: " << days;
            cout << "\n Total Fare: " << fare;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry, Room no. not found or vacant....!!";
    cout << "\n\n Press any key to continue....!!";
    cin.ignore().get();
    fin.close();
}

void hotel::rooms() {
    system("cls");
    head();
    ifstream fin("Record.dat", ios::in | ios::binary);
    cout << "\n\t\t\t    List Of Rooms Allotted";
    cout << "\n\t\t\t    ----------------------";
    while (fin.read(reinterpret_cast<char*>(this), sizeof(hotel))) {
        cout << "\n Room no: " << room_no << "\n Name: " << name;
        cout << "\n Address: " << address << "\n Phone: " << phone;
        cout << "\n Days: " << days << "\n Total: " << fare;
        cout << "\n************";
    }
    cout << "\n\n\n\t\t\tPress any key to continue.....!!";
    cin.ignore().get();
    fin.close();
}

void hotel::edit() {
    system("cls");
    head();
    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1. Modify Customer Record";
    cout << "\n 2. Delete Customer Record";
    cout << "\n Enter your choice: ";
    cin >> choice;

    system("cls");
    head();
    cout << "\n Enter room no: ";
    cin >> r;
    switch (choice) {
        case 1: modify(r);
                break;
        case 2: delete_rec(r);
                break;
        default: cout << "\n Wrong Choice.....!!";
    }
    cout << "\n Press any key to continue....!!!";
    cin.ignore().get();
}

int hotel::check(int r) {
    int flag = 0;
    ifstream fin("Record.dat", ios::in | ios::binary);
    while (fin.read(reinterpret_cast<char*>(this), sizeof(hotel))) {
        if (room_no == r) {
            flag = 1;
            break;
        }
    }
    fin.close();
    return flag;
}

void hotel::modify(int r) {
    system("cls");
    head();
    long pos;
    int flag = 0;
    fstream file("Record.dat", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read(reinterpret_cast<char*>(this), sizeof(hotel));
        if (room_no == r) {
            cout << "\n Enter New Details";
            cout << "\n -----------------";
            cout << "\n Name: ";
            cin.ignore();
            cin.getline(name, 30);
            cout << " Address: ";
            cin.getline(address, 50);
            cout << " Phone no: ";
            cin.getline(phone, 15);
            cout << " Days: ";
            cin >> days;
            fare = days * 900;
            file.seekg(pos);
            file.write(reinterpret_cast<char*>(this), sizeof(hotel));
            cout << "\n Record is modified....!!";
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "\n Sorry, Room no. not found or vacant...!!";
    file.close();
}

void hotel::delete_rec(int r) {
    system("cls");
    head();
    int flag = 0;
    char ch;
    ifstream fin("Record.dat", ios::in | ios::binary);
    ofstream fout("temp.dat", ios::out | ios::binary);
    while (fin.read(reinterpret_cast<char*>(this), sizeof(hotel))) {
        if (room_no == r) {
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone No: " << phone;
            cout << "\n Days: " << days;
            cout << "\n Total Fare: " << fare;
            cout << "\n\n Do you want to delete this record (y/n): ";
            cin >> ch;
            if (ch == 'n')
                fout.write(reinterpret_cast<char*>(this), sizeof(hotel));
            flag = 1;
        } else {
            fout.write(reinterpret_cast<char*>(this), sizeof(hotel));
        }
    }

    fin.close();
    fout.close();
    if (flag == 0)
        cout << "\n Sorry, room no. not found or vacant...!!";
    else {
        remove("Record.dat");
        rename("temp.dat", "Record.dat");
    }
}

int main() {
    hotel h;
    system("cls");
    cout << "\n\n\n";
    intro();
    time();
    cout << "\n\n\n\t\t\tPress any key to continue....!!";

    cin.ignore().get();
    system("cls");
    head();
    char id[5], pass[7];
    cout << "\n\n\t\t\t\tusername => ";
    cin >> id;
    cout << "\n\t\t\t\tpassword => ";
    cin >> pass;
    cout << "\n\n\t";
    time();
    cout << "\t";
    if (strcmp(id, "admin") == 0 && strcmp(pass, "**") == 0)
        cout << "\n\n\t\t\t  !!!Login Successful!!!";
    else {
        cout << "\n\n\t\t\t!!!INVALID CREDENTIALS!!!";
        cin.ignore().get();
        exit(-1);
    }
    system("cls");
    h.main_menu();
    cin.ignore().get();

    return 0;
}
