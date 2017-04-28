#include <string>
#include <map>
#include <sstream>
#pragma once

using namespace std;

typedef struct item {
	string value = "#";
	string location;
	item* right = nullptr;
	item* left = nullptr;
	item* parent;
}* node;
class MorseTree {
	map<string, string> characters;
	node root = new item;
	node curr;
public:
	void addNode(node add, string location) {
		curr = root;
		for (int i = 0; i < location.size(); i++) {
			if (location[i] == '.') {
				if (curr->left == nullptr) {
					curr->left = new item;
					curr->left->value = "#";
					curr = curr->left;
				}
				else {
					curr = curr->left;
				}
			}
			else if (location[i] == '_') {
				if (curr->right == nullptr) {
					curr->right = new item;
					curr->right->value = "#";
					curr = curr->right;
				}
				else {
					curr = curr->right;
				}
			}
		}
		curr->value = add->value;
		curr->location = location;
	}


	string decode(string morse) {
		curr = root;
		string temp = "";
		for (int i = 0; i < morse.size(); i++) {
			if (morse[i] == ' ') {
				if (morse[i - 1] == ' ') {
					temp += ' ';
				}
				else {
					temp += curr->value;
					curr = root;
				}
			}
			else if (morse[i] == '.') {
				curr = curr->left;
				if (i == (morse.size() - 1))
					temp += curr->value;
			}
			else if (morse[i] == '_') {
				curr = curr->right;
				if (i == (morse.size() - 1))
					temp += curr->value;
			}
			
		}
		return temp;
	}
	void readInchar(string alpha, string location) {
		characters[alpha] = location;
		node temp = new item;
		temp->value = alpha;
		temp->location = location;
		addNode(temp, location);
	}
	string encode(string toencode) {
		stringstream ss;
		string temp;
		string coded = "";
		for (int i = 0; i < toencode.size(); i++) {
			ss << toencode[i];
			ss >> temp;
			ss.clear();
			if (temp != " ") {
				coded += characters[temp];
				coded += " ";
			}
			else {
				coded += " ";
			}
			temp = "";
		}
		return coded;
	}

};