
//Dwifi Parizza Ibrahim
//G1A021092

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *addToEmpty(struct Node *last, int data)
{
	// Function untuk list yang tidak tersedia
	if (last != NULL)
	return last;

	// Membuat sebuah node .
	struct Node *temp =
		(struct Node*)malloc(sizeof(struct Node));

	// Menambahkan data.
	temp -> data = data;
	last = temp;

	// Membuat link.
	last -> next = last;

	return last;
}

struct Node *addBegin(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	struct Node *temp =
			(struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;

	return last;
}

struct Node *addEnd(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);
	
	struct Node *temp =
		(struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;
	last = temp;

	return last;
}

struct Node *addAfter(struct Node *last, int data, int item)
{
	if (last == NULL)
		return NULL;

	struct Node *temp, *p;
	p = last -> next;
	do
	{
		if (p ->data == item)
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			temp -> data = data;
			temp -> next = p -> next;
			p -> next = temp;

			if (p == last)
				last = temp;
			return last;
		}
		p = p -> next;
	} while(p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;

}

void traverse(struct Node *last)
{
	struct Node *p;

	// Perkondisian jika list kosong,, maka akan kembali
	if (last == NULL)
	{
		cout << "List is empty." << endl;
		return;
	}

	// Pointing to first Node of the list.
	p = last -> next;

	// Traversing the list.
	do
	{
		cout << p -> data << " ";
		p = p -> next;

	}
	while(p != last->next);

}

// Menjalankan program
int main()
{
	struct Node *last = NULL;

	last = addToEmpty(last, 10);
	last = addBegin(last, 2);
	last = addBegin(last, 8);
	last = addEnd(last, 14);
	last = addEnd(last, 4);
	last = addAfter(last, 112, 6);

	traverse(last);

	return 0;
}
