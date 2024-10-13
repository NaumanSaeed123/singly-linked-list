#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T info;
	Node<T>* next;
	Node()
	{
		next = nullptr;
	}
	Node(T val)
	{
		info = val;
		next = nullptr;
	}
};
template<typename T>
class LSLL
{
	Node<T>* head;
public:

	LSLL()
	{
		head = nullptr;
	}
	void insertAtHead(T val)
	{
		Node<T>* p = new Node<T>(val);
		p->next = head;
		head = p;
	}
	void insertAtTail(T val)
	{
		if (!head)
		{
			head = new Node<T>(val);
			return;
		}
		Node<T>* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Node<T>(val);
	}
	void insertAfter(T key, T val)
	{
		if (!head)
		{
			return;
		}
		Node<T>* p = head;
		while (p != nullptr && p->info != key)
		{
			p = p->next;
		}
		if (!p)
		{
			return;
		}
		Node<T>* x = new Node<T>(val);
		x->next = p->next;
		p->next = x;
	}

	void insertBefore(T key, T val)
	{
		if (!head)
		{
			return;
		}
		Node<T>* prev = head, * p = head->next;
		if (prev->info == key)
		{
			insertAtHead(val);
			return;
		}
		while (p != nullptr && p->info != key)
		{
			prev = p;
			p = p->next;
		}
		if (!p)
		{
			return;
		}
		Node<T>* x = new Node<T>(val);
		prev->next = x;
		x->next = p;
	}
	void remove(T key)
	{
		if (!head)
		{
			return;
		}
		Node<T>* prev = head, * p = head->next;
		if (prev->info == key)
		{
			removeAtHead();
			return;
		}
		while (p != nullptr && p->info != key)
		{
			prev = p;
			p = p->next;
		}
		if (!p)
		{
			return;
		}
		prev->next = p->next;
		delete p;
	}

	void removeAtHead()
	{
		if (!head)
		{
			return;
		}
		Node<T>* x = head;
		head = head->next;
		delete x;
	}
	void removeAtTail()
	{
		if (!head)
		{
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		Node<T>* prev = head, * p = head->next;
		while (p->next != nullptr)
		{
			prev = p->next;
			p = p->next;
		}
		prev->next = nullptr;
		delete p;
	}
	void removeAfter(T key)
	{
		if (!head || head->next == nullptr)
		{
			return;
		}
		Node<T>* p = head;
		while (p != nullptr && p->info != key)
		{
			p = p->next;
		}
		if (!p || p->next == nullptr)
		{
			return;
		}
		Node<T>* x = p->next;
		p->next = p->next->next;
		delete x;
	}
	void removeBefore(T key)
	{
		if (!head || head->next == nullptr)
		{
			return;
		}
		if (head->next->info == key)
		{
			removeAtHead();
			return;
		}
		Node<T>* p = head;
		while (p->next->next != nullptr && p->next->next->info != key)
		{
			p = p->next;
		}
		if (p->next->next == nullptr)
		{
			return;
		}
		Node<T>* x = p->next;
		p->next = p->next->next;
		delete x;
	}
	void printList()
	{
		Node<T>* p = head;
		while (p != nullptr)
		{
			cout << p->info << " : ";
			p = p->next;
		}
	}
	bool search(T key)
	{
		if (!head)
		{
			return false;
		}
		Node<T>* p = head;
		while (p != nullptr && p->info != key)
		{
			p = p->next;
		}
		if (p != nullptr && p->info == key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void delAlternate()
	{
		if (!head)
		{
			return;
		}
		Node<T>* curN = head;
		Node<T>* nextN;
		int i = 0;
		while (curN != nullptr)
		{
			nextN = curN->next;
			if (i == 1)
			{
				remove(curN->info);

			}
			curN = nextN;
			i == 0 ? i = 1 : i = 0;
		}
	}
	LSLL<T> createClone()
	{
		LSLL<T> list2;
		Node<T>* p = head;
		while (p != nullptr)
		{
			list2.insertAtTail(p->info);
			p = p->next;
		}
		return list2;
	}
	~LSLL()
	{
		while (head)
		{
			removeAtHead();

		}
	}
	
};

