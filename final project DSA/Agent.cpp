#include "pch.h"
#include "Admin.cpp"

using namespace std;

class cAgent
{

public:
	cAgent Solve(cQueue & Agent1,cQueue &Admin)
	{
		string Ans;
		int flag = 0;															//flag to handle empty case
		cNode * ptr = Agent1.AnswerQuery(flag);
		if (flag == 0)															//if queue is not empty 
		{	
		cout << "Give Answer to this Question:" << endl << ptr->getQuestion() << endl;
		cin.ignore();
		getline(cin, Ans);
		ptr->setAnswer(Ans);													//setting Answer
		ptr->setStatus("Solved");												//changing Status

		cNode * n1 = Admin.search(ptr->getId(), flag);							//Setting the main queue
		if (flag == 1)
		{
			cout << " ID is invalid" << endl;
		}
		else
		{
			n1->setAnswer(ptr->getAnswer());									//Setting Answer in the main queue
			n1->setStatus(ptr->getStatus());
		}
		}

		return *this;
	}

	cAgent view(cQueue & Agent)
	{
		Agent.print();										//To SEE THE MAIN Queue 
		return *this;
	}


	bool checkAgentPass(string username, string password)           //this is used in order to load the courses
	{
		string usersList[7];
		string passwordsList[7];
		int c = 0;
		ifstream ufile("agent.txt");               //this will open the text file
		if (ufile)								  //Until EOF Character if found
		{
			string uname, pass, line1;				
			while (getline(ufile, line1))        //getting a single line from the file
			{
				stringstream ss(line1);			//breaking the line to get user name and password
				getline(ss, uname, ',');
				getline(ss, pass, ',');
				usersList[c] = uname;            ///reading from file and storing in array
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

};