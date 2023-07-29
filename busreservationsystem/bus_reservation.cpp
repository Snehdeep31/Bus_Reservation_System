#include <iostream>
#include <fstream>
using namespace std;

int r = 0, k = 20;
float TotalSale = 0;
class bus
{
    char PessengerName[99];
    char deprt[9];
    char from[9];
    char to[9];
    char arriva[9];
    int Total_Seats, Total_Fare;
    int BusNo, Arrival_Timing, Departure_Timing, s;

public:
    void Bus_Registration();
    void show();
    void book();
    void Exit();

};
class allBusDetails
{
    public:
        allBusDetails()
        {
            count = 0;
        };
        bus buses[100];
        int count;
}abd;

/* Dummy function used to add lines of `*` to separate and clean output*/
void vline(char ch)
{

    for (int i = 75; i > 0; i--)
    {
        cout << ch;
    }
    cout << endl;
}
void bus::Bus_Registration(void)
{
    cout.setf(ios::right, ios::adjustfield);
    cout.width(15);
    cout << "\nEnter Bus No:";
    cin >> BusNo;
    cout.setf(ios::right, ios::adjustfield);
    cout.width(15);
    cout << "\nFrom: ";
    cin >> from;
    cout.setf(ios::right, ios::adjustfield);
    cout.width(15);
    cout << "\nTo: ";
    cin >> to;
    cout.setf(ios::right, ios::adjustfield);
    cout.width(15);
    cout << "\nDeparture: ";
    cin >> Departure_Timing;
    cout.setf(ios::right, ios::adjustfield);
    cout.width(15);
    cout << "\nArrival: ";
    cin >> Arrival_Timing;
    cout.setf(ios::right, ios::adjustfield);
    cout.width(15);
    cout << "\nTotal seats: ";
    cin >> Total_Seats;

    abd.count++; //Number of buses(index of array bus) increase
    cout << "\n";
    cout << "Bus Information Added!!\n";
    system("PAUSE");
    system("CLS");
}

void bus::show(void)
{
    cout << "\nTotal bus available:" << endl;
    for (int i = 0; i < abd.count; i++)
    {
        cout.setf(ios::right, ios::adjustfield);
        cout.width(15);
        cout << "Bus No: ";
        cout << abd.buses[i].BusNo << endl;
        cout.setf(ios::right, ios::adjustfield);
        cout.width(15);
        cout << "From: ";
        cout << abd.buses[i].from << endl;
        cout.setf(ios::right, ios::adjustfield);
        cout.width(15);
        cout << "To: ";
        cout << abd.buses[i].to << endl;
        cout.setf(ios::right, ios::adjustfield);
        cout.width(15);
        cout << "Departure: ";
        cout << abd.buses[i].Departure_Timing << " O'clock" << endl;
        cout.setf(ios::right, ios::adjustfield);
        cout.width(15);
        cout << "Arrival: ";
        cout << abd.buses[i].Arrival_Timing << " O'clock" << endl;
        cout.setf(ios::right, ios::adjustfield);
        cout.width(15);
        cout << "Seats: ";
        cout << abd.buses[i].Total_Seats << endl
             << endl
             << endl;
    }
    system("PAUSE");
    system("CLS");
}

void bus::book(void)
{
    int number;
    float Total_Fare;
    cout << "\nEnter Bus No: ";
    cin >> number;
    int n;
    for (n = 0; n < abd.count; n++)
    {
        if (abd.buses[n].BusNo == number)
        {
            if (abd.buses[n].Total_Seats <= 0)
            {
                cout << "\tSORRY!" << endl
                     << "\tNo  Seat Available\t";
            }
            else
            {
                cout << endl
                     << "Total seat available: " << abd.buses[n].Total_Seats;
                cout << endl
                     << "Enter Passenger's Name: ";
                cin >> PessengerName;
                cout << endl
                     << "Number of seats: ";
                cin >> s;
                while ((abd.buses[n].Total_Seats = abd.buses[n].Total_Seats - s) < 0)
                {
                    cout << endl
                         << "Limit Exceed...Please re-enter ";
                    abd.buses[n].Total_Seats = abd.buses[n].Total_Seats + s;
                    cin >> s;
                }

                cout << endl
                     << "Your purchase is completed" << endl;
                cout.setf(ios::right, ios::adjustfield);
                cout.width(30);
                cout << "Bus No: ";
                cout << abd.buses[n].BusNo << endl;
                cout.setf(ios::right, ios::adjustfield);
                cout.width(30);
                cout << "From: ";
                cout << abd.buses[n].from << " to " << abd.buses[n].to << endl;
                cout.setf(ios::right, ios::adjustfield);
                cout.width(30);
                cout << "Departure: ";
                cout << abd.buses[n].Departure_Timing << " O'clock" << endl;
                cout.setf(ios::right, ios::adjustfield);
                cout.width(30);
                cout << "Arrival: ";
                cout << abd.buses[n].Arrival_Timing << " O'clock" << endl;
                cout.setf(ios::right, ios::adjustfield);
                cout.width(30);
                cout << "Total seat: ";
                cout << s << endl;
                Total_Fare = 30 * s;
                Total_Fare = Total_Fare + (Total_Fare * .12);
                TotalSale = TotalSale + Total_Fare;
                cout.setf(ios::right, ios::adjustfield);
                cout.width(30);
                cout << "Total Total_Fare(with 12%vat): ";

                cout.setf(ios::showpoint);
                cout.precision(3);
                cout.setf(ios::fixed, ios::floatfield);
                cout.width(8);
                cout << Total_Fare << endl;

                cout.setf(ios::right, ios::adjustfield);
                cout.width(30);
                cout << "Thank You!!!" << endl
                     << endl;
            }
        }
    }
    system("PAUSE");
    system("CLS");
}

int main()
{
    int w, g = 1;
    ifstream infile;
    infile.open("AllBusDetails.dat", ios::binary | ios::in);
    infile.read((char*)&abd, sizeof(allBusDetails));
    infile.close();
    while (g)
    {
        vline('-');
        cout << "\t\t\t\tBus Ticketing System\n";
        vline('-');
        cout << endl;
        vline('*');
        cout << "\t\t\t 1 :: Bus_Registration\n\t\t\t 2 :: List Available Bus\n\t\t\t 3 => Book Tickets\n\t\t\t 4 => Exit\n";
        vline('*');
        cout << "\n\n\t\t Enter your choice: ";
        cin >> w;
        switch (w)
        {
        case 1:
            abd.buses[abd.count].Bus_Registration();

            break;
        case 2:
            abd.buses[abd.count].show();
            break;
        case 3:
            abd.buses[abd.count].book();

            break;
        case 4:
        {
            g = 0;

            cout << endl
                 << "Successfully Logged out from the Application. Visit Again!" << endl
                 << "Total Sales:" << TotalSale << endl;
            break;
        }
        }
    }
    ofstream outfile;
    outfile.open("AllBusDetails.dat", ios::binary|ios::out);
    outfile.write((char*)&abd, sizeof(allBusDetails));
    outfile.close();
    return 0;
}


