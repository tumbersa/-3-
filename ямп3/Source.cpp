//Дан кольцевой список, содержащий 20 фамилий игроков 
//футбольной команды. Разбить игроков на 2 группы по 10 человек.
//Во вторую группу попадает каждый n-й человек
#include <iostream>
#include <string> 
using namespace std;
struct Node
{
	string info;
	Node* prev ;
	Node* next ; 
};

Node* initList(string x) 
{
	Node* temp = new Node; 
	temp->info = x;
	temp->next = temp;
	temp->prev = temp;
	return temp;
}

void add(Node* p, string x) {
	Node* temp = initList(x);
	Node* q = p->prev;
	q->next = temp;
	temp->prev = q;
	temp->next = p;
	p->prev = temp;

}

void del(Node** p) {
	Node* q = *p;
	*p = (*p)->next;
	if (q != nullptr) {
		q->prev->next = q->next;
		q->next->prev = q->prev;
		q->prev = nullptr;
		q->next = nullptr;
		delete q;
	}
}

void print(Node* p) {
	Node* q = p;
	while (q != p->prev) {
		cout << q->info << " ";
		q = q->next;
	}
	cout << q->info << " ";
	cout << endl;
}

void choice(Node** p, int k, int count,Node*q)
{
	Node* temp = *p; bool f = 0;
	for (int i = 0; i < k/2 ; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			cout << temp->info << " " << i << " " << j << endl;
			temp = temp->next;

		}
		cout << temp->info << " " << i  << endl;
		
		if (f != 0) {
			 add(q, temp->info);
			 print(q);
		}
		f++;

		del(&temp);
	}
	*p = temp;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int k; string x;
	int count;
	cout << "Введите n-й элемент" << endl;
	cin >> count;
	cout << "Введите количество элементов" << endl;
	cin >> k;
	cout << "Введите имена" << endl;
	getline(cin, x);
	Node* p = initList(x);
	for (int i = 0; i < k - 1; i++) {
		getline(cin, x);

		add(p, x);
	}
	Node* temp = p;
	for (int j = 0; j < count - 1; j++)
	{
		cout << temp->info << " " << endl;
		temp = temp->next;

	}
	Node* q = initList(temp->info);
	print(p);
	choice(&p, k, count,q);
	cout << endl;
	print(p);
	cout << endl;
	print(q);
}

