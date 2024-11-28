#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

// Set console code page to UTF-8
void setConsoleCodePage()
{
    system("chcp 65001 > nul");
}

// temporary 2d array to store data
string freelancerLogin[1][5];
string clientLogin[1][3];

// color change function
void setColor(int colorCode)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

// display the admin menu upon admin login
void adminMenu()
{
    setColor(2);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl
         << endl;
    cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
    cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
    cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
    cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
    cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
    cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
         << endl;
    cout << "-----";
    setColor(8);
    cout << " ADMIN : MENU ";
    setColor(2);
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl

         << endl;
    setColor(15);
    cout << right;
    cout << setw(125) << "1. Freelancers Statistics \n"
         << setw(121) << " 2. Clients Statistics \n"
         << setw(124) << " 3. Update Privacy Policy \n"
         << setw(128) << "4. Remove Freelancer Account \n"
         << setw(124) << " 5. Remove Client Account \n"
         << setw(123) << " 6. See Customer Support \n"
         << setw(108) << "7. Niches\n"
         << setw(108) << "0. Log Out" << endl;
    cout.unsetf(ios::right);
}

// display the freelancer menu upon freelancer login
void freelancerMenu()
{
    setColor(2);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl
         << endl;
    cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
    cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
    cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
    cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
    cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
    cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
         << endl;
    cout << "-----";
    setColor(8);
    cout << " FREELANCER : MENU ";
    setColor(2);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl
         << endl;

    setColor(15);
    cout << right;
    cout << setw(123) << "1. Available Jobs\n"
         << setw(120) << "2. Submit Work\n"
         << setw(126) << " 3. Rating & Earnings\n"
         << setw(125) << "4. Customer Support\n"
         << setw(123) << "5. Privacy Policy\n"
         << setw(115) << "0. Log Out" << endl;
    cout.unsetf(ios::right);
}

// display the client menu upon client login
void clientMenu()
{
    setColor(2);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl
         << endl;
    cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
    cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
    cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
    cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
    cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
    cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
         << endl;
    cout << "-----";
    setColor(8);
    cout << " CLIENT : LOGIN IN ";
    setColor(2);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl;
    setColor(15);
    cout << right;
    cout << setw(119) << "1. Post a Job\n"
         << setw(123) << "2. Pending Rating\n"
         << setw(123) << "3. Privacy Policy\n"
         << setw(125) << "4. Customer Support\n"
         << setw(115) << "0. Log Out" << endl
         << endl;
    cout.unsetf(ios::right);
}

///////////////////////////////// ADMIN FUNCTION //////////////////////////////

// show all the detail of freelancers
void freelancerStatistic(int Findex, string freelancerUserName[], string freelancerPassword[], string freelancerNiche[], string freelancerRating[], int freelancerEarning[])
{
    system("cls");
    cout << setw(120) << " Freelancer Statistics " << endl;
    cout << left;
    setColor(2);

    // display all the freelancers in tabular form
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(8);
    cout << setw(25) << "Number " << setw(45) << "Freelancer Username " << setw(45) << "Freelancer Password " << setw(40) << "Niche" << setw(35) << "Freelancer Ratings " << setw(30) << "Earnings" << endl;
    setColor(2);
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(15);

    // if there is no freelancer then prompt the message
    if (freelancerUserName[0] == " " && freelancerPassword[0] == " ")
    {
        cout << "No User(s) Registered Yet! " << endl
             << endl
             << endl
             << endl;
    }
    for (int i = 0; i < Findex; i++)
    {
        // if freelancer found display all the details of the freelancer
        if (freelancerUserName[i] != " " && freelancerPassword[i] != " ")
        {
            cout << setw(25) << i + 1 << setw(45) << freelancerUserName[i] << setw(45) << freelancerPassword[i] << setw(40) << freelancerNiche[i] << setw(35) << fixed << setprecision(1) << freelancerRating[i] << setw(30) << freelancerEarning[i] << endl
                 << endl;
        }
    }
    cout.unsetf(ios::left);
    cout << endl
         << endl;
}

// show all the detail of clients
void clientStatistic(int Cindex, string clientUserName[], string clientPassword[], string clientNiche[1000][5], int clientSpend[])
{
    system("cls");
    cout << setw(120) << " Client Statistics " << endl;
    cout << left;
    setColor(2);

    // display all the clients in tabular form
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(8);
    cout << setw(40) << "Number " << setw(60) << "Client Username " << setw(60) << "Client Password " << setw(60) << "Money Spent" << endl;
    setColor(2);
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(15);

    // if there is no client then prompt the message
    if (clientUserName[0] == "empty" && clientPassword[0] == "empty")
    {
        cout << "No User(s) Registered Yet! " << endl
             << endl
             << endl
             << endl;
    }
    for (int i = 0; i < Cindex; i++)
    {
        // if client found display all the details of the clients
        if (clientUserName[i] != "empty" && clientPassword[i] != "empty")
        {
            cout << setw(40) << i + 1 << setw(60) << clientUserName[i] << setw(60) << clientPassword[i] << setw(60) << clientSpend[i];

            cout << endl
                 << endl;
        }
    }
    cout << endl
         << endl;
}

// show all the detail of customer policy
void customerPolicy(string headingCustomerPolicy[], string dataCustomerPolicy[])
{
    system("cls");
    // ANSI escape code for bold text
    const string bold = "\033[1m";
    const string reset = "\033[0m"; // Reset text style
    setColor(8);

    cout << setw(100) << bold << "PRIVACY POLICY FOR FREELANCING WEBSITE\n"
         << reset;
    setColor(2);
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
         << endl;
    setColor(3);
    // 1. Data Collection
    cout << bold << "====== 1. DATA COLLECTION ======" << reset << "\n";
    setColor(15);
    cout << "We collect personal information such as name, email, payment details, and project preferences to facilitate communication and transactions between freelancers and clients.\n\n";
    setColor(3);
    // 2. Usage of Information
    cout << bold << "====== 2. USAGE OF INFORMATION ======" << reset << "\n";
    setColor(15);
    cout << "The collected data is used to match clients with suitable freelancers, process payments, and provide personalized user experiences.\n\n";
    setColor(3);
    // 3. Data Sharing
    cout << bold << "====== 3. DATA SHARING ======" << reset << "\n";
    setColor(15);
    cout << "Personal information is only shared between clients and freelancers as necessary for project fulfillment. We do not sell or share your data with third parties without your consent.\n\n";
    setColor(3);
    // 4. Communication Privacy
    cout << bold << "====== 4. COMMUNICATION PRIVACY ======" << reset << "\n";
    setColor(15);
    cout << "All communications between freelancers and clients on the platform are encrypted and securely stored to protect sensitive information.\n\n";
    setColor(3);
    // 5. Payment Security
    cout << bold << "====== 5. PAYMENT SECURITY ======" << reset << "\n";
    setColor(15);
    cout << "Payment details are processed through secure, third-party payment gateways. We do not store full credit card or bank account details on our servers.\n\n";
    setColor(3);
    // 6. Profile Visibility
    cout << bold << "====== 6. PROFILE VISIBILITY ======" << reset << "\n";
    setColor(15);
    cout << "Freelancer profiles, including their skills and portfolios, are visible to registered clients. Contact information remains private unless shared explicitly by the user.\n\n";
    setColor(3);
    // 7. Confidentiality of Project Details
    cout << bold << "====== 7. CONFIDENTIALITY OF PROJECT DETAILS ======" << reset << "\n";
    setColor(15);
    cout << "Any project details, including files and communication, are confidential and accessible only to the involved freelancer and client.\n\n";
    setColor(3);
    // 8. Account Security
    cout << bold << "====== 8. ACCOUNT SECURITY ======" << reset << "\n";
    setColor(15);
    cout << "Users are responsible for maintaining the confidentiality of their account credentials. We recommend using strong passwords and enabling two-factor authentication (2FA).\n\n";
    setColor(3);
    // 9. Data Retention
    cout << bold << "====== 9. DATA RETENTION ======" << reset << "\n";
    setColor(15);
    cout << "We retain user data only as long as necessary for providing services and complying with legal obligations. Users can request data deletion at any time.\n\n";
    setColor(3);
    // 10. Policy Updates
    cout << bold << "====== 10. POLICY UPDATES ======" << reset << "\n";
    setColor(15);
    cout << "We may update this privacy policy periodically. Users will be notified of significant changes, and continued use of the platform constitutes acceptance of the updated policy.\n\n";

    for (int i = 10; i < 1000; i++)
    {
        // search for more customer policy if added by the admin
        if (headingCustomerPolicy[i] != " ")
        {
            setColor(3);
            cout << bold << "====== " << i + 1 << ". " << headingCustomerPolicy[i] << " ======" << reset << "\n";
            setColor(15);
            cout << dataCustomerPolicy[i] << endl
                 << endl;
        }
    }
}

// allow admin to add more policy
int customerAddPolicy(string headingCustomerPolicy[], string dataCustomerPolicy[])
{
    system("cls");
    char option = 'c';
    customerPolicy(headingCustomerPolicy, dataCustomerPolicy);
    setColor(2);
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(15);

    // allow admin to add new privacy policy in the app
    cout << "Do you want to add more Privacy Policy (Y/N): ";
    cin.clear();
    cin.ignore(100, '\n');
    cin.get(option);

    while (option != 'Y' && option != 'y' && option != 'n' && option != 'N')
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid Data Entered! \nDo you want to add more Privacy Policy (Y/N): ";
        cin.get(option);
    }

    if (option == 'n' || option == 'N')
    {
        system("cls");
        return 1;
    }
    if (option == 'Y' || option == 'y')
    {
        for (int i = 10; i < 1000; i++)
        {
            if (headingCustomerPolicy[i] == " ")
            {
                cin.clear();
                cin.ignore(100, '\n');

                // stores the heading in the free space of privacy policy
                cout << "Enter Heading: ";
                getline(cin, headingCustomerPolicy[i]);
                cin.clear();

                // stores the details of the heading in the free space of privacy policy
                cout << "Enter Details: ";
                getline(cin, dataCustomerPolicy[i]);

                setColor(3);
                cout << "Privacy Policy Updated! " << endl;
                setColor(15);
                break;
            }

            // if max policy reached then display the message
            else if (headingCustomerPolicy[999] != " ")
            {
                cout << "Maximum Privacy Policies Entered! ";
                break;
            }
        }
    }
}

// allow admin to delete freelancer account
int removeFreelancerAcc(int &Findex, string user, string freelancerUserName[], string freelancerPassword[], string freelancerNiche[], string freelancerRating[], int freelancerEarning[], string freelancerCustomerSupport[1000][2])
{
    int result = -1;
    if (user == "0")
    {
        system("cls");
        result = 2;
        return result;
    }

    // Findex increases when new freelancer is registered and decreases when freelancer is removed
    for (int i = 0; i < Findex; i++)
    {
        // search if the match found with the search name in the files
        if (freelancerUserName[i] == user)
        {
            // if name is found deletes its data
            freelancerUserName[i] = " ";
            freelancerPassword[i] = " ";
            freelancerRating[i] = "N/A";
            freelancerEarning[i] = 0;
            freelancerNiche[i] = " ";

            for (int n = 0; n < 2; n++)
            {
                freelancerCustomerSupport[i][n] = " ";
            }

            result = 1;

            // move all the data of freelancer next to the user removed one space back to maintain in consistent order
            for (int j = i; j < Findex - 1; j++)
            {
                freelancerUserName[j] = freelancerUserName[j + 1];
                freelancerPassword[j] = freelancerPassword[j + 1];
                freelancerRating[j] = freelancerRating[j + 1];
                freelancerEarning[j] = freelancerEarning[j + 1];
                freelancerNiche[j] = freelancerNiche[j + 1];

                for (int n = 0; n < 2; n++)
                {
                    freelancerCustomerSupport[j][n] = freelancerCustomerSupport[j + 1][n];
                }
            }

            break;
        }
    }

    // initialize the last freelancer properly to avoid any unexcepted data
    freelancerUserName[Findex - 1] = " ";
    freelancerPassword[Findex - 1] = " ";
    freelancerRating[Findex - 1] = "N/A";
    freelancerEarning[Findex - 1] = 0;
    freelancerNiche[Findex - 1] = " ";

    for (int n = 0; n < 2; n++)
    {
        freelancerCustomerSupport[Findex - 1][n] = " ";
    }

    // Findex decreases
    Findex--;

    return result;
}

// allow admin to delete client account
int removeClientAcc(int &Cindex, string rating[1000][5][1], string user, string clientUserName[], string clientPassword[], string clientNiche[1000][5], int clientSpend[], string clientJobDescription[1000][5], int ratingCounter[1000][5], int clientPayment[1000][5], string clientCustomerSupport[1000][2])
{
    int result = -1;
    if (user == "0")
    {
        system("cls");
        result = 2;
        return result;
    }

    // Cindex increases when new client is registered and decreases when client is removed
    for (int i = 0; i < Cindex; i++)
    {
        // search if the match found with the search name in the files
        if (clientUserName[i] == user)
        {
            // if name is found deletes its data
            clientUserName[i] = "empty";
            clientPassword[i] = "empty";
            clientSpend[i] = 0;
            for (int k = 0; k < 5; k++)
            {
                clientNiche[i][k] = "empty";
                clientJobDescription[i][k] = "empty";
                rating[i][k][0] = "empty";
                ratingCounter[i][k] = {0};
                clientPayment[i][k] = {0};
            }
            for (int n = 0; n < 2; n++)
            {
                clientCustomerSupport[i][n] = "empty";
            }

            for (int j = i; j < Cindex - 1; j++)
            {
                // move all the data of client next to the user removed one space back to maintain in consistent order
                clientUserName[j] = clientUserName[j + 1];
                clientPassword[j] = clientPassword[j + 1];
                clientSpend[j] = clientSpend[j + 1];
                for (int m = 0; m < 5; m++)
                {
                    clientNiche[j][m] = clientNiche[j + 1][m];
                    clientJobDescription[j][m] = clientJobDescription[j + 1][m];
                    ratingCounter[j][m] = ratingCounter[j + 1][m];
                    clientPayment[j][m] = clientPayment[j + 1][m];
                    rating[j][m][0] = rating[j + 1][m][0];
                }
                for (int n = 0; n < 2; n++)
                {
                    clientCustomerSupport[j][n] = clientCustomerSupport[j + 1][n];
                }
            }

            // delete the last value as all data is moved one step back
            clientUserName[Cindex - 1] = "empty";
            clientPassword[Cindex - 1] = "empty";
            clientSpend[Cindex - 1] = 0;

            for (int k = 0; k < 5; k++)
            {
                clientNiche[Cindex - 1][k] = "empty";
                clientJobDescription[Cindex - 1][k] = "empty";
                ratingCounter[Cindex - 1][k] = 0;
                clientPayment[Cindex - 1][k] = 0;
                rating[Cindex - 1][k][0] = "empty";
            }

            for (int n = 0; n < 2; n++)
            {
                clientCustomerSupport[Cindex - 1][n] = "empty";
            }

            // Cindex decreases
            Cindex--;
            result = 1;
            break;
        }
    }

    return result;
}

// show admin all the queries/suggesstion of freelancers and clients
void customerSupport(string freelancerCustomerSupport[1000][2], string clientCustomerSupport[1000][2])
{
    system("cls");
    const string bold = "\033[1m";
    const string reset = "\033[0m"; // Reset text style
    cout << setw(135) << "CUSTOMER SUPPORT (FREELANCERS) \n"
         << reset;

    setColor(2);
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl;
    setColor(15);

    for (int i = 0; i < 1000; i++)
    {
        // if freelancer Customer support data is not empty then show the customer support message to the admin
        if (freelancerCustomerSupport[i][1] != " ")
        {
            setColor(3);
            cout << bold << "====== " << i + 1 << "." << freelancerCustomerSupport[i][0] << " ======" << reset << "\n";
            setColor(15);
            cout << freelancerCustomerSupport[i][1] << endl;
        }
        else if (freelancerCustomerSupport[0][1] == " ")
        {
            cout << "No freelancer has submitted any Query/Suggesstion." << endl;
            break;
        }
    }
    cout << endl
         << endl
         << endl;
    cout << setw(130) << "CUSTOMER SUPPORT (CLIENT) \n"
         << reset;

    setColor(2);
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl;
    setColor(15);
    for (int i = 0; i < 1000; i++)
    {
        // if client Customer support data is not empty then show the customer support message to the admin
        if (clientCustomerSupport[i][1] != "empty")
        {
            setColor(3);
            cout << bold << "====== " << i + 1 << "." << clientCustomerSupport[i][0] << " ======" << reset << "\n";
            setColor(15);
            cout << clientCustomerSupport[i][1] << endl;
        }
        else if (clientCustomerSupport[0][1] == "empty")
        {
            cout << "No Client has submitted any Query/Suggesstion.";
            break;
        }
    }
    cout << endl
         << endl
         << endl
         << endl;
}

// display all the niches which admin has allowed in the app
void nichesShow(string niches[])
{
    system("cls");
    setColor(3);
    cout << "Available Niches: " << endl;
    setColor(15);

    for (int i = 0; i < 100; i++)
    {
        if (i < 9)
        {
            if (niches[i] != " ")
            {
                cout << "\n\t" << i + 1 << ".   " << niches[i];
            }
        }
        else if (i >= 9)
        {
            if (niches[i] != " ")
            {
                cout << "\n\t" << i + 1 << ".  " << niches[i];
            }
        }
    }
    cout << endl;
    setColor(2);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl;
    setColor(15);
}

// allow admin to add more niches
int adminAddNiches(string niches[])
{
    system("cls");
    char option = 'c';
    nichesShow(niches);
    cout << "Do you want to add more Niches (Y/N): ";
    cin.clear();
    cin.ignore(100, '\n');
    cin.get(option);
    while (option != 'Y' && option != 'y' && option != 'n' && option != 'N')
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid Data Entered! \nDo you want to add more Niches (Y/N): ";
        cin.get(option);
    }
    if (option == 'n' || option == 'N')
    {
        return 1;
    }
    if (option == 'Y' || option == 'y')
    {
        // by default 10 niches are displayed but if the admin want to add more he can add more from here
        for (int i = 10; i < 100; i++)
        {
            if (niches[i] == " ")
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Enter Niche Name: ";
                getline(cin, niches[i]);
                cin.clear();

                cout << "New Niche Added! " << endl;
                break;
            }

            // cannot entertain more than 100 niches
            else if (niches[99] != " ")
            {
                cout << "Maximum Niches Entered! ";
                break;
            }
        }
    }
}

///////////////////////////////// ADMIN FUNCTION END //////////////////////////////

/////////////////////////////////FREELANCER FUNCTION //////////////////////////////

// display the freelancer the jobs which match according to freelancer profession/skill
void availableJob(int Cindex, string freelancerLogin[1][5], string clientUserName[], string clientJobDescription[1000][5], string clientNiche[1000][5], int clientPayment[1000][5])
{
    system("cls");
    const string bold = "\033[1m";
    const string reset = "\033[0m"; // Reset text style
    cout << setw(95) << bold << "Available Job(s) that match with your Niche " << reset << endl;
    setColor(2);
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(8);
    cout << left;
    cout << setw(20) << "Number" << setw(40) << "Client Name" << setw(50) << "Client Niche" << setw(80) << "Client Job Description" << setw(50) << "Price" << endl;
    setColor(2);
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(15);
    int a = 0;
    for (int i = 0; i < Cindex; i++)
    {
        for (int m = 0; m < 5; m++)
        {
            // freelancerLogin second column store the particular niche of that logged in freelancers
            if (freelancerLogin[0][2] == clientNiche[i][m])
            {
                // if client job niches match with the freelancer Logged in niches then it show him the jobs, only the match niches
                cout << setw(20) << a + 1 << setw(40) << clientUserName[i] << setw(50) << clientNiche[i][m] << setw(80) << clientJobDescription[i][m] << setw(50) << clientPayment[i][m] << endl;
                a++;
            }
        }
    }
    cout << endl
         << endl
         << endl
         << endl;
    setColor(2);
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(15);
}

// allow freelancer to select the job from the available one's
bool jobSelection(int Findex, int Cindex, string clientUserName[], string freelancerLogin[1][5], string clientJobDescription[1000][5], string clientNiche[1000][5], int clientPayment[1000][5], string freelancerJobSelected[1000][4], string freelancerUserName[])
{
    system("cls");
    int selectedNo = -1;
    int jobIndex = -1;
    int clientIndex = -1;

    // freelancer select the job by selecting the user number displayed in the table
    availableJob(Cindex, freelancerLogin, clientUserName, clientJobDescription, clientNiche, clientPayment);
    cout << "Select the Job Number of Client from the available ones to Apply on job or press 0 to go back: ";
    cin.clear();
    cin.ignore();

    // get the job number of client from freelancer to apply on job
    cin >> selectedNo;
    if (selectedNo == 0 && cin)
    {
        system("cls");
        // if zero back to main menu
        return false;
    }
    while (!cin)
    {
        setColor(3);
        cout << "Wrong Number Selected!" << endl;
        setColor(15);
        cout << "Select the Job Number of Client from the available ones to Apply on job or press 0 to go back: ";
        cin.clear();
        cin.ignore();

        // get the job number of client from freelancer to apply on job
        cin >> selectedNo;
        if (selectedNo == 0 && cin)
        {
            system("cls");
            // if zero back to main menu
            return false;
        }
    }

    // job counter variable
    int jobCounter = 1;

    // if job found bool variable true
    bool jobfound = false;
    int totalJob = 0;

    // search all the client
    for (int i = 0; i < Cindex; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // if niche match of freelancer and client
            if (freelancerLogin[0][2] == clientNiche[i][j])
            {
                // count total jobs
                totalJob++;
            }
        }
    }
    while (!cin || selectedNo < 0 || selectedNo > totalJob)
    {
        setColor(3);

        // if selected job is less than 0 or more than total  job display an error message
        cout << "Wrong Number Selected!" << endl;
        setColor(15);
        cout << "Select the Job Number of Client from the available ones to Apply on job or press 0 to go back: ";
        cin.clear();
        cin.ignore();

        // get the job number of client from freelancer to apply on job
        cin >> selectedNo;
        if (selectedNo == 0 && cin)
        {
            // if zero back to main menu
            return false;
        }
    }

    for (int i = 0; i < Cindex; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (freelancerLogin[0][2] == clientNiche[i][j])
            {
                // if job counter match with selected number then that job is selected
                if (selectedNo == jobCounter)
                {
                    // job found --> true
                    jobfound = true;

                    // store that client index
                    clientIndex = i;

                    // store that job index of the client
                    jobIndex = j;
                    break;
                }
                jobCounter++;
            }
        }
        if (jobfound == true)
        {
            break;
        }
    }
    for (int i = 0; i < Findex; i++)
    {
        if (freelancerLogin[0][0] == freelancerUserName[i])
        {
            // only one job can be selected by the freelancer
            // first he has to submit the previous job and then he can apply on new one
            if (freelancerJobSelected[i][0] != " ")
            {
                setColor(3);

                // he first have to deliver the work before selecting the new job
                cout << "Only One job can we selected by the freelancer Now! " << endl;
                setColor(15);
                return false;
            }

            // copy that job description in freelancer job selected array
            freelancerJobSelected[i][0] = clientUserName[clientIndex];
            freelancerJobSelected[i][1] = clientJobDescription[clientIndex][jobIndex];
            freelancerJobSelected[i][2] = clientNiche[clientIndex][jobIndex];
            freelancerJobSelected[i][3] = to_string(clientPayment[clientIndex][jobIndex]);

            setColor(3);
            cout << "Job Accepted Successfully!" << endl;
            setColor(15);
            cout << "Deliver the work to the client by submitting in the submit menu." << endl;
            return true;
        }
    }
}

// freelaner customer support section
void customerSupportfreelancer(int Findex, string freelancerLogin[1][5], string freelancerCustomerSupport[1000][2], string freelancerUserName[])
{
    system("cls");
    for (int i = 0; i < Findex; i++)
    {
        if (freelancerLogin[0][0] == freelancerUserName[i])
        {
            // allow freelancer to give any suggestion or query to admin
            freelancerCustomerSupport[i][0] = freelancerLogin[0][0];
            cin.clear();
            cin.ignore();
            cout << "Enter Your Query/Suggestion: ";
            getline(cin, freelancerCustomerSupport[i][1]);
            setColor(3);
            cout << "Query/Suggestion has been successfully sent to Admin." << endl;
            setColor(15);
            break;
        }
    }
}

// freelancer work submit
void freelancerWorkSubmit(int Findex, int Cindex, string freelancerLogin[1][5], string freelancerUserName[], string freelancerJobSelected[1000][4], string clientUserName[], string clientJobDescription[1000][5], string clientNiche[1000][5], int clientPayment[1000][5], int freelancerEarning[], int ratingCounter[1000][5], string rating[1000][5][1])
{
    system("cls");
    // ANSI escape code for bold text
    const string bold = "\033[1m";
    const string reset = "\033[0m"; // Reset text style
    string answer = " ";
    bool flag = false;

    cout << bold << setw(125) << "Submit Job " << reset << endl;
    setColor(2);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(15);
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    for (int i = 0; i < Findex; i++)
    {
        // search the name with the logged in freelancer account name
        if (freelancerLogin[0][0] == freelancerUserName[i])
        {
            cout << left;

            // if job selected display all the job data to submit
            if (freelancerJobSelected[i][0] != " ")
            {
                cout << endl;
                cout << setw(30) << "Client Name: " << freelancerJobSelected[i][0] << endl
                     << endl;
                cout << setw(30) << "Job Description: " << freelancerJobSelected[i][1] << endl
                     << endl;
                cout << setw(30) << "Job Niche: " << freelancerJobSelected[i][2] << endl
                     << endl;
                cout << setw(30) << "Job Price: " << freelancerJobSelected[i][3] << endl
                     << endl
                     << endl;
                cout << "Do you want to submit/(mark completed) this job(Yes/No): ";
                setColor(3);
                cin >> answer;
                setColor(15);
                while (answer != "no" && answer != "No" && answer != "yes" && answer != "Yes")
                {
                    setColor(3);
                    cout << "Select only Yes/No. " << endl;
                    setColor(15);
                    cout << "Do you want to submit/(mark completed) this job(Yes/No): ";
                    setColor(3);
                    cin >> answer;
                    setColor(15);
                }
                if (answer == "No" || answer == "no")
                {
                    flag = false;
                }
                if (answer == "Yes" || answer == "yes")
                {
                    cout << "Are you sure you want to submit this job (this can not undo): ";
                    setColor(3);
                    cin >> answer;
                    setColor(15);
                    while (answer != "no" && answer != "No" && answer != "yes" && answer != "Yes")
                    {
                        setColor(3);
                        cout << "Select only Yes/No. " << endl;
                        setColor(15);
                        cout << "Do you want to submit/(mark completed) this job(Yes/No): ";
                        setColor(3);
                        cin >> answer;
                        setColor(15);
                    }
                    if (answer == "No" || answer == "no")
                    {
                        flag = false;
                    }
                    if (answer == "Yes" || answer == "yes")
                    {
                        setColor(3);

                        cout << "Congratulations!!  Your job has been successfully submitted. Keep up the great work and good luck with your freelancing journey! " << endl;
                        setColor(15);
                        for (int k = 0; k < Cindex; k++)
                        {
                            // search that name of client who posted this job
                            if (freelancerJobSelected[i][0] == clientUserName[k])
                            {
                                for (int l = 0; l < 5; l++)
                                {
                                    // search that job niche
                                    if (freelancerJobSelected[i][2] == clientNiche[k][l])
                                    {
                                        // add earning to freelancer account
                                        // freelancerEarning[i] += clientPayment[k][l];

                                        if (freelancerJobSelected[i][1] == clientJobDescription[k][l])
                                        {
                                            // rating counter of client job increases
                                            ratingCounter[k][l]++;
                                            rating[k][l][0] = freelancerUserName[i];

                                            int amount = 0;
                                            for (int s = 0; s < freelancerJobSelected[i][3].length(); s++)
                                            {
                                                char ch = freelancerJobSelected[i][3][s];
                                                if (ch >= '0' && ch <= '9')
                                                {
                                                    amount = amount * 10 + (ch - '0');
                                                }
                                            }

                                            freelancerEarning[i] += amount;
                                        }
                                    }
                                }
                            }
                        }
                        for (int p = 0; p < 4; p++)
                        {
                            freelancerJobSelected[i][p] = " ";
                        }
                        break;
                    }
                }
                if (flag == false)
                {
                    break;
                }
            }
            cout.unsetf(ios::left);
        }
    }
}

// allow freelancer to widthdraw their money
char widthdrawMoney(int Findex, string freelancerLogin[1][5], string freelancerUserName[], int freelancerEarning[])
{
    char option = 'c';
    for (int i = 0; i < Findex; i++)
    {
        if (freelancerLogin[0][0] == freelancerUserName[i])
        {
            if (freelancerEarning[i] > 0)
            {
                cout << "Do you want to widthdraw this money(Y/N) ?";
                cin >> option;
                if (option == 'y' || option == 'Y' || option == 'n' || option == 'N')
                {
                    return option;
                }
                while (option != 'y' && option != 'Y' && option != 'n' && option != 'N')
                {
                    cin.clear();
                    cin.ignore();
                    setColor(3);
                    cout << "Select only Y/N " << endl;
                    setColor(15);
                    cout << "Do you want to widthdraw this money(Y/N) ?";
                    cin >> option;
                    if (option == 'y' || option == 'Y' || option == 'n' || option == 'N')
                    {
                        return option;
                    }
                }
            }
        }
    }
}

// display the freelancer his total earning
void freelancerEarnings(int Findex, string freelancerLogin[1][5], string freelancerUserName[], int freelancerEarning[], string freelancerRating[])
{
    system("cls");
    char answer;
    for (int i = 0; i < Findex; i++)
    {
        if (freelancerLogin[0][0] == freelancerUserName[i])
        {
            cout << endl;

            cout << "Rating : " << freelancerRating[i] << endl
                 << endl;

            cout << "Total Earnings up till now:";
            setColor(3);
            cout << " $";
            cout << freelancerEarning[i] << endl
                 << endl;
            setColor(15);
            answer = widthdrawMoney(Findex, freelancerLogin, freelancerUserName, freelancerEarning);
            if (answer == 'y' || answer == 'Y')
            {
                setColor(3);
                cout << endl;
                cout << "The amount will be send to your account soon! " << endl;
                setColor(15);
            }
            if (answer == 'n' || answer == 'N')
            {
                break;
            }
        }
    }
    cout << endl
         << endl
         << endl
         << endl;
}

/////////////////////////////////FREELANCER FUNCTION END //////////////////////////////

/////////////////////////////////CLIENT FUNCTION //////////////////////////////

// allow clients to post their jobs
bool postJob(int Cindex, string niches[], string clientLogin[1][3], string clientUserName[], string clientPassword[], string clientNiche[1000][5], string clientJobDescription[1000][5], int clientPayment[1000][5], int clientSpend[], int ratingCounter[1000][5])
{
    system("cls");
    bool flag = false;
    nichesShow(niches);
    cin.ignore(20, '\n');
    cout << "Enter the name of Niche for job posting from selected option: ";

    // store the niche name in client login array
    getline(cin, clientLogin[0][2]);

    while (flag == false)
    {
        for (int i = 0; i < 100; i++)
        {
            // match the niche name with the admin allowed niches
            if (clientLogin[0][2] == niches[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            break;
        }

        nichesShow(niches);
        setColor(3);

        // if wrong niche selected then again ask for input
        cout << "Wrong Niche Selected (select from available one's)" << endl;
        setColor(15);
        cout << "Enter Niche: ";
        getline(cin, clientLogin[0][2]);
    }
    bool breaker = false;

    // search for client name untill the Cindex counter
    for (int i = 0; i < Cindex; i++)
    {

        // if clientLogin name and clientUserName match
        if ((clientLogin[0][0] == clientUserName[i]) && (clientLogin[0][1] == clientPassword[i]))
        {
            for (int k = 0; k < 5; k++)
            {
                // check for free niche space available of that clientUserName
                if (clientNiche[i][k] == "empty")
                {
                    // if available then store niche name in that particular client niche slot
                    clientNiche[i][k] = clientLogin[0][2];

                    // store the job description in particular niche data
                    cout << "Enter Job Description: ";
                    getline(cin, clientJobDescription[i][k]);

                    while (clientJobDescription[i][k].length() < 1)
                    {
                        setColor(3);
                        cout << "Please Enter a valid Job Description." << endl;
                        setColor(15);
                        cout << "Enter Job Description: ";
                        getline(cin, clientJobDescription[i][k]);
                    }

                    // store payment in particular niche data
                    cout << "Enter Payment: $";
                    cin >> clientPayment[i][k];
                    while (!cin)
                    {
                        cin.clear();
                        cin.ignore(20, '\n');
                        setColor(3);
                        cout << endl
                             << "Wrong Input Given" << endl;
                        setColor(15);

                        // store payment in particular niche data
                        cout << "Enter Payment: $";
                        cin >> clientPayment[i][k];
                    }
                    clientSpend[i] += clientPayment[i][k];
                    ratingCounter[i][k]++;
                    breaker = true;
                    break;
                }
            }

            // if particular client have new niche space available it will update
            if (breaker == true)
            {
                return true;
                break;
            }
        }
    }

    // if all slots are full return to menu
    if (breaker == false)
    {
        return false;
    }
}

// freelaner customer support section
void customerSupportClient(int Cindex, string clientCustomerSupport[1000][2], string clientUserName[])
{
    system("cls");
    for (int i = 0; i < Cindex; i++)
    {
        if (clientLogin[0][0] == clientUserName[i])
        {
            clientCustomerSupport[i][0] = clientLogin[0][0];
            cin.clear();
            cin.ignore();
            cout << "Enter Your Query/Suggestion: ";
            getline(cin, clientCustomerSupport[i][1]);
            setColor(3);
            cout << "Query/Suggestion has been successfully sent to Admin." << endl;
            setColor(15);
            break;
        }
    }
}

void pendingRating(int Findex, int Cindex, string clientLogin[1][3], string clientUserName[], string freelancerUserName[], string freelancerRating[], int ratingCounter[1000][5], string rating[1000][5][1], string clientJobDescription[1000][5], int clientPayment[1000][5], string clientNiche[1000][5], float ratingSum[], int ratingCount[])
{
    system("cls");
    // ANSI escape code for bold text
    const string bold = "\033[1m";
    const string reset = "\033[0m"; // Reset text style
    float ratingValue = 0.0;
    bool flag = false;

    cout << bold << setw(130) << "Pending Rating of Freelancers " << reset << endl;
    setColor(2);
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl;
    setColor(15);
    for (int i = 0; i < Cindex; i++)

    {
        // search for client name from main array
        if (clientLogin[0][0] == clientUserName[i])
        {
            for (int m = 0; m < 5; m++)
            {

                // if rating counter reaches the limit then display the job details which is available for rating
                if (ratingCounter[i][m] == 2)
                {
                    cout << "Freelancer Name that Completed this Job: " << rating[i][m][0] << endl
                         << endl;
                    cout << "Job Niche : " << clientNiche[i][m] << endl
                         << endl;
                    cout << "Job Description : " << clientJobDescription[i][m] << endl
                         << endl;
                    cout << "Job Price : " << clientPayment[i][m] << endl
                         << endl
                         << endl;
                    cout << "Enter Rating (0-5) : ";
                    cin >> ratingValue;
                    while ((ratingValue > 5 || ratingValue < 0) || !cin)
                    {
                        cin.clear();
                        cin.ignore(4, '\n');
                        setColor(3);
                        cout << "Invalid Rating Enter!" << endl;
                        setColor(15);
                        cout << "Enter Rating (0-5) : ";
                        cin >> ratingValue;
                    }
                    for (int p = 0; p < Findex; p++)
                    {
                        // display that name who has completed this job
                        if (rating[i][m][0] == freelancerUserName[p])
                        {
                            // add the average of rating value to that client account
                            ratingSum[p] += (ratingValue);
                            ratingCount[p]++;
                            freelancerRating[p] = to_string(ratingSum[p] / ratingCount[p]);
                            setColor(3);
                            cout << "Rating: " << fixed << setprecision(1) << ratingValue << " has been given to freelancer " << rating[i][m][0] << endl;
                            setColor(15);

                            // once the rating has been given delete this job data
                            clientJobDescription[i][m] = "empty";
                            clientPayment[i][m] = 0;
                            clientNiche[i][m] = "empty";
                            rating[i][m][0] = "empty";
                            ratingCounter[i][m] = 0;
                            flag = true;
                            break;
                        }
                        if (flag == true)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
}

/////////////////////////////////CLIENT FUNCTION END //////////////////////////////

// load all the data from files
void loadData(string freelancerUserName[], string freelancerPassword[], string freelancerRating[], string freelancerNiche[], int freelancerEarning[], float ratingSum[], int ratingCount[], string freelancerCustomerSupport[][2], int &Findex, string clientUserName[], string clientPassword[], int clientSpend[], string clientJobDescription[][5], string clientNiche[][5], int clientPayment[][5], string clientCustomerSupport[][2], int ratingCounter[][5], string rating[][5][1], int &Cindex, string niches[], string headingCustomerPolicy[], string dataCustomerPolicy[])
{
    ifstream fin;

    // Load Metadata
    fin.open("metadata.txt");
    if (!fin)
    {
        cout << "No metadata found. Starting fresh.\n";
    }
    else
    {
        fin >> Findex;

        // consume delimiter
        fin.get();
        fin >> Cindex;
        fin.close();
    }

    // Load Freelancer Data
    fin.open("freelancerData.txt");
    if (!fin)
    {
        cout << "No freelancer data found. Starting fresh.\n";
    }
    else
    {
        Findex = 0;
        while (fin.peek() != EOF)
        {
            getline(fin, freelancerUserName[Findex], ',');
            getline(fin, freelancerPassword[Findex], ',');
            getline(fin, freelancerRating[Findex], ',');
            getline(fin, freelancerNiche[Findex], ',');

            fin >> freelancerEarning[Findex];

            // consume delimiter
            fin.get();

            fin >> ratingSum[Findex];

            // consume delimiter
            fin.get();

            fin >> ratingCount[Findex];

            // consume delimiter
            fin.get();

            getline(fin, freelancerCustomerSupport[Findex][0], ';');
            getline(fin, freelancerCustomerSupport[Findex][1], '\n');

            ++Findex;
        }
        fin.close();
    }

    // Open clientData.txt to load client data
    fin.open("clientData.txt");
    if (!fin)
    {
        cout << "Error opening clientData.txt for reading.\n";
        return;
    }

    string line;

    // reset Cindex to 0 before loading data
    Cindex = 0;

    // read client data line by line
    while (getline(fin, line))
    {
        int pos = 0;
        string temp;

        // read username
        while (line[pos] != ',' && pos < line.length())
        {
            temp += line[pos];
            pos++;
        }
        clientUserName[Cindex] = temp;

        // skip the comma
        pos++;
        temp.clear();

        // read password
        while (line[pos] != ',' && pos < line.length())
        {
            temp += line[pos];
            pos++;
        }
        clientPassword[Cindex] = temp;

        // skip the comma
        pos++;
        temp.clear();

        // read spend (manually convert string to integer)
        int spend = 0;
        while (line[pos] != ',' && pos < line.length())
        {
            if (line[pos] >= '0' && line[pos] <= '9')
            {
                // check if character is a digit
                // convert it to the integer digit by digit
                spend = spend * 10 + (line[pos] - '0');
            }
            pos++;
        }
        clientSpend[Cindex] = spend;

        // skip the comma
        pos++;

        // read job descriptions, niches, and payments (5 entries each)
        for (int j = 0; j < 5; ++j)
        {
            // read job description
            temp.clear();
            while (line[pos] != ';' && pos < line.length())
            {
                temp += line[pos];
                pos++;
            }
            clientJobDescription[Cindex][j] = temp;

            // skip the semicolon
            pos++;

            // Read niche
            temp.clear();
            while (line[pos] != ';' && pos < line.length())
            {
                temp += line[pos];
                pos++;
            }
            clientNiche[Cindex][j] = temp;

            // skip the semicolon
            pos++;

            // read payment (manually convert string to integer)
            int payment = 0;
            while (line[pos] != '|' && line[pos] != ',' && pos < line.length())
            {
                if (line[pos] >= '0' && line[pos] <= '9')
                {
                    // check if character is a digit
                    // onvert the integer digit by digit
                    payment = payment * 10 + (line[pos] - '0');
                }
                pos++;
            }
            clientPayment[Cindex][j] = payment;
            if (line[pos] == '|')
                // skip the pipe delimiter
                pos++;
        }

        // read rating counter and ratings (5 entries each)
        for (int j = 0; j < 5; ++j)
        {
            // read rating counter (manually convert string to integer)
            int counter = 0;
            while (line[pos] != ';' && pos < line.length())
            {
                if (line[pos] >= '0' && line[pos] <= '9')
                {
                    // check if character is a digit
                    // convert the integer digit by digit
                    counter = counter * 10 + (line[pos] - '0');
                }
                pos++;
            }
            ratingCounter[Cindex][j] = counter;

            // skip the semicolon
            pos++;

            // Read rating
            temp.clear();
            while (line[pos] != '|' && line[pos] != ',' && pos < line.length())
            {
                temp += line[pos];
                pos++;
            }
            rating[Cindex][j][0] = temp;
            if (line[pos] == '|')

                // skip the pipe delimiter
                pos++;
        }

        // Skip the separator (|)
        while (line[pos] == ',')
            pos++;

        // read customer support info (2 entries)
        temp.clear();
        while (line[pos] != ';' && pos < line.length())
        {
            temp += line[pos];
            pos++;
        }
        clientCustomerSupport[Cindex][0] = temp;

        // skip the semicolon
        pos++;

        temp.clear();
        while (pos < line.length())
        {
            temp += line[pos];
            pos++;
        }
        clientCustomerSupport[Cindex][1] = temp;

        // increment Cindex for next client
        Cindex++;
    }

    fin.close();

    // Load Admin Allowed Niches
    fin.open("nichesData.txt");
    if (!fin)
    {
        cout << "No niches data found. Starting fresh.\n";
    }
    else
    {
        string line = "";
        int index = 10;
        while (getline(fin, line))
        {
            if (line != " ")
            {
                niches[index] = line;
            }
            ++index;
            line = "";
        }
        fin.close();
    }

    // Load Customer Policies (heading and data)
    fin.open("customerPolicy.txt");
    if (!fin)
    {
        cout << "No customer policies found. Starting fresh.\n";
    }
    else
    {
        int index = 10;
        while (fin.peek() != EOF)
        {
            getline(fin, headingCustomerPolicy[index], '|');
            getline(fin, dataCustomerPolicy[index], '\n');
            ++index;
        }
        fin.close();
    }

    cout << "Data loaded successfully.\n";
}

// store all the data to files
void storeData(string freelancerUserName[], string freelancerPassword[], string freelancerRating[], string freelancerNiche[], int freelancerEarning[], float ratingSum[], int ratingCount[], string freelancerCustomerSupport[][2], int Findex, string clientUserName[], string clientPassword[], int clientSpend[], string clientJobDescription[][5], string clientNiche[][5], int clientPayment[][5], string clientCustomerSupport[][2], int ratingCounter[][5], string rating[][5][1], int Cindex, string niches[], string headingCustomerPolicy[], string dataCustomerPolicy[])
{
    ofstream fout;

    // Store Freelancer Data
    fout.open("freelancerData.txt");

    for (int i = 0; i < Findex; ++i)
    {
        fout << freelancerUserName[i] << ","
             << freelancerPassword[i] << ","
             << freelancerRating[i] << ","
             << freelancerNiche[i] << ","
             << freelancerEarning[i] << ","
             << ratingSum[i] << ","
             << ratingCount[i] << ","
             << freelancerCustomerSupport[i][0] << ";"
             << freelancerCustomerSupport[i][1] << "\n";
    }
    fout.close();

    // Open clientData.txt to store data
    fout.open("clientData.txt");

    // write each client data to file
    for (int i = 0; i < Cindex; ++i)
    {
        // write basic client data
        fout << clientUserName[i] << "," << clientPassword[i] << "," << clientSpend[i] << ",";

        // write job descriptions, niches, and payments
        for (int j = 0; j < 5; ++j)
        {
            fout << clientJobDescription[i][j] << ";";
            fout << clientNiche[i][j] << ";";
            fout << clientPayment[i][j];
            if (j < 4)

                // Separate with "|"
                fout << "|";
        }

        fout << ",";

        // write rating counter and ratings
        for (int j = 0; j < 5; ++j)
        {
            fout << ratingCounter[i][j] << ";";
            fout << rating[i][j][0];
            if (j < 4)

                // Separate ratings with "|"
                fout << "|";
        }

        fout << ",";

        // write customer support
        fout << clientCustomerSupport[i][0] << ";" << clientCustomerSupport[i][1] << "\n";
    }

    fout.close();

    // Store Admin Allowed Niches
    fout.open("nichesData.txt");

    for (int i = 10; i < 100; ++i)
    {
        if (niches[i] != " ")
            fout << niches[i] << "\n";
    }
    fout.close();

    // Store Customer Policies
    fout.open("customerPolicy.txt");

    for (int i = 10; i < 1000; ++i)
    {
        if (headingCustomerPolicy[i] != " ")
        {
            fout << headingCustomerPolicy[i] << "|" << dataCustomerPolicy[i] << "\n";
        }
    }
    fout.close();

    // Store Metadata
    fout.open("metadata.txt");

    fout << Findex << "," << Cindex << "\n";
    fout.close();

    cout << "Data stored s/uccessfully.\n";
}

int main()
{
    // setColor(7);  //original code
    int Findex = 0, Cindex = 0;

    string freelancerUserName[1000], freelancerPassword[1000], clientUserName[1000], clientPassword[1000], freelancerRating[1000], headingCustomerPolicy[1000], dataCustomerPolicy[1000], freelancerNiche[1000];
    int freelancerEarning[1000], clientSpend[1000];
    string freelancerCustomerSupport[1000][2];
    string clientCustomerSupport[1000][2];
    string niches[100]; // contain all allowed niches

    string clientJobDescription[1000][5], clientNiche[1000][5];
    int clientPayment[1000][5];
    int ratingCounter[1000][5] = {0};
    string freelancerJobSelected[1000][4];
    float ratingSum[1000] = {0.0};
    int ratingCount[1000] = {0};

    string rating[1000][5][1]; // 1000 is client ,5 is niche and 1 is freelancer name

    for (int i = 0; i < 1000; i++)
    {
        freelancerUserName[i] = " ";
        freelancerPassword[i] = " ";
        clientUserName[i] = "empty";
        clientPassword[i] = "empty";
        freelancerRating[i] = "N/A";
        freelancerEarning[i] = 0;
        clientSpend[i] = 0;
        headingCustomerPolicy[i] = " ";
        dataCustomerPolicy[i] = " ";
        freelancerNiche[i] = " ";
        for (int j = 0; j < 2; j++)
        {
            freelancerCustomerSupport[i][j] = " ";
            clientCustomerSupport[i][j] = "empty";
        }
        for (int j = 0; j < 5; j++)
        {
            clientNiche[i][j] = "empty";
            clientJobDescription[i][j] = "empty";
            clientPayment[i][j] = 0;
            for (int m = 0; m < 1; m++)
            {
                rating[i][j][m] = "empty";
            }
        }
        for (int j = 0; j < 4; j++)
        {
            freelancerJobSelected[i][j] = " ";
        }
    }
    niches[0] = "Graphic Designing";
    niches[1] = "Web Development";
    niches[2] = "Content Writing";
    niches[3] = "Digital Marketing";
    niches[4] = "Video Editing";
    niches[5] = "Game Development";
    niches[6] = "SEO Optimization";
    niches[7] = "CyberSecurity";
    niches[8] = "Machine Learning";
    niches[9] = "AI Learning";
    for (int i = 10; i < 100; i++)
    {
        niches[i] = " ";
    }
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            freelancerLogin[i][j] = " ";
        }
    }
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            clientLogin[i][j] = "empty";
        }
    }

    loadData(freelancerUserName, freelancerPassword, freelancerRating, freelancerNiche, freelancerEarning,
             ratingSum, ratingCount, freelancerCustomerSupport, Findex, clientUserName, clientPassword,
             clientSpend, clientJobDescription, clientNiche, clientPayment, clientCustomerSupport,
             ratingCounter, rating, Cindex, niches, headingCustomerPolicy, dataCustomerPolicy);

    string username, password;
    int input = 0;
    int adminCounter = 0;
    int usertype = 11;
    bool exit = false;
    system("cls");
    setConsoleCodePage();

    setColor(7);
    do
    {
        setColor(2);
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
             << endl
             << endl;
        cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
        cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
        cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
        cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
        cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
        cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
             << endl;
        cout << "-----";
        setColor(8);
        cout << "FREELANCING MANAGEMENT SYSTEM ";
        setColor(2);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
             << endl;
        setColor(15);
        cout << right;
        cout << endl;
        cout << setw(120) << "1. Administrator Login\n"
             << setw(117) << "2. Freelancer Login\n"
             << setw(113) << "3. Client Login\n"
             << setw(105) << "0. Exit " << endl
             << endl;
        cout.unsetf(ios::right);
        cout << "Enter: ";
        cin >> input;
        if (input == 0 && cin)
        {
            setColor(3);
            cout << "Thank you for using system! " << endl;
            setColor(15);
            break;
        }
        while ((input > 3 || input < 0) || !cin)
        {
            system("cls");
            cin.clear();
            cin.ignore(100, '\n');
            setColor(2);
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                 << endl
                 << endl;
            cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
            cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
            cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
            cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
            cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
            cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
                 << endl;
            cout << "-----";
            setColor(8);
            cout << "FREELANCING MANAGEMENT SYSTEM ";
            setColor(2);
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                 << endl;
            setColor(3);
            cout << "Invalid Details Entered!" << endl;
            setColor(15);
            cout << "Please select the correct number" << endl;
            cout << setw(120) << "1. Administrator Login\n"
                 << setw(117) << "2. Freelancer Login\n"
                 << setw(113) << "3. Client Login\n"
                 << setw(105) << "0. Exit " << endl
                 << endl;
            cout << "Enter: ";
            cin >> input;
            cout << endl;
            if (input == 0 && cin)
            {
                exit = true;
                setColor(3);
                cout << "Thank you for using system! " << endl;
                setColor(15);
                break;
            }
        }
        switch (input)
        {
        case 1:
            system("cls");

            setColor(2);
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                 << endl
                 << endl;
            cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
            cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
            cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
            cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
            cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
            cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
                 << endl;
            cout << "-----";
            setColor(8);
            cout << "ADMIN : LOGIN IN ";
            setColor(2);
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                 << endl;
            setColor(15);

            cout << endl;
            cout << setw(115) << "Enter Username: ";
            cin >> username;
            cin.clear();
            cin.ignore();
            cout << setw(115) << "Enter Password: ";

            char character;
            password = "";
            while ((character = _getch()) != '\r')
            {
                if (character == '\b')
                {
                    if (!password.empty())
                    {
                        password.pop_back();
                        cout << "\b \b";
                    }
                }
                else
                {
                    // get character by character and store it in password
                    password += character;
                    cout << "*";
                }
            }
            cout << endl;
            if (username == "Admin" && password == "123")
            {
                usertype = 1;

                cout << setw(117) << "Logging In...." << endl;
                password = "";
                Sleep(1000);
                system("cls");
            }
            else
            {
                // only two admin attempts are allowed to login the system
                adminCounter++;
                usertype = -1;
                if (adminCounter == 2)
                {
                    break;
                }
                setColor(3);
                cout << "One last attempt remaining!" << endl;
                setColor(15);
            }
            break;
        case 2:
            system("cls");
            setColor(2);
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                 << endl
                 << endl;
            cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
            cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
            cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
            cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
            cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
            cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
                 << endl;
            cout << "-----";
            setColor(8);
            cout << " FREELANCER : LOGIN IN ";
            setColor(2);
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                 << endl;
            setColor(15);
            cout << endl;
            cout << setw(116) << "1. Sign up\n"
                 << setw(116) << "2. Sign in\n"
                 << setw(115) << "0. Go Back" << endl;
            cout << "Enter: ";
            cin.clear();
            cin.ignore(20, '\n');
            cin >> input;
            if (input == 0 && cin)
                break;
            while ((input > 2 || input < 0) || !cin)
            {
                system("cls");
                cin.clear();
                cin.ignore(100, '\n');
                setColor(2);
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                     << endl
                     << endl;
                cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
                cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
                cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
                cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
                cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
                cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
                     << endl;
                cout << "-----";
                setColor(8);
                cout << " FREELANCER : LOGIN IN ";
                setColor(2);
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                     << endl;
                setColor(15);
                cout << endl;
                setColor(3);
                cout << "Invalid Details Entered!" << endl;
                setColor(15);
                cout << "Please select the correct number" << endl;
                cout << setw(116) << "1. Sign up\n"
                     << setw(116) << "2. Sign in\n"
                     << setw(115) << "0. Go Back" << endl;
                cout << "Enter: ";
                cin >> input;

                if (input == 0 && cin)
                    break;
                cout << endl;
                usertype = 0;
            }
            if (input == 1)
            {
                usertype = 0; // random initialize
                for (int i = 0; i < 1000; i++)
                {
                    if (freelancerUserName[i] == " ")
                    {

                        cin.clear();
                        cin.ignore(20, '\n');
                        cout << setw(121) << "Enter Username: ";

                        cin >> freelancerUserName[i];
                        while (freelancerUserName[i].length() < 3)
                        {

                            cin.ignore();
                            setColor(3);
                            cout << "UserName should contain atleast 3 character's." << endl;
                            setColor(15);
                            cout << setw(121) << "Enter Username: ";
                            cin >> freelancerUserName[i];
                        }
                        cin.ignore();
                        cout << setw(121) << "Enter Password: ";
                        cin >> freelancerPassword[i];

                        while (freelancerPassword[i].length() < 8)
                        {
                            cin.ignore();
                            cout << endl;
                            setColor(3);
                            cout << "Password should contain atleast 8 character's." << endl;
                            setColor(15);
                            cout << setw(121) << "Enter Password: ";
                            cin >> freelancerPassword[i];
                        }
                        cin.ignore();
                        cout << endl
                             << endl;

                        nichesShow(niches);
                        cout << "Select Your Niche: ";
                        getline(cin, freelancerNiche[i]);
                        bool flag = false;
                        while (flag == false)
                        {
                            for (int j = 0; j < 100; j++)
                            {
                                if (freelancerNiche[i] == niches[j])
                                {
                                    flag = true;
                                    break;
                                }
                            }
                            if (flag == true)
                            {
                                break;
                            }
                            setColor(3);
                            cout << "Wrong Niche Selected (select from available one's)" << endl;
                            setColor(15);
                            cout << "Select Your Niche: ";
                            getline(cin, freelancerNiche[i]);
                        }
                        Findex++;
                        setColor(3);
                        cout << "Account Created Successfully! " << endl;
                        setColor(15);

                        break;
                    }
                    if (freelancerUserName[999] != " ")
                    {
                        cout << "Account limit reached, unable to register more users" << endl;
                        break;
                    }
                }
            }
            else if (input == 2)
            {
                cin.clear();
                cin.ignore(30, '\n');
                cout << setw(121) << "Enter Username: ";
                getline(cin, username);
                cout << setw(121) << "Enter Password: ";

                char character;
                password = "";
                while ((character = _getch()) != '\r')
                {
                    if (character == '\b')
                    {
                        if (!password.empty())
                        {
                            password.pop_back();
                            cout << "\b \b";
                        }
                    }
                    else
                    {
                        password += character;
                        cout << "*";
                    }
                }
                cout << endl;

                for (int i = 0; i < Findex; i++)
                {
                    if (username == freelancerUserName[i] && password == freelancerPassword[i])
                    {
                        usertype = 2;
                        freelancerLogin[0][0] = freelancerUserName[i];
                        freelancerLogin[0][1] = freelancerPassword[i];
                        freelancerLogin[0][2] = freelancerNiche[i];
                        freelancerLogin[0][3] = freelancerRating[i];
                        freelancerLogin[0][4] = freelancerEarning[i];
                        setColor(3);

                        cout << setw(122) << "Logging In...." << endl;
                        setColor(15);
                        Sleep(1000);
                        system("cls");
                        break;
                    }
                    else if (username != freelancerUserName[i] || password != freelancerPassword[i])
                    {
                        usertype = -1;
                    }
                }
            }

            break;
        case 3:
            system("cls");
            setColor(2);
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                 << endl
                 << endl;
            cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
            cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
            cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
            cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
            cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
            cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
                 << endl;
            cout << "-----";
            setColor(8);
            cout << " CLIENT : LOGIN IN ";
            setColor(2);
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                 << endl;
            setColor(15);
            cout << setw(116) << "1. Sign up\n"
                 << setw(116) << "2. Sign in\n"
                 << setw(115) << "0. Go Back" << endl;
            cout << "Enter: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
            if (input == 0 && cin)
                break;
            while ((input > 2 || input < 0) || !cin)
            {
                system("cls");
                cin.clear();
                cin.ignore(100, '\n');

                setColor(2);
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                     << endl
                     << endl;
                cout << "                                                       ███████╗██████╗ ███████╗███████╗██╗      █████╗ ███╗   ██╗ ██████╗███████╗    ███████╗██╗      ██████╗ ██╗    ██╗" << endl;
                cout << "                                                       ██╔════╝██╔══██╗██╔════╝██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝██╔════╝    ██╔════╝██║     ██╔═══██╗██║    ██║" << endl;
                cout << "                                                       █████╗  ██████╔╝█████╗  █████╗  ██║     ███████║██╔██╗ ██║██║     █████╗      █████╗  ██║     ██║   ██║██║ █╗ ██║" << endl;
                cout << "                                                       ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝  ██║     ██╔══██║██║╚██╗██║██║     ██╔══╝      ██╔══╝  ██║     ██║   ██║██║███╗██║" << endl;
                cout << "                                                       ██║     ██║  ██║███████╗███████╗███████╗██║  ██║██║ ╚████║╚██████╗███████╗    ██║     ███████╗╚██████╔╝╚███╔███╔╝" << endl;
                cout << "                                                       ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    ╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ " << endl
                     << endl;
                cout << "-----";
                setColor(8);
                cout << " CLIENT : LOGIN IN ";
                setColor(2);
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                     << endl;
                setColor(3);
                cout << "Invalid Data Entered\n";
                setColor(15);
                cout << "Please select the correct number\n";
                cout << setw(116) << "1. Sign up\n"
                     << setw(116) << "2. Sign in\n"
                     << setw(115) << "0. Go Back" << endl;
                cout << "Enter: ";
                cin >> input;

                if (input == 0 && cin)
                    break;
                cout << endl;
            }
            if (input == 1)
            {
                usertype = 0;
                for (int i = 0; i < 1000; i++)
                {
                    if (clientUserName[i] == "empty")
                    {
                        cin.ignore(20, '\n');
                        cout << setw(121) << "Enter Username: ";
                        cin >> clientUserName[i];

                        while (clientUserName[i].length() < 3)
                        {

                            setColor(3);
                            cout << "UserName should contain atleast 3 character's." << endl;
                            setColor(15);
                            cout << setw(121) << "Enter Username: ";
                            cin >> clientUserName[i];
                        }

                        cout << setw(121) << "Enter Password: ";
                        cin >> clientPassword[i];
                        cin.ignore();
                        while (clientPassword[i].length() < 8)
                        {

                            cout << endl;
                            setColor(3);
                            cout << "Password should contain atleast 8 character's." << endl;
                            setColor(15);

                            cout << setw(121) << "Enter Password: ";
                            getline(cin, clientPassword[i]);
                        }

                        Cindex++;
                        setColor(3);
                        cout << "Account Created Successfully! " << endl;
                        setColor(15);
                        break;
                    }
                    if (clientUserName[999] != "empty")
                    {
                        cout << "Account limit reached, unable to register more users" << endl;
                        break;
                    }
                }
            }
            else if (input == 2)
            {
                cin.clear();
                cin.ignore(30, '\n');
                cout << setw(121) << "Enter Username: ";
                getline(cin, username);
                cout << setw(121) << "Enter Password: ";

                char character;
                password = "";
                while ((character = _getch()) != '\r')
                {
                    if (character == '\b')
                    {
                        if (!password.empty())
                        {
                            password.pop_back();
                            cout << "\b \b";
                        }
                    }
                    else
                    {
                        password += character;
                        cout << "*";
                    }
                }
                cout << endl;

                for (int i = 0; i < Cindex; i++)
                {
                    if ((username == clientUserName[i]) && (password == clientPassword[i]))
                    {
                        usertype = 3;
                        clientLogin[0][0] = clientUserName[i];
                        clientLogin[0][1] = clientPassword[i];
                        setColor(3);

                        cout << setw(122) << "Logging In...." << endl;
                        setColor(15);
                        Sleep(1000);
                        system("cls");
                        break;
                    }
                    else if ((username != clientUserName[i]) || (password != clientPassword[i]))
                    {
                        usertype = -1;
                    }
                }
            }
            break;
        default:
            break;
        } // switch end

        if (usertype == 1) // admin menu
        {
            do
            {
                adminMenu();
                cout << endl;
                cout << "Enter: ";
                cin >> input;
                if (input == 0 && cin)
                {
                    cout << setw(115) << "Logging Out....." << endl;
                    Sleep(1000);
                    break;
                }
                while ((input > 7 || input < 0) || !cin)
                {
                    system("cls");
                    cin.clear();
                    cin.ignore(100, '\n');
                    adminMenu();
                    setColor(3);
                    cout << "Invalid Details Entered!" << endl;
                    setColor(15);
                    cout << "Please select the correct number" << endl;
                    cout << "Enter: ";
                    cin >> input;
                    cout << endl;
                    if (input == 0 && cin)
                    {
                        cout << setw(115) << "Logging Out....." << endl;
                        Sleep(1000);
                        break;
                    }
                }
                if (input == 1)
                {
                    freelancerStatistic(Findex, freelancerUserName, freelancerPassword, freelancerNiche, freelancerRating, freelancerEarning);
                    // check freelancer statistics
                }
                else if (input == 2)
                {
                    clientStatistic(Cindex, clientUserName, clientPassword, clientNiche, clientSpend);
                    // check client statistics
                }
                else if (input == 3)
                {
                    customerAddPolicy(headingCustomerPolicy, dataCustomerPolicy);
                    // update customer policy function
                }
                else if (input == 4)
                {
                    string user = " ";
                    int userRemoved = 5;
                    system("cls");
                    freelancerStatistic(Findex, freelancerUserName, freelancerPassword, freelancerNiche, freelancerRating, freelancerEarning);
                    cout << endl;
                    setColor(2);
                    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                         << endl
                         << endl;
                    setColor(15);
                    cout << "Enter Username to remove or press 0 to go back: ";
                    cin.ignore(30, '\n');
                    cin.clear();
                    getline(cin, user);

                    userRemoved = removeFreelancerAcc(Findex, user, freelancerUserName, freelancerPassword, freelancerNiche, freelancerRating, freelancerEarning, freelancerCustomerSupport);
                    cin.clear();
                    if (userRemoved == 1)
                        cout << "Freelancer " << user << " Removed Successfully! " << endl;
                    if (userRemoved == -1)
                        cout << "No such Freelancer Account Exist in the system! " << endl;

                    // remove freelancer function
                }
                else if (input == 5)
                {
                    string user = " ";
                    int userRemoved = 5;
                    system("cls");
                    clientStatistic(Cindex, clientUserName, clientPassword, clientNiche, clientSpend);
                    cout << endl;
                    setColor(2);
                    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
                         << endl
                         << endl;
                    setColor(15);
                    cout << "Enter Username to remove or press 0 to go back: ";
                    cin.ignore(30, '\n');
                    cin.clear();
                    getline(cin, user);

                    userRemoved = removeClientAcc(Cindex, rating, user, clientUserName, clientPassword, clientNiche, clientSpend, clientJobDescription, ratingCounter, clientPayment, clientCustomerSupport);
                    cin.clear();
                    if (userRemoved == 1)
                        cout << "Client " << user << " Removed Successfully! " << endl;
                    if (userRemoved == -1)
                        cout << "No such Client Account Exist in the system! " << endl;
                    // remove client function
                }
                else if (input == 6)
                {
                    customerSupport(freelancerCustomerSupport, clientCustomerSupport);
                    // customer support function
                }
                else if (input == 7)
                {
                    adminAddNiches(niches);
                    // add new niches
                }
            } while (input != 0);

        } // admin menu end

        if (usertype == 2)
        {
            do
            {
                freelancerMenu();
                cout << "Enter: ";
                cin >> input;
                if (input == 0 && cin)
                {
                    cout << endl
                         << "Logging Out....." << endl;
                    Sleep(1000);
                    system("cls");
                    break;
                }
                while ((input > 5 || input < 0) || !cin)
                {
                    system("cls");
                    cin.clear();
                    cin.ignore(100, '\n');
                    freelancerMenu();
                    setColor(3);
                    cout << "Invalid Details Entered!" << endl;
                    setColor(15);
                    cout << "Please select the correct number" << endl;
                    cout << "Enter: ";
                    cin >> input;
                    cout << endl;
                    if (input == 0 && cin)
                    {
                        cout << endl
                             << "Logging Out....." << endl;
                        Sleep(1000);
                        system("cls");
                        break;
                    }
                }
                if (input == 1)
                {
                    jobSelection(Findex, Cindex, clientUserName, freelancerLogin, clientJobDescription, clientNiche, clientPayment, freelancerJobSelected, freelancerUserName);
                    /*funtion call code*/
                }
                else if (input == 2)
                {
                    freelancerWorkSubmit(Findex, Cindex, freelancerLogin, freelancerUserName, freelancerJobSelected, clientUserName, clientJobDescription, clientNiche, clientPayment, freelancerEarning, ratingCounter, rating);
                    /*function call code*/
                }
                else if (input == 3)
                {
                    freelancerEarnings(Findex, freelancerLogin, freelancerUserName, freelancerEarning, freelancerRating);
                    /*function call code*/
                }
                else if (input == 4)
                {
                    customerSupportfreelancer(Findex, freelancerLogin, freelancerCustomerSupport, freelancerUserName);
                    /*customer Support freelancer function */
                }
                else if (input == 5)
                {
                    customerPolicy(headingCustomerPolicy, dataCustomerPolicy);
                    /*customerPolicy function */
                }

            } while (input != 0); // freelancer menu end
        }
        if (usertype == 3)
        {
            do
            {

                clientMenu();
                cout << "Enter: ";
                cin >> input;
                if (input == 0 && cin)
                {
                    cout << endl
                         << "Logging Out....." << endl;
                    Sleep(1000);
                    system("cls");
                    break;
                }
                while ((input > 4 || input < 0) || !cin)
                {
                    system("cls");
                    cin.clear();
                    cin.ignore(100, '\n');
                    clientMenu();
                    setColor(3);
                    cout << "Invalid Details Entered!" << endl;
                    setColor(15);
                    cout << "Please select the correct number" << endl;
                    cout << "Enter: ";
                    cin >> input;
                    cout << endl;
                    if (input == 0 && cin)
                    {
                        cout << endl
                             << "Logging Out....." << endl;
                        Sleep(1000);
                        system("cls");
                        break;
                    }
                }
                if (input == 1)
                {
                    bool res = postJob(Cindex, niches, clientLogin, clientUserName, clientPassword, clientNiche, clientJobDescription, clientPayment, clientSpend, ratingCounter);
                    if (res == 0)
                    {
                        setColor(3);
                        cout << "\nMaximum Jobs are already Posted.\nCan not post more jobs!" << endl;
                        setColor(15);
                    }
                    if (res == 1)
                    {
                        setColor(3);
                        cout << "\nJob Posted Successfully!" << endl;
                        setColor(15);
                    }
                    /*post job funtion */
                }
                else if (input == 2)
                {
                    pendingRating(Findex, Cindex, clientLogin, clientUserName, freelancerUserName, freelancerRating, ratingCounter, rating, clientJobDescription, clientPayment, clientNiche, ratingSum, ratingCount);
                    /*function call code*/
                }
                else if (input == 3)
                {
                    customerPolicy(headingCustomerPolicy, dataCustomerPolicy);
                    /*customer policy function */
                }
                else if (input == 4)
                {
                    customerSupportClient(Cindex, clientCustomerSupport, clientUserName);
                    /*customer support client function call code*/
                }

            } while (input != 0); // client menu end
        }

        if (usertype == -1)
        {
            setColor(3);
            cout << "Invalid Details Entered!" << endl;
            setColor(15);
        }

        // last menu to check again

        if (adminCounter == 2 || exit == true)
        {
            break; // break the loop if invalid credentials are entered twice
        }
        usertype = 0; // no garbage value
        input = -1;   // so that it doesnot terminate the main loop

    } while (input != 0); // change input to 0 to stop the program

    storeData(freelancerUserName, freelancerPassword, freelancerRating, freelancerNiche, freelancerEarning,
              ratingSum, ratingCount, freelancerCustomerSupport, Findex, clientUserName, clientPassword,
              clientSpend, clientJobDescription, clientNiche, clientPayment, clientCustomerSupport,
              ratingCounter, rating, Cindex, niches, headingCustomerPolicy, dataCustomerPolicy);

    return 0;
}