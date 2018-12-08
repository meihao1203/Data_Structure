//������
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#if 0
typedef struct BinaryTreeNode  //������������ݽṹ
{
	char data;  
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode,*pBTNode;
//����һ��������
int createBinaryTree(pBTNode& root);
//�����������ֱ���
void preorderTraversal(const pBTNode& root);  //ǰ�����,������
void inorderTraversal(const pBTNode& root);  //��������������
void postorderTraversal(const pBTNode& root);  //������������Ҹ�
int main()
{
	do{
		BTNode* root;  //����һ�������ָ��
		createBinaryTree(root);
		cout<<"preorder traversal:"<<endl;
		preorderTraversal(root);
		cout<<endl<<endl;

		cout<<"inorder traversal:"<<endl;
		inorderTraversal(root);
		cout<<endl<<endl;;

		cout<<"postorder traversal:"<<endl;
		postorderTraversal(root);
		cout<<endl<<endl;;
	}while(cout<<"continue?(Y/N):",fflush(stdin),getchar()=='Y');
	system("pause");
}
int createBinaryTree(pBTNode& root)
{
	char data;
	//scanf("%c",&data);  //�س��������ȥ
	if(cin>>data)  //������while, ��Ȼ�ݹ�һֱ��whileѭ����ֱ��������
	{
		if('#'==data)  //������������ַ�Ϊ��#����ʾ�����Ϊ��
			root = NULL;
		else if('\n'!=data)
		{
			root = new BTNode();
			root->data = data;
			createBinaryTree(root->lchild);  //�ݹ齨��������
			createBinaryTree(root->rchild);  //�ݹ齨��������
		}
	}
	return 0;
}
void preorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ; 
	cout<<root->data<<" ";  //ǰ�����������������
	preorderTraversal(root->lchild);  //ǰ�����������
	preorderTraversal(root->rchild);  //ǰ�����������
}
void inorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ;
	inorderTraversal(root->lchild);  //�������������
	cout<<root->data<<" ";  //�������������������
	inorderTraversal(root->rchild);  //�������������
}
void postorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ;
	postorderTraversal(root->lchild);  //�������������
	postorderTraversal(root->rchild);  //�������������
	cout<<root->data<<" ";  //�������������������
}
#endif
//AB##C##
//preorder traversal:
//A B C
//
//inorder traversal:
//B A C
//
//postorder traversal:
//B C A
//
//continue?(Y/N):Y
//ABC###DE##F##
//preorder traversal:
//A B C D E F
//
//inorder traversal:
//C B A E D F
//
//postorder traversal:
//C B E F D A
//
//continue?(Y/N):N