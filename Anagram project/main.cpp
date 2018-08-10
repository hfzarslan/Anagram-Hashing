#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include"HashMap.h"
using namespace std;




bool isword(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return true;

	return false;
}
 string alphagram(string w) {
	
	  sort(w.begin(), w.end());
	  return w;
}

int main() {
	HashMap hash;
	int key;
	string str, strsort;
	ifstream fin;
	fin.open("words.txt");
	if (!fin) {
		cerr << "Unable to open file input.txt";
		exit(1);
	}
	cout << "Reading...";
	while (!fin.eof()) {
		fin >> str;
		//cout << str << endl;
		strsort = hash.alphagram2(str);
		
	
		hash.Insert(strsort, str);

	}
	cout << "Done" << endl;
	//hash.printBin();
	fin.close();
	
	cout << "max collision: " << hash.maxc() << endl;
	cout << "OBins: " << hash.getOBins() << endl;
	cout << "RBins: " << hash.getRBins() << endl;
	cout << "Ratio: " << float(hash.getRBins()) / hash.getOBins() << endl;
	ofstream fout;
	fout.open("output.txt");
	if (!fout) {
		cerr << "Unable to open file input.txt";
		exit(1);
	}
	
	ifstream fin2;
	string str2;
	fin2.open("input.txt");
	if (!fin2) {
		cerr << "Unable to open file input.txt";
		exit(1);
	}

	while (!fin2.eof()){
		getline(fin2, str2);
		strsort = hash.alphagram2(str2);
		fout <<endl<< str2 << ": ";
		hash.search(strsort, fout);
	}
	fout.close();



	

	_getch();
	return 0;
}

