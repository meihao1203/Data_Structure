#include"DFS.h"
namespace meihao
{
	void DFS(const meihao::Graph& g,int vi,bool*& visited)
	{
		visited[vi] = true;  //�޸ĵ�vi�����ķ��ʱ��Ϊtrue
		cout<<g.getGraphVertexData(vi)<<" ";
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			if(1==g.getGraphEdgeWeight(vi,idx)&&
				false==visited[idx])  //���(vi,idx)֮����ڱߣ�==1�������ҵ�idx�����㻹û�з��ʹ�
			{
				DFS(g,idx,visited);  //�ݹ������idx������
			}
		}
	}
	void DFSTraversal(const meihao::Graph& g)
	{
		bool* visited = new bool[g.getGraphVertexNumber()];
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			visited[idx] = false;  //��ʼ�����ʱ�ǣ�ȫ��Ϊfalse����ʾδ����
		}
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			if(false==visited[idx])  //���ѡһ���㣬���δ���ʹ����ʹ�����ʼ������ȱ���
				DFS(g,idx,visited);
		}
	}
};