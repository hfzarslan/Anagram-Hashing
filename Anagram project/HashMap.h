#pragma once
#include"HashNode.h"
#include <fstream>
const int TABLE_SIZE = 200000;
static int countBin = 0;
static const size_t InitialFNV = 2166136261U;
static const size_t FNVMultiple = 16777619;
class HashMap
{
private:

	HashNode * * htable;

public:
	HashMap();
	~HashMap();
	/*
	* Hash Function
	*/
	int hash(string);
	int HashFunc(string key);
	/***********************************************************/
	string mytolower(string s);
	int getMax(int arr[], int n);
	void radixsort(int arr[], int n);
	void countSort(int arr[], int n, int exp);
	void convertToString(char* arry, int arr[], int len);
	void convertToASCII(string letter, int arr[]);
	string alphagram2(string w);
	/*
	* Insert Element at a key
	*/
	void Insert(string key,string word);
	int getOBins();
	int getRBins();
	int maxc();
	void search(string key,ofstream&);
	/*

	* Remove Element at a key

	*/


	string alphagram(string w);
	bool isWord(string s);
	bool equalize(string x1, string x2);
	void printBin();
	size_t myhash(const string &s);
};

