#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Hash
{
public:
	int idNumber;
	int deleted;
	Hash();
};
Hash::Hash()
{
	idNumber=0;
	deleted=0;

}
int collision = 0;
int removeCounter = 0;
void insert(Hash *table,int type,int id,int M,int a1, int a2, int a3)
{
	int h;
	if(type == 1)
	{
		for(int i=0;i<M;i++)
		{
			h=(id+i)%M;
			if(table[h].deleted==0||table[h].deleted==-1)
			{
				Hash eleman;
				eleman.idNumber=id;
				if(table[h].deleted==-1) removeCounter--;
				eleman.deleted=1;
				cout<<"INSERT::"<<id<<" is inserted to "<<h<<"th slot."<<endl;
				table[h]=eleman;				
				if(i>0) collision++;
				return;
			}
			if(i>0) collision++;
		}
	}
	else if(type == 2)
	{
		for(int i=0;i<M;i++)
		{
			h=((id%M)+i*(1+(id%(M-1))))%M;
			if(table[h].deleted==0||table[h].deleted==-1)
			{
				Hash eleman;
				if(table[h].deleted==-1) removeCounter--;
				eleman.deleted=1;
				eleman.idNumber=id;
				cout<<"INSERT::"<<id<<" is inserted to "<<h<<"th slot."<<endl;
				table[h]=eleman;
				if(i>0) collision++;
				return;
			}
			if(i>0) collision++;
		}
	}
	else if(type == 3)
	{
		for(int i=0;i<M;i++)
		{
			h=((id%M)+i+i*i)%M;
			if(table[h].deleted==0||table[h].deleted==-1)
			{
				if(table[h].deleted==-1) removeCounter--;
				Hash eleman;
				eleman.idNumber=id;
				eleman.deleted=1;
				cout<<"INSERT::"<<id<<" is inserted to "<<h<<"th slot."<<endl;
				table[h]=eleman;
				if(i>0) collision++;
				return;
			}
			if(i>0) collision++;
		}
	}
	else if(type == 4)
	{
		int i=0;
		while(true)
		{
		int k1,k2,k3;
		k1=id/1000000;
		k2=(id%1000000)/1000;
		k3=id%1000;
		h=(k1*a1+k2*a2+k3*a3)%M;
		if((table[h].deleted==0||table[h].deleted==-1)&&i==0)
		{
			if(table[h].deleted==-1) removeCounter--;
			Hash eleman;
			eleman.idNumber=id;
			eleman.deleted=1;
			cout<<"INSERT::"<<id<<" is inserted to "<<h<<"th slot."<<endl;
			table[h]=eleman;
			return;
		}
		else
		{
			int k=(h+i)%M;
			if(table[k].deleted==0||table[k].deleted==-1)
			{
				if(table[k].deleted==-1) removeCounter--;
				Hash eleman;
				eleman.idNumber=id;
				eleman.deleted=1;
				cout<<"INSERT::"<<id<<" is inserted to "<<k<<"th slot."<<endl;
				table[h]=eleman;
				if(i>0) collision++;
				return;
			}
			if(i>0) collision++;
		}
		
		i++;
		}
	}

}
int search(Hash *table,int type,int id,int M,int a1, int a2, int a3)
{
	int h;
	if(type == 1)
	{
		int i;
		for(i=0;i<M;i++)
		{
			h=(id+i)%M;
			if(table[h].idNumber==id)
			{			
				return h;
			}
		}
		if(i>=M) return -1;
	}
	else if(type == 2)
	{
		int i;
		for(i=0;i<M;i++)
		{
			h=((id%M)+i*(1+(id%(M-1))))%M;
			if(table[h].idNumber==id)
			{
				return h;
			}
		}
		if(i>=M) return -1;
	}
	else if(type == 3)
	{
		int i;
		for(i=0;i<M;i++)
		{
			h=((id%M)+i+i*i)%M;
			if(table[h].idNumber==id)
			{
				return h;
			}
		}
		if(i>=M) return -1;
	}
	else if(type == 4)
	{
		int i=0;
		while(i<M)
		{
		int k1,k2,k3;
		k1=id/1000000;
		k2=(id%1000000)/1000;
		k3=id%1000;
		h=(k1*a1+k2*a2+k3*a3)%M;
		int k=(h+i)%M;
		if(table[h].idNumber==id && i==0) return h;
		else if (table[k].idNumber==id) return k;
		i++;
		}
		return -1;
	}

}
void remove(Hash *table,int type,int id,int M,int a1, int a2, int a3)
{
	int h = search(table, type, id, M,a1,a2,a3);
	if(h==-1)
	{
		cout<<"DELETE is not achieved "<< id <<" could NOT find"<<endl;
	}
	else if(removeCounter < 50)
	{
		removeCounter++;
	table[h].deleted=-1;
	cout<<"DELETE:: "<<h<<"th slot of table is deleted"<<endl;
	}
	else
	{
		int j=0;
		Hash *temp=new Hash[M];
		cout<<"DELETE could NOT achieved number of deletion = 0"<<endl;
		for(int i=0;i<=M;i++)
		{
			if(table[i].deleted==1)
			{
				temp[j].deleted=table[i].deleted;
				temp[j].idNumber=table[i].idNumber;
				j++;
			}
		}
		for(int i=0;i<=M;i++)
		{
			table[i].deleted=0;
			table[i].idNumber=0;
		}
		removeCounter=0;
		for(int i=0;i<j;i++)
		{
			insert(table,type,temp[i].idNumber,M,a1,a2,a3);
		}
		
	}
		
}
void update(Hash *table,int type,int id,int M,int id2,int a1, int a2, int a3)
{
	int h=search(table, type, id, M,a1,a2,a3);
	if(h==-1)
	{
		cout<<"UPDATE is not achieved "<< id <<" could NOT find"<<endl;
	}
	else
	{

	cout<<"UPDATE:: old id of "<<h<<"th slot is "<<table[h].idNumber;
	remove(table, type, id, M,a1,a2,a3);
	insert(table,type,id2,M,a1,a2,a3);
	cout<<" new id is "<<id2<<"in"<<h<<"th slot"<<endl;
	
	}
}

int main()
{
	
	ifstream file;
	file.open("operations.txt");
	char* operation = new char;
	int id1,id2;
	int M,type;
	cout<<"M - type:";
	cin>>M>>type;
	srand (time(NULL));
	int a1=rand() % M;
	int a2=rand() % M;
	int a3=rand() % M;
	Hash *table = new Hash[M];
	while(!file.eof())
	{
		
		file>>operation;
		file>>id1;
		
		if(strcmp(operation,"update")==0)
		{
			file>>id2;
			update(table, type, id1, M, id2,a1,a2,a3);
		}
		else if(strcmp(operation,"insert")==0)
		{
			insert(table, type, id1, M,a1,a2,a3);
		}
		else if(strcmp(operation,"delete")==0)
		{
			remove(table, type, id1, M,a1,a2,a3);
		}
		else if(strcmp(operation,"search")==0)
		{
			int a=search(table, type, id1, M,a1,a2,a3);
			if(a==-1) cout<<"SEARCH:: "<< id1 <<" could NOT be found"<<endl;
			else cout<<"SEARCH:: "<<id1<<" found in "<<a<<"th slot"<<endl;
		}

	}
	cout<<"collision:"<<collision;
	return 0;
}


