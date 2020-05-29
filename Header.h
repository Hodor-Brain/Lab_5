#pragma once

#include <iostream>
#include <conio.h>

using namespace std;

struct Tree
{
	char engword[20] = {};
	char rusword[20] = {};

	char* eng = engword;
	char* rus = rusword;

	int popul = 0;

	Tree* left = nullptr;
	Tree* right = nullptr;

	Tree()
	{};
	Tree(char* engl, char* rusi)
	{
		for (int i = 0; i < strlen(engl); i++)
		{
			eng[i] = engl[i];
		}
		for (int i = 0; i < strlen(rusi); i++)
		{
			rus[i] = rusi[i];
		}
	}
};

void add(char* engl, char* rusi, Tree*& our);
void show(Tree* my);
char* showword(Tree* our, char* engl);
void addnew(Tree*& our, Tree* comp);

int menu();

int DeletedComp(Tree* our, int a);

Tree* Component(Tree*& our, int num);