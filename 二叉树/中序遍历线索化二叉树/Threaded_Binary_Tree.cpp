#include<iostream>
using namespace std;
enum TBT{child=0,thread};  //��������������ָ����ָ���ӻ���ǰ�����
typedef struct tbt
{
	struct tbt* lchild;
	enum TBT ltag;
	char data;
	enum TBT rtag;
	struct tbt* rchild;
}TBTreeNode,*pTBTree;
int createThreadedBinaryTree(pTBTree& root);
void inorderThreadingBinaryTree(const pTBTree& root);  //����������������
//�����������ͬʱ��������������
void inorderThreadingBinaryTreeTraversal(pTBTree root); //��������������������
int main()
{
	TBTreeNode* root = nullptr;
	int ret = createThreadedBinaryTree(root);
	{
		if(0==ret)
		{
			inorderThreadingBinaryTree(root);
			cout<<endl;
			inorderThreadingBinaryTreeTraversal(root);
			cout<<endl;
		}
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
		else 
		{//��data��������ʼ��root��㣬Ȼ��ݹ齨����������������
			root = new TBTreeNode();  //��������ʱ��Ͱѽ��ȫ����ֵΪ��
			root->data = data;
			createThreadedBinaryTree(root->lchild);
			createThreadedBinaryTree(root->rchild);
		}
	}
	return 0;
}

static TBTreeNode* pre = nullptr;  //����һ��ָ��ָ�����������ǰ���ʽ���ǰһ�����ʽ��
//���������ĺ��Ҫ�õ�,��Ϊ�������˳��������,����㣬������
//ǰ�������øոշ��ʹ��Ľ��ֱ�Ӹ�ֵ����̻�û�з��ʣ���ʱ��ǰ��������һ�����ʽ��pre�ĺ��
//��Ȼ��ǰ��������pre��������Ϊ��
//pre��ʼֵΪnullptr,��Ϊ�Ӹ���㿪ʼ���ʣ�ǰһ�����ʽ���ֻ���ǿ���
void inorderThreadingBinaryTree(const pTBTree& root)
{
	if(nullptr==root)
		return ;
	/*  �ο��������
	inorderTraversal(root->lchild);
	cout<<root->data<<" ";
	inorderTraversal(root->rchild);
	*/
	inorderThreadingBinaryTree(root->lchild);   //�������������
	//�жϽ��ָ����ɲ�����������
	if(nullptr==root->lchild)  //���������Ϊ�գ��Ϳ��԰�ָ����������������ָ��ǰ��
	{
		root->lchild = pre;
		root->ltag = thread;
	}
	if(nullptr!=pre&&nullptr==pre->rchild)  //�����ǰ���ʵĸ���㲻Ϊ�գ�����ǰ����ʵĽ��pre������Ϊ�գ�������ǰһ�����ĺ��
	{
		pre->rchild = root;
		pre->rtag = thread;
	}
	//���ʸ����ͱ���޸�ǰһ�����ʽ��ָ��pre
	pre = root;  //֮��Ҫ��������������ǰ�����Ȼ����pre
	inorderThreadingBinaryTree(root->rchild);  //�������������
}
void inorderThreadingBinaryTreeTraversal(pTBTree root)
{
	if(nullptr==root)
		return;
	while(nullptr!=root)
	{
		while(nullptr!=root->lchild&&child==root->ltag)  //�����������������������һ������ǰ����nullptr
		{//��Ѱ�Ӹ���㿪ʼ�������������һ���ڵ�
			root = root->lchild;
		}
		cout<<root->data<<" ";  //��������
		while(thread==root->rtag)  //�ý���к��,��ζ��û��������
		{
			cout<<root->rchild->data<<" ";  //ֱ�������̣�Ҳ�������������ǰ�����һ��Ҫ���ʵĽ���ֵ
			root = root->rchild;  //�������ݵ����
		}
		//�ý������������root->rtag==child,�������Ѿ��������ˣ��������������
		root = root->rchild;   //�ظ�����Ĳ���
	}
}