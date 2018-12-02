#include<iostream>
using namespace std;
//�鲢����,������ϸ��Ϊ�������ںϲ�
int mergeArr(int* arr,int first,int mid,int last);
int mergeSort(int* arr,int first,int last);  //�ݹ�ʵ��
int metgeSortIterator(int* arr,int first,int last);  //�ǵݹ�ʵ��
void swap(int& elem1,int& elem2);
void test();
void printArr(int* arr,int length);
int main()
{
	test();
	system("pause");
}
void printArr(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return ;
	for(int idx=0;idx!=length;++idx)
	{
		cout<<arr[idx]<<" ";
	}
	cout<<endl;
}
void test()
{
	int arr[] = {6,5,3,1,8,7,2,4};
	printArr(arr,8);
	mergeSort(arr,0,7);
	/*metgeSortIterator(arr,0,7);*/
	printArr(arr,8);
	cout<<endl;

	int arr1[] = {1,2,0,-1,5,6,8,3};
	printArr(arr1,8);
	mergeSort(arr1,0,7);
	/*metgeSortIterator(arr1,0,7);*/
	printArr(arr1,8);
	cout<<endl;

	int arr2[] = {2,2,2,2};
	printArr(arr2,4);
	mergeSort(arr2,0,3);
	//metgeSortIterator(arr2,0,3);
	printArr(arr2,4);
	cout<<endl;

	int arr3[] = {2,4,1};
	printArr(arr3,3);
	mergeSort(arr3,0,2);
	/*metgeSortIterator(arr3,0,2);*/
	printArr(arr3,3);
	cout<<endl;

	int arr5[] = {1,2,3,4,5,6,7,8};
	printArr(arr5,8);
	mergeSort(arr5,0,7);
	/*metgeSortIterator(arr5,0,7);*/
	printArr(arr5,8);
	cout<<endl;

	int* arr6 = NULL;
	printArr(arr6,4);
	mergeSort(arr6,0,3);
	/*metgeSortIterator(arr6,0,3);*/
	printArr(arr6,4);
	cout<<endl;
}
void swap(int& elem1,int& elem2)
{
	int tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
}
int mergeArr(int* arr,int first,int mid,int last)
{
	if(NULL==arr||first>last||first>mid||mid>last||first<0||mid<0||last<0)
		return -1;
	int len = last - first +1;
	int* tmpArr = new int[len]();
	int firIdx = first,lasIdx = mid + 1;
	int idx = 0;
	while(firIdx<=mid&&lasIdx<=last)
	{
		if(arr[firIdx]<arr[lasIdx])
			tmpArr[idx++] = arr[firIdx++];
		else
			tmpArr[idx++] = arr[lasIdx++];
	}
	while(firIdx<=mid)
		tmpArr[idx++] = arr[firIdx++];
	while(lasIdx<=last)
		tmpArr[idx++] = arr[lasIdx++];
	for(int iidx=first,idx=0;iidx<=last;++iidx)
		arr[iidx] = tmpArr[idx++];
	delete []tmpArr;
	return 0;
}
int mergeSort(int* arr,int first,int last)
{
	if(NULL==arr||first<0||last<0||first>last)
		return -1;
	int mid = (first + last)/2;
	if(first<last)  //����Ϊֻ��һ��Ԫ��
	{
		mergeSort(arr,first,mid);
		mergeSort(arr,mid+1,last);
	}
	//�ϲ�
	mergeArr(arr,first,mid,last);
	return 0;
}
int metgeSortIterator(int* arr,int first,int last)
{
	if(NULL==arr||first<0||last<0||first>last)
		return -1;
	//�ǵݹ飬ֱ�Ӻϲ�
	for(int idx=1;idx<=last;idx*=2)  //���������ϲ������Գ���2�������1��ʼ����ʾ���鶼����Ϊ1�ĵ�������
	{
		int firstIdx = 0;
		while(firstIdx+idx<=last)
		{
			int mid = firstIdx + idx -1;
			//last�������������������������������ʣ��һ��Ԫ��
			int lastIdx = mid + idx <= last ? mid + idx : last;
			mergeArr(arr,firstIdx,mid,lastIdx);
			firstIdx = lastIdx + 1;  //��ʼ�ϲ���һ��������
		}
	}
	return 0;
}
//6 5 3 1 8 7 2 4
//1 2 3 4 5 6 7 8
//
//1 2 0 -1 5 6 8 3
//-1 0 1 2 3 5 6 8
//
//2 2 2 2
//2 2 2 2
//
//2 4 1
//1 2 4
//
//1 2 3 4 5 6 7 8
//1 2 3 4 5 6 7 8