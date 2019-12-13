#include "pch.h"
#include<fstream>         //to open file
#include<sstream>         //to input string from file
#include<cstring>	     //
#include<string.h>        //contain old string functions like strcpy
#include<stdlib.h>       //header of the general purpose library which includes functions involving memory allocation, process control,
#include<windows.h>
#include "customer.cpp"

using namespace std;
int main()
{
	system("color E0");
	cout << endl << endl << "\t\t\t*************Welcome to Query Management System**************" << endl;
	int choice, option; //To get choices from user
	string username, password, Answer, Question;			//variables to enter user name and password Answer and Question
	int identity;                                        //Local variable to ask for id 
	int ID = 10000;
	cQueue Agent1;                       //main queue for agent1
	cQueue Agent2;                       //main queue for agent2
	cQueue Admin;						//Admin queue
	cQueue temporary;                   //secondary Queue  
	cAdmin a1;
	cAgent ag1;
	cAgent ag2;
	customer c1;
	cNode * Query;                      //A single question node;

logout:

	cout << "Choose the option for Login" << endl << "1 for Admin" << endl << "2 for Agent" << endl << "3 for Customer" << endl << "Enter option:";
	cin >> choice;
	switch (choice)
	{

	case 1:
	{

		cout << endl << "Dear User, current software is intended for authorized users only." << endl;
		cout << "Login to the system to get access." << endl;

	again:

		cout << "Username : ";
		cin >> username;
		cout << "Password : ";
		cin >> password;
		if (a1.checkAdminPass(username, password))                     //used in order to give access to the user
		{
			cout << endl << "You have sucessfully logged into the system" << endl;

			while (1)                          //infinite loop so that user can exit according to his will
			{
				cout << "Choose the following option" << endl;
				cout << "1     Assign Query" << endl;
				cout << "2     Delete Query" << endl;
				cout << "3     View Pending" << endl;
				cout << "4     View All" << endl;
				cout << "5     Logout of the System" << endl;
				cout << "6     Exit Program" << endl;

				cout << "Choose the option:" << endl;

				cin >> choice;

				switch (choice)
				{

				case 1:
				{
					a1.Assign(Agent1, Agent2, temporary, Admin);
					
					break;
				}
				case 2:
				{
					cout << "Enter ID of Query You want to Delete" << endl;
					cin >> identity;
					a1.Delete(identity, Admin);
					break;
				}
				case 3:
				{
					a1.viewPending(Admin);
					break;
				}
				case 4:
				{
					a1.viewAll(Admin);
					break;
				}
				case 5:
				{
					goto logout;                   //in order to logout from system this will take us to the main
				}
				case 6:
				{
					a1.SaveQueries(Admin);
					return 0;                   //in order to exit program
				}

				default:
				{
					cout << "Enter valid option. " << endl;
					break;
				}
				}

			}

		}
		else
		{
			cout << endl << "Dear User, Username/password is incorrect. Enter the" << endl;
			cout << endl << "username/password again to get access to the system" << endl;
			goto again;
		}

	}

	case 2:
	{

		cout << endl << "Dear User, current software is intended for authorized users only." << endl;
		cout << "Login to the system to get access." << endl;

	again1:

		cout << "Username : ";
		cin >> username;
		cout << "Password : ";
		cin >> password;
		if (ag1.checkAgentPass(username, password))                     //used in order to give access to the user
		{
			cout << endl << "You have sucessfully logged into the system" << endl;
			while (1)                          //infinite loop so that user can exit according to his will
			{
				cout << "Choose the following option" << endl;
				cout << "1     Solve Queries" << endl;
				cout << "2     View" << endl;
				cout << "3     Logout of the System" << endl;
				cout << "4     Exit Program" << endl;

				cout << "Choose the option:" << endl;

				cin >> choice;

				switch (choice)
				{

				case 1:
				{
					cout << "Press 1 for Agent 1 " << endl << "Press 2 for Agent 2" << endl;
					cin >> option;
					if (option == 1)
					{
						ag1.Solve(Agent1, Admin);
					}
					else if (option == 2)
					{
						ag2.Solve(Agent2, Admin);
					}
					else
						cout << "Invalid input" << endl;

					break;
				}
				case 2:
				{
					cout << "Press 1 for Agent 1 " << endl << "Press 2 for Agent 2" << endl;
					cin >> option;
					if (option == 1)
					{
						ag1.view(Agent1);
					}
					else if (option == 2)
					{
						ag2.view(Agent2);
					}
					else
						cout << "Invalid input" << endl;

					break;
				}
				case 3:
				{
					goto logout;                   //in order to logout from system this will take us to the main
				}
				case 4:
				{
					return 0;                   //in order to exit program
				}

				default:
				{
					cout << "Enter valid option. " << endl;
					break;
				}
				}
			}
		}
		else
		{
			cout << endl << "Dear User, Username/password is incorrect. Enter the" << endl;
			cout << endl << "username/password again to get access to the system" << endl;
			goto again1;
		}

	}
	case 3:
	{

		cout << endl << "Welcome Dear Customer. We are here to help you. Enter any query." << endl;
		while (1)                          //infinite loop so that user can exit according to his will
		{
			cout << "Choose the following option" << endl;
			cout << "1     Any Questions?" << endl;
			cout << "2     View Status" << endl;
			cout << "3     Replies" << endl;
			cout << "4     Back" << endl;
			cout << "5     Exit Program" << endl;

			cout << "Choose the option:" << endl;

			cin >> choice;

			switch (choice)
			{

			case 1:
			{

				cout << "What is your Question?" << endl;
				cin.ignore();                                      //to ignore space endl from entering into the question
				getline(cin, Question);
				c1.AskQuestion(Question, ID, Admin, temporary);
				cout << endl << "Dear User ID Assigned to your Query is: " << ID - 1 << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Enter the ID of Query: ";
				cin >> identity;
				c1.viewStatus(identity, Admin);
				break;
			}
			case 3:
			{
				cout << "Enter the ID of Query you want to see the answer of: ";
				cin >> identity;
				c1.viewAnswer(identity, Admin);
				break;
			}
			case 4:
			{
				goto logout;                   //in order to logout from system this will take us to the main
			}
			case 5:
			{
				return 0;                   //in order to exit program
				break;
			}

			default:
			{
				cout << "Enter valid option. " << endl;
				break;
			}
			}
		}

	}

	}   //bracket for choice / switch login screen

	return 0;

}







