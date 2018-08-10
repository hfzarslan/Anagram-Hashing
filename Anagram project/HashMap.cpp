#include "HashMap.h"
#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>
#include<math.h>
#include <fstream>
#include <locale>
using namespace std;
//destructor 
HashMap::~HashMap() {
	for (int i = 0; i < TABLE_SIZE; ++i) {
		HashNode* entry = htable[i];
		while (entry != NULL) {
			HashNode* prev = entry;
			entry = entry->next;
			delete prev;
		}
	}
	delete[] htable;
}
//constructor
HashMap::HashMap()
{
	htable = new HashNode*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		htable[i] = NULL;
}

//sorting function
string HashMap::alphagram2(string w) {
	
	w = mytolower(w);
	int len = w.length();
	int* arr = new int[len];
	convertToASCII(w, arr);


	

	radixsort(arr, len);

	char* arry = new char[len];
	convertToString(arry, arr, len);
	string s1(arry);


	return s1;
}
string HashMap::alphagram(string w) {
	sort(w.begin(), w.end());
	return w;
}
//checking weather its string or not
bool HashMap::isWord(string s) {
	bool trust = true;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) 
			return false;
		
	}
	return true;
} 

//checking two strings or equal
bool HashMap::equalize(string x1, string x2){
	return x1.compare(x2);
}
//myhash function 1
int HashMap::HashFunc(string key)
{
	
	int hashVal = 0;
	for (int i = 0; i<key.length(); i++)
		hashVal = 37 * hashVal + key[i];
	hashVal %= TABLE_SIZE;
	if (hashVal<0)
		hashVal += TABLE_SIZE;
	return hashVal;
}
//myhash function 2


/* Fowler / Noll / Vo (FNV) Hash */
size_t HashMap::myhash(const string &s)
{
	size_t hash = InitialFNV;
	for (size_t i = 0; i < s.length(); i++)
	{
		hash = hash ^ (s[i]);       /* xor  the low 8 bits */
		hash = hash * FNVMultiple;  /* multiply by the magic number */
	}
	return hash%TABLE_SIZE;
}
//hash function 1
int HashMap::hash(string key)
{
	int u = 3141526113231545;
	for (int i = 0; i < key.length(); i += 1){
		u = 33 * u + key[i];
	}
	return abs(u%TABLE_SIZE);
}

//hash function 2





//*********************************************************************************************//
// A utility function to get maximum value in arr[]
string HashMap::mytolower(string s) {
	locale loc;
	for (string::size_type i = 0; i<s.length(); ++i)
		s[i] = tolower(s[i], loc);
	return s;
}
int HashMap::getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void HashMap::convertToASCII(string letter, int arr[])
{
	for (int i = 0; i < letter.length(); i++)
	{
		int x = letter.at(i);
		arr[i] = x;
	}
}
void HashMap::convertToString(char* arry, int arr[], int len) {



	for (int i = 0; i < len; i++)
	{

		arry[i] = char(arr[i]);

	}
	arry[len] = '\0';
}


// A function to do counting sort of arr[] according to
// the digit represented by exp.
void HashMap::countSort(int arr[], int n, int exp)
{
	int* output = new int[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using 
// Radix Sort
void HashMap::radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

//**************************************************************************************************//
//insert function for hash table
void HashMap::Insert(string key,string word) {
	int hash_val = HashFunc(key);
	if (htable[hash_val] == nullptr)
	{
		htable[hash_val] = new HashNode();
	}
	htable[hash_val]->insert(key, word);
}

void HashMap::search(string key,ofstream& fout)
{

	int hash_val = HashFunc(key);
	if (htable[hash_val] != nullptr)
	{
		HashNode* node = htable[hash_val]->search(key);
		fout << key << " ";
		if (node->anagram != nullptr)
		{
			
			fout << node->anagram->val << " ";
			node->anagram = node->anagram->next;
		}
		fout << endl;
	}
}

int HashMap::getRBins()
{
	int c = 0;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (htable[i] != nullptr)
		{
			c = c + htable[i]->getCount();
		}
	}
	return c;
}
int HashMap::getOBins()
{
	int c = 0;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (htable[i] != nullptr)
		{
			c++;
		}
	}
	return c;
}
int HashMap::maxc()

{
	int m = 0;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (htable[i] != nullptr)
		{
			if (m < htable[i]->getCount())
			{
				m = htable[i]->getCount();
			}
		}
	}
	return m;
}
void HashMap::printBin() {
	cout << countBin;
}