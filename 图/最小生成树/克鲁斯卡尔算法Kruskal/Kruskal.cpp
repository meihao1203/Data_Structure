#include"Kruskal.h"
#include<iostream>
#include<vector>
#include<algorithm>
namespace meihao
{
	bool cmp(const edges& a,const edges& b)
	{
		return a.weight < b.weight;  //��С��������
	}
	void readEgdesFromGraph(const meihao::Graph& g,vector<edges>& edgeArr)
	{//����ͼ�ڽӾ����ǶԳƵģ�ֻ��ȡ�����Ǽ���
		int vertexCnt = g.getGraphVertexNumber();
		for(int idx=0;idx!=vertexCnt;++idx)
		{
			for(int iidx=idx;iidx!=vertexCnt;++iidx)
			{
				if(0!=g.getGraphEdgeWeight(idx,iidx)&&max_weight_value!=g.getGraphEdgeWeight(idx,iidx))
				{
					edges tmp;
					tmp.begin = idx;
					tmp.end = iidx;
					tmp.weight = g.getGraphEdgeWeight(idx,iidx);
					edgeArr.push_back(::move(tmp));
				}
			}
		}
		sort(edgeArr.begin(),edgeArr.end(),cmp);  //��С��������
	}
	void MiniSpanTree_Kruskal(const meihao::Graph& g)
	{
		vector<edges> edgeArr;  //�߼�����
		readEgdesFromGraph(g,edgeArr);
		//����parent���飬�����±��ӦΨһ��ͼ��㣬����ֵ��ӦС����ĸ���㣬��С����������һ����
		int vertexCnt = g.getGraphVertexNumber();
		int* parent = new int[vertexCnt]();  //��ʼ��ȫ��Ϊ0��parent[i] = 0,��ʾi���û�и���㣨����㣩
		int edgeCnt = edgeArr.size();  //�߼������С��Ҳ����ͼ�бߵ�����
		for(int idx=0;idx!=edgeCnt;++idx)
		{
			int firstFather = find(parent,edgeArr[idx].begin);
			int secondFather = find(parent,edgeArr[idx].end);
			if(firstFather!=secondFather)  //������������ߵĸ������ͬ������ٰ������߼��룬�ͻ���ֻ���
			{//������̾���һ���ҵ����̣���С������ֻ����һ������㣬���������߶������˵Ķ���ȥ�ҵ��ҵ���ͬ�ģ���ʱ���ټ��������߾ͳ��ֻ�����->��
				parent[firstFather] = secondFather;   //��������ߣ�(firstFather,secondFather),firstFather�ĸ����secondFather
				//����ҵ��ı�
				cout<<"("<<edgeArr[idx].begin<<","<<edgeArr[idx].end<<")"<<" ";
			}
		}
		cout<<endl;
	}
	//int find(int* parent,int vi)
	//{
	//	while(parent[vi]>0)  //vi����и����
	//	{
	//		vi = parent[vi];
	//	}
	//	return vi;
	//}
	int find(int* parent,int vi)
	{//�Ż�
		int viTmp = vi;
		while(parent[vi]>0)  //vi����и����
		{
			vi = parent[vi];  //�Ҹ����
		}
		while(vi!=viTmp)  
		{//vi�и���㣬����������и���㻹�����Ƚ�㣬��Ҫ˵����������������eg:0��1��5��0�ĸ���1,1�ĸ���5�� ��� 0��5��1��5
			int tmp = parent[viTmp];  //�ݴ����vi���(0)�ĸ����(tmp=1)
			parent[viTmp] = vi;  //(parent[0]=5)
			viTmp = tmp;  //0���1��
		}
		return vi;
	}
};