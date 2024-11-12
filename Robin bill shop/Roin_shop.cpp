
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <fstream>


using namespace std;



typedef struct
{
    int price[1000];
    string robin_stuff[100000];
    string date;
    int choose;
    int calculate;
    int amount[1000];

}Robin_stuff;


typedef struct
{
    int price;
    string staff_name;

}data_user;

typedef struct
{
    string robin_stuff;

}Show_manu_board;

void bill_end(Robin_stuff* Robin_stuff , ofstream& file);

void bill_create(Robin_stuff* Robin,ofstream& file);

void bill_sign(data_user* user, ofstream& file);

void Bill_show_manu(Show_manu_board * Draw_manu, ofstream& file);

void bill_end_create(ofstream& file);

Robin_stuff robin;

data_user user;

Show_manu_board list;


int main()
{

     ofstream file("Robin_bill.txt");
    if (!file.is_open())
    {
        cout << "Failed to open file" << endl;
        return(1);

    }

    cout << "Enter your costumer name  = " << "\t";

    cin >> user.staff_name;

    file << "Costumer name = " << user.staff_name << std::endl;

    cout << "Date = " << "\t";

    cin >> robin.date;

    file << "Date = " << robin.date << std::endl;



   Bill_show_manu(&list , file);

   bill_sign(&user , file);

   bill_create(&robin , file);

   bill_end_create(file);
       
   file.close();

   return(0);
}


void bill_create(Robin_stuff* Robin , ofstream& file)
{
    cout << "choose number of stuff = " << "\t";
    cin >> Robin->choose;

    for (int i = 0; i < Robin->choose ; i++)
    {
        cout << "Enter stuff = " << "\t";
        cin >> Robin->robin_stuff[i];
        file << "stuff name = " << Robin->robin_stuff[i] << "\t" << std::endl;

        cout << "Enter price = " << "\t";
        cin >> Robin->price[i];
        file << "price = " << Robin->price[i] << "\t" << std::endl;

        cout << "amount stuff = " << "\t";
        cin >> Robin->amount[i];
        file << "Amount of stuff = " << Robin->amount[i] << "\t" << std::endl;
        Robin->calculate += Robin->price[i] * Robin->amount[i] + 7 / 100;
        

    }

    bill_end(&robin , file);
}

void bill_sign(data_user* user, ofstream& file)
{

    cout << "___________________________" << "\r\n";

    file << "___________________________" << "\r\n" << std::endl;

    cout << "Welcome To Robin love Nana shop" << "\r\n";

    file << "Welcome To Robin love Nana shop" << "\r\n" << std::endl;

    cout << "___________________________" << "\r\n";

    file << "___________________________" << "\r\n" << std::endl;
}
void bill_end(Robin_stuff* Robin_stuff , ofstream& file)
{

    cout << "______________________________________________________" << "\r\n";

    file << "______________________________________________________" << "\r\n" << std::endl;

    cout << "Total price = " << Robin_stuff->calculate  << "\r\n";

    file << "Total price = " << Robin_stuff->calculate << "\r\n" << std :: endl;

    cout << "______________________________________________________" << "\r\n";

    file << "______________________________________________________" << "\r\n" << std::endl;
}


void Bill_show_manu(Show_manu_board* Draw_manu, ofstream& file)
{
    cout << "____________________ ROBIN MANU ____________________"  << "\r\n";

    file << "____________________ ROBIN MANU ____________________" << "\r\n" << std::endl;


    cout << "       *****MANU*****       " << "\r\n";
    file << "       *****MANU*****       " << "\r\n" << std::endl;

    cout << "1. Robin backpack cost = 20 dollar" << "\r\n";
    file << "1. Robin backpack cost = 20 dollar" << "\r\n" << std::endl;

    cout << "2. Robin T-shirt cost = 100 dollar" << "\r\n";
    file << "2. Robin T-shirt cost = 100 dollar" << "\r\n" << std::endl;

    cout << "3. Robin Earphone cost = 150 dollar" << "\r\n";
    file << "3. Robin Earphone cost = 150 dollar" << "\r\n" << std::endl;

    cout << "4. Robin pen cost = 10 dollar" << "\r\n";
    file << "4. Robin pen cost = 10 dollar" << "\r\n" << std::endl;

    cout << "5. Robin smart watch = 90 dollar" << "\r\n";
    file << "5. Robin smart watch = 90 dollar" << "\r\n" << std::endl;


}

void bill_end_create(ofstream& file)
{
    cout << "___________________________" << "\r\n";
    file << "___________________________" << "\r\n" << std::endl;

    cout << "Thank you for visiting Robin love Nana shop" << "\r\n";
    file << "Thank you for visiting Robin love Nana shop" << "\r\n" << std::endl;

    cout << "___________________________" << "\r\n";
    file << "___________________________" << "\r\n" << std::endl;
}