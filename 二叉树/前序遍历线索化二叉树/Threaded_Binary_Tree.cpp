#include<iostream>
using namespace std;
enum TBT{child=0,thread};
typedef struct tbt
{
	struct tbt* lchild;
	enum TBT ltag;
	char data;
	enum TBT rtag;
	struct tbt* rchild;
}TBTreeNode,*pTBTree;
int createThreadedBinaryTree(pTBTree& root);
//����������+����
void inorderThreadingBinaryTree(const pTBTree& root,TBTreeNode*& pre); 
void inorderThreadedBinaryTreeTraversal(pTBTree root);
//ǰ��������+����
void preorderThreadingBinaryTree(const pTBTree& root,TBTreeNode*&pre);
void preorderThreadedBinaryTreeTraversal(pTBTree root);

int main()
{
	TBTreeNode* root = nullptr;
	int ret = createThreadedBinaryTree(root);
	if(0==ret)
	{
		TBTreeNode* pre = nullptr;
		//inorderThreadingBinaryTree(root,pre);
		//cout<<"inorder traversal Threaded Binary Tree:"<<endl;
		//inorderThreadedBinaryTreeTraversal(root);
		//cout<<endl;

		pre = nullptr;
		preorderThreadingBinaryTree(root,pre);
		cout<<"preorder traversal Threaded Binary Tree:"<<endl;
		preorderThreadedBinaryTreeTraversal(root);
		cout<<endl;
	}
	system("pause");
}
int createThreadedBinaryTree(pTBTree& root)
{
	char data;
	if(cin>>data)
	{
		if('#'==data)
		{
			root = nullptr;
			return -1;
		}
		root = new TBTreeNode();
		root->data = data;
		createThreadedBinaryTree(root->lchild);
		createThreadedBinaryTree(root->rchild);
	}
	return 0;
}

void inorderThreadingBinaryTree(const pTBTree& root,TBTreeNode*& pre)
{
	if(nullptr==root)
		return ;
	inorderThreadingBinaryTree(root->lchild,pre);
	if(nullptr==root->lchild)
	{
		root->lchild = pre;
		root->ltag = thread;
	}
	if(nullptr!=pre&&nullptr==pre->rchild)
	{
		pre->rchild = root;
		pre->rtag = thread;
	}
	pre = root;
	inorderThreadingBinaryTree(root->rchild,pre);
}
void inorderThreadedBinaryTreeTraversal(pTBTree root)
{
	if(nullptr==root)
		return ;
	while(nullptr!=root)
	{
		while(nullptr!=root->lchild&&child==root->ltag)
		{
			root = root->lchild;
		}
		cout<<root->data<<" ";
		while(thread==root->rtag)
		{
			cout<<root->rchild->data<<" ";
			root = root->rchild;
		}
		root = root->rchild;
	}
}

void preorderThreadingBinaryTree(const pTBTree& root,TBTreeNode*&pre)
{
	if(nullptr==root)
		return ;
	/*  �ο��������
	cout<<root->data;
	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
	*/
	// ����˳�򣺸���㣬��������������
	//pre��Զָ��ǰ���ʽ��root��ǰһ�����ʹ��Ľ�㣬��ʼΪnull
	if(nullptr==root->lchild)
	{
		root->lchild = pre;
		root->ltag = thread;
	}
	if(nullptr!=pre&&nullptr==pre->rchild)
	{//Ҫ������һ�������ĺ�̣����պ������˳��ֻ�ܷ��ʵ�root��ʱ�����������ǰһ�����pre�ĺ�̣�ǰ��preҪ����null,����û��������
		pre->rchild = root;
		pre->rtag = thread;
	}
	pre = root;
	//��������������������������Ϊ��ǰ����ȷ��ʵ���ͬʱ����������
	//���������������������Ҫ�ж�һ�������������������������������ǰ�����
	if(child==root->ltag)
	{
		preorderThreadingBinaryTree(root->lchild,pre);
	}
	if(child==root->rtag)
	{
		preorderThreadingBinaryTree(root->rchild,pre);
	}
}
void preorderThreadedBinaryTreeTraversal(pTBTree root)
{
	if(nullptr==root)
		return ;
	while(nullptr!=root)
	{
		while(nullptr!=root->lchild&&
			child==root->ltag)
		{
			cout<<root->data<<" ";  //���ʸ����
			root = root->lchild;  //��������������
		}
		//������������߽��
		cout<<root->data<<" ";
		//ͨ����̱�����һ��Ҫ���ʵĽ��
		while(thread==root->rtag)  //��ǰ����к��
		{
			cout<<root->rchild->data<<" ";  //������
			root = root->rchild;  //���¸����
		}
		//������û�к�̣���ô������������
		//�����������������жϵ�ǰ�����û�����������о͸��¸�����ȱ���������
		if(child==root->ltag)
			root = root->lchild;
		//û�оͱ���������
		else 
			root = root->rchild;
	}
}
//ab##c##
//preorder traversal Threaded Binary Tree:
//a b c
//�밴���������. . .

//ABC###DE##F##
//preorder traversal Threaded Binary Tree:
//A B C D E F
//�밴���������. . .

//ABDH##I##EJ###CF##G##
//preorder traversal Threaded Binary Tree:
//A B D H I E J C F G
//�밴���������. . .