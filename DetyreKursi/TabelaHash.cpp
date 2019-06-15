#include <iostream>
 #include <string>
 #include <fstream>
 #define MAX_SIZE 9
 using namespace std;

 struct element
 {
 string fjale;              //deklarimi i struktures se tabeles HASH
 struct element *next;
 };

 struct element *tabele[MAX_SIZE]= {NULL};

 int Hash(string fjala)
 {

 int gjatesi=fjala.length();
 int shuma=0;
 for(int i=0; i<gjatesi; i++)
 shuma=shuma+(int)fjala.at(i);

 return shuma%MAX_SIZE;
 }

 void shtoNeTabHash(string fjala)
 {

 int poz=Hash(fjala);


 element *tmp=new element;
 tmp->fjale=fjala;
 tmp->next=tabele[poz];
 tabele[poz]=tmp;

 }
  bool gjendetNeListe(string fjala,element *l)
 {

 while(l)
 {
 if(l->fjale==fjala)
 return true;
 l=l->next;
 }
 return false;
 }
 bool gjendet(string fjala)
 {

 int poz=Hash(fjala);

 return gjendetNeListe(fjala,tabele[poz]);

 }


 void afishoListe(element *l)
 {

 while(l!=NULL)
 {

 cout<<l->fjale<<endl;
 l=l->next;
 }
 }
 void afishoTabeleHash()
 {

 for(int i=0; i<MAX_SIZE; i++)
 {
 cout<<"liste "<<i+1<<" //////"<<endl;

 afishoListe(tabele[i]);
 }
}




 int main()
{

ifstream S;



 string str;

 S.open("FJALORI.txt");

 while(S>>str)
 {


 if(str.at(0)=='.'||str.at(0)==',')
 str=str.substr(1,str.length());

 else

 if(str.at(str.length()-1)=='.'||str.at(str.length()-1)==',')
 str=str.substr(0,str.length()-1);

 if(!gjendet(str))
 {

 shtoNeTabHash(str);

 }



 }




 S.close();


 afishoTabeleHash();

 return 0;
 }

