#pragma once
#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>


using namespace std;

struct List {
	int powe;
	int nom;
	List* next;
};

bool add(List** b);
int Sum(List* b, int a);
List* derivative(List* b);
void Delete(List** b);
void Print(List* b, char w);
bool compear(List* a, List* b);

