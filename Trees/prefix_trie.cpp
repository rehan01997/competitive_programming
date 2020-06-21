#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		char data;
		unordered_map<char , Node* >children;
		bool isTerminal = false;

		Node(char data)
		{
			this->data = data;
			isTerminal = false;
		}
};
Node *root = new Node('\0');
 void insertWord(Node *& root , string word)
{
	if( word.length() == 0)
	{	
		root -> isTerminal = true;
		return;
	}
	Node * child;
	if( root->children.find(word[0]) == root->children.end())
	{	
		Node* temp = new Node(word[0]); 
		root->children[word[0]] = temp;
		child = root->children[word[0]];
	}
	else
	{
		child = root->children[word[0]];
	}
	insertWord( child , word.substr(1));
	return;
}
bool searchWord(Node *& root , string word)
{	
	if( word.length() == 0)
	{
		if(root->isTerminal == true) return true;
		else return false;
	}
	if( root->children.find(word[0]) == root->children.end() )
	{
		return false;
	}
	else
	{
		Node * temp = root->children[word[0]];
		bool ans = searchWord( temp , word.substr(1));
		if( ans == false) return false;
		else if( ans == true ) return true;
	}
	return false;
}
bool startsWith(string prefix)
{
	if( word.length() == 0)
	{
		return true;
	}
	if( root->children.find(word[0]) == root->children.end() )
	{
		return false;
	}
	else
	{
		Node * temp = root->children[word[0]];
		bool ans = startsWith( temp , word.substr(1));
		if( ans == false) return false;
		else if( ans == true ) return true;
	}
	return false;
}
int main()
{	
	insertWord(root , "apple");
	insertWord(root , "bapp");
	//cout<<root->children.size();

	// bool ans = searchWord(root , "bapp");
	// if(ans == true) cout<<"found";
	// else cout<<"Not found";

	bool anss = startsWith("c");
	if(anss == true) cout<<"found";
	else cout<<"Not found";


	return 0;
}