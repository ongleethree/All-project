
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int age,your_age;
string gmail,password,username,phone_number;
string inform_text;

float ans;
float saraly,x,y,va;

void saveToCSV(const std::string textdata, const std::string& filename) {
	ofstream file;
	file.open(filename, std::ios::app);

	if (file.is_open()) {
		file << textdata << "\n";
		file.close();
		cout << "Data saved to " << filename << endl;
	}
	else {
		cerr << "Unable to open file " << filename << endl;
	}
}

int Login()
{
	cout << "your username is ==" << username << '\n';
	cin >> username;
	cout << "your password is ==" << password << '\n';
	cin >> password;

	return 0;
}
int information()
{
	cout << "write your gamail" << gmail<<'\n';
	cin >> gmail;
	cout << "your phone number is =" << phone_number << '\n';
	cin >> phone_number;

	cout << "enter your age =";
	cin >> age;
    
	if (age >= 18)
	{
		cout << "you you can sign in" << '\n';
	}
	else
	{
		cout << "you you can't sign in your age under 18" << '\n';
	}
	return 0;
}

float vat()
{
    cout << "enter your money=" << '\n';
	cin >> saraly;
	if (saraly >= 150000 && saraly <= 300000)
	{
		va=saraly * 5 / 100;
	}

	if (saraly >=300000 && saraly <= 500000)
	{
		va = saraly * 10 / 100;
	}

	if (saraly >= 500000 && saraly <= 750000)
	{
		va = saraly * 15 / 100;
	}
	else
	{
		va = saraly * 20 / 100;
	}
	cout << "your vat is=" << va << '\n';
	return(va);
}

int main()
{
	information();
	Login();
	vat();
	inform_text = gmail + "\t" + phone_number+ "\t" + std::to_string(age);
	//inform_text = inform_text+username + "\t" + password + "\t" +  "\r\n";
	inform_text += username + "\t" + password + "\t";

	saveToCSV(inform_text, "file.csv");
	return 0;
}