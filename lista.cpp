#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

 struct Node { 
   string  fjala; 
   struct Node *pas; 
}; 
// kerkimi i nje fjale ne liste 
bool kontrollo (Node *l, string x )
{
	Node *m=new Node();
	m=l;
   if (m==NULL)
   return false;
   else{
   	while(m!=NULL)
   	{
   		if(m->fjala==x)
   		return true;
   		else 
   		m=m->pas;
	   }
	   return false;
   }
}
// shtimi i nje fjale ne liste
Node *shto (Node *l, string x)
{
   Node* t = new Node() ; 
   t->fjala=x;
   t->pas=l;
   l=t;
   return l;
   
}
int main (){
	 clock_t start, end;
    double cpu_time_used;
	start = clock();
    ifstream input;
    input.open("teksti100.txt");
    string x,y;
   


     Node *n =new Node();
   

    if (input.is_open())
    {
       while (!input.eof())
       {
          input>>x;
          bool gjej=kontrollo(n,x);
          if (gjej==false)
          {
             n=shto(n,x);
          }
       }
    }


    input.close();
    Node *l=new Node();
    
    l=n;
    int c=0;

    while(l!=NULL)
    {
    	
    	y=l->fjala;
       cout<<y<<" ";
       c++;
       l=l->pas;
       
    }
    cout<<" "<<endl;
    cout<<"u afishuan :"<<c<<endl;
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used;
    return 0;
}

