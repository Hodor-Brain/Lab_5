#include "Header.h"

int menu()
{
int key = 0;
int code;

do {
	system("cls");

	key = (key + 3) % 3;

	if (key == 0) cout << "-> Add the word" << endl;
	else  cout << "   Add the word" << endl;
	if (key == 1) cout << "-> Find the word" << endl;
	else  cout << "   Find the word" << endl;
	if (key == 2) cout << "-> Create new Tree" << endl;
	else  cout << "   Create new Tree" << endl;

	code = _getch();

	if (code == 224)
	{
		code = _getch();
		if (code == 80) key++;
		if (code == 72) key--;
	}

} while (code != 13);

system("cls");
return key;
}

void add(char* engl, char* rusi, Tree*& our)
{
	if (!our)
	{
		our = new Tree(engl,rusi);
		return;
	}
	for (int i = 0; i < 20; i++)
	{
		if (engl[i] > our->eng[i])
		{
			add(engl, rusi, our->right);
			return;
		}
		else if (engl[i] < our->eng[i])
		{
			add(engl, rusi, our->left);
			return;
		}
	}
	cout << "Such a word is already in the list" << endl;
	return;
}

void show(Tree* my)
{
	if (my == nullptr)
	{
		return;
	}
	else
	{
		show(my->left);
		cout << my->eng << " - " << my->rus << endl;;
	}
	show(my->right);
}

char* showword(Tree* our, char* engl)
{
	char* temp = nullptr;

	if (our == nullptr)
	{
		return nullptr;
	}
	else
	{
		if (temp == nullptr)
		{
			temp = showword(our->left, engl);
		}

		if (temp == nullptr)
		{
			bool equal = true;

			for (int i = 0; i < strlen(engl) + 1; i++)
			{
				if (our->eng[i] != engl[i])
				{
					equal = false;
					break;
				}
			}

			if (equal == true)
			{
				our->popul++;
				return our->rus;
			}
		}
	}
	if (temp == nullptr)
	{
		temp = showword(our->right, engl);
	}
	return temp;
}



void addnew(Tree*& our, Tree* comp)
{
	if (!our)
	{
		our = comp;
		return;
	}
	if (comp == nullptr)
	{
		return;
	}

	if (comp->popul > our->popul)
	{
		addnew(our->right, comp);
	}
	else
	{
		addnew(our->left, comp);
	}
}

int DeletedComp(Tree* our, int a)
{
	if (our == nullptr)
	{
		return -1;
	}
	else
	{
		a = our->popul;

		if (DeletedComp(our->left, a) > a)
		{
			a = DeletedComp(our->left, a);
		}
	}
	if (DeletedComp(our->right, a) > a)
	{
		a = DeletedComp(our->right, a);
	}
	return a;
}

Tree* Component(Tree*& our, int num)
{
	Tree* temp = nullptr;

	if (our == nullptr)
	{
		return nullptr;
	}
	else if (our->popul == num)
	{
		addnew(our->right, our->left);
		our->left = nullptr;
		temp = our;
		our = our->right;
		temp->right = nullptr;
		return temp;
	}
	else if (our->left != nullptr && our->left->popul == num)
	{
		temp = our->left;
		our->left = nullptr;
		addnew(temp->right, temp->left);
		temp->left = nullptr;
		addnew(our, temp->right);
		temp->right = nullptr;
		return temp;
	}
	else if (our->right != nullptr && our->right->popul == num)
	{
		temp = our->right;
		our->right = nullptr;
		addnew(temp->left, temp->right);
		temp->right = nullptr;
		addnew(our, temp->left);
		temp->left = nullptr;
		return temp;
	}
	else
	{
		if (temp == nullptr)
		{
			temp = Component(our->left, num);
		}

	}
	if (temp == nullptr)
	{
		temp = Component(our->right, num);
	}
	return temp;
}
