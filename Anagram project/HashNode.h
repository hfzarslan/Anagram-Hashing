#pragma once
#include"Node.h"
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
class HashNode{
public:
	string key;
	HashNode* next;
	Node* anagram;
	HashNode();
	int getCount();
	HashNode* search(string key);
	void insert(string key, string word);
};

