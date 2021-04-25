#include<stack>
#include<queue>
#include<iostream>


template<class ElemType>
class BST
{
private:
	typedef struct Node {
		ElemType data;
		struct Node* left, * right,*parent;
	}Node;

typedef struct BTNode{
		Node* btnode;
		bool isFirst;
	}BTNode;



public:
	
	Node* root;      //��
	/**
	 * BST initialize
	 * @param BinarySortTreePtr BST
	 * @return is complete
	 */
	BST();

	/**
	 * BST insert
	 * @param BinarySortTreePtr BST
	 * @param ElemType value to insert
	 * @return is successful
	 */
	bool BST_insert(ElemType data);
	/*���BST_insert����ʵ�ֵݹ�*/
	void BST_insert_recu(Node* current, ElemType data);

	/**
	 * BST delete
	 * @param BinarySortTreePtr BST
	 * @param ElemType the value for Node which will be deleted
	 * @return is successful
	 */
	Node* BST_search(Node* T, ElemType data);  //���ؽڵ�ָ��
	/*����ڵ����Ϣ*/
	void BST_search_result(Node* T, ElemType data);


	/**
	 * BST search
	 * @param BinarySortTreePtr BST
	 * @param ElemType the value to search
	 * @return is exist
	 */
	bool BST_delete(Node* T, ElemType key);         //T��ʼӦ��Ϊroot
	/*���BST_delete����ʵ�ֵݹ�*/
	bool Delete(Node* T);



	/**
	 * BST preorder traversal without recursion
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	void BST_preorderI(Node* T);

	/**
	 * BST preorder traversal with recursion
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	void BST_preorderR(Node* T);

	///**
	// * BST inorder traversal without recursion
	// * @param BinarySortTreePtr BST
	// * @param (*visit) callback
	// * @return is successful
	// */
	void BST_inorderI(Node* T);

	///**
	// * BST inorder traversal with recursion
	// * @param BinarySortTreePtr BST
	// * @param (*visit) callback
	// * @return is successful
	// */
	void BST_inorderR(Node* T);

	///**
	// * BST preorder traversal without recursion
	// * @param BinarySortTreePtr BST
	// * @param (*visit) callback
	// * @return is successful
	// */
	void BST_postorderI(Node* T);

	///**
	// * BST postorder traversal with recursion
	// * @param BinarySortTreePtr BST
	// * @param (*visit) callback
	// * @return is successful
	// */
	void BST_postorderR(Node* T);

	///**
	// * BST level order traversal
	// * @param BinarySortTreePtr BST
	// * @param (*visit) callback
	// * @return is successful
	// */
	void BST_levelOrder(Node* T);
	ElemType CreatData();
};


template<class ElemType>
BST<ElemType>::BST()
{
	root = NULL;
}

template<class ElemType>
bool BST<ElemType>::BST_insert(ElemType data)
{

	if (root == NULL) {//�����Ϊ�գ��ͽ�����ڵ�ŵ����ڵ�
		Node* node = new Node;  //����һ���ڵ㣬�����ŵ��ڵ���
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		node->parent = NULL;
		root = node;
	}
	else
	{
		BST_insert_recu(root, data);
	}
	return true;
}

template<class ElemType>
void BST<ElemType>::BST_insert_recu(Node* current, ElemType data)
{
	if (current->data == data)
	{
		std::cout << "�Ѿ����ڸ����ݣ�����ʧ��" << std::endl;
		return;
	}
	if (current->data < data) {		//�ڽڵ�current������������
		if (current->right == NULL) {		//����������Ҷ�ڵ�
			current->right = new Node;		//�����ɽڵ㲢���뵽��ǰ�ڵ���ҽڵ�
			current->right->data = data;
			current->right->left = nullptr;
			current->right->right = nullptr;
			current->right->parent = current;
		}
		else {
			BST_insert_recu(current->right, data);//�ݹ�ֱ��Ҷ�ӽڵ�
		}
	}
	else if (current->data > data) {		//�ڽڵ�����������룬����ͬ��
		if (current->left == NULL) {
			current->left = new Node;
			current->left->data = data;
			current->left->left = nullptr;
			current->left->right = nullptr;
			current->left->parent = current;
		}
		else {
			BST_insert_recu(current->left, data);
		}
	}
}
template<class ElemType>
typename BST<ElemType>::Node* BST<ElemType>::BST_search(Node* T, ElemType data)		//����1Ϊroot
{

	if (T == NULL)
		return NULL;

	if (data == T->data)
		return T;

	if (data < T->data)
		return BST_search(T->left, data);

	return BST_search(T->right, data);

}

template<class ElemType>
void  BST<ElemType>::BST_search_result(Node* T, ElemType data)
{
	Node* p = BST_search(T, data);
	if (p != NULL)
	{
		std::cout << "�ýڵ�";
		if (p->left != NULL)
			std::cout << data << "��Ϊ��" << p->left->data << " ";
		if (p->right != NULL)
			std::cout << "�Һ�Ϊ��" << p->right->data << std::endl;
		if (p->right == NULL && p->left == NULL)
			std::cout << "�޺���" << std::endl;
	}
	else
		std::cout << "δ�ҵ�������" << std::endl;
}

template<class ElemType>
bool BST<ElemType>::BST_delete(Node* T,ElemType key)
{
	if (T == NULL)
		return	false;
	else {
		if (T->data == key)
			return Delete(T);

		else if (T->data > key)
			return BST_delete(T->left, key);
		else
			return BST_delete(T->right, key);
	}
}

template<class ElemType>
bool BST<ElemType>::Delete(Node* T)
{
	Node *q,* s;
	if (T->left == NULL && T->right == NULL){
		if (T->parent->left == T) {
			T->parent->left = nullptr;
			free(T);
		}
		else {
			T->parent->right = nullptr;
			free(T);
		}
		return true;
	}
	if (T->right == NULL)
	{
		q = T;
		T = T->left;
		T->parent = q->parent;
		if (q->parent->left == q)		//���ӱ�ɾ�ڵ�ĸ��ڵ������ڵ�
			q->parent->left = T;
		else
			q->parent->right = T;
		free(q);
	}
	else if (T->left == NULL)
	{
		q = T;
		T = T->right;
		T->parent = q->parent;
		if (q->parent->left == q)		//���ӱ�ɾ�ڵ�ĸ��ڵ������ڵ�
			q->parent->left = T;
		else
			q->parent->right = T;
		free(q);
	}
	else
	{
		q = T;
		s = T->left;
		while (s->right)
		{
			q = s;
			s = s->right;
		}
		T->data = s->data;
		if (q != T)
			q->right = s->left;
		else
			q->left = s->left;
		//s->left->parent = q;
		free(s);
	}
	return true;
}


template<class ElemType>
void BST<ElemType>::BST_preorderR(Node* T)
{
	if (T != NULL) {
		std::cout << T->data << " ";
		BST_preorderI(T->left);
		BST_preorderI(T->right);
	}
	else 
		return;

}

template<class ElemType>
void BST<ElemType>::BST_preorderI(Node* T)
{
	std::stack<Node*> s;
	Node* p = T;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			std::cout << p->data << " ";
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}

}

template<class ElemType>
void BST<ElemType>::BST_inorderR(Node* T)
{
	if (T != NULL) {
		BST_inorderR(T->left);
		std::cout << T->data << " ";
		BST_inorderR(T->right);
	}
	else
		return;
}

template<class ElemType>
void BST<ElemType>::BST_inorderI(Node* T)
{
	std::stack<Node*>s;
	Node* p = T;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			std::cout << p->data << " ";
			s.pop();
			p = p->right;
		}
	}
}


template<class ElemType>
void BST<ElemType>::BST_postorderR(Node* T)
{
	if (T != NULL) {
		BST_postorderR(T->left);
		BST_postorderR(T->right);
		std::cout << T->data << " ";
	}
	else
		return;

}

template<class ElemType>
void BST<ElemType>::BST_postorderI(Node* T)
{
	std::stack<BTNode*> s;
	Node* p = T;
	BTNode* temp;
	while (p != NULL || !s.empty()){
		while (p != NULL){
			BTNode* btn = (BTNode*)malloc(sizeof(BTNode));
			btn->btnode = p;
			btn->isFirst = true;
			s.push(btn);
			p = p->left;
		}
		if (!s.empty()){
			temp = s.top();
			s.pop();
			if (temp->isFirst == true){
				temp->isFirst = false;
				s.push(temp);
				p = temp->btnode->right;
			}
			else{
				std::cout << temp->btnode->data << " ";
				p = NULL;
			}
		}
	}
}


template<class ElemType>
void BST<ElemType>::BST_levelOrder(Node* T)
{
	if (T == NULL)
		return;
	std::queue<Node*>s;
	s.push(T);
	while (!s.empty()) {
		Node* p = s.front();
		std::cout << p->data << " ";
		s.pop();
		if (p->left != NULL) {
			s.push(p->left);
		}
		if (p->right != NULL) {
			s.push(p->right);
		}
	}

}

template<class ElemType>
ElemType BST<ElemType>::CreatData()
{
	ElemType data;
	std::cout << "���������ݣ�";
	std::cin >> data;
	return data;
}