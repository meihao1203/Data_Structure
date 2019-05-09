#include"Graph.h"
#include"Prim.h"
#include<iostream>
using namespace std;
int main()
{
	meihao::Graph g("data.txt");
	meihao::MiniSpanTree_Prim(g);
	cout<<endl;
}
//(0,1) (0,5) (1,8) (8,2) (1,6) (6,7) (7,4) (7,3)
//请按任意键继续. . .