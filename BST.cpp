#include <iostream>
using namespace std;

typedef int Item;
struct Node {
	Item data;
	Node* left;
	Node* right;	
};
class BST {
public:	
	// methods
	BST();
	BST(Item v);
	Node* createNode(Item v);
	bool isEmpty();	
	void preOrder(Node* root);
	void inOrder(Node* root);
	void posOrder(Node* root);	
	void deleteTree(Node* &root);
	Node* search(Node* p, Item v);
	void insert(Node* &root, Item v);
	Node* minValueNode(Node* p);
	Node* maxValueNode(Node* p);
	Node* remove(Node* &root, int v);
	// variable
	Node* root;	
};

BST::BST() {
	root = NULL;
}

BST::BST(Item v) {
	root = createNode(v);
}

bool BST::isEmpty() {
	return (root == NULL);
}

void BST::preOrder(Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void BST::inOrder(Node* root)
{
	if(root != NULL) {
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

void BST::posOrder(Node* root)
{
	if(root != NULL) {
	   posOrder(root->right);
	   posOrder(root->left);
	   cout << root->data << " ";
	} 
}

Node* BST::createNode(Item v) {	
    Node* q = new Node;
	q->data = v;
	q->left = NULL;
	q->right = NULL;
	return q;
}

Node* BST::search(Node* p, Item v)
{
    if(p == NULL)
        return NULL;
    if(p->data == v)
        return p;
    Node* q;
    if(p->data > v)
        q = search(p->left, v);
    if(p->data < v)
        q = search(p->right, v);
    return q;
}

void BST::insert(Node* &root, Item v) {
    if(root == NULL)
		root = createNode(v);
	else 
	{
		if(v < root->data)
			insert(root->left, v);
		else if(v > root->data)
			insert(root->right, v);
	}	
}

// Node* BST::minValueNode(Node* p) 
// { 
//     Node *current = p;
//     while(current && current->left != NULL)
//     	current = current->left;
//     return current;
// } 


Node* BST::remove(Node* &root, int v)
{
    if(root == NULL)
		return root;
	if(v < root->data)
  		remove(root->left,v);
	else if(v > root->data)
		remove(root->right,v);
	else{
		if(root->left == NULL && root->right == NULL)
			root = NULL;
		else if(root->left == NULL){
			root=root->right;
		}
		else if(root->right == NULL){
			root=root->left;
		}
		else{
			root->data = minValueNode(root->right)->data;
			root->right = remove( root->right, root->data );	
		}
	}
	return root;
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Tạo một cây nhị phân gồm n nút, mỗi nút lưu một phần tử của một mảng số nguyên cho trước.
void nhap(Item &n, BST &bst)
{
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {    
        bst.insert(bst.root, a[i]);
    }
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Xuất ra màn hình giá trị của mỗi nút theo chiều tăng dần.
void xuatTangDan(Item n, BST &bst)
{
    bst.inOrder(bst.root);
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Xuất ra màn hình giá trị của mỗi nút theo chiều giảm dần.
void xuatGiamDan(Node* root)
{
    if(root != NULL) {
		xuatGiamDan(root->right);
		cout << root->data << " ";
		xuatGiamDan(root->left);
	}
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Xác định nút chứa khóa X.
Node* searchBST(Node* root, int key){
	if(root == NULL)
		return NULL;
	if(root->data == key)
		return root;
	Node *q;
	if(root->data > key)
		q=searchBST(root->right,key);
	if(root->data < key)
		q=searchBST(root->left,key);
	return q;
}

//Cho biết nút có giá trị lớn nhất.
Node* BST::maxValueNode(Node* p) 
{ 
    Node *current = p;
    while(current && current->right != NULL)
    	current = current->right;
    return current;
}

//Cho biết nút có giá trị nhỏ nhất.
Node* BST::minValueNode(Node* p) 
{ 
    Node *current = p;
    while(current && current->left != NULL)
    	current = current->left;
    return current;
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Tính tổng các giá trị trên cây.
int tinh_tong(Node *t){
	int sum=0;
	if(t != NULL){
		tinh_tong(t->left);
		tinh_tong(t->right);
		sum += t->data;
	}
	return sum;
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
int main()
{
    BST bst;
    int n;
    cout << "nhap so luong phan tu: ";
    cin >> n;
    nhap(n, bst);
    xuatGiamDan(bst.root);
    xuatTangDan(n, bst);
    searchBST(bst.root, 2);
    

    system("pause");
    return 0;
}
