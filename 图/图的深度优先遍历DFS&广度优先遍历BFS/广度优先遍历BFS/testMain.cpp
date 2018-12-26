#include"BFS.h"
#include<iostream>
int main()
{
        meihao::Graph g("data.txt");
        meihao::BFSTraversal(g);
        cout<<endl;
        system("pause");
}
/*
A B F C G I E D H
*/