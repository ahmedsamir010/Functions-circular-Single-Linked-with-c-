//اذا مررت من هنا فادعوا الله ان ييسر لي امري ويصلح لي شاني
#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
class circ {
private:
	node* last = NULL;
public:
	circ() { last = NULL; }
	void create(int value);
	void insertFirst(int value);
	void insertLast(int value);
	void display();
};
int main()
{
	circ c;
	c.insertLast(10);
	c.insertLast(20);
	c.insertLast(30);
	c.insertLast(40);
	c.insertLast(50);
	c.display();
	return 0;
}
void circ::create(int value)
{
	if (last != NULL)return;
	last = new node;
	last->data = value;
	last->next = last;
}
void circ::insertFirst(int value)
{
	if (last != NULL)
	{
		node* newNode = new node;
		newNode->data = value;
		newNode->next = last->next;
		last->next = newNode;
	}
	else {
		create(value);
		return;
	}
}
void circ::insertLast(int value)
{
	if (last == NULL) {
		create(value);
		return;
	}
	else {
		node* newNode = new node;
		newNode->data = value;
		newNode->next = last->next;
		last->next = newNode;
		last = newNode;
	}
}
void circ::display()
{
	if (last == NULL) {
		cout << "Circular Single Linked List is Empty" << endl;
		return;
	}
		node* temp = new node;
		temp = last->next;
		while (temp != last) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << last->data;
}
