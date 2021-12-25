#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Slist{
    Node *phead;
    Node *ptail;
    Slist();
};

Slist::Slist(){
    phead = ptail = NULL;
}

Node *CreateNode(int v){
    Node* p = new Node;
	p->data = v;	
	p->next = NULL;	
	return p; 
}

void addLast(Slist &list, int v){
    Node *p = CreateNode(v);
    if(list.phead == NULL){
        list.phead = list.ptail = p;
    }
    else{
        list.ptail->next = p;
        list.ptail = p;
    }
}

void traverse(Slist list){
    Node *p = list.phead;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    delete p;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Ho ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay sinh: 12/05/2002
// Email: 6151071083@st.utc2.edu.vn
Node *linearSearch(Slist list, int key){
    Node *p = list.phead;
    while(p != NULL){
        if(p->data == key)
            break;
        p = p->next;
    }
    return p;
}

// Ho ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay sinh: 12/05/2002
// Email: 6151071083@st.utc2.edu.vn
void BubbleSort(Slist &list){
    Node *i, *j;
    i = list.phead->next;
    for(i; i != NULL; i = i->next){
        for(j = list.phead; j != i; j = j->next){
            if(j->data > j->next->data){
                swap(j->data, j->next->data);
            }
        }
    }
}

// Ho ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay sinh: 12/05/2002
// Email: 6151071083@st.utc2.edu.vn
int main()
{
    Slist list;
    addLast(list, 5);
    addLast(list, 20);
    addLast(list, 12);
    addLast(list, 11);
    addLast(list, 30);
    traverse(list);
    int key;
    cout << "So can tim: "; cin >> key;
    Node *key = linearSearch(list, key);
    if(key != NULL){
        cout << "So can tim: " << key;
    } else{
        cout << "Khong tim thay..." << endl;
    }
    BubbleSort(list);
    traverse(list);
    

    system("pause");
    return 0;
}