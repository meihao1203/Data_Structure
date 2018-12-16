#include"Graph.h"
int main()
{
        meihao::Graph g("data.txt");
        cout<<"ͼ��������"<<g.getGraphVertexNumber()<<endl;
        cout<<"ͼ�������"<<endl;
        g.printVertexMatrix();
        g.printGraphEdgeMatrix();

        cout<<"��A����ȣ�"<<g.getInputDegree(0)<<endl;
        cout<<"��A�ĳ��ȣ�"<<g.getOutDegree(0)<<endl;

        cout<<"(A,C)="<<g.getGraphEdgeWeight(1,2)<<endl;

        cout<<"set <C,D> =5"<<endl;
        g.setGraphEdgeWeight(2,3,5);

        cout<<"(C,D) ="<<g.getGraphEdgeWeight(2,3)<<endl;

}
/*
ͼ��������4
ͼ�������
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

��A����ȣ�3
��A�ĳ��ȣ�3
(A,C)=1
set <C,D> =5
(C,D) =5
*/