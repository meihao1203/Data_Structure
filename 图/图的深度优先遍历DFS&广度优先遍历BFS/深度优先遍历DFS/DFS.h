#ifndef __DFS_H__
#define __DFS_H__
#include"Graph.h"
namespace meihao
{
	void DFS(const meihao::Graph& g,int vi,bool*& visited);  //������ͼ�Ͷ���������ĳ��������±�
	void DFSTraversal(const meihao::Graph& g);
};
#endif