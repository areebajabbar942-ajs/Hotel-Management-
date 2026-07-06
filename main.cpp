#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>   
using namespace std;

int main() {
	int choice;
	string add;
	bool addRoom;

	do {
		cout << "============================================" << endl;
		cout << "        WELCOME TO HOTEL MANAGEMENT         " << endl;
		cout << "============================================" << endl;
		cout << "1. Add Rooms" << endl;
		cout << "2. View Rooms" << endl;
		cout << "3. Search Rooms" << endl;
		cout << "4. Make Booking" << endl;
		cout << "5. View Bookings" << endl;
		cout << "6. Cancel Booking" << endl;
		cout << "7. Add Customer" << endl;
		cout << "8. View Customers" << endl;
		cout << "9. Search customer" << endl;
		cout << "10. Exit" << endl;
		cout << "--------------------------------------------" << endl;

		cout << "Enter choice (1-10): ";
		bool validChoice = false;
		do {
			cin >> choice;
			if (cin.fail()) {
				cout << "Invalid input! choice must be numeric: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else validChoice = true;
		} while (!validChoice);


		if (choice == 1) {
			while (add != "n") {
				WriteFor_Rooms();
				bool validType = false;
				cout << "do you want to add more rooms? (Y/N)";
				do {
					cin >> add;
					for (int i = 0; i < add.length(); i++)
						add[i] = tolower(add[i]);

					if (add == "y" || add == "n")
						validType = true;
					else
						cout << "Invalid input! Enter Y or N only: ";

				} while (!validType);
			}
			cout << "rooms added successfully" << endl;
		}
		else if (choice == 2) {
			ReadFrom_Rooms();

		}
		else if (choice == 3) {
			search_rooms();
		}
		else if (choice == 4) {
			MakeBooking();
		}
		else if (choice == 5) {
			viewbookings();
		}
		else if (choice == 6) {
			cancel_booking();
		}
		else if (choice == 7) {
			WriteFor_Customers();
		}
		else if (choice == 8) {
			ReadFrom_Customers();
		}
		else if (choice == 9) {
			Search_Customer();
		}
		else if (choice == 10) {
			cout << "Thankyou for using the Hotel Management System. Exiting now....." << endl;
		}

		if (choice < 1 || choice>10) {
			cout << "invalid menu choice: " << endl;
		}

	} while (choice != 10);

	return 0;
}
