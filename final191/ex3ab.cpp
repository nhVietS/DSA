#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// 3a.
class GraphNode
{
public:
 string vertex;
 list<string> adjVertex;
 list<int> adjWeight;
 int inDeg;
 int outDeg;
 bool isMarked;
 GraphNode(string vertex){
 this->vertex = vertex;
 this->inDeg = 0;
 this->outDeg = 0;
 this->isMarked = false;
 }
 void mark(){
 this->isMarked = true;
 }
 void unmark(){
 this->isMarked = false;
 }
 bool searchAdjvertex(string vertex_to){
 bool found = false;
 std::list<string>::const_iterator iterator;
 for ( iterator = adjVertex.begin();
 iterator != adjVertex.end();
 ++iterator) {
 string node_to = *iterator;
 if (node_to.compare(vertex_to) == 0){
 found= true;
 break;
 }
 }
 return found;
 }
 bool addAdjVertex(string vertex_to, int weight){
 bool found = this->searchAdjvertex(vertex_to);
 if(found)
 return false; //edge is existing
 //add new
 this->adjVertex.push_back(vertex_to);
 this->adjWeight.push_back(weight);
 this->outDeg++;
 return true;
 }
 void println(){
 cout << vertex << endl;
 cout << "\t" << "in degree =" << inDeg << endl;
 cout << "\t" << "out degree =" << outDeg << endl;
 cout << "\tto nodes:" << endl;
 cout << "\t\t";
 std::list<string>::const_iterator iterator;
 int idx = 0;
 std::list<int>::const_iterator iter_weight =
this->adjWeight.begin();
 for ( iterator = adjVertex.begin();
 iterator != adjVertex.end();
 ++iterator) {
 string node_to = *iterator;
 int w = *iter_weight;
 cout << node_to << " (w=" << w << ")" << " , ";
 iter_weight++;
 }
 cout << endl;
 }
};

// 3a.
class DiGraph
{
public:
 vector<GraphNode> node_list;
 void unmark(){
 for (int idx = 0; idx < this->node_list.size(); idx++) {
 GraphNode* pNode = (GraphNode*)(&(this->node_list[idx]));
 pNode->unmark();
 }
 }
 // 3b.
 void dfs(string vertex_start){
 unmark();
 GraphNode* pStart = this->search(vertex_start);
 if(pStart == NULL){
 cout << vertex_start << " does not exist!" << endl;
 return;
 }
 //vertex_start exists
 stack<GraphNode*> fringe;
 //(0) push the start to fringe
 fringe.push(pStart);
 pStart->mark();
 while(!fringe.empty()){
 //(1) get the top node on the stack (called current)
 GraphNode* pCurrent = fringe.top();
 fringe.pop();
 //(2)process current node
 cout << pCurrent->vertex << " ";
 //(3)push all children of the current node to stack
 std::list<string>::const_iterator iterator;
 for ( iterator = pCurrent->adjVertex.begin();
 iterator != pCurrent->adjVertex.end();
 ++iterator) {
 string node_to = *iterator;
 GraphNode* pChild = this->search(node_to);
 if (pChild->isMarked == false){
 pChild->mark();
 fringe.push(pChild);
 }
 } //for
 }//while
 cout << endl;
 }//dfs
 /**
 * return NULL : not found
 */
 GraphNode* search(string vertex){
 GraphNode* pNode = NULL;
 bool found = false;
 for (int idx = 0; idx < this->node_list.size(); idx++) {
 pNode = (GraphNode*)(&(this->node_list[idx]));
 if(pNode->vertex.compare(vertex) == 0){
 found = true;
 break;
 }
 }
 if(found)
 return pNode;
 else
 return NULL;
 }
 bool insert_vertex(string vertex){
 GraphNode* pNode = this->search(vertex);
 if(pNode != NULL)
 return false; //duplicate
 //insert
 GraphNode node(vertex);
 this->node_list.push_back(node);
 return true;
 }
 bool insert_edge(string vertex_from, string vertex_to, int weight){
 GraphNode* pNode_from = this->search(vertex_from);
 GraphNode* pNode_to = this->search(vertex_to);
 if ((pNode_from == NULL) || (pNode_to == NULL)){
 return false; //vertex is not found
 }
 bool added = pNode_from->addAdjVertex(vertex_to, weight);
 if(added){
 pNode_to->inDeg++;
 return true;
 }
 else{
 return false;
 }
 }
 /*
 print the graph
 */
 void println(){
 if (node_list.size() <= 0){
 cout << "The graph is empty!";
 return;
 }
 cout << "Num of nodes:" << this->node_list.size() << endl;
 for(int idx=0; idx < node_list.size(); idx++){
 GraphNode &node = node_list[idx];
 node.println();
 }
 }
};
int main(int argc, char** argv) {
 DiGraph graph;
 graph.insert_vertex("1");
 graph.insert_vertex("2");
 graph.insert_vertex("3");
 graph.insert_vertex("4");
 graph.insert_vertex("5");
 graph.insert_vertex("6");
 graph.insert_vertex("7");
 graph.insert_vertex("8");
 graph.insert_vertex("9");
 graph.insert_edge("1", "2", 8);
 graph.insert_edge("1", "3", 3);
 graph.insert_edge("1", "6", 13);
 graph.insert_edge("2", "3", 2);
 graph.insert_edge("2", "4", 1);
 graph.insert_edge("3", "2", 3);
 graph.insert_edge("3", "4", 9);
 graph.insert_edge("3", "5", 2);
 graph.insert_edge("4", "5", 4);
 graph.insert_edge("4", "8", 2);
 graph.insert_edge("4", "7", 6);
 graph.insert_edge("5", "1", 5);
 graph.insert_edge("5", "4", 6);
 graph.insert_edge("5", "6", 5);
 graph.insert_edge("5", "9", 4);
 graph.insert_edge("6", "7", 1);
 graph.insert_edge("6", "9", 7);
 graph.insert_edge("7", "5", 3);
 graph.insert_edge("7", "8", 4);
 graph.insert_edge("8", "9", 1);
 graph.insert_edge("9", "7", 5);
 graph.println();
 cout << "Visit nodes in graph:" << endl;
 graph.dfs("1");
 return 0;
}
