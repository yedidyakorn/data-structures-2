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
	for (int i = str.length() - 1; i >= 0; i--)
	{
		index = str[i] - 'a';
		temp = temp->_parent;
		delete temp->_children[index];
		temp->_children[index] = NULL;
		if (!temp->isLeaf())
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
