#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <limits>
#include <regex>

using namespace std;

bool isNumber(string str);
void clearScreen();
int RandomNumber();
void Menu();
void DataEntry();
void excemptIva();
void returnMenu();
void calculation();
void wholeCalculation();
void generateInvoice();
bool isValidName(const string &name);

// Structure used for the invoice Creation and access the data
struct InvoiceData
{
    float totalToPayWithIVA;
    float ivaAmount;
    int fixedFee;
    int contentProtection;
    int totalStreamingConsumption;
} invoice;

// Structure used to store and manage the data from option 1
struct informationCustomer
{
    string fullName;
    string invoice;
    string clientID;
    string totalWatchedHoursCalc;
    int totalWatchedHours;
} info;

string ivaYesNo;
int menu;
string menuInput;

int main()
{

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    setlocale(LC_ALL, "Spanish");
    bool condition = false;

    do
    {

        Menu();
        switch (menu)
        {
        case 1:
        {
            DataEntry();
            excemptIva();
            condition = true;
            returnMenu();

            break;
        }

        case 2:
        {

            if (condition == true)
            {
                calculation();
            }
            else
            {
                cout << "You must enter the information first" << endl;
                break;
            }

            break;
        }

        case 3:
        {
            clearScreen();
            cout << "Exiting the system, see you soon!";
            break;
        }
        default:
            cout << "Invalid option." << endl;
        }

    } while (menu != 3 || cin.fail());

    return 0;
}

bool isNumber(string str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear") // Linux or Mac
#endif
}

int RandomNumber()
{
    // Providing a seed value
    srand((unsigned)time(NULL));

    // Get a random number
    int random = rand();

    return random;
}

void Menu()
{

    cout << "Welcome!" << endl;
    cout << "" << endl;

    cout << "1. Enter streaming usage data for the month" << endl;

    cout << "2. Generate the monthly bill for streaming service" << endl;

    cout << "3. Exit the Program" << endl;

    cin >> menuInput;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (menuInput.length() != 1)
    {
        cout << "Only 1 character is allowed! Try again: ";
        getline(cin, menuInput);
    }
    menu = stoi(menuInput);

}

void DataEntry()
{

    clearScreen();
    cout << "              Data entry in the system              " << endl;

    // Client ID number
    cout << "Enter the customer ID number (must be 9 digits, example: 123456789): " << endl;
    cin >> info.clientID;

    while (info.clientID.length() != 9 || !isNumber(info.clientID))
    {
        cout << "Invalid ID number, please try again!" << endl;

        // Prompt for input again in case it fails
        cout << "Re-enter the customer ID number (9 digits): " << endl;
        cin >> info.clientID;
    }

    // SERVICE OWNER'S FULL NAME
    cout << "Enter the service owner's full name: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, info.fullName);
    while (!isValidName(info.fullName))
    {
        cout << "The name is invalid, try again. \n";
        cout << "Insert the owner's name: ";
        getline(cin, info.fullName);
    }

    // Invoice number
    cout << "Insert the invoice number of your streaming service(6 digits): " << endl;
    cin >> info.invoice;

    while (info.invoice.length() != 6 || !isNumber(info.invoice))
    {
        cout << "The invoice is invalid, try again (Example: 123456)!" << endl;

        cout << "Insert the invoice number (6 digits): " << endl;
        cin >> info.invoice;
    }

    // Number of hours watched
    cout << "Enter the number of hours watched during the month: ";
    cin >> info.totalWatchedHoursCalc;

    // Validate the input
    while (!isNumber(info.totalWatchedHoursCalc))
    {
        cout << "Invalid input. Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Re-enter the number of hours watched: ";
        cin >> info.totalWatchedHoursCalc;
    }

    // Convert to integer after validation
    int totalHours;
    totalHours = stoi(info.totalWatchedHoursCalc);

    // Validation based on the limits
    while (totalHours <= 0 || totalHours > 720)
    {
        cout << "Number of hours out of range (0-720)" << endl;
        cout << "Re-enter the number of hours watched: ";
        cin >> info.totalWatchedHoursCalc;

        // Validate the input again
        while (!isNumber(info.totalWatchedHoursCalc))
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Re-enter the number of hours watched: ";
            cin >> info.totalWatchedHoursCalc;
        }
    }

    // Store the valid total hours again
    info.totalWatchedHours = totalHours;
}

/* Fixed prices are presented here and the sum of all of them with the final price of Streaming Consumption.
Additionally, the tax will be applied based on the user's response when entering data.*/
void wholeCalculation()
{
    float totalToPay = 0;

    clearScreen();
    invoice.fixedFee = 10;         // Fixed subscription fee
    invoice.contentProtection = 5; // Content protection charge

    totalToPay = invoice.fixedFee + invoice.contentProtection + invoice.totalStreamingConsumption;

    if (ivaYesNo == "N" || ivaYesNo == "n")
    {
        invoice.totalToPayWithIVA = totalToPay * 1.13;
        invoice.ivaAmount = totalToPay * 0.13;
    }
    else if (ivaYesNo == "Y" || ivaYesNo == "y")
    {
        invoice.ivaAmount = 0;
        invoice.totalToPayWithIVA = totalToPay + invoice.ivaAmount;
    }

    // generating the receipt once all the information has been filled out
    generateInvoice();

    returnMenu();
}

// This is where the core calculation happens, with the additional costs based on the watched hours
void calculation()
{
    int first10 = 0, in11to40 = 0, in51to100 = 0, above100 = 0, total = 0, total1 = 0, total2 = 0, total3 = 0;
    if (info.totalWatchedHours > 0)
    {
        first10 = min(info.totalWatchedHours, 10);
        total += first10 * 2;
        info.totalWatchedHours -= first10;
    }

    if (info.totalWatchedHours > 0)
    {
        in11to40 = min(info.totalWatchedHours, 40);
        total1 += (in11to40 * 2) * 1.10;
        info.totalWatchedHours -= in11to40;
    }

    if (info.totalWatchedHours > 0)
    {
        in51to100 = min(info.totalWatchedHours, 50);
        total2 += (in51to100 * 2) * 1.20;
        info.totalWatchedHours -= in51to100;
    }

    if (info.totalWatchedHours > 0)
    {
        above100 = min(info.totalWatchedHours, 670);
        total3 += (above100 * 2) * 1.30;
    }

    // Calculate the total for all additional hours consumed
    invoice.totalStreamingConsumption += total + total1 + total2 + total3;

    // calling whole calculation to complete the process
    wholeCalculation();
}

// This is used in the option 2, where the information is presented to the user based on what was inserted on option 1.
void generateInvoice()
{
    // calling the function with the random code
    int numberRandom = RandomNumber();
    // Invoice presentation
    cout << "              Streaming Consumption Invoice              " << endl;
    cout << "Client ID:                    " << info.clientID << endl;
    cout << "Client Name:                  " << info.fullName << endl;
    cout << "Client's invoice number:      " << info.invoice << endl;
    cout << "Hours watched this month:     " << info.totalWatchedHoursCalc << endl;
    cout << " " << endl;
    cout << "              Invoice Details              " << endl;
    cout << "Fixed subscription fee:       " << "$" << invoice.fixedFee << endl;
    cout << "Content protection:           " << "$" << invoice.contentProtection << endl;
    cout << "Additional consumption:       " << "$" << invoice.totalStreamingConsumption << endl;
    cout << "Taxes:                        " << "$" << invoice.ivaAmount << endl;
    cout << "TOTAL to pay in dollars:      " << "$" << invoice.totalToPayWithIVA << endl;
    cout << "Code to complete payment:     " << numberRandom << endl;
    cout << " " << endl;
}

// Menu for the validation if the user is excempt from IVA or not
void excemptIva()
{

    while (true)
    {
        cout << "Are you exempt from IVA (taxes)? (Y/N): ";
        cin >> ivaYesNo;
        if (ivaYesNo.length() == 1)
        {

            if (ivaYesNo == "Y" || ivaYesNo == "y")
            {
                break;
            }
            else if (ivaYesNo == "N" || ivaYesNo == "n")
            {
                break;
            }
        }
        else
        {
            cout << "Response cannot be longer than one character!\n";
            continue;
        }
    }
}

// Return to the menu function, separating it from the
void returnMenu()
{
    string returnToMenu;

    while (true)
    {
        cout << "Do you want to return to the main menu? (Y/N): ";
        cin >> returnToMenu;
        if (returnToMenu.length() == 1)
        {

            if (returnToMenu == "N" || returnToMenu == "n")
            {
                continue;
            }
            else if (returnToMenu == "Y" || returnToMenu == "y")
            {
                clearScreen();
                break;
            }
        }
        else
        {
            cout << "Response cannot be longer than one character!\n";
            continue;
        }
    }
}

// Function with regex to validate that a string only includes letter from A to Z and spaces
bool isValidName(const string &name)
{
    // including special code for the characters: Áá Éé Íí Óó Úú Ññ Üü
    regex nameRegex("^(?=.*[a-zA-Z])[a-zA-Z\\s\\u00f1\\u00d1\\u00c1\\u00c9\\u00cd\\u00d3\\u00da\\u00e1\\u00e9\\u00ed\\u00f3\\u00fa\\u00fc\\u00dc]+$");
    return regex_match(name, nameRegex);
}
