#include<iostream>
#include <limits>
using namespace std;
struct vertex{
	int dist;
	bool known;
	int parent;
};
class graph{
	vertex v[100];
	int a[100][100];
	int n,noe,cost;
	
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
			}
			for(i=0;i<n;i++){
				v[i].dist=INT_MAX;
				v[i].known=false;
				v[i].parent=0;
			}
		}
		int findmin(int a[100][100]){
			int i,minimum;
			for(i=0;i<n;i++){
				if(v[i].known==false){minimum =i; break;
				}
					
			}//cout<<minimum+1<<endl;
			for(i=0;i<n;i++){
				if(v[i].dist<v[minimum].dist && v[i].known==false)
					minimum=i;
			}
			
			return minimum;
		}
		void displayv(){
			int i;
			cout<<"Vertex\tDv\tPv"<<endl;
			for(i=1;i<n;i++){
				cout<<i+1<<"\t"<<v[i].dist<<"\t"<<v[i].parent<<endl;
			}
		}
		void displaya(){
			int i,j;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(a[i][j]==INT_MAX)
						cout<<"INF\t";
					else
						cout<<a[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		void prims(int ver){
			int i,minimum,flag=0;
			v[--ver].dist=0;
			v[ver].known=true; flag++;
			for(i=0;i<n;i++){
				if(a[ver][i]!=INT_MAX && a[ver][i]!=0){
					v[i].dist=a[ver][i];
					v[i].parent=ver+1;
				}
			}
			while(flag<n){
				minimum=findmin(a);
				cout<<"EXPLORED "<<minimum+1<<endl;
				v[minimum].known=true; flag++;
				for(i=0;i<n;i++){
					if(a[minimum][i]!=INT_MAX && a[minimum][i]!=0){
						if(!v[i].known){
							if(a[minimum][i]<v[i].dist){
								v[i].dist=a[minimum][i];
								v[i].parent=minimum+1;
							}
						}
					}
				}
			displayv();
			cout<<endl;
			}
			
		}
		
		void displayt(){
			cout<<"TOTAL COST : "<<cost<<endl;
		}
		void display(int source){
			int i;
			cost=0;
			cout<<"EDGES IN THE MST"<<endl;
			for(i=1;i<n;i++){
				
				cout<<v[i].parent<<" "<<i+1<<" "<<v[i].dist<<endl;
				cost=cost+v[i].dist;
			}
			//cout<<"TOTAL COST : "<<cost<<endl;
		}
};

int main(){
	int ch=1,ver;
	graph g;
	cout<<"1.INPUT GRAPH\n2.DISPLAY ADJACENCY MATRIX\n3.PERFORM PRIM'S\n4.DISPLAY EDGES IN MST\n5.DISPLAY TOTAL COST\n6.EXIT"<<endl;
	while(ch!=6){
		cout<<"\nENTER CHOICE : ";
		cin>>ch;
		if(ch==1) g.input();
		if(ch==2) g.displaya();
		if(ch==3){
			cout<<"Enter the source vertex : ";
			cin>>ver;
			g.prims(ver);
		}
		if(ch==4) g.display(ver);
		if(ch==5) g.displayt();
	}
	return 0;
}
