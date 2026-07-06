struct customer
{
	int custID;
	string name;
	string passport;

	int readCustID;
	string readName;
	string readPassport;
};
void WriteFor_Customers()
{
	customer C;

	ofstream outFile("Customers.txt", ios::app);

	if (outFile.is_open())
	{
		cout << "please enter a unique Customer ID (numeric): ";
		bool valid = false;
		do {
			cin >> C.custID;
			if (cin.fail()) {
				cout << "Invalid input! Customer ID must be numeric: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else valid = true;
		} while (!valid);


		bool exists = false;
		ifstream checkFile("Customers.txt");
		string line;

		while (!checkFile.eof())
		{
			string line;
			getline(checkFile, line);
			if (line.empty()) continue;
			int pos = line.find('|');
			int id = stoi(line.substr(0, pos));

			if (id == C.custID)
			{
				exists = true;
				break;
			}
		}
		checkFile.close();

		if (exists)
		{
			cout << "Customer ID already exists. Please try again." << endl;
			return;
		}


		cin.ignore();
		cout << "Enter Customer Name: ";
		bool validName = false;
		do {
			getline(cin, C.name);
			validName = true;

			for (char c : C.name) {
				if (isdigit(c)) {
					validName = false;
					break;
				}
			}

			if (!validName || C.name.empty())
				cout << "Invalid input! Name should contain letters only: ";

		} while (!validName);


		cout << "Enter Passport Number: ";
		cin >> C.passport;

		outFile << C.custID << '|' << C.name << '|' << C.passport << endl;

		outFile.close();
		cout << "Customer added successfully." << endl;
	}
	else
	{
		cout << "Error: could not open Customers file for writing." << endl;
	}
}

void ReadFrom_Customers()
{
	customer C;
	ifstream inFile("Customers.txt", ios::in);

	if (inFile.is_open())
	{
		cout << "--- All Customers List ---" << endl;
		while (!inFile.eof())
		{
			string line;
			getline(inFile, line);
			if (line.empty()) continue;

			int pos1 = line.find('|');
			int pos2 = line.find('|', pos1 + 1);

			C.readCustID = stoi(line.substr(0, pos1));
			C.readName = line.substr(pos1 + 1, (pos2 - pos1) - 1);
			C.readPassport = line.substr(pos2 + 1);

			cout << "Customer No: " << C.readCustID << ", Name: " << C.readName << ", Passport: " << C.readPassport << endl;
		}
		inFile.close();
	}
	else
	{
		cout << "Error! Could not open customers file for reading." << endl;
	}
}

void Search_Customer()
{
	customer C;
	int searchID;
	bool found = false;

	cout << "Enter Customer ID to Search: ";
	cin >> searchID;

	ifstream inFile("Customers.txt", ios::in);

	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			string line;
			getline(inFile, line);
			if (line.empty()) continue;

			int pos1 = line.find('|');
			int pos2 = line.find('|', pos1 + 1);

			C.readCustID = stoi(line.substr(0, pos1));
			C.readName = line.substr(pos1 + 1, (pos2 - pos1) - 1);
			C.readPassport = line.substr(pos2 + 1);

			if (C.readCustID == searchID)
			{
				cout << "--- Customer Found ---" << endl;
				cout << "Customer ID: " << C.readCustID << endl;
				cout << "Name       : " << C.readName << endl;
				cout << "Passport   : " << C.readPassport << endl;
				found = true;
				break;
			}
		}
		inFile.close();

		if (!found)
		{
			cout << "No Customer found with " << searchID << endl;
		}
	}
	else
	{
		cout << "Error: Could not open Customers file for search." << endl;
	}
}
