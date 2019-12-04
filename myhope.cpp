#include"Header.h"
int main() {
	List* beginp = NULL;
	List* beginq = NULL;
	List* begind = NULL;
	bool status = false;
	int a, b, n;
	cout << "Input zone" << endl;
	do {
		cout << "P->";
		a = add(&beginp);
		cout << "Q->";
		b = add(&beginq);
		if (a == true && b == true) {
			status = true;
		}
	} while (status == false);
	while (status == true)
	{
		cout << endl;
		cout << "Function menu:" << endl;
		cout << "1. Compear polinomial p and q" << endl;
		cout << "2. Polinomial value p or q from x" << endl;
		cout << "3. Polinomal derivative " << endl;
		cout << "4. Output  polinomial p or q from variable" << endl;
		cout << "5. Clear console\n";
		cout << "6. Exite" << endl << endl << endl;
		cin >> n;
		switch (n)
		{
		case(1):
			a = compear(beginp, beginq);
			if (a == true) { cout << "Polinomials are the same.\n"; }
			else { cout << "Polinomials are various.\n"; }
			status = true;
			break;
		case(2):
			cout << "Input your integer number 'x':\t";
			cin >> b;
			cout << "Make the choise between q and p .\n";
			cout << "1. For P.           2. For Q.\n";
			cin >> a;
			switch (a) {
			case(1): cout << "P(x)=" << Sum(beginp, b); break;
			case(2): cout << "Q(x)=" << Sum(beginq, b); break;
			default:cout << "Bad input!\n"; break;
			}
			break;
		case(3):

			cout << "Make the choise between q and p.\n";
			cout << "1. For P.           2. For Q.\n";
			cin >> a;
			switch (a) {
			case(1): begind = derivative(beginp); Delete(&beginp); beginp = begind; begind = NULL; break;
			case(2): begind = derivative(beginq); Delete(&beginq); beginq = begind; begind = NULL; break;
			default:cout << "Bad input!\n"; break;
			}
			break;
		case(4):
			cout << "Input your variable\n";
			char c;
			cin >> c;
			cout << "Make the choise between q and p.\n";
			cout << "1. For P.           2. For Q.\n";
			cin >> a;
			switch (a) {
			case(1): cout << "P(" << c << ")="; Print(beginp, c); break;
			case(2): cout << "Q(" << c << ")="; Print(beginq, c); break;
			default:cout << "Bad input!\n"; break;
			}
			break;
		case(5):
			system("cls");
			break;
		case(6):
			status = false;
			break;
		default:
			cout << "Bad input!\n";
			break;
		}
	}
	Delete(&beginp);
	Delete(&beginq);
	return 0;
}