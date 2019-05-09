#include"Graph.h"
#include"Kruskal.h"
#include<iostream>
using namespace std;
int main()
{
	meihao::Graph g("data.txt");
	cout<<"MiniSpanTree_Kruskal:"<<endl;
	meihao::MiniSpanTree_Kruskal(g);
	cout<<endl;

}

//MiniSpanTree_Kruskal:
//(4,7) (2,8) (0,1) (0,5) (1,8) (1,6) (3,7) (6,7)
//
