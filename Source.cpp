#include"Header.h"
bool add(List** b)
{
	cout << "Input your file name:\t";
	char* fn = new char[30];
	cin >> fn;
	fstream din;
	din.open(fn);
	bool i = false;
	if (din.is_open())
	{
		i = true;
		int a = 0;
		char c[200];
		din >> c;
		din.close();
		istringstream in(c);
		while (in >> a && a == 0)
		{
			in.seekg(3, ios::cur);
			in >> a;
		}
		*b = new List;
		(*b)->nom = a;
		in.seekg(3, ios::cur);
		in >> (*b)->powe;
		(*b)->next = NULL;
		List* end = *b;
		while (in >> a) {
			if (a == 0) { in.seekg(3, ios::cur); in >> a; continue; }
			end->next = new List;
			end = end->next;
			end->nom = a;
			in.seekg(3, ios::cur);
			in >> end->powe;
			end->next = NULL;
		}
		return i;
	}
	else
	{
		cout << "File error !" << endl;
		return i;
	}
}

int Sum(List* b, int a)
{
	int sum = 0;
	while (b != NULL)
	{
		sum += b->nom * pow(a, b->powe);
		b = b->next;
	}
	return sum;
}

List* derivative(List* b) {
	List* d=NULL;
	List* c=NULL;
	while (b != NULL && b->powe == 0) {
		b = b->next;
		c = b;
	}
	b = c;
	d = new List;
	d->nom = (b)->nom * (b)->powe;
	d->powe = ((b)->powe - 1);
	d->next = NULL;
	b = b->next;
	List* end = d;
	while (b != NULL)
	{
		if (b->powe == 0) {
			b = b->next;
			continue;
		}
		end->next = new List;
		end = end->next;
		end->nom = b->nom * b->powe;
		end->powe = b->powe - 1;
		end->next = NULL;
		b = b->next;
	}
	return d;
}


void Delete(List** b)
{
	if (*b == NULL)return;
	List* p = *b;
	List* t;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*b = NULL;
	cout << "Termination was finished successfully" << endl;
}


bool compear(List* a, List* b)
{
	bool sim = true;
	while (b != NULL || a != NULL) {
		if (a->nom != b->nom || a->powe != b->powe) {
			sim = false;
			break;
		}
		a = a->next; 
		b = b->next;
	}
	if (b != a) { sim = false; }
	return sim;
}

void Print(List* b, char w) {
	if (b->powe == 0) { cout << b->nom; }
	else { cout << b->nom << w << "**" << b->powe; }
	b = b->next;
	while (b != NULL) {
		if (b->nom > 0) {
			if (b->powe == 0) {
				cout << "+" << b->nom;
			}
			else { cout << "+" << b->nom << w << "**" << b->powe; }
		}
		else {
			if (b->powe == 0) {
				cout << b->nom;
			}
			else { cout << b->nom << w << "**" << b->powe; }
		}
		b = b->next;
	}
	cout << endl;
}
