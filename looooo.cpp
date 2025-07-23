#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class passenger;
class internationalflight;
class domesticflight;

class amount {
private:
    int price;
public:
    amount()  {
        price=0;
    }

    void billcal1() {
        price = 20000;
    }

    void billcal2() {
        price = 10000;
    }

    void displayticket1(passenger p1, string flight, string dep, string des, int seat, string departuretime, string flighttype);
    friend class internationalflight;
    friend class domesticflight;
    friend class passenger;
};

class passenger {
private:
    string first_name, last_name;
    int pno;
    int id;
    string password;
public:
    passenger()  {
        pno=0;
    }

    void getdata() {
        cout << "Enter Your First Name : ";
        cin >> first_name;
        cout << "Enter Your Last Name : ";
        cin >> last_name;
        cout << "Enter Your Passport Number : ";
        cin >> pno;
        id = uniqueid();
        cout << "Enter Your Password : ";
        cin >> password;
    }

    void display() {
        cout << "PASSENGER FIRST NAME : " << first_name << endl;
        cout << "PASSENGER LAST NAME : " << last_name << endl;
        cout << "PASSPORT NUMBER : " << pno << endl;
        cout << "PASSENGER ID : " << id << endl;
        cout << "PASSWORD : " << password << endl;
    }

    static int uniqueid() {
        srand(time(0));
        int min_random_no = 10000;
        int max_random_no = 99999;
        int id = rand() % (max_random_no - min_random_no + 1) + min_random_no;
        return id;
    }

    string getFirstname() {
        return first_name;
    }

    string getLastname() {
        return last_name;
    }

    int getid() {
        return id;
    }

    string getpassword() {
        return password;
    }

    friend class airline;
    friend class amount;
};

class airline {
protected:
    string flight;
    string dep;
    string des;
    string departuretime;
    int seat;
public:
    airline()  {
        seat=0;
    }

    void getdata() {
        cout << "Enter Flight Number : ";
        cin >> flight;
        cout << "Enter Departure : ";
        cin >> dep;
        cout << "Enter Destination : ";
        cin >> des;
        cout << "Enter Departure Time : ";
        cin >> departuretime;
        cout << "Enter Number Of Seats : ";
        cin >> seat;
    }

    string flights() {
        return flight;
    }

    string departure() {
        return dep;
    }

    string destination() {
        return des;
    }

    string deptime() {
        return departuretime;
    }

    void seatreserve(passenger p1) {
        if (seat > 0) {
            cout << "Seat reserved on flight: " << flight << " for Passenger: " << p1.first_name << " " << p1.last_name << " with Passport number: " << p1.pno << endl;
            seat--;
        }
        else {
            cout << "Seats are not available on flight " << flight << endl;
        }
    }

    void display() {
        cout << flight << "\t\t" << dep << "\t\t" << des << "\t\t\t" << departuretime << "\t\t\t" << seat << "\t\t";
    }

};

class internationalflight : public airline {
private:
    amount a;
    string flighttype;
public:
    internationalflight() {}

    void getdata() {
        airline::getdata();
        cout << "Enter Flight Type : ";
        cin >> flighttype;
    }

    void display() {
        airline::display();
        cout << flighttype << endl;
    }

    string flight_type() {
        return flighttype;
    }

    void seatreserve(passenger p1) {
        airline::seatreserve(p1);
    }

    void billcal1() {
        a.billcal1();
    }

    void displayticket1(passenger p1) {
        a.displayticket1(p1, flight, dep, des, seat, departuretime, flighttype);
    }

};

class domesticflight : public airline {
private:
    amount a;
    string flighttype;
public:
    domesticflight() {}

    void getdata() {
        airline::getdata();
        cout << "Enter Flight Type : ";
        cin >> flighttype;
    }

    void display() {
        airline::display();
        cout << flighttype << endl;
    }

    string flight_type() {
        return flighttype;
    }

    void seatreserve(passenger p1) {
        airline::seatreserve(p1);
    }

    void billcal2() {
        a.billcal2();
    }

    void displayticket1(passenger p1) {
        a.displayticket1(p1, flight, dep, des, seat, departuretime, flighttype);
    }

};

void amount::displayticket1(passenger p1, string flight, string dep, string des, int seat, string departuretime, string flighttype) {
    cout << "\t\tMk AIRLINE SYSTEM\t\t" << endl;
    cout << "Ticket Details are: " << endl;
    cout << "Passenger ID : " << p1.id << endl;
    cout << "Passenger name: " << p1.first_name << " " << p1.last_name << endl;
    cout << "Passenger passport number: " << p1.pno << endl;
    cout << "Flight number: " << flight << endl;
    cout << "Departure & Destination: " << dep << " to " << des << endl;
    cout << "Departure time: " << departuretime << endl;
    cout << "Seat Number : " << seat << endl;
    cout << "Flight Type : " << flighttype << endl;
    cout << "Bill: " << price << endl;
}


int main() {
    internationalflight i1;
    domesticflight d1;
    passenger p1;

    bool exit = false;

top:
    system("cls");
    cout << "************************************************************************************************************************" << endl;
    cout << "\t\t\t\t Welcome to MK Airline System \t " << endl;
    cout << "************************************************************************************************************************" << endl;
    cout << "Press 1 for ADMIN LOGIN " << endl;
    cout << "Press 2 for CUSTOMER LOGIN" << endl;
    cout << "Press 3 for CUSTOMER SIGNUP" << endl;
    cout << "Press 0 to EXIT" << endl;
    string username, password;
    int val;
    bool flag = false;
    int count = 0;
    cout << "Enter Your Choice : ";
    cin >> val;
    switch (val) {
    case 0:
        cout << "Goodbye!" << endl;
        exit = true;
        break;
    case 1:
    admin_again:
        cout << "Enter User Name : ";
        cin >> username;
        cout << "Enter Password : ";
        cin >> password;
        if ((username == "admin" && password == "admin123") || (username == "ADMIN" && password == "ADMIN123")) {
        admin_page:
            system("cls");
            cout << "\t\t\t\t\tWELCOME TO ADMIN PANEL" << endl;
            cout << "\n\nPress 1 to See All Customer Record " << endl;
            cout << "Press 2 to Delete Customer Account" << endl;
            cout << "Press 3 to Add International Flights" << endl;
            cout << "Press 4 to See International Flights" << endl;
            cout << "Press 5 to Add Domestic Flights" << endl;
            cout << "Press 6 to See Domestic Flights" << endl;
            cout << "Press 7 to See All Booked International Flights" << endl;
            cout << "Press 8 to See All Booked Domestic Flights" << endl;
            cout << "Press 0 to go Back" << endl;
            int choice;
            cout << "\nEnter Your Choice : ";
            cin >> choice;
            switch (choice) {
            case 0:
                goto top;
            case 1:
            {
                ifstream read("Customer Detail.dat", ios::binary);
                if (!read) {
                    cout << "Error Opening File for Reading" << endl;
                    break;
                }
                cout << "Reading Data........" << endl;
                cout << "--------------------------------------------" << endl;
                while (read.read(reinterpret_cast<char*>(&p1), sizeof(passenger))) {
                    p1.display();
                    cout << "--------------------------------------------" << endl;
                }
                read.close();
            }
            break;
            case 2:
            {
                int id;
                cout << "Enter Customer ID you Want to Delete : ";
                cin >> id;
                ofstream temp("temp File.dat", ios::binary | ios::app);
                ifstream read("Customer Detail.dat", ios::binary);
                if (!read || !temp) {
                    cout << "Error Opening File for Writing or Reading" << endl;
                    break;
                }
                while (read.read(reinterpret_cast<char*>(&p1), sizeof(passenger))) {
                    if (id != p1.getid()) {
                        temp.write(reinterpret_cast<char*>(&p1), sizeof(passenger));
                    }
                    else {
                        flag = true;
                    }
                }
                if (flag) {
                    cout << "Account with " << id << " ID Has been Deleted!" << endl;
                }
                else {
                    cout << "Account NOT FOUND!" << endl;
                }
                temp.close();
                read.close();
                remove("Customer Detail.dat");
                rename("temp File.dat", "Customer Detail.dat");
            }
            break;
            case 3:
            {
                ofstream write("International Detail.dat", ios::app | ios::binary);
                if (!write) {
                    cout << "Error Opening File for Writing" << endl;
                    break;
                }
                i1.getdata();
                write.write(reinterpret_cast<char*>(&i1), sizeof(internationalflight));
                write.close();
            }
            break;
            case 4:
            {
                ifstream read("International Detail.dat", ios::binary);
                if (!read) {
                    cout << "Error Opening File for Reading" << endl;
                    break;
                }
                cout << "Reading Data........" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "FLIGHTNO\tDEPARTURE\t\tDESTINATION\t\tDEPARTURE-TIME\t\tSEATS\t\tFLIGHT-TYPE" << endl;
                while (read.read(reinterpret_cast<char*>(&i1), sizeof(internationalflight))) {
                    i1.display();
                }
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                read.close();
            }
            break;
            case 5:
            {
                ofstream write("Domestic Detail.dat", ios::app | ios::binary);
                if (!write) {
                    cout << "Error Opening File for Writing" << endl;
                    break;
                }
                d1.getdata();
                write.write(reinterpret_cast<char*>(&d1), sizeof(domesticflight));
                write.close();
            }
            break;
            case 6:
            {
                ifstream read("Domestic Detail.dat", ios::binary);
                if (!read) {
                    cout << "Error Opening File for Reading" << endl;
                    break;
                }
                cout << "Reading Data........" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "FLIGHTNO\tDEPARTURE\tDESTINATION\t\tDEPARTURE-TIME\t\tSEATS\t\tFLIGHT-TYPE" << endl;
                while (read.read(reinterpret_cast<char*>(&d1), sizeof(domesticflight))) {
                    d1.display();
                }
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                read.close();
            }
            break;
            case 7:
            {
                ifstream read("Booked International Flights.dat", ios::binary);
                if (!read) {
                    cout << "Error Opening File for Reading" << endl;
                    break;
                }
                cout << "Booked Flights Details:\n";
                cout << "--------------------------------------------" << endl;
                while (read.read(reinterpret_cast<char*>(&p1), sizeof(passenger))) {
                    read.read(reinterpret_cast<char*>(&i1), sizeof(internationalflight));
                    i1.displayticket1(p1);
                    cout << "--------------------------------------------" << endl;
                }
                read.close();
            }
            break;
            case 8:
            {
                ifstream read("Booked Domestic Detail.dat", ios::binary);
                if (!read) {
                    cout << "Error Opening File for Reading" << endl;
                    break;
                }
                cout << "Booked Flights Details:\n";
                cout << "--------------------------------------------" << endl;
                while (read.read(reinterpret_cast<char*>(&p1), sizeof(passenger))) {
                    read.read(reinterpret_cast<char*>(&d1), sizeof(domesticflight));
                    d1.displayticket1(p1);
                    cout << "--------------------------------------------" << endl;
                }
                read.close();
            }
            break;
            default:
                cout << "Invalid Input!" << endl;
                break;
            }
        }
        else {
            cout << "INVALID CREDENTIALS!" << endl;
            count++;
            cout << "YOU HAVE TOTAL " << 3 - count << " CHANCES LEFT" << endl;
            if (count == 3) {
                cout << "SORRY! YOU HAVE USED ALL YOUR CHANCES" << endl;
                return 1;
            }
            goto admin_again;
        }
        cout << "Do you Want to Perform Anything Else ? (y/n) : ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            goto admin_page;
        }
        else {
            goto top;
        }
        break;
    case 2:
    {
        int id;
        string password;
    cust_again:
        cout << "Enter Your Passenger ID : ";
        cin >> id;
        cout << "Enter Your Password : ";
        cin >> password;
        ifstream read("Customer Detail.dat", ios::binary);
        while (read.read(reinterpret_cast<char*>(&p1), sizeof(passenger))) {
            if (id == p1.getid() && password == p1.getpassword()) {
                flag = true;
                break; // Exit the loop as soon as the correct customer is found
            }
        }
        read.close(); // Close the file after reading
        if (flag) {
        cust_panel:
            system("cls");
            cout << "\t\t\tWELCOME " << p1.getFirstname() << " " << p1.getLastname() << endl;
            cout << "Press 1 Reserve an International Flight " << endl;
            cout << "Press 2 Reserve a Domestic Flight " << endl;
            cout << "Press 3 to See Your International Booked Flights" << endl;
            cout << "Press 4 to See Your Domestic Booked Flights" << endl;
            cout << "Press 0 To Go Back " << endl;
            int choice;
            cout << "\nEnter Your Choice : ";
            cin >> choice;

            switch (choice) {
            case 0:
            {
                goto top;
            }
            break;
            case 1:
            {
                ofstream temp("temp.dat", ios::binary);
                ifstream read("International Detail.dat", ios::binary);
                if (!read || !temp) {
                    cout << "Error Opening File for Reading or Writing" << endl;
                    break;
                }
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "FLIGHTNO\tDEPARTURE\t\tDESTINATION\t\tDEPARTURE-TIME\t\tSEATS\t\tFLIGHT-TYPE" << endl;
                while (read.read(reinterpret_cast<char*>(&i1), sizeof(internationalflight))) {
                    i1.display();
                }
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                string flight;
                cout << "Enter Flight Number To Book Flight : ";
                cin >> flight;
                bool flightFound = false;
                read.close();
                read.open("International Detail.dat", ios::binary);
                while (read.read(reinterpret_cast<char*>(&i1), sizeof(internationalflight))) {
                    if (flight == i1.flights()) {
                        flightFound = true;
                        i1.seatreserve(p1);
                        i1.billcal1();
                        i1.displayticket1(p1);
                        temp.write(reinterpret_cast<char*>(&i1), sizeof(internationalflight));

                        ofstream booked("Booked International Flights.dat", ios::app | ios::binary);
                        booked.write(reinterpret_cast<char*>(&p1), sizeof(passenger));
                        booked.write(reinterpret_cast<char*>(&i1), sizeof(internationalflight));
                        booked.close();
                    }
                    else {
                        temp.write(reinterpret_cast<char*>(&i1), sizeof(internationalflight));
                    }
                }
                if (!flightFound) {
                    cout << "Flight Not Found!" << endl;
                }
                temp.close();
                read.close();
                remove("International Detail.dat");
                rename("temp.dat", "International Detail.dat");
                system("pause");
            }
            break;

            case 2:
            {
                ofstream temp("temp.dat", ios::binary);
                ifstream read("Domestic Detail.dat", ios::binary);
                if (!read || !temp) {
                    cout << "Error Opening File for Reading or Writing" << endl;
                    break;
                }
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "FLIGHTNO\tDEPARTURE\t\tDESTINATION\t\tDEPARTURE-TIME\t\tSEATS\t\tFLIGHT-TYPE" << endl;
                while (read.read(reinterpret_cast<char*>(&d1), sizeof(domesticflight))) {
                    d1.display();
                }
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                string flight;
                cout << "Enter Flight Number To Book Flight : ";
                cin >> flight;
                bool flightFound = false;
                read.close();
                read.open("Domestic Detail.dat", ios::binary);
                while (read.read(reinterpret_cast<char*>(&d1), sizeof(domesticflight))) {
                    if (flight == d1.flights()) {
                        flightFound = true;
                        d1.seatreserve(p1);
                        d1.billcal2();
                        d1.displayticket1(p1);
                        temp.write(reinterpret_cast<char*>(&d1), sizeof(domesticflight));

                        ofstream booked("Booked Domestic Detail.dat", ios::app | ios::binary);
                        booked.write(reinterpret_cast<char*>(&p1), sizeof(passenger));
                        booked.write(reinterpret_cast<char*>(&d1), sizeof(domesticflight));
                        booked.close();
                    }
                    else {
                        temp.write(reinterpret_cast<char*>(&d1), sizeof(domesticflight));
                    }
                }
                if (!flightFound) {
                    cout << "Flight Not Found!" << endl;
                }
                temp.close();
                read.close();
                remove("Domestic Detail.dat");
                rename("temp.dat", "Domestic Detail.dat");
                system("pause");
            }
            break;
            case 3:
            {
                ifstream read("Booked International Flights.dat", ios::binary);
                if (!read) {
                    cout << "Error Opening File for Reading" << endl;
                    break;
                }
                cout << "Your Booked International Flights:\n";
                cout << "--------------------------------------------" << endl;
                while (read.read(reinterpret_cast<char*>(&p1), sizeof(passenger))) {
                    internationalflight temp;
                    read.read(reinterpret_cast<char*>(&temp), sizeof(internationalflight));
                    if (p1.getid() == id) {
                        temp.displayticket1(p1);
                        cout << "--------------------------------------------" << endl;
                    }
                }
                read.close();
                system("pause");
                goto cust_panel;
            }
            break;
            case 4:
            {
                ifstream read("Booked Domestic Detail.dat", ios::binary);
                if (!read) {
                    cout << "Error Opening File for Reading" << endl;
                    break;
                }
                cout << "Your Booked Domestic Flights:\n";
                cout << "--------------------------------------------" << endl;
                while (read.read(reinterpret_cast<char*>(&p1), sizeof(passenger))) {
                    domesticflight temp;
                    read.read(reinterpret_cast<char*>(&temp), sizeof(domesticflight));
                    if (p1.getid() == id) {
                        temp.displayticket1(p1);
                        cout << "--------------------------------------------" << endl;
                    }
                }
                read.close();
                system("pause");
                goto cust_panel;
            }
            break;
            default:
                cout << "Invalid Input!" << endl;
                break;
            }
            goto cust_panel;
        }
        if (!flag) {
            cout << "INVALID CREDENTIALS!" << endl;
            count++;
            cout << "YOU HAVE TOTAL " << 3 - count << " CHANCES LEFT" << endl;
            if (count == 3) {
                cout << "SORRY! YOU HAVE USED ALL YOUR CHANCES" << endl;
                return 1;
            }
            goto cust_again;
        }
        read.close();
        cout << "Do you Want to Perform Anything Else ? (y/n) : ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            goto cust_panel;
        }
        else {
            goto top;
        }
    }
    break;
    case 3:
    {
        ofstream write("Customer Detail.dat", ios::app | ios::binary);
        if (!write) {
            cout << "Error Opening File for Writing" << endl;
            break;
        }
        p1.getdata();
        cout << "YOUR ID IS : " << p1.getid() << endl;
        write.write(reinterpret_cast<char*>(&p1), sizeof(passenger));
        write.close();
        system("pause");
    }
    break;
    default:
        cout << "Invalid Option!" << endl;
        break;
    }
    if (!exit)
        goto top;
    return 0;
}
