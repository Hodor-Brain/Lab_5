#include "Header.h"

int main()
{
	int key = 0;
	Tree* start = nullptr;
	Tree* end = nullptr;

	while (true)
	{
		bool exit = false;
		key = menu();

		switch (key)
		{
		case 0:
		{
			system("cls");

			cout << "Enter the word you want to add : ";
			
			char engword[20] = {};
			char* ew = engword;

			cin >> ew;

			cout << "Enter the translation : ";

			char rusword[20] = {};
			char* rw = rusword;

			cin >> rw;

			add(ew, rw, start);

			show(start);

			system("pause");

			break;
		}
		case 1:
		{
			cout << "Enter the word you want to find : ";

			char engword[20] = {};
			char* ew = engword;

			cin >> ew;

			char* k = nullptr;

			k = showword(start, ew);

			if (k == nullptr)
			{
				cout << "There is no such a word" << endl;
			}
			else
			{
				cout << "Translate : " << k << endl;
			}

			system("pause");

			break;
		}
		case 2:
		{
			cout << "Old list : " << endl;
			show(start);

			while (start != nullptr)
			{
				int point = DeletedComp(start, 0);

				Tree* comp = Component(start, point);

				addnew(end, comp);
			}

			cout << endl;
			cout << "New list (From the least popular to the most popular) : " << endl;
			show(end);
			cout << endl;

			exit = true;

			system("pause");

			break;
		}
		default:
		{
			break;
		}
		}

		if (exit == true)
		{
			break;
		}
	}
}
