#include<iostream>
#include<stack>
using namespace std;
typedef struct BinaryTree
{
	char data;
	struct BinaryTree* lchild;
	struct BinaryTree* rchild;
}binaryTreeNode,*pBinaryTree;
int createBinaryTree(pBinaryTree& root);
//�ǵݹ�ʵ��ǰ�����������ջ��ģ��ݹ����
void preorderTraversalNonRecursion(pBinaryTree root);  
//�ǵݹ�ʵ���������������ջ��ģ��ݹ����
void inorderTraversalNonRecursion(pBinaryTree root);
//�ǵݹ�ʵ�ֺ������,����ջ��ģ��ݹ����
void postorderTraversalNonRecursion(pBinaryTree root);
int main()
{
	pBinaryTree root = nullptr;
	int ret = createBinaryTree(root);
	if(0==ret)
	{
		cout<<"preorder traversal non-recursion:"<<endl;
		preorderTraversalNonRecursion(root);
		cout<<endl<<endl;;
		cout<<"inorder traversal non-recursion:"<<endl;
		inorderTraversalNonRecursion(root);
		cout<<endl<<endl;;
		cout<<"postorder traversal non-recursion:"<<endl;
		postorderTraversalNonRecursion(root);
		cout<<endl;
	}

	cout<<endl;
	system("pause");
}
int createBinaryTree(pBinaryTree& root)
{
	char data;
	if(cin>>data)
	{
		if('#'==data)  //����#��ʾ�ý��Ϊ��
		{
			root = NULL;  
			return -1;  //ֻҪ��������#�Ż᷵��-1����ʾ����
		}		
		//���������
		binaryTreeNode* node = new binaryTreeNode();
		node->data = data;
		root = node;
		//�ݹ�ȥ����������
		createBinaryTree(root->lchild);
		//�ݹ�ȥ����������
		createBinaryTree(root->rchild);
	}
	return 0;   //���յݹ鷵�ص���0��
}

void preorderTraversalNonRecursion(pBinaryTree root)
{//���ʽڵ�˳���ǣ�����㣬��������������;����������������ǰ��ո����ҵ�˳����ʣ��������������Ҫ��¼�����
	if(nullptr==root)
		return;
	stack<binaryTreeNode*> rootNode;  //���������м�¼�����
	while(!rootNode.empty()||
		nullptr!=root)
	{
		while(nullptr!=root)
		{
			cout<<root->data<<" ";  //��������
			//����������
			rootNode.push(root);  //��¼�������ĸ���㣬ǰ��������ݷ�����������ʱ��Ҫ�õ�
			root = root->lchild;
		}//һֱ����������ߵ����һ����㣬�϶�������Ϊ���ˣ���whileѭ������ʱ���Ҫ���ݷ�����������
		if(!rootNode.empty())
		{
			root = rootNode.top();  //ջ��ȡ�������ջ�ĸ����
			root = root->rchild;  //�����ָ��������
			rootNode.pop();  //���ѹջ�ĸ���㵯ջ
			//������Ҳ��һ�ö��������ֻص��ڶ���whileѭ����ǰ������������ҵķ�������������
		}

	}
}
void inorderTraversalNonRecursion(pBinaryTree root)
{//������������㣬������
	if(nullptr==root)
		return ;
	stack<binaryTreeNode*> rootNode;
	while(nullptr!=root||
		!rootNode.empty())
	{
		while(nullptr!=root)
		{
			rootNode.push(root);  //ջ�б������㣬��ȥ����������
			root = root->lchild;
		}//�������������
		cout<<rootNode.top()->data<<" ";  //���ʸ����
		root = rootNode.top()->rchild;  //����������
		rootNode.pop();  //��ջ�������Ľ��
	}
}

typedef struct Traversal
{
	binaryTreeNode* rootAddr;   //����������ַ
	bool accessToken;  //���ʱ��
}traversalInfo,*pTraversal;

//�򻯲���
void stackPush(stack<traversalInfo>& rootNodeInfo,binaryTreeNode* &rootAddr,bool&& flag)
{
	traversalInfo tmp;
	tmp.rootAddr = rootAddr;
	tmp.accessToken = flag;  //��һ�η���,�ڶ��η����޸�Ϊtrue�������Ϣ
	rootNodeInfo.push(tmp);
}
void postorderTraversalNonRecursion(pBinaryTree root)
{//������������������������������
	//��������������Ҫ���ݵ������ȥ������������������Ҫһ���������¼����㣬����ǵڶ��α�������ֱ�����ֵ
	if(nullptr==root)
		return ;
	stack<traversalInfo> rootNodeInfo;
	while(nullptr!=root)   //��������������Ż����
	{
		//����������
		stackPush(rootNodeInfo,root,false);
		//traversalInfo tmp;
		//tmp.rootAddr = root;
		//tmp.accessToken = false;  //��һ�η���,�ڶ��η����޸�Ϊtrue�������Ϣ
		//rootNodeInfo.push(tmp);  //������������;�ĸ������ջ

		root = root->lchild;
	}//��ʼ���ݱ���������
	while(!rootNodeInfo.empty())
	{
		root = rootNodeInfo.top().rootAddr;  //ȡ��������ʵĸ����
		//����������
		while(nullptr!=root->rchild&&
			!rootNodeInfo.top().accessToken)  //���������գ����Ҹ����ֻ���ڵ�һ�η���
		{
			rootNodeInfo.top().accessToken = true;  //�����ڶ��η��ʣ��޸�Ϊtrue���´λ��ݷ��ʵ���Ҫ���
			//������������ջ
			root = root->rchild;
			stackPush(rootNodeInfo,root,false);
			//traversalInfo tmp;
			//tmp.rootAddr = root;
			//tmp.accessToken = false;
			//rootNodeInfo.push(tmp);

			//�����������������գ����ű���������
			while(nullptr!=root->lchild)  
			{
				root = root->lchild;
				stackPush(rootNodeInfo,root,false);
				/*traversalInfo tmp;
				tmp.rootAddr = root;
				tmp.accessToken = false;
				rootNodeInfo.push(tmp);*/
			}//��������������������ϣ����ݱ�������������������
		}
		//��������Ϣ
		//ִ���������ֻ�����������1����Ӧ����������߽��û��������������������������߽��
		//2�������ٴη��ʵ�����㣬����3��whileѭ���ĵڶ�������!rootNodeIndo.top().accessToken������
		cout<<rootNodeInfo.top().rootAddr->data<<" ";
		rootNodeInfo.pop();  //��ջ
	}
}
/* ��������һ */
//AB##C##
//preorder traversal non-recursion:
//A B C
//
//inorder traversal non-recursion:
//B A C
//
//postorder traversal non-recursion:
//B C A
//
//�밴���������. . .


/* ���������� */
//ABC###DE##F##
//preorder traversal non-recursion:
//A B C D E F
//
//inorder traversal non-recursion:
//C B A E D F
//
//postorder traversal non-recursion:
//C B E F D A
//
//�밴���������. . .