#include <iostream>
#include <vector>
#include <list>
using namespace std;
typedef struct
{
 string name;
 long long nposts;
} Person;
// 6a
class FriendNode
{
public:
 Person vertex;
 list<FriendNode*> adjVertex;
 int degree;
 bool isMarked;
 // 6a
 FriendNode(string name, long long nposts)
 {
 this->vertex.name = name;
 this->vertex.nposts = nposts;
 this->degree = 0;
 this->isMarked = false;
 }
 void mark()
 {
 this->isMarked = true;
 }
 void unmark()
 {
 this->isMarked = false;
 }
 bool searchAdjVertex(string name)
 {
 bool found = false;
 for (auto const &node : adjVertex)
 {
 if (node->vertex.name.compare(name) == 0)
 {
 found = true;
 break;
 }
 }
 return found;
 }
 // 6a
 bool addAdjVertex(FriendNode* person)
 {
 bool found = this->searchAdjVertex(person->vertex.name);
 if (found)
 return false; //edge is existing
 //add new
 this->adjVertex.push_back(person);
 this->degree++;
 person->addAdjVertex(this);
 return true;
 }
 void println()
 {
 cout << vertex.name << endl;
 cout << "\t"
 << "degree =" << degree << endl;
 cout << "\tto nodes:" << endl;
 cout << "\t\t";
 for (auto const &node : adjVertex)
 {
 cout << node->vertex.name << " , ";
 }
 cout << endl;
 }
};
// 6b
bool query(list<FriendNode*> graph, vector<Person*> &ret, long long
nfriends)
{
 for (auto node : graph)
 {
 if (node->degree >= nfriends)
 {
 ret.push_back(&node->vertex);
 }
 }
 if (!ret.empty())
 {
 return true;
 }
 else
 {
 return false;
 }
}
template<typename T>
class AVLNode
{
public:
 AVLNode<T>(T d)
 {
 data = d;
 left = nullptr;
 right = nullptr;
 }
 T data;
 AVLNode* left;
 AVLNode* right;
};
class PostTree
{
public:
 PostTree(FriendNode* graphNode)
 {
 root = new AVLNode<Person*>(&graphNode->vertex);
 }
 ~PostTree()
 {
 delTree(root);
 }
 void addNode(AVLNode<Person*> *parent, FriendNode* graphNode, bool
isLeft)
 {
 if (isLeft)
 {
 parent->left = new AVLNode<Person*>(&graphNode->vertex);
 }
 else
 {
 parent->right = new AVLNode<Person*>(&graphNode->vertex);
 }
 }
 // 6c
 bool find(AVLNode<Person*> *pR, int npost_b, int npost_e,
vector<Person *> &ret)
 {
 if (pR)
 {
 if (pR->data->nposts >= npost_b)
 find(pR->left, npost_b, npost_e, ret);
 if (pR->data->nposts >= npost_b && pR->data->nposts <=
npost_e)
 ret.push_back(pR->data);
 if (pR->data->nposts <= npost_e)
 find(pR->right, npost_b, npost_e, ret);
 }
 if (!ret.empty())
 return true;
 else
 return false;
 }
 AVLNode<Person*> *root;
private:
 void delTree(AVLNode<Person*> *pR)
 {
 if (pR)
 {
 delTree(pR->left);
 delTree(pR->right);
 delete pR;
 }
 }
};
int main()
{
 FriendNode* a = new FriendNode("A", 5);
 FriendNode* b = new FriendNode("B", 10);
 FriendNode* c = new FriendNode("C", 4);
 FriendNode* d = new FriendNode("D", 11);
 FriendNode* e = new FriendNode("E", 15);
 FriendNode* f = new FriendNode("F", 25);
 FriendNode* g = new FriendNode("G", 12);
 FriendNode* h = new FriendNode("H", 30);
 FriendNode* i = new FriendNode("I", 14);
 list<FriendNode*> friendGraph{a, b, c, d, e, f, g, h, i};
 a->addAdjVertex(b);
 a->addAdjVertex(c);
 b->addAdjVertex(d);
 b->addAdjVertex(e);
 c->addAdjVertex(e);
 c->addAdjVertex(d);
 d->addAdjVertex(f);
 e->addAdjVertex(f);
 f->addAdjVertex(g);
 f->addAdjVertex(h);
 g->addAdjVertex(i);
 h->addAdjVertex(i);
 vector<Person*> ret;
 // B, C, D, E, F
 cout << "Person has more than 3 friend:" << endl;
 if (query(friendGraph, ret, 3))
 {
 for(auto person : ret)
 {
 cout << person->name << endl;
 }
 }
 PostTree ptree(d);
 ptree.addNode(ptree.root, a, true);
 ptree.addNode(ptree.root, e, false);
 ptree.addNode(ptree.root->left, c, true);
 ptree.addNode(ptree.root->left, b, false);
 ptree.addNode(ptree.root->right, g, true);
 ptree.addNode(ptree.root->right, f, false);
 ptree.addNode(ptree.root->right->left, i, false);
 ptree.addNode(ptree.root->right->right, h, false);
 ret.clear();
 // B, D, G, I, E
 cout << "Person has number of posts from 10 to 20:" << endl;
 if (ptree.find(ptree.root, 10, 20, ret))
 {
 for(auto person : ret)
 {
 cout << person->name << " " << person->nposts << endl;
 }
 }
 while(!friendGraph.empty())
 {
 auto node = friendGraph.back();
 delete node;
 friendGraph.pop_back();
 }
 return 0;
}
