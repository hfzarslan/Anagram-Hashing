#pragma once
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
class Node
{
public:
	string val;
	Node* next;
	Node();
	Node(string val);
};

