#include "Trie.h"
#include <string>

void Trie::insert(string str)
{
	int index;
	TrieNode* temp = _root;
	for (int i = 0; i < str.length(); i++)
	{
		index = str[i] - 'a';
		if (!temp->_children[index])
			temp->_children[index] = new TrieNode(str[i], temp);
		temp = temp->_children[index];
	}
	// mark last node as leaf 
	temp->_isEndOfWord = true;
}
bool Trie::search(string str)
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


bool Trie::del(string str)
{
	if (!search(str))
		return false;
	TrieNode* temp = _root;
	int index;
	for (int i = 0; i < str.length(); i++)
	{
		index = str[i] - 'a';
		temp = temp->_children[index];
	}
	if (!temp->isLeaf())
	{
		temp->_isEndOfWord = false;
		return true;
	}
	for (int i = str.length()-1; i >= 0; i--)
	{
		index = str[i] - 'a';
		temp = temp->_parent;
		temp->_children[index] = NULL;
		delete temp->_children[index];

		if (!temp->isLeaf()||temp->_isEndOfWord==true||temp==_root)
			return true;
	}
}

bool TrieNode::isLeaf()
{
	for (int i = 0; i < 26; i++)
		if (_children[i] != NULL)
			return false;
	return true;
}

int Trie::printAutoSuggestions(string str)//sends a pointer to
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

void TrieNode::print( string str)
{
	string temp=str;
	if (this->_isEndOfWord == true)
		cout << str << endl;
	if (this->isLeaf())
	{
		return;
		
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (this->_children[i] != NULL)
		{
			temp += this->_children[i]->_val;
			this->_children[i]->print(temp);
		}
	}
	
}


TrieNode::TrieNode(char val, TrieNode* parent)
{
	for (int i = 0; i < 26; i++)
	{
		_children[i] = NULL;
	}
	_isEndOfWord = false;
	_val = val;
	_parent = parent;
}
