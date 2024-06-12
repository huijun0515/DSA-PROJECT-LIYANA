#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<chrono>
#include<thread>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<unordered_map>
#include<cstring>

#define fees 40.00

using namespace std;

class BaseUser;
class UserPage;
bool goBack();
int main();
bool isNumeric(const string& str);

struct TextColor
{
    string g = {"\033[1;32m"}; // Green
    string r = {"\033[1;31m"}; // Red
    string y = {"\033[1;33m"}; // Yellow
    string w = {"\033[0m"}; // White
    string b = {"\033[1;34m"}; // Blue
    string c = {"\033[1;36m"}; // Cyan
    string m = {"\033[1;35m"}; // Magenta
    string k = {"\033[1;30m"}; // Black
    string o = {"\033[1;38;5;208m"}; // Orange
    string p = {"\033[1;38;5;200m"}; // Pink
    string s = {"\033[1;38;5;7m"}; // Silver
    string v = {"\033[1;38;5;63m"}; // Violet

} TC;

int main();

class EditAdminValue
{
    private:

        string id, password;

    public:

        void setData(string adminID, string adminPassword)
        {
            id = adminID;
            password = adminPassword;
        }

        string getID()
        {
            return id;
        }

        string getPassword()
        {
            return password;
        }

} EAV;

class ChildrenInfo
{
    protected:

        string childName, parentName, address, contactNum, selectedService, newAge;
        int age;

    public:

        void childInfo()
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "PLEASE ENTER YOUR CHILD NAME : ";
            getline(cin, childName);

            do
            {
                cout << "PLEASE ENTER THE AGE OF YOUR CHILDREN : ";
                cin >> newAge;

                if(!(all_of(newAge.begin(), newAge.end(), ::isdigit)))
                {
                    cout << TC.r << "PLEASE ENTER THE NUMBER" << TC.w << endl;
                }

            } while(!(all_of(newAge.begin(), newAge.end(), ::isdigit)));
            
            age = stoi(newAge);

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "PLEASE ENTER YOUR NAME : ";
            getline(cin, parentName);
            cout << "PLEASE ENTER YOUR CONTACT NUMBER : ";
            cin >> contactNum;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "PLEASE ENTER YOUR HOME ADDRESS : ";
            getline(cin, address);
            system("cls");
        }

        friend class UserPage;

        friend class Calculation;
};

class BaseUser
{
    protected:

        string userID, password, adminID, adminPassword;

    public:

        void getUserCredentials()
        {
            cout << "Enter user ID: ";
            cin >> userID;

            if(userID == "*")
            {
                system("cls");
                    
                main();
            }

            cout << "Enter password: ";
            cin >> password;

            if(password == "*")
            {
                system("cls");
                    
                main();
            }
        }

        void getAdminCredentials()
        {
            cout << "Enter admin ID: ";
            cin >> adminID;

            if(adminID == "*")
            {
                system("cls");
                    
                main();
            }

            cout << "Enter password: ";
            cin >> adminPassword;

            if(adminPassword == "*")
            {
                system("cls");
                    
                main();
            }
        }

        string get_userID()
        {
            return userID;
        }

        string get_adminID()
        {
            return adminID;
        }

        friend class Calculation;
};

class Calculation
{
    protected:

        string menthod;
        string pay_code;
        char code;
        float total, price = 0.0, t_price = 0.0, e_price = 0.0, m_price = 0.0, v_price = 0.0, h_price = 0.0, s_price = 0.0;
        int t_count = 0, e_count = 0, m_count = 0, v_count = 0, h_count = 0, s_count = 0;

    public:

        Calculation(int T, int E, int M, int V, int H, int S)
        {
            t_count = T;
            e_count = E;
            m_count = M;
            v_count = V;
            h_count = H;
            s_count = S;
            total = 0.00;
        }

        void get_total()
        {
            ifstream Price("price.txt");

            while(Price >> code >> price)
            {
                if(code == 'T')
                {
                    t_price = price;
                }
                else if(code == 'E')
                {
                    e_price = price;
                }
                else if(code == 'M')
                {
                    m_price = price;
                }
                else if(code == 'V')
                {
                    v_price = price;
                }
                else if(code == 'H')
                {
                    h_price = price;
                }
                else if(code == 'S')
                {
                    s_price = price;
                }
            }

            Price.close();
        }

        void display_total(string UserID)
        {
            float sub_total, price;

            int line_count;
            
            string line;

            ChildrenInfo* childArry;

            auto currentTime = chrono::system_clock::now();

            time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);

            tm* currentTM = localtime(&currentTimeT);

            ifstream Record("record.txt");

            while(getline(Record, line))
            {
                line_count++;
            }

            string service[line_count];

            childArry = new ChildrenInfo[line_count];

            Record.clear();
            Record.seekg(0, ios::beg);

            for(int i = 0; i < line_count && getline(Record, childArry[i].childName, '_') && (Record >> ws >> childArry[i].age >> ws, Record.ignore(numeric_limits<streamsize>::max(), '_')) && getline(Record >> ws, childArry[i].parentName, '_') && getline(Record >> ws, childArry[i].contactNum, '_') && getline(Record >> ws, childArry[i].address); i++)
            {
                if(childArry[i].age > 4 && childArry[i].age <= 6)
                {
                    price = fees;
                }
                else if(childArry[i].age > 6 && childArry[i].age <= 9)
                {
                    price = fees * 1.4;
                }
                else if(childArry[i].age > 9 && childArry[i].age <= 12)
                {
                    price = fees * 1.8;
                }
                else
                {
                    price = 0.00;
                }

                sub_total += price;
            }

            do
            {
                system("cls");

                cout << TC.g << UserID << TC.w;
                cout << "\t\t\t      " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                cout << "===============================================" << endl;
                cout << "                 PAYMENT CENTER                " << endl;
                cout << "===============================================" << endl << endl;
                cout << "TOTAL REGISTARTION FEE           : RM " << fixed << setprecision(2) << sub_total << endl << endl;
                cout << "TRANSPORTATION TAKEN   [" << t_count << "] TIMES : RM " << fixed << setprecision(2) << t_price * t_count << endl << endl;
                cout << "EVENT TAKEN            [" << e_count << "] TIMES : RM " << fixed << setprecision(2) << e_price * e_count << endl << endl;
                cout << "MEALS TAKEN            [" << m_count << "] TIMES : RM " << fixed << setprecision(2) << m_price * m_count << endl << endl;
                cout << "MEALS (VEGGIE) TAKEN   [" << v_count << "] TIMES : RM " << fixed << setprecision(2) << v_price * v_count << endl << endl;
                cout << "HOMEWORK SUPPORT TAKEN [" << h_count << "] TIMES : RM " << fixed << setprecision(2) << h_price * h_count << endl << endl;

                total = (t_price * t_count) + (e_price * e_count) + (m_price * m_count) + (v_price * v_count) + (h_price * h_count) + sub_total;

                cout << "THE TOTAL WILL BE                : " << TC.y << "RM " << total << TC.w << fixed << setprecision(2) << endl << endl << endl;

                cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "                 PAYING MENTHOD                " << endl;
                cout << "                [A] Touch 'n Go                " << endl;
                cout << "                [B] Online Banking             " << endl;
                cout << "                [C] Cash                       " << endl << endl;
                cout << "       PLEASE CHOOSE YOUR PAYING MENTHOD : ";
                cin >> menthod;

                if(menthod == "A" || menthod == "a")
                {
                    pay_code = "Touch 'n Go";
                }
                else if(menthod == "B" || menthod == "b")
                {
                    pay_code = "Online Banking";
                }
                else if(menthod == "C" || menthod == "c")
                {
                    pay_code = "Cash";
                }
                else
                {
                    system("cls");

                    cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
                }

            }while((menthod != "A" && menthod != "a") && (menthod != "B" && menthod != "b") && (menthod != "C" && menthod != "c"));

            Record.close();
        }

        void receipt_generate(string UserID, string Password)
        {
            BaseUser BU;

            cin.ignore();

            int error = 0;

            auto currentTime = chrono::system_clock::now();

            time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);

            tm* currentTM = localtime(&currentTimeT);

            string USERID, USERPASSWORD, ADMINID, ADMINPASSWORD;

            string filename = UserID + ".txt";

            ifstream Veritfy(filename);

            system("cls");

            cout << TC.g << UserID << TC.w;
            cout << "\t\t\t      " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
            cout << "===============================================" << endl;
            cout << "                 PAYMENT CENTER                " << endl;
            cout << "===============================================" << endl << endl;
            cout << "PLEASE ENTER YOUR PASSWORD AGAIN TO IDENTIFY YOUR IDENTITY : ";
            getline(cin, BU.password);

            if(BU.password == Password)
            {
                cout << endl;
                cout << "IDENTITY CONFIRM, GENERATE THE RECEIPT" << endl;
                Veritfy.close();
                system("pause");
            }

            while((BU.password.length() != 10 || BU.password != Password) && error <= 3)
            {
                cout << TC.g << UserID << TC.w;
                cout << "\t\t\t      " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                cout << "===============================================" << endl;
                cout << "                 PAYMENT CENTER                " << endl;
                cout << "===============================================" << endl << endl;
                cout << "PLEASE ENTER YOUR PASSWORD AGAIN TO IDENTIFY YOUR IDENTITY : ";
                getline(cin, BU.password);

                if(BU.password.length() != 10)
                {
                    system("cls");

                    cout << TC.r << "PASSWORD MUST BE 10 CHARACTER\n" << TC.w << endl;
                }
                else if(BU.password == Password)
                {
                    cout << endl;
                    cout << "IDENTITY CONFIRM, GENERATE THE RECEIPT" << endl;
                    Veritfy.close();
                    system("pause");
                }
                else if(BU.password != Password)
                {
                    system("cls");

                    cout << TC.r << "PASSWORD ARE INVALID... PLEASE TRY AGAIN." << TC.w << endl;

                    error++;
                }
                else if(error > 3)
                {
                    Veritfy.close();

                    break;
                }
            }

            Veritfy.close();
        }

        void receipt_display(string UserID)
        {
            int duration = 100;
            int steps = 20;
            int line_count = 0;

            ChildrenInfo* childArry;

            auto currentTime = chrono::system_clock::now();

            time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);

            tm* currentTM = localtime(&currentTimeT);

            system("cls");

            int stepSize = 100 / steps;

            for (int i = 0; i <= steps; ++i) 
            {
                cout << TC.g << "\t\t\r[";

                for (int j = 0; j < i; ++j) 
                {
                    cout << "=";
                }

                for (int j = i; j < steps; ++j) 
                {
                    cout << " ";
                }
                
                cout << "] " << i * stepSize << "%" << TC.w;
                cout.flush();

                this_thread::sleep_for(chrono::milliseconds(duration));
            }

            std::unordered_map<std::string, std::pair<std::string, float>> serviceMap = 
            {
                {"T", {"\t-TRANSPORTATION", 5.00}},
                {"E", {"\t-EVENT", 20.00}},
                {"M", {"\t-MEAL", 9.00}},
                {"V", {"\t-VEGGIE", 8.00}},
                {"H", {"\t-HOME WORKSUPPORT", 5.00}},
                {"S", {"\t-NONE", 0.00}}
            };

            cout << endl;

            string filename = UserID + "Receipt.txt";

            ofstream Save(filename, ios::app);

            Save << "===============================================" << endl;
            Save << "                     RECEIPT                   " << endl;
            Save << TC.y << "\t\t   " << UserID << TC.w << endl;
            Save << TC.g << "\t\t   " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << TC.w << endl;
            Save << "===============================================" << endl;

            ifstream Receipt("record.txt");

            string line;

            while(getline(Receipt, line))
            {
                line_count++;
            }

            string service_selected[line_count];

            childArry = new ChildrenInfo[line_count];

            Receipt.clear(); 
            Receipt.seekg(0, ios::beg); 

            for(int i = 0; i < line_count && getline(Receipt, childArry[i].childName, '_') && (Receipt >> ws >> childArry[i].age >> ws, Receipt.ignore(numeric_limits<streamsize>::max(), '_')) && getline(Receipt >> ws, childArry[i].parentName, '_') && getline(Receipt >> ws, childArry[i].contactNum, '_') && getline(Receipt >> ws, childArry[i].address, '_') && getline(Receipt >> ws, service_selected[i]); i++)
            {
                Save << "\n\tCHILD " << i+1 << "(AGE " << childArry[i].age << ")" << endl;

                Save << "\tCHILD NAME       : " << childArry[i].childName << endl;

                Save << "\tPARNET NAME      : " << childArry[i].parentName << endl;

                Save << "\tCONTACT NUMBER   : " << childArry[i].contactNum << endl;

                Save << "\tADDRESS          : " << childArry[i].address << endl;

                if(childArry[i].age > 4 && childArry[i].age <= 6)
                {
                    Save << "\tREGISTRATION FEE : RM " << fixed << setprecision(2) << fees << endl;
                }
                else if(childArry[i].age > 6 && childArry[i].age <= 9)
                {
                    Save << "\tREGISTRATION FEE : RM " << fixed << setprecision(2) << fees * 1.4 << endl;
                }
                else if(childArry[i].age > 9 && childArry[i].age <= 12)
                {
                    Save << "\tREGISTRATION FEE : RM " << fixed << setprecision(2) << fees * 1.8 << endl;
                }

                Save << "\tSERVICE          : " << endl;

                for (char& c : service_selected[i]) 
                {
                    c = toupper(c);
                }

                std::istringstream iss(service_selected[i]);
                std::string serviceCode;

                while (iss >> serviceCode) 
                {
                    auto it = serviceMap.find(serviceCode);

                    if (it != serviceMap.end()) 
                    {
                        Save << it->second.first << " (RM " << std::fixed << std::setprecision(2) << it->second.second << ")\n";
                    } 
                    else 
                    {
                        Save << "\t-UNKNOW SERVICE";
                    }
                }
            }

            Save << TC.g << "\n\tTOTAL PAYMENT  : RM " << fixed << setprecision(2) << total << TC.w << endl;

            if(menthod == "A" || menthod == "a")
            {
                pay_code = "Touch 'n Go";
            }
            else if(menthod == "B" || menthod == "b")
            {
                pay_code = "Online Banking";
            }
            else if(menthod == "C" || menthod == "c")
            {
                pay_code = "Cash";
            }

            Save << "\tPAID BY  : " << pay_code << endl << endl;

            Receipt.close();

            Save.close();

            ifstream DisplayReceipt(filename);

            cout << DisplayReceipt.rdbuf() << endl;

            DisplayReceipt.close();

            ofstream Delete("record.txt", ios::trunc);

            Delete.close();

            delete[] childArry;
        }

        ~Calculation()
        {
            cout << "PAYMENT END, RETURN TO THE USER PAGE";
        }
};

class AdminPage
{
    private:

        friend class Login;
        string userID, userPassword, adminID, adminPassword, newAdminID, newAdminPassword, 
               typeName, editedID, editedPassword, editAID, editAP, newAmount;
        string ChooseLogin;
        float total;

        vector<pair<char, string>> readDataFromFile(const string& filename);
        void writeDataToFile(const string& filename, const vector<pair<char, string>>& data);
        bool isNumeric(const string& str);

    public:

        bool isGoBack;

        void getLogin_choice(string log_choice)
        {
            ChooseLogin = log_choice;
        }

        void adminMenu(string adminID, string adminPassword)
        {
            string choice, type;

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            do
            {
                auto currentTime = chrono::system_clock::now();
                time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);
                tm* currentTM = localtime(&currentTimeT);

                cout << "================================================================" << endl;
                cout << "|                  WELCOME ADMIN [" << TC.y << EAV.getID() << TC.w << "]                  |" << endl;
                cout << "================================================================" << endl;
                cout << "|                       Date : " << TC.g << (currentTM->tm_year + 1900) << '-' 
                     << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << TC.w << "                       |" << endl;
                cout << "================================================================" << endl;
                cout << "|            WHAT SERVICES YOU WISH TO HAVE TODAY ?            |" << endl;
                cout << "================================================================" << endl;
                cout << "|                      [1] -- EDIT ADMIN                       |" << endl;
                cout << "|                      [2] -- EDIT PRICE                       |" << endl;
                cout << "================================================================" << endl;
                cout << "|                      [3] -- ADD ADMIN                        |" << endl;
                cout << "================================================================" << endl;
                cout << "|                      [4] -- VIEW USER                        |" << endl;
                cout << "|                      [5] -- VIEW ADMIN                       |" << endl;
                cout << "================================================================" << endl;
                cout << "|                 YOU MAY ENTER " << TC.y << "[6]" << TC.w << " TO GO BACK                 |" << endl;
                cout << "================================================================" << endl << endl;
                cout << " PLEASE ENTER YOUR CHOICE --> ";
                cin >> choice;


                if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6")
                {
                    system("cls");
                    cout << TC.r << "INVALID INPUT..... PLEASE ENTER 1 TO 6 ONLY....." << TC.w << endl;
                }

            } while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6");

            if(choice == "1")
            {
                type = "[1] -- EDIT ADMIN -- [1]";
                editAdmin(type);
            }
            else if(choice == "2")
            {
                type = "[2] -- EDIT PRICE -- [2]";
                cout << "YOUR CURRENT SERVICE : " << type << endl;
                editPrice(type, adminID, adminPassword);
            }
            else if(choice == "3")
            {
                system("cls");
                type = "[3] -- ADD ADMIN -- [3]";
                cout << "YOUR CURRENT SERVICE : " << type << endl;
                addAdmin(adminID, type, adminPassword);
            }
            else if(choice == "4")
            {
                type = "[4] -- VIEW USER -- [4]";
                viewUser(adminID, type, adminPassword);
            }
            else if(choice == "5")
            {
                type = "[5] -- VIEW ADMIN -- [5]";
                viewAdmin(adminID, type, adminPassword);
            }
            else if(choice == "6")
            {
                system("cls");
                main();
            }
            else
            {
                type = "Invalid";
            }        
        }

        void editAdmin(string type)
        {
            system("cls");
            string choice;
            string lines, newADMINID, newADMINPASSWORD;
            string ADMINID = EAV.getID();
            string ADMINPASSWORD = EAV.getPassword();
            AdminPage ap;

            cout << "YOUR CURRENT SERVICE : " << type << endl;
            cout << "================================================================" << endl;
            cout << "|                         | " << TC.y << "EDIT ADMIN" << TC.w << " |                       |" << endl;
            cout << "================================================================" << endl;
            cout << "| ADMIN ID       : " << TC.b << ADMINID << TC.w << "                                  |" << endl;
            cout << "| ADMIN PASSWORD : " << TC.b << ADMINPASSWORD << TC.w << "                                  |" << endl;
            cout << "================================================================" << endl;
            cout << "|      [1] EDIT ADMIN ID [2] EDIT ADMIN PASSWORD [3] EXIT      |" << endl;
            cout << "================================================================" << endl;
            cout << " ENTER YOUR CHOICE --> ";
            cin >> choice;

            cout << "================================================================" << endl;

            if(choice == "1")
            {
                cout << "\nENTER NEW ADMIN ID : ";
                cin.ignore();
                getline(cin, newADMINID);

                ifstream adminFile("adminData.txt");

                while(getline(adminFile, lines))
                {
                    string usr = lines.substr(0, lines.find(' '));
                    if(usr == newADMINID)
                    {
                        cout << TC.r << "\nADMIN NAME ALREADY EXISTS..... PLEANSE ENTER AGAIN....." << TC.w << endl;
                        system("pause");
                        system("cls");
                        ap.adminMenu(ADMINID, ADMINPASSWORD);
                    }
                }
                adminFile.close();

                if(newADMINID.length() != 10)
                {
                    cout << TC.r << "\nNEW ADMIN NAME MUST BE EXACTLY 10 CHARACTER !!!" << TC.w << endl;
                    system("pause");
                    system("cls");
                    ap.adminMenu(ADMINID, ADMINPASSWORD);
                }
                newADMINPASSWORD = ADMINPASSWORD;

                system("cls");
                cout << "================================================================" << endl;
                cout << "|                   UPDATED SUCCESSFULLY !!!                   |" << endl;
                cout << "================================================================" << endl;
                cout << "| OLD ADMIN ID : " << TC.g << ADMINID << TC.w << "                                   |" << endl;
                cout << "| NEW ADMIN ID : " << TC.g << newADMINID << TC.w << "                                   |" << endl;
                cout << "================================================================" << endl;

                
            }
            else if(choice == "2")
            {
                cout << "\nENTER NEW ADMIN PASSWORD : ";
                cin.ignore();
                getline(cin, newADMINPASSWORD);

                if(newADMINPASSWORD.length() != 10)
                {
                    cout << TC.r << "\nNEW ADMIN PASSWORD MUST BE EXACTLY 10 CHARACTER !!!" << TC.w << endl;
                    system("pause");
                    system("cls");
                    ap.adminMenu(ADMINID, ADMINPASSWORD);
                }
                newADMINID = ADMINID;

                system("cls");
                cout << "================================================================" << endl;
                cout << "| UPDATED SUCCESSFULLY !!! |" << endl;
                cout << "================================================================" << endl;
                cout << "| OLD ADMIN PASSWORD : " << TC.c << ADMINPASSWORD << TC.w << "                               |" << endl;
                cout << "| NEW ADMIN PASSWORD : " << TC.c << newADMINPASSWORD << TC.w << "                               |" << endl;
                cout << "================================================================" << endl;
            }
            else if(choice == "3")
            {
                system("cls");
                ap.adminMenu(ADMINID, ADMINPASSWORD);
            }
            else
            {
                cout << TC.r << "\nINVALID INPUT..... PLEASE ENTER 1, 2 OR 3 ONLY....." << TC.w << endl;
                system("pause");
                system("cls");
                ap.adminMenu(ADMINID, ADMINPASSWORD);
            }

            string line;
            vector<string> lines_2;
            ifstream fread("adminData.txt");
            while(getline(fread, line))
            {
                lines_2.push_back(line);
            }
            fread.close();

            for(string &CurrentLines : lines_2)
            {
                size_t pos = CurrentLines.find(ADMINID + " " + ADMINPASSWORD);
                if(pos != string::npos)
                {
                    CurrentLines = newADMINID + " " + newADMINPASSWORD;
                    break;
                }
            }
            ofstream fwrite("adminData.txt");
            for(const string &CurrentLine : lines_2)
            {
                fwrite << CurrentLine <<endl;
            }
            fwrite.close();
            EAV.setData(newADMINID, newADMINPASSWORD);
            cout << TC.g << "\nADMIN INFORMATION UPDATED !!!" << TC.w << endl;
            system("pause");
            system("cls");
            ap.adminMenu(ADMINID, ADMINPASSWORD);

        }   

        void editPrice(string type, string adminIDs, string adminPasswords)
        {
            system("cls");
            string lineNum;
            int intLineNum;
            double amt;
            const string price = "price.txt";
            vector<pair<char, string>> amount = readDataFromFile(price);

            initial:

            do
            {
                cout << "YOUR CURRENT SERVICE : " << type << endl;
                cout << "================================================================" << endl;
                cout << "|                         | " << TC.y << "EDIT PRICE" << TC.w << " |                       |" << endl;
                cout << "================================================================" << endl;
                cout << "| FOR YOUR INFORMATION,   |                                    |" << endl;
                cout << "|                         | ---------------------------------- |" << endl;
                cout << "| [" << TC.s << "T" << TC.w << "] -- " << TC.p << "TRANSPORT" << TC.w << "        |                                    |" << endl;
                cout << "| [" << TC.s << "E" << TC.w << "] -- " << TC.b << "EVENT" << TC.w << "            |   YOU MAY FOLLOW THE " << TC.c << "KEYWORD" << TC.w << " TO    |" << endl;
                cout << "| [" << TC.s << "M" << TC.w << "] -- " << TC.y << "MEAL" << TC.w << "             |        DETERMINE THE SERVICE       |" << endl;
                cout << "| [" << TC.s << "V" << TC.w << "] -- " << TC.g << "VEGGIE" << TC.w << "           |                                    |" << endl;
                cout << "| [" << TC.s << "H" << TC.w << "] -- " << TC.v << "HOMEWORK SUPPORT" << TC.w << " | ---------------------------------- |" << endl;
                cout << "================================================================" << endl;

                cout << endl;

                for(size_t i = 0; (i < amount.size() - 1); i++)
                {
                    cout << "\n[---------------------------]|[" << TC.s << "0" << i+1 << TC.w << "]|[---------------------------]\n" << endl;
                    cout << "TYPE      : [" << TC.b << amount[i].first << TC.w << "]" << endl;
                    cout << "PRICE     : -- " << TC.y << "RM " << fixed << setprecision(2) << amount[i].second << TC.w << " --\n";
                }

                cout << "\n[YOU CAN ENTER 1-5 TO EDIT OR [R] TO RETURN BACK]" << endl;
                cout << "ENTER THE TYPE NUMBER THAT YOU WANT TO EDIT FOR --> 0";
                cin >> lineNum;

                if(lineNum == "R")
                {
                    system("cls");
                    adminMenu(adminIDs, adminPasswords);
                }
                
                if(!(all_of(lineNum.begin(), lineNum.end(), ::isdigit)))
                {
                    cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
                    system("pause");
                    system("cls");
                    adminMenu(adminIDs, adminPasswords);
                }
                
                intLineNum = stoi(lineNum);

                if(intLineNum < 1 || (static_cast<int>(intLineNum) > static_cast<int>(amount.size()) - 1))
                {
                    cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID NUMBER...\n" << TC.w << endl;
                }
                else
                {
                    do
                    {
                        cout << "ENTER THE NEW PRICE --> RM ";
                        cin.ignore();
                        getline(cin, newAmount);

                        if(!isNumeric(newAmount))
                        {
                            cout << TC.r << "YOU MUST ENTER NUMERIC CHARACTER.....\n" << TC.w << endl;
                        }
                        else
                        {
                            amt = stod(newAmount);

                            if (amt < 0)
                            {
                                cout << TC.r << "NO NEGATIVE VALUE ALLOWED.....\n" << TC.w << endl;
                            }
                        }

                    } while(!isNumeric(newAmount) || amt < 0);

                    if(!(newAmount.find(".") != string::npos))
                    {
                        newAmount = newAmount + ".00";
                    }
                    else
                    {
                        size_t decimalPos = newAmount.find(".");
                        size_t numDecimalPlaces = newAmount.length() - decimalPos - 1;
                        if (numDecimalPlaces != 2)
                        {
                            cout << "\nTHE FORMAT MUST BE [XX.XX]....." << endl;
                            system("pause");
                            system("cls");
                            goto initial;

                        }
                    }

                        amount[intLineNum - 1].second = newAmount;
                        writeDataToFile(price, amount);

                        cout << TC.g << "UPDATED SUCCESSFULY!!!\n" << TC.w << endl;
                }

                isGoBack = goBack();

                if(isGoBack)
                {
                    adminMenu(adminIDs, adminPasswords);
                }

            } while(intLineNum < 1 || (static_cast<int>(intLineNum) > static_cast<int>(amount.size()) - 1));
        }

        void addAdmin(string adminIDs, string type, string adminPasswords)
        {
            string yesNo, lines;

            do
            {
                cout << "================================================================" << endl;
                cout << "|                         | " << TC.y << "ADD ADMIN" << TC.w << " |                        |" << endl;
                cout << "================================================================" << endl;
                cout << "|  TO ADD, ENTER THE NEW" << TC.r << " ID" << TC.w 
                     << " AND" << TC.r << " PASSWORD" << TC.w << " IN ONLY 10 CHARACTER  |" << endl;
                cout << "================================================================" << endl;
                cout << "|                     ENTER [" << TC.y << "*" << TC.w << "] TO GO BACK                     |" << endl;
                cout << "================================================================" << endl;

                cout << "PLEASE ENTER THE NEW ADMIN ID : ";
                cin >> newAdminID;

                if(newAdminID == "*")
                {
                    cout << endl;

                    isGoBack = goBack();

                    if(isGoBack)
                    {
                        adminMenu(adminIDs, adminPasswords);
                    }
                }

                cout << "PLEASE ENTER THE NEW ADMIN PASSWORD : ";
                cin >> newAdminPassword;

                ifstream fread("adminData.txt");
                while(getline(fread, lines))
                {
                    string adm = lines.substr(0, lines.find(' '));
                    if(adm == newAdminID)
                    {
                        cout<<"\nADMIN NAME ALREADY EXISTS..... PLEASE ENTER ANOTHER ID....."<<endl;
                        fread.close();
                        system("pause");
                        system("cls");
                        adminMenu(adminIDs, adminPasswords);
                    }
                }
                fread.close();

                if(newAdminID.length() != 10 || newAdminPassword.length() != 10)
                {
                    system("cls");
                    cout << TC.r << "INVALID INPUT... PLEASE FOLLOW THE INSTRUCTION...\n" << TC.w << endl;
                    cout << "YOUR CURRENT SERVICE : " << type << endl;
                }
                else
                {
                    system("cls");
                    cout << "IS THE INFORMATION CORRECT?" << endl;
                    cout << "-------------------------------------------" << endl;
                    cout << "ADMIN ID       : " << newAdminID << endl;
                    cout << "ADMIN PASSWORD : " << newAdminPassword << endl;
                    cout << "-------------------------------------------" << endl;
                    cout << "YES [Y] | NO [N] --> ";
                    cin >> yesNo;
                    yesNo[0] = toupper(yesNo[0]);

                    if(yesNo == "N")
                    {
                        system("cls");
                        cout << "YOUR CURRENT SERVICE : " << type << endl;
                    }
                    else
                    {
                        ofstream addNewAdmin("adminData.txt", ios::app);

                        addNewAdmin << newAdminID << " " << newAdminPassword << endl;

                        cout << TC.g << "\nNEW ADMIN ADDED !!!" << TC.w << endl;

                        addNewAdmin.close();

                        isGoBack = goBack();

                        if(isGoBack)
                        {
                            adminMenu(adminIDs, adminPasswords);
                        }
                    }
                }

            } while((newAdminID.length() != 10 || newAdminPassword.length() != 10) || yesNo == "N");
        }

        void viewUser(string adminIDs, string type, string adminPasswords)
        {
            system("cls");
            int i = 0, count = 0;
            string yesNo, keyword;
            ifstream viewU("userData.txt");

            cout << "YOUR CURRENT SERVICE : " << type << endl;
            cout << "================================================================" << endl;
            cout << "|                         | " << TC.y << "VIEW USER" << TC.w << " |                        |" << endl;
            cout << "================================================================" << endl;
            cout << "|" << TC.g << "  THIS IS THE LIST OF THE ACTIVE USERS THAT UNDER THE RECORD" << TC.w << "  |" << endl;
            cout << "================================================================" << endl;

            while(viewU >> userID >> userPassword)
            {
                cout << "|                          " << userID << "                          |" << endl;
                i++;
            }

            cout << "================================================================\n" << endl;

            cout << "TOTAL NUMBER OF USERS --> " << TC.r << i << TC.w << " PERSONS\n" << endl;

            cout << "DO YOU WANT TO " << TC.g << "SEARCH" << TC.w << " FOR ANY USER ? [Y|N] --> ";
            cin >> yesNo;

            yesNo[0] = toupper(yesNo[0]);

            if(yesNo == "Y")
            {
                cout << "ENTER THE " << TC.o << "KEYWORD" << TC.w << " YOU WISH TO SEARCH --> ";
                cin.ignore();
                getline(cin, keyword);

                system("cls");

                cout << "================================================================" << endl;
                cout << "                           : " << TC.c << "RESULTS" << TC.w << " :                          " << endl;
                cout << "================================================================" << endl;

                viewU.clear();
                viewU.seekg(0, ios::beg);

                while(viewU >> userID >> userPassword)
                {
                    size_t found = userID.find(keyword);
                    
                    if(found != string::npos)
                    {
                        cout << "|                          " << userID << "                          |" << endl;
                        count++;
                    }
                }

                cout << "================================================================\n" << endl;

                cout << "THE KEYWORD [" << TC.r << keyword << TC.w << "] WAS FOUND " << count << " TIMES.\n" << endl;

                viewU.close();

                isGoBack = goBack();
            
                if(isGoBack)
                {
                    adminMenu(adminIDs, adminPasswords);
                }
            }
            else if(yesNo == "N")
            {
                isGoBack = goBack();
            
                if(isGoBack)
                {
                    adminMenu(adminIDs, adminPasswords);
                }
            }
            else
            {
                viewU.close();
                cout << TC.r << "INVALID INPUT... PLEASE KEY-IN \"Y\" OR \"N\" ONLY...\n" << TC.w << endl;
                system("pause");
                system("cls");
                adminMenu(adminIDs, adminPasswords);
            }
        }

        void viewAdmin(string adminIDs, string type, string adminPasswords)
        {
            system("cls");
            int i = 0, count = 0;
            string yesNo, keyword;
            ifstream viewA("adminData.txt");

            cout << "YOUR CURRENT SERVICE : " << type << endl;
            cout << "================================================================" << endl;
            cout << "|                         | " << TC.y << "VIEW ADMIN" << TC.w << " |                       |" << endl;
            cout << "================================================================" << endl;
            cout << "|" << TC.g << "    THIS IS THE LIST OF THE ADMIN ID THAT UNDER THE RECORD" << TC.w << "    |" << endl;
            cout << "================================================================" << endl;

            while(viewA >> adminID >> adminPassword)
            {
                cout << "|                          " << adminID << "                          |" << endl;
                i++;
            }

            cout << "================================================================\n" << endl;

            cout << "TOTAL NUMBER OF ADMIN --> " << TC.r << i << TC.w << " PERSONS\n" << endl;

            cout << "DO YOU WANT TO " << TC.g << "SEARCH" << TC.w << " FOR ANY USER ? [Y|N] --> ";
            cin >> yesNo;

            yesNo[0] = toupper(yesNo[0]);

            if(yesNo == "Y")
            {
                cout << "ENTER THE " << TC.o << "KEYWORD" << TC.w << " YOU WISH TO SEARCH --> ";
                cin.ignore();
                getline(cin, keyword);

                system("cls");

                cout << "================================================================" << endl;
                cout << "                           : " << TC.c << "RESULTS" << TC.w << " :                          " << endl;
                cout << "================================================================" << endl;

                viewA.clear();
                viewA.seekg(0, ios::beg);

                while(viewA >> userID >> userPassword)
                {
                    size_t found = userID.find(keyword);
                    
                    if(found != string::npos)
                    {
                        cout << "|                          " << userID << "                          |" << endl;
                        count++;
                    }
                }

                cout << "================================================================\n" << endl;

                cout << "THE KEYWORD [" << TC.r << keyword << TC.w << "] WAS FOUND " << count << " TIMES.\n" << endl;

                viewA.close();

                isGoBack = goBack();
            
                if(isGoBack)
                {
                    adminMenu(adminIDs, adminPasswords);
                }
            }
            else if(yesNo == "N")
            {
                isGoBack = goBack();
            
                if(isGoBack)
                {
                    adminMenu(adminIDs, adminPasswords);
                }
            }
            else
            {
                cout << TC.r << "INVALID INPUT... PLEASE KEY-IN \"Y\" OR \"N\" ONLY...\n" << TC.w << endl;
                system("pause");
                system("cls");
                adminMenu(adminIDs, adminPasswords);
            }
        }
};

vector<pair<char, string>> AdminPage::readDataFromFile(const string& filename)
{
    vector<pair<char, string>> data;

    ifstream priceData(filename);

    char typeName;
    string total;

    while (priceData >> typeName >> total)
    {
        data.emplace_back(typeName, total);
    }

    priceData.close();

    return data;
}



void AdminPage::writeDataToFile(const string& filename, const vector<pair<char, string>>& data)
{
    ofstream outputFile(filename);

    for (const auto& entry : data)
    {
        outputFile << entry.first << ' '  << entry.second << endl;
    }
}

bool AdminPage::isNumeric(const string& str)
{
    return ::all_of(str.begin(), str.end(), [](char c)
    {return ::isdigit(c) || c == '.';}) && ::count(str.begin(), str.end(), '.') <= 1;
}


class UserPage : public BaseUser
{
    private:

        string line, selectedService;
        char choice, correct, confirm, payment;
        int childNum, line_count = 0;
        ChildrenInfo* childArry;
    
    public:

        ChildrenInfo CI;

        void user_menu(string UserID, string Password)
        {
            system("cls");

            auto currentTime = chrono::system_clock::now();

            time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);

            tm* currentTM = localtime(&currentTimeT);

            do
            {
                cout << TC.g << UserID << TC.w;
                cout << "\t\t\t " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "+           SUNDAY DAYCARE CENTER         +" << endl;
                cout << "+       IS VERY PLEASED TO SERVE YOU!     +" << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
                cout << "    [A] ADD YOUR CHILDREN INFO & SERVICE   " << endl;
                cout << "    [B] SELECT THE SERVICES                " << endl;
                cout << "    [C] PAYMENT                            " << endl;
                cout << "    [D] SEE YOUR PROFILE                   " << endl;
                cout << "    [E] LOGOUT AND GO BACK                 " << endl << endl;
                cout << "WHAT DO YOU NEED TODAY? : ";
                cin >> choice;

                choice = toupper(choice);

                if(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E')
                {
                    system("cls");
                    cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w;
                }

            } while(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E');

            switch(choice)
            {
                case 'A':

                    system("cls");

                    while(true)
                    {
                        cout << TC.g << UserID << TC.w;
                        cout << "\t\t\t " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                        cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
                        cout << "+        CHILD INFO REGISTER STATION      +" << endl;
                        cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
                        cout << "HOW MANY CHILDREN YOU WANT TO ADD? [ENTER 0 TO RETURN] : ";

                        if(cin >> childNum) 
                        {
                            if(childNum == 0) 
                            {
                                system("cls");
                                user_menu(UserID, Password);
                            } 
                            else if(childNum > 0 && childNum <= 10)
                            {
                                break;
                            }
                            else if(childNum > 10 || childNum < 0)
                            {
                                system("cls");
                                cout << TC.r << "SORRY, WE CANNOT SUPPORT MORE THAN 10 AND LESS THAN 0 CHILDREN." << TC.w << endl << endl;
                                continue;
                            }
                        } 
                        else 
                        {
                            cin.clear();
                            cin.ignore();
                            system("cls");
                            cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A NUMBER...\n" << TC.w;
                        }
                    }

                    childArry = new ChildrenInfo[childNum];
                    
                    for(int i = 0; i < childNum;)
                    {
                        do
                        {
                            system("cls");
                            cout << TC.g << UserID << TC.w;
                            cout << "\t\t\t " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                            cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
                            cout << "+        CHILD INFO REGISTER STATION      +" << endl;
                            cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
                            cout << "ENTER THE INFO OF CHILDREN " << i + 1 << endl;

                            childArry[i].childInfo();

                            if(childArry[i].age <= 4 || childArry[i].age > 12)
                            {
                                cout << TC.r << "THE CHILDREN ABOVE 12 AND BELOW 5 ARE NOT ALLOWED. SORRY FOR THE INCONVENIENCE" << TC.w << endl;
                                system("pause");
                            }

                        }while(childArry[i].age <= 4 || childArry[i].age > 12);    

                        do
                        {
                            cout << TC.g << UserID << TC.w;
                            cout << "\t\t\t " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                            cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
                            cout << "+        CHILD INFO REGISTER STATION      +" << endl;
                            cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
                            cout << "CHILD NAME     : " << childArry[i].childName << endl;
                            cout << "CHILD AGE      : " << childArry[i].age << endl;
                            cout << "PARENT NAME    : " << childArry[i].parentName << endl;
                            cout << "CONTACT NUMBER : " << childArry[i].contactNum << endl;
                            cout << "HOME ADDRESS   : " << childArry[i].address << endl;

                            cout << "ARE THESE INFO CORRECT? (THE INFO WILL BE SAVED) [Y/N] : ";
                            cin >> correct;

                            correct = toupper(correct);

                            if(correct == 'Y')
                            {
                                string filename = UserID + ".txt";

                                ofstream userDetail(filename, ios::app);

                                userDetail << childArry[i].childName << "_" << childArry[i].age << "_" << childArry[i].parentName << "_" << childArry[i].contactNum << "_" << childArry[i].address << endl;

                                if (userDetail.good()) 
                                {
                                    cout << "Information saved successfully to file." << endl;
                                } 
                                else 
                                {
                                    cout << "Error saving information to file." << endl;
                                }

                                system("pause");

                                userDetail.close();

                                i++;
                            }
                            else if(correct == 'N')
                            {
                                system("cls");

                                cout << TC.r << "PLEASE ENTER AGAIN" << TC.w << endl;
                            }
                            else 
                            {
                                system("cls");
                                cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
                            }

                        }while(correct != 'Y' && correct != 'N');
                    }

                    delete[] childArry;

                    user_menu(UserID, Password);

                    break;

                case 'B':

                    system("cls");

                    select_services(UserID, Password);

                    break;

                case 'C':

                    system("cls");

                    payment_check(UserID, Password);

                    break;

                case 'D':

                    profile(UserID, Password);
                    
                    break;

                case 'E':

                    system("cls");

                    main();

                    break;
                
                default:

                    system("cls");

                    cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;

                    break;
            }
        }

        void select_services(string UserID, string Password)
        {
            auto currentTime = chrono::system_clock::now();

            time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);

            tm* currentTM = localtime(&currentTimeT);

            string filename = UserID + ".txt";

            ifstream Service2(filename);

            if(Service2.peek() == ifstream::traits_type::eof())
            {
                cout << TC.r << "YOU SHOULD ADD YOUR CHILD FIRST" << TC.w << endl;

                system("pause");

                system("cls");

                user_menu(UserID, Password);
            }

            Service2.close();

            ifstream Service("service_menu.txt");

            ifstream UserDetail(filename);

            do
            {
                ReTry:
                cout << TC.g << UserID << TC.w;
                cout << "\t\t\t        " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                cout << "===============================================" << endl;
                cout << "                 SERVICES CENTER               " << endl;
                cout << "===============================================" << endl;

                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                string line;

                while(getline(Service, line)) 
                {
                    cout << line << endl;
                }

                while(getline(UserDetail, line))
                {
                    line_count++;
                }

                string service[line_count];

                UserDetail.clear(); 
                UserDetail.seekg(0, ios::beg); 

                childArry = new ChildrenInfo[line_count];

                for(int i = 0; i < line_count && getline(UserDetail, childArry[i].childName, '_') && (UserDetail >> ws >> childArry[i].age >> ws, UserDetail.ignore(numeric_limits<streamsize>::max(), '_')) && getline(UserDetail >> ws, childArry[i].parentName, '_') && getline(UserDetail >> ws, childArry[i].contactNum, '_') && getline(UserDetail >> ws, childArry[i].address); i++)
                {
                    do
                    {
                        cout << endl;

                        cout << "SELECT THE SERVICE FOR YOUR CHILDREN " << i+1 << " " << childArry[i].childName << " (ENTER [S] TO SKIP [*] TO RETURN) : ";
                        getline(cin, service[i]);

                        if(service[i] == "*")
                        {
                            system("cls");

                            UserDetail.close();

                            user_menu(UserID, Password);
                        }
                        else if(service[i].find_first_not_of("TtEeMmVvHhSs *") != std::string::npos)
                        {
                            system("cls");

                            cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w;

                            bool hasDuplicate = false;

                            for (size_t pos1 = 0; pos1 < service[i].length() - 1; ++pos1)
                            {
                                for (size_t pos2 = pos1 + 1; pos2 < service[i].length(); ++pos2)
                                {
                                    if (service[i][pos1] == service[i][pos2])
                                    {
                                        hasDuplicate = true;
                                        break;
                                    }
                                }

                                if (hasDuplicate)
                                {

                                    break;
                                }
                            }

                            if (hasDuplicate) 
                            {
                                cout << TC.r << "INVALID INPUT... PLEASE KEY-IN EACH SERVICE ONLY ONCE...\n" << TC.w;
                            }

                            Service.clear(); 
                            Service.seekg(0, ios::beg);

                            cout << TC.g << UserID << TC.w;
                            cout << "\t\t\t        " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                            cout << "===============================================" << endl;
                            cout << "                 SERVICES CENTER               " << endl;
                            cout << "===============================================" << endl;

                            while(getline(Service, line)) 
                            {
                                cout << line << endl;
                            }

                            cout << endl;
                        }

                    }while(service[i].find_first_not_of("TtEeMmVvHhSs *") != std::string::npos);
                }

                cout << endl;
                cout << "ARE THESE SELECTION CORRECT? (THE INFO WILL BE SAVED) [Y/N] : ";
                cin >> confirm;

                confirm = toupper(confirm);

                if(confirm == 'Y')
                {
                    ofstream Record("record.txt");

                    for(int j = 0; j < line_count; j++)
                    {
                        Record << childArry[j].childName << "_" << childArry[j].age << "_" << childArry[j].parentName << "_" <<  childArry[j].contactNum << "_" << childArry[j].address << "_" << service[j] << endl;
                    }

                    cout << TC.g << "THE INFO IS SUCCESSFULLY RECORDED!" << TC.w << endl;

                    RETRY:

                        cout << "DO YOU WANT TO GO FOR PAYMENT? [Y/N] (YOU CAN ALSO GO TO [C] PAYMENT TO PAY) : ";
                        cin >> payment;

                        payment = toupper(payment);

                        if(payment == 'Y')
                        {
                            UserDetail.close();

                            system("cls");

                            payment_check(UserID, Password);
                        }
                        else if(payment == 'N')
                        {
                            UserDetail.close();

                            system("cls");

                            user_menu(UserID, Password);
                        }
                        else
                        {
                            goto RETRY;
                        }

                    UserDetail.close();

                    Record.close();
                }
                else if(confirm == 'N')
                {
                    system("cls");

                    Service.clear(); 
                    Service.seekg(0, ios::beg); 

                    goto ReTry;
                }

            }while(confirm != 'Y' && confirm != 'N');

            cout << endl;

            delete[] childArry;

            Service.close();

            UserDetail.close();

            user_menu(UserID, Password);
        }

        void payment_check(string UserID, string Password)
        {
            string choice;

            auto currentTime = chrono::system_clock::now();

            time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);

            tm* currentTM = localtime(&currentTimeT);

            do
            {
                cout << TC.g << UserID << TC.w;
                cout << "\t\t\t      " << (currentTM->tm_year + 1900) << '-' << (currentTM->tm_mon + 1) << '-' << currentTM->tm_mday << endl;
                cout << "===============================================" << endl;
                cout << "                 PAYMENT CENTER                " << endl;
                cout << "===============================================" << endl << endl;
                cout << "              Enter '*' to go back.            " << endl << endl;
                cout << "                 [1] - PAY NOW                 " << endl;
                cout << "           [2] - CHECK PAYMENT HISTORY         " << endl << endl;
                cout << "WHAT DO YOU NEED TODAY? : ";
                cin >> choice;

                if(choice != "1" && choice != "2" && choice != "*")
                {
                    system("cls");

                    cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
                }

            }while(choice != "1" && choice != "2" && choice != "*");

            if(choice == "1")
            {
                int line_count = 0;
                int t_count = 0;
                int e_count = 0;
                int m_count = 0;
                int v_count = 0;
                int h_count = 0;
                int s_count = 0;

                ifstream Record2("record.txt");

                if(Record2.peek() == ifstream::traits_type::eof())
                {
                    cout << TC.r << "YOU NEED TO ADD THE SERVICE FIRST" << TC.w << endl;

                    system("pause");

                    system("cls");

                    user_menu(UserID, Password);
                }

                Record2.close();

                ifstream Record("record.txt");

                while(getline(Record, line))
                {
                    line_count++;
                }

                string service_selected[line_count];

                childArry = new ChildrenInfo[line_count];

                Record.clear(); 
                Record.seekg(0, ios::beg);

                for(int i = 0; i < line_count && getline(Record, childArry[i].childName, '_') && (Record >> ws >> childArry[i].age >> ws, Record.ignore(numeric_limits<streamsize>::max(), '_')) && getline(Record >> ws, childArry[i].parentName, '_') && getline(Record >> ws, childArry[i].contactNum, '_') && getline(Record >> ws, childArry[i].address, '_') && getline(Record >> ws, service_selected[i]); i++)
                {
                    string currentService = service_selected[i];

                    t_count += count(currentService.begin(), currentService.end(), 'T') + count(currentService.begin(), currentService.end(), 't');
                    e_count += count(currentService.begin(), currentService.end(), 'E') + count(currentService.begin(), currentService.end(), 'e');
                    m_count += count(currentService.begin(), currentService.end(), 'M') + count(currentService.begin(), currentService.end(), 'm');
                    v_count += count(currentService.begin(), currentService.end(), 'V') + count(currentService.begin(), currentService.end(), 'v');
                    h_count += count(currentService.begin(), currentService.end(), 'H') + count(currentService.begin(), currentService.end(), 'h');
                    s_count += count(currentService.begin(), currentService.end(), 'S') + count(currentService.begin(), currentService.end(), 's');
                }

                Calculation CN(t_count, e_count, m_count, v_count, h_count, s_count);

                CN.get_total();

                CN.display_total(UserID);

                CN.receipt_generate(UserID, Password);

                CN.receipt_display(UserID);

                system("pause");

                user_menu(UserID, Password);
            }
            else if(choice == "2")
            {
                string filename = UserID + "Receipt.txt";

                ifstream DisplayReceipt(filename);

                if (!DisplayReceipt.good()) 
                {
                    int countdownSeconds = 3;

                    for (int i = countdownSeconds; i > 0; --i) 
                    {
                        cout << "FILE NOT FOUND. RETURNING" << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                    }

                    DisplayReceipt.close();

                    system("cls");

                    payment_check(UserID, Password);
                }
                else if(DisplayReceipt.good())
                {
                    cout << DisplayReceipt.rdbuf() << endl;
                    system("pause");

                    DisplayReceipt.close();

                    user_menu(UserID, Password);
                }
            }
            else if(choice == "*")
            {
                user_menu(UserID, Password);
            }

            delete[] childArry;
        }

        void profile(string UserID, string Password)
        {
            string question;

            string filename = UserID + ".txt";

            ifstream Profile2(filename);

            if(Profile2.peek() == ifstream::traits_type::eof())
            {
                cout << "THE PROFILE IS NOW EMPTY" << TC.w << endl;
                
                system("pause");

                system("cls");

                user_menu(UserID, Password);
            }

            Profile2.close();

            ifstream Profile(filename);
            
            do
            {
                system("cls");
                cout << "===============================================" << endl;
                cout << "                      PROFILE                 " << endl;
                cout << "===============================================" << endl;
                cout << TC.y << "            YOUR ID : " << UserID << TC.w << endl;

                string line;

                while(getline(Profile, line))
                {
                    line_count++;
                }

                string service_selected[line_count];

                Profile.clear();
                Profile.seekg(0, ios::beg);

                childArry = new ChildrenInfo[line_count];

                for(int i = 0; i < line_count && getline(Profile, childArry[i].childName, '_') && (Profile >> ws >> childArry[i].age, "_") && getline(Profile >> ws, childArry[i].parentName, '_') && getline(Profile >> ws, childArry[i].parentName, '_') && getline(Profile >> ws, childArry[i].contactNum, '_') && getline(Profile >> ws, childArry[i].address); i++)
                {
                    cout << "\n\t    CHILD " << i+1 << "(AGE " << childArry[i].age << ")" << endl;
                    cout << "\t    CHILD NAME     : " << childArry[i].childName << endl;
                    cout << "\t    PARNET NAME    : " << childArry[i].parentName << endl;
                    cout << "\t    CONTACT NUMBER : " << childArry[i].contactNum << endl;
                    cout << "\t    ADDRESS        : " << childArry[i].address << endl << endl;
                }

                cout << "DO YOU WANT TO RENEW YOUR PROFILE? [Y/N]: ";
                cin >> question;

                if((question != "Y" && question != "y") && (question != "N" && question != "n"))
                {
                    system("cls");
                    cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
                }
                
            }while((question != "Y" && question != "y") && (question != "N" && question != "n"));

            if(question == "Y" || question == "y")
            {
                string edit;

                do
                {
                    system("cls");
                    cout << "===============================================" << endl;
                    cout << "                      PROFILE                 " << endl;
                    cout << "===============================================" << endl;
                    cout << TC.y << "            YOUR ID : " << UserID << TC.w << endl;

                    Profile.clear();
                    Profile.seekg(0, ios::beg);

                    for(int i = 0; i < line_count && getline(Profile, childArry[i].childName, '_') && (Profile >> ws >> childArry[i].age >> ws, Profile.ignore(numeric_limits<streamsize>::max(), '_')) && getline(Profile >> ws, childArry[i].parentName, '_') && getline(Profile >> ws, childArry[i].contactNum, '_') && getline(Profile >> ws, childArry[i].address); i++)
                    {
                        cout << "\n\t    CHILD " << i+1 << "( AGE " << childArry[i].age << ")" << endl;
                        cout << "\t    CHILD NAME     : " << childArry[i].childName << endl;
                        cout << "\t    PARNET NAME    : " << childArry[i].parentName << endl;
                        cout << "\t    CONTACT NUMBER : " << childArry[i].contactNum << endl;
                        cout << "\t    ADDRESS        : " << childArry[i].address << endl << endl;
                    }

                    cout << "WHAT DO YOU WANT TO EDIT? [1]-> EDIT ID AND PASSWORD [2]-> ERASE THE CHILD FILE : ";
                    cin >> edit;

                    if(edit != "1" && edit != "2")
                    {
                        system("cls");

                        cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
                    }

                }while(edit != "1" && edit != "2");

                if(edit == "1")
                {
                    Profile.close();

                    system("cls");
                    cout << "===============================================" << endl;
                    cout << "                      PROFILE                 " << endl;
                    cout << "===============================================" << endl;
                    cout << "            YOUR CURRENT ID : " << TC.y << UserID << TC.w << endl;
                    cout << "            YOUR CURRENT PASSWORD : " << TC.y << Password << TC.w << endl;

                    ifstream inputFile("userData.txt");

                    string line;
                    stringstream updatedFileData;

                    while(getline(inputFile, line))
                    {
                        stringstream ss(line);
                        string fileID;
                        string filePassword;

                        if(ss >> fileID >> filePassword)
                        {
                            if(fileID == UserID && filePassword == Password)
                            {
                                cout << endl;
                                cout << "MATCH FOUND : " << line << endl << endl;

                                string newID, newPassword;

                                do
                                {   
                                    cout << "ENTER YOUR NEW ID : ";
                                    cin >> newID;
                                    cout << "ENTER YOUR NEW PASSWORD : ";
                                    cin >> newPassword;

                                    if(newID.length() != 10 && newPassword.length() != 10)
                                    {
                                        cout << TC.r << "\nINVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
                                    }

                                }while(newID.length() != 10 && newPassword.length() != 10);

                                updatedFileData << newID << " " << newPassword;

                                string oldFile = UserID + ".txt";
                                string newFileName = newID + ".txt";
                                string oldReceipt = UserID + "Receipt.txt";
                                string newReceipt = newID + "Receipt.txt";

                                if(rename(oldFile.c_str(), newFileName.c_str()) != 0) 
                                {
                                    cerr << "Error renaming file. Error code: " << errno << " - " << strerror(errno) << endl;
                                    system("pause");
                                    system("cls");

                                    user_menu(UserID, Password);
                                }

                                if(rename(oldReceipt.c_str(), newReceipt.c_str()) != 0)
                                {
                                    cerr << "Error renaming recp. Error code: " << errno << " - " << strerror(errno) << endl;
                                    system("pause");
                                    system("cls");

                                    user_menu(UserID, Password);
                                }
    
                                cout << TC.g << "THE FILES NAME HAS CHANGED. PLEASE LOGIN AGAIN" << TC.w << endl;
                                system("pause");
                                system("cls");

                            }
                            else
                            {
                                updatedFileData << line << endl;
                            }

                            if (!inputFile.eof()) 
                            {
                                updatedFileData << endl;
                            }
                            
                        }
                    }

                    ofstream Delete_Record("record.txt", ios::trunc);

                    Delete_Record.close();

                    ofstream outputFile("userData.txt");

                    outputFile << updatedFileData.str();

                    outputFile.close();

                    inputFile.close();

                    main();
                }
                else if(edit == "2")
                {
                    string con;

                    do
                    {
                        system("cls");
                        cout << "===============================================" << endl;
                        cout << "                      PROFILE                 " << endl;
                        cout << "===============================================" << endl;
                        cout << "WARNING !!! THIS CHOICE WILL CLEAR ALL YOUR CHILD DATA YOU SAVED, CONTINUE? [Y/N] : ";
                        cin >> con;

                        if(con != "Y" && con != "y" && con != "N" && con != "n")
                        {
                            system("cls");

                            cout << TC.r << "INVALID INPUT... PLEASE KEY-IN A VALID VALUE..." << TC.w << endl;
                        }

                    }while(con != "Y" && con != "y" && con != "N" && con != "n");

                    if(con == "Y")
                    {
                        filename = UserID + ".txt";

                        ofstream Cover(filename, ios::trunc);

                        Cover.close();

                        cout << "THE FILES HAS BEEN REMOVE...";

                        system("pause");

                        system("cls");

                        user_menu(UserID, Password);
                    }
                    else if(con == "N")
                    {
                        cout << "RETURN TO THE USER PAGE...";

                        system("pause");

                        system("cls");

                        user_menu(UserID, Password);
                    }
                }

            }
            else if(question == "N" || question == "n")
            {
                user_menu(UserID, Password);
            }

            delete[] childArry;

            Profile.close();
        }
};

class Register : public BaseUser
{
    private: 

        string filename;

    public:

        void getData()
        {
            do
            {
                cout << "===========================================================" << endl;
                cout << "                       USER REGISTER                       " << endl;
                cout << "===========================================================\n" << endl;
                cout << "                   Enter '*' to go back.                   \n" << endl;
                cout << "===========================================================" << endl;
                cout << "          YOUR ID & PASSWORD MUST BE 10 CHARACTER          " << endl;
                cout << "===========================================================\n" << endl;

                getUserCredentials();

                if(userID.length() != 10 || password.length() != 10)
                {
                    system("cls");
                    cout << TC.r << "       INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
                }
                else
                {
                    ofstream userData("userData.txt", ios::app);

                    userData << userID << " " << password << endl;

                    filename = userID + ".txt";

                    ofstream userDetail(filename, ios::app);

                    if(userData)
                    {
                        cout << TC.g << "\nREGISTER SUCCESSFULLY!!!" << TC.w << endl;
                        userData.close();
                        system("pause");
                        system("cls");
                        main();
                    }

                    userData.close();
                    userDetail.close();
                }

            } while(userID.length() != 10 || password.length() != 10);
        }
};

class Login : public BaseUser
{
    public:

        UserPage UP;
        AdminPage AP;
        bool loginSuccessful;
        

        void userLogin(string chooseLogin)
        {
            string USERID, USERPASSWORD, ADMINID, ADMINPASSWORD, loginType;

            if(chooseLogin == "1")
            {
                system("CLS");
                loginType = "USER LOGIN";
            }
            else if(chooseLogin == "2")
            {
                system("CLS");
                loginType = "ADMIN LOGIN";
            }

            do
            {
                cout << "===========================================================" << endl;
                cout << "                         " << loginType << endl;
                cout << "===========================================================\n" << endl;
                cout << "                   Enter '*' to go back.                   " << endl << endl;
                
                
                if(chooseLogin == "1")
                {
                    getUserCredentials();

                    if(userID.length() != 10 && password.length() != 10)
                    {
                        system("cls");
                        cout << TC.r << "         YOUR ID & PASSWORD MUST BE 10 CHARACTER\n" << TC.w << endl;
                    }
                    else
                    {
                        ifstream userData("userData.txt");

                        loginSuccessful = false;

                        while(userData >> USERID >> USERPASSWORD)
                        {
                            if (userID == USERID && password == USERPASSWORD)
                            {
                                loginSuccessful = true;
                                break;
                            }
                        }

                        if(loginSuccessful)
                        {
                            cout << TC.g << "\nLOGIN SUCCESSFULLY!!!" << TC.w << endl;
                            system("pause");
                            system("cls");

                            int iterations = 20;

                            cout << "Hello " << userID << " ! Welcome to Sunday Daycare Center " << endl;

                            for(int i = 0; i <= iterations; i++)
                            {
                                int percentage = static_cast<int>((static_cast<double>(i) / iterations) * 100);
                                cout << TC.g << "Loading : " << percentage << " %" << TC.w ;
                                this_thread::sleep_for(chrono::milliseconds(100));
                                cout << "\r";
                            }

                            userData.close();

                            UP.user_menu(userID, password);
                        }
                        else
                        {
                            cout << endl;
                            cout << TC.r << "THE USER ID OR THE PASSWORD ARE INVALID... PLEASE TRY AGAIN." << TC.w << endl;
                            system("pause");
                            userLogin(chooseLogin);
                        }

                        userData.close();
                    }

                }
                else if(chooseLogin == "2")
                {
                    getAdminCredentials();

                    if(adminID.length() != 10 && adminPassword.length() != 10)
                    {
                        system("cls");
                        cout << TC.r << "         YOUR ID & PASSWORD MUST BE 10 CHARACTER\n" << TC.w << endl;
                    }
                    else
                    {
                        ifstream admin("adminData.txt");

                        loginSuccessful = false;


                        while(admin >> ADMINID >> ADMINPASSWORD)
                        {
                            if(adminID == ADMINID && adminPassword == ADMINPASSWORD)
                            {
                                loginSuccessful = true;
                                break;
                            }
                        }

                        if(loginSuccessful)
                        {
                            cout << TC.g << "\nLOGIN SUCCESSFULLY!!!" << TC.w << endl;
                            system("pause");
                            system("cls");
                            EAV.setData(adminID, adminPassword);
                            AP.adminMenu(adminID, adminPassword);

                        }
                        else
                        {
                            cout << endl;
                            cout << TC.r << "THE ADMIN ID OR THE PASSWORD ARE INVALID... PLEASE TRY AGAIN." << TC.w << endl;
                            system("pause");
                            userLogin(chooseLogin);
                        }

                        admin.close();
                    }
                }

            } while((userID.length() != 10 || password.length() != 10) && (adminID.length() != 10 || adminPassword.length() != 10));            
        }
};

bool goBack()
{
    char key;

    cout << "DEAR ADMIN, YOU MAY PRESS " << TC.y << "[ESC]" << TC.w << " TO GO BACK...";

    do
    {
        key = _getch();

    } while (key != 27);

    system("cls");
    return true;
}

bool isNumeric(const string& str)
{
    std::istringstream ss(str);
    double value;
    ss >> value;
    return !ss.fail() && ss.eof();
}

int main()
{
    Register User;
    Login uLg, aLg;

    string option, loginType, chooseLogin;

    do
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "=========================================================" << endl;
        cout << "   CHOOSE YOUR OPTION [1] REGISTER [2] LOGIN [3] EXIT    " << endl;
        cout << "=========================================================\n" << endl;
        cout << "                      YOUR OPTION : ";
        getline(cin, option);
    

        system("cls");

        if(option != "1" && option != "2" && option != "3")
        {
            system("cls");
            cout << TC.r << "     INVALID INPUT... PLEASE KEY-IN A VALID VALUE...\n" << TC.w << endl;
        }
        else if(option == "1")
        {
            system("cls");
            User.getData();
        }
        else if(option == "2")
        {   
            do
            {
                cout << "=========================================================" << endl;
                cout << "          CHOOSE YOUR LOGIN [1] USER [2] ADMIN           " << endl;
                cout << "=========================================================\n" << endl;
                cout << "                   Enter '*' to go back\n" << endl;
                cout << "                      YOUR OPTION : ";
                getline(cin, chooseLogin);

                if(chooseLogin != "1" && chooseLogin != "2" && chooseLogin != "*")
                {
                    system("cls");
                    cout << TC.r << "     INVALID INPUT... PLEASE ENTER A VALID VALUE...\n" << TC.w << endl;
                }
                else if(chooseLogin == "*")
                {
                    system("cls");
                    main();
                }

            } while(chooseLogin != "1" && chooseLogin != "2");
            
            AdminPage AP;

            AP.getLogin_choice(chooseLogin);

            uLg.userLogin(chooseLogin);
        }
        else if(option == "3")
        {
            system("cls");
            cout << TC.g <<  "THANK YOU FOR USING THE SYSTEM..... HAVE A NICE DAY....." << TC.w;
            exit(0);
        }

    } while(option != "1" && option != "2");
}