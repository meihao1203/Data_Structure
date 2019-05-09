#include"Graph.h"
namespace meihao
{
	void Graph::readGraphFromFile(const string& filename)
	{
		ifstream ifs(filename.c_str(),ios::in|ios::out);  //���ļ����ɶ���д
		if(ifs.bad())
		{
			cout<<"read file data init Graph failure!"<<endl;
			return ;
		}
		ifs>>_vertexNum;
		_vertex = new graph_value_type[_vertexNum]();
		for(int idx=0;idx!=_vertexNum;++idx)  //��ʼ����������
			ifs>>_vertex[idx];
		//��̬���ٶ�ά������ڴ�ռ�
		_arc = new weight_vaule_type*[_vertexNum]();
		for(int idx=0;idx!=_vertexNum;++idx)
		{
			_arc[idx] = new weight_vaule_type[_vertexNum]();
		}
		//��ʼ�������飬�ڽӾ���
		for(int idx=0;idx!=_vertexNum;++idx)  
		{
			for(int iidx=0;iidx!=_vertexNum;++iidx)
			{
				ifs>>_arc[idx][iidx];
			}
		}
		ifs.close();
	}
	void Graph::writeGraphFromFile(const string& fileName)
	{
		ofstream ofs(fileName.c_str(),ios::out);
		if(ofs.bad())
		{
			cout<<"write file Graph failure!"<<endl;
			return ;
		}
		//д������
		ofs<<_vertexNum<<endl;
		//д��������
		for(int idx=0;idx!=_vertexNum;++idx)
		{
			ofs<<_vertex[idx]<<" ";
		}
		ofs<<endl;
		//д�ڽӾ���
		for(int idx=0;idx!=_vertexNum;++idx)
		{
			for(int iidx=0;iidx!=_vertexNum;++iidx)
			{
				ofs<<_arc[idx][iidx]<<" ";
			}
			ofs<<endl;
		}
		ofs<<endl;
	}
	void Graph::printVertexMatrix()const
	{
		for(int idx=0;idx!=_vertexNum;++idx)
		{
			cout<<_vertex[idx]<<" ";
		}
		cout<<endl;
	}
	void Graph::printGraphEdgeMatrix()const
	{
		for(int idx=0;idx!=_vertexNum;++idx)
		{
			for(int iidx=0;iidx!=_vertexNum;++iidx)
			{
				cout<<_arc[idx][iidx]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	int Graph::getGraphVertexNumber()const
	{
		return _vertexNum;
	}
	weight_vaule_type Graph::getGraphEdgeWeight(int vi,int vj)const
	{
		if(vi<0||vj<0||vi==vj||vi>=_vertexNum||vi>=_vertexNum)
		{
			graph_error = true;
			return -1;   //��Ϊͼ��Ȩֵ�����Ǹ�����Ϊ�����֣�����һ��bool���������ʲô�����-1��ʾ������
		}
		return _arc[vi][vj];
	}
	graph_value_type Graph::getGraphVertexData(int vi)const
	{
		return _vertex[vi];
	}
	int Graph::setGraphEdgeWeight(int vi,int vj,weight_vaule_type weight)
	{
		if(vi<0||vj<0||vi==vj||vi>=_vertexNum||vi>=_vertexNum||weight>max_weight_value_type)
		{
			graph_error = true;
			return -1;   
		}
		_arc[vi][vj] = weight;
		writeGraphFromFile("data.txt");
	}
	int Graph::getOutDegree(int vi)const
	{
		if(vi<0||vi>=_vertexNum)
		{
			graph_error = true;
			return -1;
		}
		int OD = 0;
		for(int idx=0;idx!=_vertexNum;++idx)
			OD += _arc[vi][idx];
		return OD;
	}
	int Graph::getInputDegree(int vi)const
	{
		if(vi<0||vi>=_vertexNum)
		{
			graph_error = true;
			return -1;
		}
		int ID = 0;
		for(int idx=0;idx!=_vertexNum;++idx)
			ID += _arc[idx][vi];
		return ID;
	}
	Graph::~Graph()
	{
		if(nullptr!=_vertex)
		{
			delete []_vertex;
			_vertex = nullptr;
		}	
		if(nullptr!=_arc)
		{
			for(int idx=0;idx!=_vertexNum;++idx)
				delete []_arc[idx];
			delete []_arc;
			_arc = nullptr;
		}	
	}
};