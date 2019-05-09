#include"Prim.h"
#include<iostream>
namespace meihao
{
	typedef struct Arr
	{
		int vi;  //����vi
		weight_vaule_type weight;  //(vi,vj)��Ȩֵ
	}node,*pNode;
	//˼·��
	//�ӽ��0��ʼ������n-1��node�����飬�ֱ�ֵ(0,1),(0,2)...
	void MiniSpanTree_Prim(const meihao::Graph& g)
	{
		//��ȡ�������
		int vertexNum = g.getGraphVertexNumber();
		node* arr = new node[vertexNum]();
		for(int idx=1;idx!=vertexNum;++idx)
		{
			arr[idx].vi = 0;  //ѡȡ�ĳ�ʼ���0
			arr[idx].weight = g.getGraphEdgeWeight(0,idx);
		}
		for(int idx=1;idx!=vertexNum;++idx)
		{
			weight_vaule_type min = max_weight_value;
			int newVertex;
			for(int iidx=1;iidx!=vertexNum;++iidx)
			{
				if(0!=arr[iidx].weight&&arr[iidx].weight<min)
				{
					min = arr[iidx].weight;
					newVertex = iidx;
				}
			}
			cout<<"("<<arr[newVertex].vi<<","<<newVertex<<")"<<" ";
			arr[newVertex].weight = 0;
			//��������
			for(int iiidx=1;iiidx!=vertexNum;++iiidx)
			{
				if(0!=arr[iiidx].weight&&g.getGraphEdgeWeight(newVertex,iiidx)<arr[iiidx].weight)
				{
					arr[iiidx].vi = newVertex;  
					arr[iiidx].weight = g.getGraphEdgeWeight(newVertex,iiidx);
				}
			}
		}
	}
};
