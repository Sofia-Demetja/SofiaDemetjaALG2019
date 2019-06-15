#include<conio.h>
#include<iostream>
#include<fstream>
#include<time.h>
//Gjate leximit te skedarit, programi duhet te krijoje nje fjalor me te gjitha fjalet qe jane shfaqur ne skedar.
// Sa here qe shfaqet nje fjale e re, dmth qe nuk ndodhet ne fjalor, programi duhet ta shtoje ate ne fjalor. 

//1.NEPERMJET LISTES SE LIDHUR NJE DREJTIMORE

using namespace std;
struct Node{
		string word;     //deklarimi i struktures liste 
		Node* next;
};
	bool exist (Node* head,string w){   //funksioni boolean per te kontrolluar nqs eksizton
	Node* tmp=head;                   // * shenjon ne koken e listes
	while(tmp!=NULL){            	  //per sa kohe qe lista eshte joBoshe
		                             
			if(tmp->word==w){       // nqs e kemi gjetur fjalen kthejme true nqs kemi shkruar 
			return true;            // deri ne fund te listes 
		}                           //kthejm false
			tmp=tmp->next;	}
			return false;
}
Node* add(Node* head,string w){      //vendosja e fjaleve ne liste nga perpara
		if(exist(head,w)){          
		return head;
	}
	else {
		Node* tmp=new Node;     //vendosja e fjaleve ne fillim te listes pasi ka dhe kompleksitet me te ulet dhe procesim me te shpejte
		tmp->word=w;
		tmp->next=head;
		head=tmp;
		return head;
	}
}
void print (Node* head){  //funksioni per te printuar (funksion qe nuk kkthen vlere) 
	Node* tmp=head;//shenojme ne koken e listet
	int i=1;//indeksim per printimin e fjaleve
	while(tmp!=NULL){//bejme bredhjen ne liste
		cout<<i<<" "<<tmp->word<<endl;//printojme fjalet te cdo nyje te listes
		tmp=tmp->next; //per te kaluar tek nyja tjeter
		i++;
	}
}
int main(int argc,char * argv[]){   //funksioni main 
	clock_t start, end;
	start = clock();
	ifstream in;
	Node* head=new Node;
	int count=0;
	in.open("FJALORI.txt"); //hapim skedarin tekst 
	while(!in.eof()){ //bejme bredhjen ne skedar endoffile
		string str;
		in>>str;
		//cout<<str<<endl;
		if(count==0){//nese lista eshte boshe ath fusim fjalen e pare si koke te listes
			head->word=str;
			head->next=NULL;
			count++;
		}
		else{
			head=add(head,str);//vendosje ne fillim te listes
		}
	}
	print(head);//printimin e listes
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
	cout<<"FJALORI yne ka keto fjale te vendosura si mesiper: "<<endl;
	cout<<"KOha e ekzekutimit eshte "<<time_taken<<"s"<<endl; 
	getch();
	return 0;
}
