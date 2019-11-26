#include "trie.h"
#include <string>

void Trie::insert(string str)//inserts a word to trie
{
	int index;
	TrieNode* temp = _root;
	for (int i = 0; i < str.length(); i++)
	{
		index = str[i] - 'a';		//direct acsess
		if (!temp->_children[index])
			temp->_children[index] = new TrieNode(str[i], temp);
		temp = temp->_children[index];
	}
	// mark last node as leaf 
	temp->_isEndOfWord = true;
}
bool Trie::search(string str)//search if word is in trie
{

	TrieNode* temp = _root;
	int index;
	for (int i = 0; i < str.length(); i++)
	{
		index = str[i] - 'a';
		if (!temp->_children[index])
			return false;

		temp = temp->_children[index];
	}
	return (temp->_isEndOfWord);
}


bool Trie::del(string str)//deletes word from trie
{
	if (!search(str))		//checks if the word is in the trie
		return false;
	TrieNode* temp = _root;
	int index;
	for (int i = 0; i < str.length(); i++)
	{
		index = str[i] - 'a';
		temp = temp->_children[index];
	}
	if (!temp->isLeaf())		//checks if the letters are used for a difrint word
	{
		temp->_isEndOfWord = false;
		return true;
	}
	for (int i = str.length()-1; i >= 0; i--)		//deletes the unuesed letters
	{
		index = str[i] - 'a';
		temp = temp->_parent;
		temp->_children[index]->~TrieNode();
		temp->_children[index] = NULL;
		if (!temp->isLeaf()||temp->_isEndOfWord==true||temp==_root)
			return true;
	}
}

bool TrieNode::isLeaf()		//checkes if a letter is in the midlle of any word
{
	for (int i = 0; i < 26; i++)
		if (_children[i] != NULL)
			return false;
	return true;
}

int Trie::printAutoSuggestions(string str)	//sends a pointer of the sub tree to the print functaion
{
	TrieNode* temp = _root;
	int index;
	for (int i = 0; i < str.length(); i++)
	{
		index = str[i] - 'a';
		if (temp->_children[index] == NULL)//checks if the prefix exsists
			return 0;
		temp = temp->_children[index];
	}
	temp->print(str);
	return 1;
}

void TrieNode::print( string str)		//prints all words that start with a prefix
{
	if (this->_isEndOfWord == true)		//checks if a word ends at a letter
		cout << str << endl;
	if (this->isLeaf())			//Stop conditions of Recursion
		return;			
	for (int i = 0; i < 26; i++)
	{
		if (this->_children[i] != NULL)
		{
			this->_children[i]->print(str + this->_children[i]->_val);
		}
	}
	
}


TrieNode::TrieNode(char val, TrieNode* parent)		//ctor
{
	for (int i = 0; i < 26; i++)
	{
		_children[i] = NULL;
	}
	_isEndOfWord = false;
	_val = val;
	_parent = parent;
}
