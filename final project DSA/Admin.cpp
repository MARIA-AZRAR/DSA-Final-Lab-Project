#include "pch.h"
#include "Queue.cpp"
#include<fstream>         //to open file
#include<sstream>         //to input string from file

using namespace std;

class cAdmin
{

public:

	cAdmin& Assign(cQueue& Agent1, cQueue& Agent2, cQueue& temp, cQueue& amain)
	{
		if (temp.count > 0)							//Check if queue is not empty
		{
			cNode * ptr;
			for (int i = 0; i < amain.count; ++i)
			{
				ptr = temp.Remove();                //remove from temporary
				//
				
					if (Agent1.count >= Agent2.count)   //check if agent 1 or agent 2 have more items
					{
						Agent2.Add(ptr);				//giving it to agent array
					}
					else
					{
						Agent1.Add(ptr);
					}
					cout << endl << "Successfully Assigned to the respective Agents." << endl;
			}
		}
		else
		{
			cout << "Queue is Empty" << endl;
		}
		return *this;
	}
	cAdmin& Delete(int id, cQueue& amain)
	{
		amain.RemoveAt(id);

		return *this;						//cancelling a query
	}

	void viewAll(cQueue &Admin)
	{
		Admin.showAll();					//View all 
	}

	void viewPending(cQueue &Admin)
	{
		Admin.pending();
	}

	bool checkAdminPass(string username, string password)           //this is used in order to load the courses
	{
		string usersList[7];
		string passwordsList[7];
		int c = 0;
		ifstream ufile("Users.txt");               //this will open the text file
		if (ufile)
		{
			string uname, pass, line1;
			while (getline(ufile, line1))
			{
				stringstream ss(line1);
				getline(ss, uname, ',');
				getline(ss, pass, ',');
				usersList[c] = uname;
				passwordsList[c] = pass;
				c++;
				//counter for the users authorized to operate
			}
			ufile.close();
			for (int i = 0; i < c; i++)
			{
				if (usersList[i] == username && passwordsList[i] == password)
				{
					return 1;
				}

			}
			return 0;
		}
		else
		{
			cout << endl << "Sorry, we are unable to run the program, as user data does not exist." << endl;
		}
	}

	void SaveQueries(cQueue &admin)                 //used to save data in a file
	{
		ofstream outdata;
		cNode * ptr = admin.getTop();
		outdata.open("Data.txt");               //used to oppen the text file
		outdata << "  ID   " << "   Status   " << "             Question                 " << "              Answer              " << endl;
     	for (int i = 0; i < admin.count; ++i)
			{
				outdata <<"  "<< ptr->getId() << "      " << ptr->getStatus() << "                " << ptr->getQuestion() << "                " << ptr->getAnswer() << endl;
				ptr = ptr->next;
			}
		outdata.close();              //used to close the opened file
	}



};

