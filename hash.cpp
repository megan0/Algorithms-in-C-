#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

 struct Node { 
   string  fjala; 
   int c;
   struct Node *pas; 
}; 

void shto (Node *t[],int n,int c,string f,int& i)
{
	i++;
	int h=c%n;
	Node *b= new Node();
	b->c=c;
	b->fjala=f;
	Node *tmp=new Node();
	tmp=t[h];
	b->pas=tmp;
	t[h]=b;
	cout<<f<<" ";
	
}

bool gjej(Node *t[],int n,int c,string f)
{
	int h=c%n;
	Node * l=new Node();
	l=t[h];
	while (l!=NULL)
	{
		if (l->fjala==f)
		return true;
		else
		l=l->pas;
	}
	return false;
}

int main ()
{
	clock_t start, end;
    double cpu_time_used;
	start = clock();
    ifstream input;
    input.open("teksti1000.txt");
    int i=0,c;
    string x;
    int n=200;
    Node *t[n] ;
    for(int k=0;k<n;k++)
    t[k]=NULL;
    
    
    
     if (input.is_open())
    {
       while (!input.eof())
       {
          input>>x;
          c=x.at(0);
          bool kontr=gjej(t,n,c,x);
          if (kontr==false)
          {
             shto(t,n,c,x,i);
          }
       }
    }
    
    input.close();
    cout<<endl;
    cout<<"nr i fjalve:"<<i+1<<endl;
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used;
    return 0;
    
}

