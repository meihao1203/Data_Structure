#ifndef __GRAPH_H__
#define __GRAPH_H__
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define graph_value_type int   //ͼ�������������
#define weight_vaule_type int
#define max_weight_value 0x7FFFFFFF   //Ĭ��int������signed int,0XFFFFFFFF ��������Ǹ������油�룬0X10000001 = -1
namespace meihao
{
	//ͼ���ٽ���󶼶�̬����ռ�
	using namespace std;
	static bool graph_error = false;
	class Graph
	{
	public:
		Graph(const string& fileName):_vertexNum(0)
			,_vertex(nullptr)
			,_arc(nullptr)
		{
			readGraphFromFile(fileName);
		}
		~Graph();
		void printVertexMatrix()const;
		void printGraphEdgeMatrix()const;
		int getGraphVertexNumber()const;
		weight_vaule_type getGraphEdgeWeight(int vi,int vj)const;
		graph_value_type getGraphVertexData(int vi)const;  //��ȡ��vi�������ֵ
		int setGraphEdgeWeight(int vi,int vj,int weight);  //�޸ıߵ�Ȩֵ
		int getOutDegree(int vi)const;  //��ȡĳһ������ĳ���
		int getInputDegree(int vi)const;  //��ȡĳһ����������
	protected:
		void readGraphFromFile(const string& fileName);
		void writeGraphFromFile(const string& fileName);
	private:
		int _vertexNum;  //ͼ�Ķ�����
		graph_value_type* _vertex;   //��������
		weight_vaule_type** _arc;      //�ڽӾ���,������
	};
};
#endif