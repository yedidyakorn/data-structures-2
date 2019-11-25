#pragma once
#include <string>
#include <iostream>

using namespace std;
// Trie node
class TrieNode
{
public:
	TrieNode* _children[26];
	TrieNode* _parent;
	bool _isEndOfWord;
	char _val;
	TrieNode(char, TrieNode*);
	~TrieNode() { delete _children; }
	bool isLeaf();

};

class Trie
{
private:
	TrieNode* _root;
public:
	void insert(string str);
	bool del(string str);
	bool search(string str);
	int printAutoSuggestions(string str);
	int print(TrieNode*, string);
	Trie() { _root = new TrieNode(' ', NULL); }
	~Trie() { delete _root; }


};

