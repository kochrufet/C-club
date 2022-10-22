#include <bits/stdc++.h>

using namespace std;

struct node {
	int x;

	vector<struct node*> boys;
};

typedef struct node* treenode;

treenode insert(treenode node, int data)
{
	treenode newnode = new struct node;
	newnode->x = data;
	node->boys.push_back(newnode);
	return newnode;
}

void cleanuptree(treenode root)
{
//	cout << root->x << " cleaned." << endl;

	if(root->boys.empty())
	{
		return;
	}
	for(int i=0; i<root->boys.size(); i++)
	{
		cleanuptree(root->boys[i]);
		delete root->boys[i];
	}
	root->boys.clear();
	return;
}

void DFS(treenode root, int target, vector<int> res)
{
	res.push_back(root->x);

	if(root->x == target){
		for(int i=0; i<res.size(); i++)cout << res[i] << ' ';
		cout << endl;
	}
	for(int i=0; i<root->boys.size(); i++)
	{
		DFS(root->boys[i], target, res);
	}

	res.pop_back();
}

int main(int argc, char const *argv[])
{
	struct node* root = new struct node;
	treenode p;
	root->x = 1;

	p = insert(root, 2);
	
	insert(p, 7);
	insert(p, 9);
	p = insert(p, 11);
	insert(p, 27);
	insert(p, 91);
	
	p = insert(root, 3);
	insert(p, 4);

	vector<int> res;
	int x;cout << " x="; cin>>x;
	DFS(root, x, res);

	cleanuptree(root);

	return 0;
}


