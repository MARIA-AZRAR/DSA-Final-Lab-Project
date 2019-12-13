#include "pch.h"
#include "Agent.cpp"

using namespace std;

class customer {


	cNode * Query;

public:

	customer AskQuestion(string Question, int &ID, cQueue & Admin, cQueue & Temp)
	{
		Query = new cNode();
		Query->setQuestion(Question);
		Query->setId(ID);                                                        //Adding in the main Admin Queue
		Query->setStatus("Open");
		Admin.Add(Query);
		//Now for secondry Queue

		Query = new cNode();
		Query->setQuestion(Question);
		Query->setId(ID);
		Query->setStatus("Open");												//Addition in the temporary queue
		Temp.Add(Query);
		++ID;
		return *this;
	}

	customer& viewStatus(int ID, cQueue &Admin)
	{

		int flag = 0;									//in case if ID is not found 
		cNode * n1 = Admin.search(ID, flag);            //to search the id in main queue
		if (flag == 1)
		{
			cout << " ID is invalid" << endl;			
		}
		else
		{
			cout << n1->getStatus() << endl;
		}
		return *this;
	}

	customer & viewAnswer(int ID, cQueue &Admin)
	{
		int flag = 0;
		cNode * n1 = Admin.search(ID, flag);
		if (flag == 1)
		{
			cout << " ID not found" << endl;				//in case if invalid id is given
		}
		else
		{
			cout << n1->getAnswer() << endl;
		}
		return *this;
	}
};