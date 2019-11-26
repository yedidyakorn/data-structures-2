/*
File: trie.h
Description: classes- trie, trieNode
Course: Data structres
Exercise 2
Author: Yedidya Korn-203304084 & David Abelo-208764340
*/

#pragma once
#include <string>
#include <iostream>

using namespace std;

class TrieNode		// Trie node
{
public:
	TrieNode* _children[26];
	TrieNode* _parent;
	bool _isEndOfWord;
	char _val;
	TrieNode(char, TrieNode*);
	~TrieNode() { delete[] _children; }
	bool isLeaf(); 
	void print( string);
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
	Trie() { _root = new TrieNode(' ', NULL); }
	~Trie() { _root->~TrieNode(); _root = NULL; }
};

