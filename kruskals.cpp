#include<iostream>
#include <limits>
#include<algorithm>
struct edge{
	int v1,v2,wt;
	bool accepted;
};
bool operator <(const edge e1,const edge e2){
			if(e1.wt<e2.wt)
				return true;
			else
				return false;
}
using namespace std;
class graph{
	int a[100][100];
	int n,noe;
	edge e[100];
	int vertices_set[100];	
	public:
		void input(){
			int i,p,q,r,j;
			cout<<"Enter number of vertices : ";
			cin>>n;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(i==j)
						a[i][j]=0;
					else
						a[i][j]=INT_MAX;
				}
			}
			cout<<"Enter the number of edges : ";
			cin>>noe;
			cout<<"Enter the edges connected along with weights"<<endl;
			for(i=0;i<noe;i++){
				cin>>p>>q>>r;
				a[--p][--q]=r;
				a[q][p]=r;
				e[i].v1=p;
				e[i].v2=q;
				e[i].wt=r;
				e[i].accepted=false;
			}
			for(i=0;i<n;i++){
				vertices_set[i]=i+1;
			}
		}
		void kruskal(){
			int i,val1,val2,j;
			sort(e,e+noe);
			cout<<endl;
			e[0].accepted=true;
			val1=vertices_set[e[0].v1];
			vertices_set[e[0].v2]=val1;
			for(i=1;i<noe;i++){
				if(vertices_set[e[i].v1]!=vertices_set[e[i].v2]){
					e[i].accepted=true;
					val1=vertices_set[e[i].v1];
					val2=vertices_set[e[i].v2];
					for(j=0;j<n;j++){
						if(vertices_set[j]==val1 || vertices_set[j]==val2)
							vertices_set[j]=val1;
					}
					//displayv();
					
				}
			}
		}
		void displayv(){
			int i;
			for(i=0;i<n;i++){
				cout<<vertices_set[i]<<" ";
			}
			cout<<endl;
		}
		void displaya(){
			int i,j;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(a[i][j]!=INT_MAX) cout<<a[i][j]<<"\t";
					else cout<<"INF\t";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		void displaye(){
			int i;
			sort(e,e+noe);
			for(i=0;i<noe;i++){
				cout<<e[i].v1+1<<" "<<e[i].v2+1<<" "<<e[i].wt<<endl;
			}
		}
		
		void displayt(){
			int i,cost=0;
			for(i=0;i<noe;i++){
				if(e[i].accepted==true){
					cost=cost+e[i].wt;
				}
			}
			cout<<"TOTAL COST IS "<<cost<<endl;
		}
		void display(){
			int i;
			cout<<"List of edges in MST"<<endl;
			for(i=0;i<noe;i++){
				if(e[i].accepted==true){
					cout<<e[i].v1+1<<" "<<e[i].v2+1<<" "<<e[i].wt<<endl;
				}
			}
		}
};

int main(){
	int ch=1;
	graph g;
	cout<<"1.INPUT GRAPH\n2.DISPLAY ADJACENCY MATRIX\n3.DISPLAY ALL EDGES\n4.PERFORM KRUSKAL'S\n5.DISPLAY EDGES IN MST\n6.DISPLAY TOTAL COST\n7.EXIT"<<endl;
	while(ch!=7){
		cout<<"\nENTER CHOICE : ";
		cin>>ch;
		if(ch==1) g.input();
		if(ch==2) g.displaya();
		if(ch==3) g.displaye();
		if(ch==4) g.kruskal();
		if(ch==5) g.display();
		if(ch==6) g.displayt();
	}
	return 0;
}
