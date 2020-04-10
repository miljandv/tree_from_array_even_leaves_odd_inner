#include <iostream>
#include <vector>
using namespace std;
struct node {
	int value;
	node* sibling;
	node* child;
	node(int value_, node* sibling_, node* child_):value(value_), sibling(sibling_), child(child_) {}
	node(int value_) :value(value_), child(nullptr), sibling(nullptr) {}
};
node generateTree(int m, int* a) {
	if (m == 0)exit(-1);
	node root = node(a[0],nullptr,nullptr);
	node* pred = nullptr;
	node* lastsafe = &root;
	node* temp = &root;
	for (int i = 0; i < m - 1; i++) {
		if (a[i + 1] % 2 == 1 && a[i] % 2 == 1) {temp->child = new node(a[i + 1]); lastsafe = temp->child; pred = temp; temp = temp->child; }
		else if (a[i + 1] % 2 == 1 && a[i] % 2 != 1) {lastsafe->sibling = new node(a[i + 1]); pred = lastsafe; lastsafe = lastsafe->sibling; temp = lastsafe; }
		else if (a[i + 1] % 2 == 0 && a[i] % 2 == 0) {temp->sibling = new node(a[i + 1]); temp = temp->sibling; }
		else if (a[i + 1] % 2 == 0 && a[i] % 2 != 0) {temp->child = new node(a[i + 1]); temp = temp->child; }
	}
	return root;
}
void preorder(node* root,int n) {
	vector <node*> stack;
	node* temp = root;
	for(int i = 0; i < n; i++) {
		cout<<temp->value<<" ";
		if (temp->sibling && temp->child) { stack.push_back(temp); temp = temp->child; }
		else if (temp->child)temp = temp->child;
		else if (temp->sibling)temp = temp->sibling;
		else if (!stack.empty()) { temp = stack.back(); temp = temp->sibling; stack.pop_back(); }
		else return;
	}
}
int main() {
	int m = 9;
	int a[9] = { 3,1,4,48,2,5,3,6,18 };
	node root = generateTree(m,a);
	preorder(&root,m);
}