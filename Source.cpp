#include "MorseTree.h"
#include <iostream>
#include <fstream>

using namespace std;

void main() {
	stringstream ss;
	ifstream fin;
	fin.open("morse.txt");
	MorseTree morse;
	string temp, temp2;
	string aplha, location;
	string toencode = "hey how are you doing today"; //change the value of this string to any word or sentense you want you can also use spaces
	string todecode = ".... . _.__  .... ___ .__  ._ ._. .  _.__ ___ .._  _.. ___ .. _. __.  _ ___ _.. ._ _.__"; //change this value of this string to decode double spaces represent the end of a word
	while (getline(fin, temp)) {
		ss << temp[0];
		ss >> aplha;
		ss.clear();
		for (int i = 1; i < temp.size(); i++) {
			ss << temp[i];
			ss >> temp2;
			location += temp2;
			ss.clear();
		}
		morse.readInchar(aplha, location);
		location = "";
	}
	cout << morse.encode(toencode) << endl;
	cout << morse.decode(todecode) << endl;
	system("pause");
}
  