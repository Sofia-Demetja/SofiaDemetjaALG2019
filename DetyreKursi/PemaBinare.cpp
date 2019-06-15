#include <iostream>
#include <string>
#include <fstream>
//Gjate leximit te skedarit, programi duhet te krijoje nje fjalor me te gjitha fjalet qe jane shfaqur ne skedar.
// Sa here qe shfaqet nje fjale e re, dmth qe nuk ndodhet ne fjalor, programi duhet ta shtoje ate ne fjalor. 

//2.NEPERMJET PEMES BINARE

using namespace std;

int i = 1;
struct Node {   //deklarimi i struktures se pemes binare
    string word; //mbajtesi fjales
    Node *left; //shenjues ne te majte
    Node *right; //shenjues ne te djathte
};

bool exist(Node *root, string w) { //therritja e funksionit exist i tipit boolean 
    if(root==NULL) {                //qe kontrollon nqs pema binare eksizton per te kryer me tej veprimet e kerkuara, pra nqs eshte boshe kthejme false
        return false;
    }
    if(root->word==w) {//rasti i pare fjala mund te ndodhet ne rrenjen e pemes, nese po kthejme true
        return true;
    }
    if(w<root->word) {//rasti i dyte nese fjala eshte me e vogel rend alfabetik se ajo qe ndodhet ne rrenje
        return exist(root->left,w);//therrasim metoden rekrusive qe ben kerkimin ne nenpemen e majte
    } else {
        return exist(root->right,w);//rasti i trete ne nenpemen e djathte
    }
}
Node *newNode(string w) {//funksion per krijimin e nje kulmi te ri
    Node *temp = new Node;//rezervimin ne memorie per kulmin e ri
    temp->word = w;//vendosja e fjales
    temp->left = NULL;//biri i majte NULL
    temp->right = NULL;//biri i djathte NULL
    return temp;//kthejme kulmin
}

Node *add(Node *root, string w) { //therritja e funskionit add per te vendosur fjalet ne skedar nepermjet pemes binare
    if(root==NULL)//nqs pema eshte boshe
        return newNode(w);//kthejme nje kulm qe korrespondon me rrenjen

    if(exist(root,w))//nqs fjala ndodhet ne rrenje
        return root;//kthejme direkt pemen

    if(w<root->word) {//nese fjala eshte ne rend alfabetik me te vogel se rrenja
        root->left = add(root->left,w);//bejme therritjen rekrusive per vendosjen e fjales
    } else {
        root->right = add(root->right,w);//e kunderta nese eshte ne rend alfabetik me te madh
    }
    return root;
}
void print(Node *root) // therritja e funksionit per printimin
{
    if (root != NULL)//gjersa kemi arritur ne fund te pemes
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
	in.open("FJALORI.txt"); //hapim skedarin tekst 
	while(!in.eof()){
		string str;
		in>>str;
		//cout<<str<<endl;
		if(count == 0){
			head->word = str;
			head->left = NULL;
			head->right = NULL;
			count++;
		}
		else {
			head = add(head,str);
		}

	}
	cout<<"FJALORI yne ka keto fjale te vendosura si meposhte: "<<endl;
	print(head);
	getchar();

	return 0;
}

