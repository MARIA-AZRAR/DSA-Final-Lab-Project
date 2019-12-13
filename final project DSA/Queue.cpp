#include "pch.h"
#include<iostream>
#include<string>

using namespace std;

class cNode
{
	string question;
	string answer;
	int id;
	string status;
public:
	
	cNode * next;
	cNode() :next(NULL)
	{
		status = "open";
		status = "Still Not Answered";
	}
	cNode(int ID, string ques) : id(ID), question(ques) { }

	string getQuestion() const
	{
		return question;
	}
	string getAnswer() const
	{
		return answer;
	}
	string getStatus() const
	{
		return status;
	}
	int getId() const
	{
		return id;
	}

	cNode &setQuestion(string question) {
		this->question = question;
		return *this;
	}

	cNode &setAnswer(string answer) {
		this->answer = answer;
		return *this;
	}

	cNode &setId(int id) {
		this->id = id;
		return *this;
	}

	cNode &setStatus(string status) {
		this->status = status;
		return *this;
	}

	void print() const {
		cout << "Id: " << id << endl;
		cout << "Question: " << question << endl;
		cout << "Answer: " << answer << endl;
		cout << "Status: " << status << endl;
	}
};

class cQueue {

	cNode * top;
	cNode *tail;
public:
	int count;
	cQueue() :tail(NULL), top(NULL), count(0) {}

	cQueue(cNode * &ptr)
	{
		top = ptr;
		tail = top;
		top->next = NULL;
		ptr = NULL;
		++count;
	}

	bool isNotEmpty() const {
		if (top)
			return true;
		else
			return false;
	}
	bool isEmpty() const {
		if (top)
			return false;
		else
			return true;
	}

	cNode * getTop()
	{
		return top;
	}

	cNode * Remove()
	{
		if (isNotEmpty())
		{
			if (top->next)
			{
				cNode *ptr;
				ptr = top;
				top = top->next;
				ptr->next = NULL;
				--count;
				return ptr;
			}
			else
			{
				cNode * ptr;
				ptr = top;
				top = top->next;
				ptr->next = NULL;
				tail = NULL;
				--count;
				return ptr;
			}

		}
		else
			cout << endl << "Queue is Empty" << endl;
	}

	cNode * RemoveAt(int &id)
	{
	//	int index = 0;
		
		cNode * ptr = top;
		if (isNotEmpty())
		{
			while (ptr)
			{
				if (ptr->getId() == id)
				{
					ptr->setStatus("Cancelled");
					return ptr;
					break;
				}
				else
				{
					ptr = ptr->next;
				}

			}
		}

	}

	cNode * AnswerQuery(int &flag)
	{
		if (isNotEmpty())
		{
			if (top->next)
			{
				cNode *ptr;
				ptr = top;
				top = top->next;
				ptr->next = NULL;
				--count;
				return ptr;
			}
			else
			{
				cNode * ptr;
				ptr = top;
				top = top->next;
				ptr->next = NULL;
				tail = NULL;
				--count;
				return ptr;
			}

		}
		else
		{
			flag = 1;
			cout << endl << "Queue is Empty" << endl;
		}
			
	}

	cQueue & Add(cNode * &ptr)
	{
		if (top)
		{
			tail->next = ptr;
			tail = tail->next;           //Now once its empty this will not work cuz top is pointing tward nothing
		}
		else
		{
			top = tail = ptr;
		}

		tail->next = NULL;
		ptr = NULL;
		++count;
		return *this;
	}
	void print()
	{
		cNode *ptr = top;
		if (isNotEmpty())
		{
			while (ptr)
			{
				ptr->print();
				ptr = ptr->next;
			}
		}
		else
			cout << "Queue is Empty" << endl;
	}

	void showAll()
	{
		cNode * ptr = top;
		cout << "   ID   |     Status     |          Question          |          Answer          " << endl;
		for (int i = 0; i < count; ++i)
		{
			cout<<"  " << ptr->getId() << "      " << ptr->getStatus() << "          " << ptr->getQuestion() << "    " << ptr->getAnswer() << endl;
			ptr = ptr->next;
		}
	}

	cNode * search(int ID, int &flag)
	{
		cNode * ptr = top;
		if (isNotEmpty())
		{
			while (ptr)
			{
				if (ptr->getId() == ID)
				{
					return ptr;
					break;
				}
				else
				{
					ptr = ptr->next;
				}

			}
		}
		flag = 1;
	}
	void pending()
	{
		cNode * ptr = top;
		if (isNotEmpty())
		{
			while (ptr)
			{
				//cout << "Ptr" << ptr->getStatus();
				if (ptr->getStatus() == "Open")
				{
					ptr->print();
					ptr = ptr->next;
				}
				else
				{
					ptr = ptr->next;
				}

			}
		}
	}
	cQueue(const cQueue &src)
	{
		top = src.top;
		tail = src.tail;
		count = src.count;
		if (src.top)
		{
			cNode *sptr, *dptr;
			dptr = top = new cNode(*(src.top));
			sptr = (src.top)->next;
			while (sptr)
			{
				dptr->next = new cNode(*sptr);
				dptr = dptr->next;
				sptr = sptr->next;
			}
			tail = dptr;
		}
	}
	~cQueue()
	{
		cout << "Destructor Called" << endl;
		cNode *ptr;
		ptr = top;          //we do this so that we can connect ptr to top to perform ptr=ptr->next
		while (ptr)
		{
			ptr = ptr->next;         //This will set ptr to one step next 
			delete top;
			top = ptr;
		}
	}
};