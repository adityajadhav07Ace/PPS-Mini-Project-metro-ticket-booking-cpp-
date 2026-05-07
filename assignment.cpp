#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Constant for number of stations
    const int NUM_STATIONS = 5;

    // Array to store station names
    string stations[NUM_STATIONS] = {
        "PCMC",
        "Sant Tukaram Nagar",
        "Nashik Phata",
        "Shivajinagar",
        "Civil Court"
    };

    // 2D array to store fare between stations
    int fare[NUM_STATIONS][NUM_STATIONS] = {
        {0,  10, 20, 30, 40},
        {10,  0, 10, 20, 30},
        {20, 10,  0, 10, 20},
        {30, 20, 10,  0, 10},
        {40, 30, 20, 10,  0}
    };

    // Variable declarations
    int source, destination;
    int totalFare;
    int ticketCount = 0;   // Ticket counter for mini project completeness

    char again;
    string passengerName;

    // Loop for multiple ticket bookings
    do
    {
        cout << "\n========== Pune Metro Ticketing System ==========\n";

        // Display available stations
        cout << "\nAvailable Stations:\n";
        for (int i = 0; i < NUM_STATIONS; i++)
        {
            cout << i + 1 << ". " << stations[i] << endl;
        }

        // Input source station
        cout << "\nEnter Source Station Number: ";
        cin >> source;

        // Input destination station
        cout << "Enter Destination Station Number: ";
        cin >> destination;

        // Validate station numbers
        if (source < 1 || source > NUM_STATIONS || destination < 1 || destination > NUM_STATIONS)
        {
            cout << "\nInvalid Station Number! Please enter between 1 and "
                 << NUM_STATIONS << ".\n";
        }

        // Check same source and destination
        else if (source == destination)
        {
            cout << "\nSource and Destination cannot be the same!\n";
        }

        else
        {
            // FIX: cin.ignore() placed HERE — right before getline()
            // This clears the leftover '\n' from the last cin >> destination
            cin.ignore(1000, '\n');

            // Input passenger name
            cout << "Enter Passenger Name: ";
            getline(cin, passengerName);

            // Calculate base fare
            totalFare = fare[source - 1][destination - 1];

            // Student discount check (declared inside loop — correct scope)
            char student;
            cout << "Are you a Student? (y/n): ";
            cin >> student;

            if (student == 'y' || student == 'Y')
            {
                totalFare = totalFare - (totalFare * 20 / 100);
                cout << "\n20% Student Discount Applied!\n";
            }
            else
            {
                cout << "\nNo Discount Applied.\n";
            }

            // Increment ticket counter
            ticketCount++;

            // Print ticket
            cout << "\n====================================";
            cout << "\n         PUNE METRO TICKET         ";
            cout << "\n====================================";
            cout << "\nTicket No.     : " << ticketCount;
            cout << "\nPassenger Name : " << passengerName;
            cout << "\nSource         : " << stations[source - 1];
            cout << "\nDestination    : " << stations[destination - 1];
            cout << "\nTotal Fare     : Rs. " << totalFare;
            cout << "\n====================================";
            cout << "\n    Ticket Booked Successfully!    ";
            cout << "\n====================================\n";
        }

        // Ask for another booking
        cout << "\nDo you want to book another ticket? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    // Summary and exit
    cout << "\n====================================";
    cout << "\n  Total Tickets Booked: " << ticketCount;
    cout << "\n  Thank You for Using Pune Metro!  ";
    cout << "\n====================================\n";

    return 0;
}