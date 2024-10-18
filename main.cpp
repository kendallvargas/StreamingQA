#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>
#include <algorithm>

using namespace std;

bool isNumber(string str)
{
    for (char c : str)
    {
        if (!isdigit(c)) return false;
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

int main()
{

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    setlocale(LC_ALL,"Spanish");10 = 0, in11to40 = 0, in51to100 = 0, above100 = 0;
    float ivaAmount = 0.0, totalToPay = 0.0, totalToPayWithIVA = 0.0, total = 0.0, total1 = 0.0, total2 = 0.0, total3 = 0.0;
    string iva, returnToMenu, fullName;
    bool condition;


    int clientID = 0, menu = 0, totalWatchedHoursCalc = 0, totalStreamingConsumption = 0, totalWatchedHours = 0, fixedFee = 0, contentProtection = 0, first
    do
    {

        cout << "Welcome!" << endl;
        cout << "" << endl;

        cout << "1. Enter streaming usage data for the month" << endl;

        cout << "2. Generate the monthly bill for streaming service" << endl;

        cout << "3. Exit the Program" << endl;

        cin >> menu;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (menu)
        {
        case 1:
        {
            clearScreen();
            cout << "              Data entry in the system              " << endl;

            string clientID_string;
            string meter_string;

            // Client ID number provided during service purchase
            cout << "Enter the customer ID number (must be 9 digits, example: 123456789): " << endl;
            cin >> clientID;

            clientID_string = to_string(clientID);

            while (clientID_string.length() != 9 || !isNumber(clientID_string))
            {
                cout << "Invalid ID number, please try again!" << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Prompt for input again
                cout << "Re-enter the customer ID number (9 digits): " << endl;
                cin >> clientID;

                clientID_string = to_string(clientID);
            }

            // SERVICE OWNER'S FULL NAME
            cout << "Enter the service owner's full name: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, fullName);

            // Number of hours watched
            cout << "Enter the number of hours watched during the month: ";
            cin >> totalWatchedHoursCalc;
            while (totalWatchedHoursCalc <= 0 || totalWatchedHoursCalc > 720 || cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Number of hours out of range (0-720)" << endl;
                cout << "Re-enter the number of hours watched: ";
                cin >> totalWatchedHoursCalc;
            }
            int totalWatchedHours = totalWatchedHoursCalc;


            if (totalWatchedHours > 0)
            {
                first10 = min(totalWatchedHours, 10);
                total += first10 * 2;
                totalWatchedHours -= first10;
            }

            if (totalWatchedHours > 0)
            {
                in11to40 = min(totalWatchedHours, 40);
                total1 += (in11to40 * 2) * 1.10;
                totalWatchedHours -= in11to40;
            }

            if (totalWatchedHours > 0)
            {
                in51to100 = min(totalWatchedHours, 50);
                total2 += (in51to100 * 2) * 1.20;
                totalWatchedHours -= in51to100;
            }

            if (totalWatchedHours > 0)
            {
                above100 = min(totalWatchedHours, 670);
                total3 += (above100 * 2) * 1.30;
            }

            // Calculate the total for all additional hours consumed
            totalStreamingConsumption += total + total1 + total2 + total3;
            cout << "Consumption: " << totalStreamingConsumption << "$"<< endl;

            while (true)
            {
                cout << "Are you exempt from IVA (taxes)? (Y/N): ";
                cin >> iva;

                if (iva == "Y" || iva == "y")
                {
                    break;
                }
                else if (iva == "N" || iva == "n")
                {
                    break;
                }
            }
            condition = true;

            while (true)
            {
                cout << "Do you want to return to the main menu? (Y/N): ";
                cin >> returnToMenu;

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
            break;

        }

        case 2:
        {

            if (condition == true)
            {
                clearScreen();
                fixedFee = 10; // Fixed subscription fee
                contentProtection = 5; // Content protection charge

                totalToPay = fixedFee + contentProtection + totalStreamingConsumption;

                if (iva == "N" || iva == "n")
                {
                    totalToPayWithIVA = totalToPay * 1.13;
                    ivaAmount = totalToPay * 0.13;
                    totalToPay += totalToPayWithIVA;
                }
                else if (iva == "Y" || iva == "y")
                {
                    ivaAmount = 0;
                    totalToPayWithIVA = totalToPay + ivaAmount;
                }

                // Invoice presentation
                cout << "              Streaming Consumption Invoice              " << endl;
                cout << "Client ID:                    " << clientID << endl;
                cout << "Client Name:                  " << fullName << endl;
                cout << "Hours watched this month:     " << totalWatchedHoursCalc << endl;
                cout << " " << endl;
                cout << "              Invoice Details              " << endl;
                cout << "Fixed subscription fee:       " << "$"<< fixedFee << endl;
                cout << "Content protection:           " << "$"<< contentProtection << endl;
                cout << "Additional consumption:       " << "$"<< totalStreamingConsumption << endl;
                cout << "Taxes:                        " << "$"<< ivaAmount << endl;
                cout << "TOTAL to pay in dollars:      " << "$"<< totalToPayWithIVA << endl;
                cout << " " << endl;
                while (true)
                {
                    cout << "Do you want to return to the main menu? (Y/N): ";
                    cin >> returnToMenu;

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
                continue;
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
