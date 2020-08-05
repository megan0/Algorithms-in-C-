#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

struct pema {
	string fjala;
	struct pema *m;
	struct pema *d;
};



void shto(pema*p, string x,int&c)
{
	pema *t=new pema();
	t=p;
	 while(t!=NULL)
	 {
	    if(t->fjala == x) 
	    return;
        if(x<t->fjala) 
		{
		   if (t->m == NULL)
           {
                pema *k=new pema();
                k->fjala=x;
                t->m=k;
				c++; 
                return;
            }
			else t =t->m;
                    
        }
		else
		{
            if (t->d == NULL)
            {
                pema *k=new pema();
                k->fjala=x;
                k->d=NULL;
                k->m=NULL;
                t->d = k;
                c++;
                return;
            }
			else t =t->d;
       }
	
	}
	
}

void afisho (pema *p)
{
	if (p==NULL)
	return ;
	else
	{
		if (p->m!=NULL)
		{
			cout<<p->m->fjala<<" ";
			
			afisho(p->m);
			afisho(p->d);
		}
		else if (p->d!=NULL)
		{
			cout<<p->d->fjala<<" ";
			
		    afisho(p->m);
			afisho(p->d);
			
		}
	}
}





int main ()
{
	clock_t start, end;
    double cpu_time_used;
    start = clock();

	ifstream in;
	in.open("teksti1000000.txt");
	string x;
	pema *p= new pema();
	int c=0;


	if (in.is_open())
	{
		while (!in.eof())
		{
			in>>x;
			
			shto(p,x,c);
			
			
		}
		
	}
	
	afisho(p);
	cout<<endl;
	cout<<"nr i fjalve:"<<c+1<<endl;
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used;

	
	return 0;

}
