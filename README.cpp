#include<bits/stdc++.h>

using namespace std;

int main();

void washing_machine_machine();

class user
{
private:
    string username, password;
public:
    user(){}
    void create_new_account();
    bool isLoggedIn();
    void login();
};

class canteen
{
public:
    vector<int> product_num;
    vector<string> product_name;
    vector<float> prod_price;
public:
    void get_product_details();
    void show_product_details();
    void placeorder();
};

canteen can;

class service
{
private:
    string service_name;
public:
    void show_service_menu()
    {
        cout << "----------------WELCOME TO HALL SERVICE PAGE---------------------" << endl;
        cout<<"|   1) CANTEEN SERVICE                                           |"<<endl;
        cout<<"|   2) STORE SERVICE                                             |"<<endl;
        cout<<"|   3) WASHING MACHINE SERVICE                                   |"<<endl;
        cout<<"|----------------------------------------------------------------|"<<endl;
        cout<<"ENTER YOUR CHOICE(1-3): ";
        int choice;
        cin>>choice;
     switch(choice)
     {
   case 1:
  can.get_product_details();
  can.show_product_details();
  break;
   //case 2:


   case 3:
       washing_machine_machine();
       break;
  //break;

   //default:
  //cout<<"CHOICE NOT FOUND"<<endl;
}
    }
    void access_service()
    {

    }

};
service ser;

class order
{
private:
    int order_number;
public:
    void placeorder();
};
order ord;

void order:: placeorder()
{
    int x;
    float total_price = 0;
    char choice2;
    do
    {
        cout << "ENTER THE PRODUCT NUMBER YOU WANT TO ORDER: ";
        cin >> x;
        cout << can.product_num[x-1] << ":" << can.product_name[x-1] << " has been added to cart" << endl;
        total_price = total_price + can.prod_price[x-1];
        cout<<"DO WANT TO CONTINUE(y/n): ";
        cin >> choice2;
    }
     while(choice2=='y'||choice2=='Y');

     cout << "Your order has been placed!" << endl;
     cout << "Total cost: " << total_price << "taka" << endl;
}

void user :: create_new_account()
{
    cout << "----------------CREATE NEW ACCOUNT-----------------" << endl;
    cout << endl;
    cout << "SELECT USERNAME  : ";
    cin >> username;
    cout << "SELECT A PASSWORD: ";
    cin >> password;

    ofstream file;
    file.open(username + ".txt");
    file << username << endl << password;
    file.close();
    cout << "Welcome " << username << "!" << endl;

}

bool user :: isLoggedIn()
{
    string un, pw;

    cout << "ENTER A USERNAME: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void user :: login()
{
    bool status = isLoggedIn();

        if(!status)
        {
            cout << endl;
            cout << "Invalid login!" << endl;
            main();
        }
        else
        {
            cout << "Successfully logged in!" << endl;
            cout << endl;

            int choiceTwo;

            cout << "Welcome back!" << endl;

            ser.show_service_menu();
        }
}


void canteen::get_product_details()
{
    int i, n = 10;
    for(i = 0; i < n; i++)
    {
        product_num.push_back(i+1);
    }
    product_name = {"Full Rice", "Half Rice", "Biriyani", "Smashed Potato",
                    "Hilsha Fish", "Rohu Fish", "Lentil Curry","Egg Curry",
                    "Chicken Curry", "Egg Fry" };
    prod_price = {10, 5, 60, 5, 40, 30, 10, 20, 40, 20};

}

void canteen:: show_product_details()
{
    cout<<"======================= CANTEEN MENU =========================="<<endl;
    cout<<"PRODUCT" <<"\t\t" << "NAME OF" << "\t\t" << "        PRICE    "<<endl;
    cout<<"NUMBER " <<"\t\t" << "PRODUCT" << "\t\t" <<endl;
    cout<<"_______________________________________________________________"<<endl;
    int i;
    for(i = 0; i < 10; i++)
    {
        cout << product_num[i] << "\t\t" << product_name[i] << "\t\t" << prod_price[i] << endl;
    }
    cout << "1. PLACE AN ORDER" << endl;
    cout << "2. BACK TO THE SERVICE PAGE" << endl;
    int choice;
    cin >> choice;
    if(choice == 1)
        ord.placeorder();
    else if(choice == 2)
        ser.show_service_menu();
}

class WashingMachine {
private:
    int machineID;
    float usageFee;

public:
    WashingMachine(int id, float fee) : machineID(id), usageFee(fee) {}

    int getMachineID() const
    {
        return machineID;
    }

    float getUsageFee() const
    {
        return usageFee;
    }

    bool checkAvailability() const
    {
        return true;
    }

    void startWash() const
    {
        cout << "\nMachine " << machineID << " started washing. Usage fee: " << usageFee << " taka." << endl;
    }
};


void washing_machine_machine()
{
    vector<WashingMachine> washingMachines;

    for (int i = 1; i <= 5; ++i)  {
        WashingMachine machine(i, 50.0f);
        washingMachines.push_back(machine);
    }

    int choice;
    do {
        cout << "\nOptions:\n1. Check Washing Machine Availability\n2. Start Wash\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Available Washing Machines:\n" << endl;
                for (const WashingMachine& machine : washingMachines) {
                    cout << "Machine ID: " << machine.getMachineID() << " - Available" << endl;
                }
                break;
            }
            case 2: {
                cout << "\nEnter the machine ID to start washing: ";
                int machineID;
                cin >> machineID;

                bool found = false;

                for (const WashingMachine& machine : washingMachines) {
                    if (machine.getMachineID() == machineID) {
                        found = true;
                        if (machine.checkAvailability()) {
                            machine.startWash();
                        } else {
                            cout << "\nMachine " << machineID << " is currently in use." << endl;
                        }
                        break;
                    }
                }

                if (!found) {
                    cout << "\nInvalid machine ID. Please enter a valid ID." << endl;
                }
                break;
            }
            case 3:
                cout << "\nExiting program." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);
}

int main()
{
    user st;
    int choice;
     char choice2;
     cout<<"                     WELCOME TO MAIN MENU                   "<<endl;
     cout<<"|----------------------------------------------------------|"<<endl;
     do
     {
cout<<"|   1) LOG IN TO YOUR PROFILE                              |"<<endl;
cout<<"|   2) CREATE NEW ACCOUNT                   |"<<endl;
cout<<"|   3) APPLY FOR SEAT IF YOU'RE ALLOTED                    |"<<endl;
cout<<"|   4) TO EXIT                                             |"<<endl;
cout<<"|----------------------------------------------------------|"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>choice;
switch(choice)
{
        case 1:
                st.login();
                break;
case 2:
                st.create_new_account();
       break;
//case 3:
      // apply_for_seat();
                //break;
case 3:
                exit(0);
default:
       cout<<"INVALID CHOICE "<<endl;
 }
 cout<<"DO WANT TO CONTINUE(y/n): ";
 cin >> choice2;
     }
     while(choice2=='y'||choice2=='Y');
}

