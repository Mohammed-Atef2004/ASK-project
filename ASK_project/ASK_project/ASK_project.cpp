# include<iostream>
# include<string>
#include <windows.h>
# include<fstream>
# include<iomanip>
# include<vector>
using namespace std;
class user
{
private:
	string username;
	string password;
	string f_name;
	string s_name;
	string id;
public:
	void setfirst_name(string f)
	{
		f_name = f;
	}
	void second_name(string s)
	{
		s_name = s;
	}
	void setuser_name(string u)
	{
		username = u;
	}
	void set_password(string p)
	{
		password = p;
	}
	void set_id(string i)
	{
		id = i;
	}
	string get_fname()
	{
		return f_name;
	}
	string get_sname()
	{
		return s_name;
	}
	string get_username()
	{
		return username;
	}
	string get_id()
	{
		return id;
	}
	string getpass()
	{
		return password;
	}
};
user a[100];
int i = 1;
int j = 0;
int fromnum = 0;
int cc = 0;
int index = 0;
int askc = 0;
int askin = 0;
struct op
{
	string from;
	string to;
	string qu;
	string answer;
};
op opp[100];
op oop[100];
void menu();
int main();
void answer();
void fill();
void askfill();
void askread();
void read();
void ask();
void com();
void from();
void to();
void delet();
void login();
void registeration()
{
	cout << "____________________________________________________________welcome to registeration page_______________________________________________________________________________\n";
	string s, f, u, id, p;
	cout << "please enter your first name\n";
flag:
	getline(cin, f);
	for (int i = 0; i < f.size(); i++)
	{
		if (isspace(f[i]) || ispunct(f[i]) || isdigit(f[i]))
		{
			cout << "your first name shouldn't contain digits or symbols or spaces\n";
			Sleep(1500);
			system("cls");
			cout << "please enter your first name again\n";
			goto flag;
		}
	}
	cout << "please enter your second name\n";
flag1:
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (isspace(s[i]) || ispunct(s[i]) || isdigit(s[i]))
		{
			cout << "second name shouldn't contain digits or sympols or spaces\n";
			Sleep(1500);
			system("cls");
			cout << "please enter your second name again\n";
			goto flag1;
		}
	}
	cout << "please enter your username\n";
flag2:
	getline(cin, u);
	for (int i = 0; i < u.size(); i++)
	{
		if (isspace(u[i]))
		{
			cout << "your username shouldn't contain digits or symbols or spaces\n";
			Sleep(1500);
			system("cls");
			cout << "please enter your username again\n";
			goto flag2;
		}
	}
	cout << "please enter your id\n";
flag3:
	getline(cin, id);
	if (id.size() != 3)
	{
		cout << "your id must be 3 digits only\n";
		Sleep(1500);
		system("cls");
		cout << "please enter your id again\n";
		goto flag3;
	}
	else
	{
		ifstream in("user.txt", ios::app);
		string s;
		while (in >> s)
		{
			if (i == 1)
			{

				a[j].setfirst_name(s);

				i++;
			}
			if (i == 2)
			{
				in >> s;
				a[j].second_name(s);
				i++;
			}
			if (i == 3)
			{
				in >> s;
				a[j].setuser_name(s);
				i++;
			}
			if (i == 4)
			{
				in >> s;
				a[j].set_id(s);
				i++;
			}
			if (i == 5)
			{

				in >> s;
				a[j].set_password(s);
				i = 1;

			}
			j++;
		}
		for (int i = 0; i < j; i++)
		{
			if (id == a[i].get_id())
			{
				cout << "this id is already exist\n";
				goto flag3;
			}
		}
		for (int i = 0; i < id.size(); i++)
		{
			if (isspace(id[i]) || ispunct(id[i]) || isalpha(id[i]))
			{
				cout << "your id shouldn't contain characters or symbols or spaces\n";
				Sleep(1500);
				system("cls");
				cout << "please enter your id again\n";
				goto flag3;
			}
		}
	}
	cout << "enter your password\n";
flag4:
	getline(cin, p);
	for (int i = 0; i < p.size(); i++)
	{
		if (isspace(p[i]))
		{
			cout << "your password shouldn't contain spaces\n";
			Sleep(1500);
			system("cls");
			cout << "please enter your password again\n";
			goto flag4;
		}
	}
	cout << "registeration completed\n";
	user customer;
	customer.setfirst_name(f);
	customer.second_name(s);
	customer.setuser_name(u);
	customer.set_password(p);
	customer.set_id(id);
	ofstream out("user file.txt", ios::app);
	out << customer.get_fname() << endl << customer.get_sname() << endl << customer.get_username() << endl << customer.get_id() << endl << customer.getpass() << endl << endl;
	main();
}
void login()
{
	ifstream in("user file.txt", ios::app);
	string s;
	while (in >> s)
	{
		if (i == 1)
		{

			a[j].setfirst_name(s);

			i++;
		}
		if (i == 2)
		{
			in >> s;
			a[j].second_name(s);
			i++;
		}
		if (i == 3)
		{
			in >> s;
			a[j].setuser_name(s);
			i++;
		}
		if (i == 4)
		{
			in >> s;
			a[j].set_id(s);
			i++;
		}
		if (i == 5)
		{

			in >> s;
			a[j].set_password(s);
			i = 1;

		}
		j++;
	}

	string u, p;
	cout << "enter your username\n";
flag:
	getline(cin, u);
	for (int i = 0; i < u.size(); i++)
	{
		if (isspace(u[i]))
		{
			cout << "your username shouldn't contain digits or symbols or spaces\n";
			Sleep(1500);
			system("cls");
			cout << "please enter your username again\n";
			goto flag;
		}
	}
	cout << "enter your password\n";
flag1:
	getline(cin, p);
	for (int i = 0; i < p.size(); i++)
	{
		if (isspace(p[i]))
		{
			cout << "your password shouldn't contain spaces\n";
			Sleep(1500);
			system("cls");
			cout << "please enter your password again\n";
			goto flag1;
		}
	}
	bool cp = 0;
	for (int i = 0; i < j; i++)
	{
		if (u == a[i].get_username() && p == a[i].getpass())
		{
			fromnum = i;
			cp = 1;
			cout << "\t\t\t\t\t\t\tthis is your account information\n";

			cout << "your user name is " << a[i].get_username() << "\n" << "your id is " << a[i].get_id() << endl << "__________________________________________________________________________________________________________\n";
			read();
			askread();
			com();
			menu();
		}
	}
	if (cp == 0)
	{
		cout << "invalid values please enter the right values\n";
		goto flag;
	}
}
int main()
{
	cout << "\t\t\t\t\twelcome to A.P.....the best place to find your answer about any thing related to programming \n1-register\n2-login\n3-logout\n";
	string ans;
flag:
	getline(cin, ans);
	if (ans.length() > 1 || ans[0] > '3' || ans[0] == '0')
	{
		cout << "invalid value please enter correct value\n";
		goto flag;
	}
	else
	{
		if (ans[0] == '1')
		{
			registeration();
		}
		else if (ans[0] == '2')
			login();
		else if (ans[0] == '3')
			exit;
	}
}
void menu()
{
	cout << "1-view all users in the system\n2-ask a question\n3-questions from me\n4-questions to me\n5-answer a question\n6-logout\n";
	string s;
flag:
	getline(cin, s);
	if (s.length() > 1 || s[0] > '7' || s[0] == '0')
	{
		cout << "invalid value please enter correct value\n";
		goto flag;
	}
	else
	{
		if (s[0] == '1')
		{
			for (int i = 0; i < j; i++)
			{
				cout << i + 1 << "-" << a[i].get_username() << "\twith id ( " << a[i].get_id() <<" )" << endl;
			}
			menu();
		}
		else if (s[0] == '2')
		{

			ask();
		}
		else if (s[0] == '3')
		{
			from();
		}
		else if (s[0] == '4')
		{
			to();
		}
		else if (s[0] == '5')
		{
			answer();
		}
		else if (s[0] == '6')
		{
			fill();
			main();
		}
	}
}
void ask()
{
	int n = 0;
	for (int i = 0; i < j; i++)
	{
		cout << "username " << i + 1 << "-" << a[i].get_username() << "\tid ( " << a[i].get_id() <<" ) " << endl;
		n = i;
	}
	cout << "please enter the id of the user you want to ask\n";
flag:
	string s;
	cin >> s;
	if (s == a[fromnum].get_id())
	{
		cout << "you can't ask yourself please try again\n";
		goto flag;
	}
	for (int i = 0; i < j; i++)
	{
		if (s == a[i].get_id())
		{
			opp[cc].to = a[i].get_username();
		}
	}
	cout << "enter your question\n";
	string ques;
	cin.ignore();
	getline(cin, ques);

	opp[cc].from = a[fromnum].get_username();
	opp[cc].qu = ques;
	opp[cc].answer = "empty";
	cc++;
	menu();

}
/*void delet()
{
	int c = 0;
	for (int i = 0; i < index; i++)
	{
		if (a[fromnum].get_username() == opp[i].from)
		{
			c++;

		}
	}

	if (c == 0)
	{
		cout << "there is no questions to delete\n";
		menu();
	}
	else
	{
		cout << "this is your questions\n";
		for (int i = 0; i < index; i++)
		{
			if (a[fromnum].get_username() == opp[i].from)
			{
				cout << opp[i].qu << endl << " to " << opp[i].to << endl;
				if (opp[i].answer == "empty")
				{
					cout << "not answered yet\n";
				}
				else cout << "answer is (" << opp[i].answer << " )" << endl;

				cout << "enter (1) to delete this question or anything else to continue\n";
				int n;
				cin >> n;
				if (n == 1)
				{
					opp[i].from = "empty";
					opp[i].to = "empty";
					opp[i].qu = "empty";
					opp[i].answer = "empty";
				}
				else continue;
			}
		}
	}
	fill();
	cin.ignore();
	menu();
	/*cout << "please enter the username of the other user to delete this question\n";
flag1:
	string aa;
	getline(cin, aa);
	bool ch = 0;
	int count = 0;
	for (int i = 0; i < index; i++)
	{
		if (aa == opp[i].to)
		{
			opp[i].from = "empty";
			opp[i].to = "empty";
			opp[i].qu = "empty";
			opp[i].answer = "empty";
			ch = 1;
			count++;
		}
	}
	if (ch == 0)
	{
		cout << "invalide value please enter a correct username\n";
		goto flag1;
	}
	if (count == 0)
	{
		cout << "sorry you don't have questions yet\n";
	}*/
void from()
{

	int counter = 0;
	for (int i = 0; i < index; i++)
	{
		if (a[fromnum].get_username() == opp[i].from)
		{
			if (opp[i].qu == "empty")
			{
				continue;
			}
			cout << "your question is (" << opp[i].qu << ")\tto user  (" << opp[i].to <<")"<< endl;
			if (opp[i].answer == "empty")
			{
				cout << "not answered yet\n";
			}
			else cout << opp[i].answer << endl;
			counter++;
		}
	}
	if (counter == 0)
		cout << "sorry you haven't asked yet\n";
	menu();
}
void to()
{
	int counter = 0;
	for (int i = 0; i < index; i++)
	{
		if (a[fromnum].get_username() == opp[i].to)
		{
			counter++;
			cout << "your question is " << opp[i].qu << "\tfrom user" << opp[i].from << endl;
			if (opp[i].answer == "empty")
			{
				cout << "not answered yet\n";
			}
			else cout << opp[i].answer << endl;

		}
	}
	if (counter == 0)
		cout << "sorry you haven't recieved any question yet\n";
	menu();
}
void fill()
{

	ofstream off("operation.txt",ios::app);
	for (int i = 0; i < cc; i++)
	{
		off << opp[i].from << endl << opp[i].to << endl << opp[i].qu << endl << opp[i].answer << endl;
	}
}
void read()
{
	int c = 1;
	ifstream inn("operation.txt",ios::app);
	string read;
	if (!inn)
	{
		cout << "can't";
		return;
	}
	else
	{
		while (inn)
		{
			if (c == 1)
			{
				getline(inn, read);
				opp[index].from = read;
				c++;
			}
			if (c == 2)
			{
				getline(inn, read);
				opp[index].to = read;
				c++;
			}
			if (c == 3)
			{
				getline(inn, read);
				opp[index].qu = read;
				c++;
			}
			if (c == 4)
			{
				getline(inn, read);
				opp[index].answer = read;
				c = 1;
			}
			index++;
		}
	}
}
void answer()
{
	op ooop[10];
	int j = 0;
	for (int i = 0; i < index; i++)
	{
		if (a[fromnum].get_username() == opp[i].to)
		{
			cout << j + 1 << "- the user (" << opp[i].from << ')' << "has asked you this question ( " << opp[i].qu << " )" << endl << " answer state is  :  " << opp[i].answer << endl;
			cout << "press 1- to answer this question\n2- to continue\n";
			int a;
			cin >> a;
			if (a == 1)
			{
				cout << "enter your answer \n";
				string ans;
				cin.ignore();
				getline(cin, ans);
				opp[i].answer = ans;
				ofstream off("ask.txt", ios::app);
				off << opp[i].from << endl << opp[i].to << endl << opp[i].qu << endl << opp[i].answer << endl;

			}
			else continue;
			j++;
		}
	}
	if (j == 0)
	{
		cout << "there are no questions yet\n";
		menu();
	}
	cin.ignore();
	menu();
}
void askfill()
{
	ofstream off("ask.txt", ios::app);
	off << oop[i].from << endl << oop[i].to << endl << oop[i].qu << endl << oop[i].answer << endl;
}
void askread()
{
	int c = 1;
	ifstream inn("ask.txt", ios::app);
	string read;
	if (!inn)
	{
		cout << "can't";
		return;
	}
	else
	{
		while (inn)
		{
			if (c == 1)
			{
				getline(inn, read);
				oop[askin].from = read;
				c++;
			}
			if (c == 2)
			{
				getline(inn, read);
				oop[askin].to = read;
				c++;
			}
			if (c == 3)
			{
				getline(inn, read);
				oop[askin].qu = read;
				c++;
			}
			if (c == 4)
			{
				getline(inn, read);
				oop[askin].answer = read;
				c = 1;
			}
			askin++;
		}
	}
}
void com()
{
	for (int i = 0; i < max(index, askin); i++)
	{
		for (int j = 0; j < max(index, askin); j++)
		{
			if (oop[i].from == opp[j].from && oop[i].to == opp[j].to && oop[i].qu == opp[j].qu)
			{
				opp[j].answer = oop[i].answer;
			}
		}
	}
}