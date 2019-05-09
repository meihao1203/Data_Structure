#ifndef __KRUSCAL_H__
#define __KRUSCAL_H__
#include"Graph.h"
namespace meihao
{
	typedef struct EdgeSetArr  //�߼�����
	{
		int begin;  //�����
		int end;    //���յ�
		weight_vaule_type weight;  //��Ȩֵ
	}edges;
	void readEgdesFromGraph(const meihao::Graph& g);  //��ͼ�ж���������Ҫ�ı߼�����
	int find(int* parent,int vi);
	void MiniSpanTree_Kruskal(const meihao::Graph& g);
};
#endif