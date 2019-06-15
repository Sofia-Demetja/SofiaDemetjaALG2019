#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>

using namespace std;

int i = 1;
struct Node {      //deklarimi i struktures se pemes se balancuar
    string word;
    Node *left;
    Node *right;
    int height;
};
int max(int x, int y) {    //max kthen gjatesine maximale ndermjet dy gjatesive
    if(x>y)
        return x;
    return y;
}

int height(Node *tmp) {     //kthen gjatesine e nje kulmi
    if(tmp==NULL)
        return 0;
    return tmp->height;
}
bool exist(Node *root, string w) {
    if(root==NULL) {
        return false;
    }
    if(root->word==w) {
        return true;
    }
    if(w>root->word) {
        return exist(root->left,w);
    } else {
        return exist(root->right,w);
    }
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}
int getBalance(Node *tmp)
{
    if (tmp == NULL)
        return 0;
    return height(tmp->left) - height(tmp->right);
}
Node *newNode(string w) {
    Node *temp = new Node;
    temp->word = w;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

Node *add(Node *root, string w) {
    if(root==NULL)  //nqs eshte boshe e vendosim newNode
        return newNode(w);

    if(exist(root,w)) //nese ekziston ne rrenje bejme kontrollin ne te
        return root;

    if(w<root->word) {
        root->left = add(root->left,w);
    } else {
        root->right = add(root->right,w);
    }
    root->height = 1 + max(height(root->left),height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && w < root->left->word)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && w > root->right->word)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && w > root->left->word)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && w < root->right->word)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
		cout<<i<<" "<<root->word<<endl;
		i++;
        print(root->right);
    }
}

int main(int argc, char * argv[]) {
	ifstream in;
	Node* head = new Node;
	int count = 0;
	in.open("FJALORI.txt");   //hapim skedarin tekst 	while(!in.eof()){
	while(!in.eof()){
		string str;
		in>>str;
		//cout<<str<<endl;
		if(count == 0){
			head = add(NULL,str);
			count++;
		}
		else {
			head = add(head,str);
		}

	}
	in.close();
	cout<<"Fjalori yne ka keto fjale te vendosura: "<<endl;
	print(head);
	getchar();

	return 0;
}
