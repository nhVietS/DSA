#include <iostream>
using namespace std;
class ProbDist
{
public:
 int nrows, ncols;
 float* pWeight;
 ProbDist(int N, int F){
 this->nrows = N;
 this->ncols = F;
 this->pWeight = new float[N*F];
 for (int k=0; k<N*F; k++) {
 this->pWeight[k] = 0;
 }
 }
 ~ProbDist(){
 if (pWeight != NULL) delete []pWeight;
 }
 int idx(int n, int f) {
 return n*this->ncols + f;
 }
 void set(int n, int f, float prob) {
 pWeight[idx(n, f)] = prob;
 }
 float get(int n, int f) {
 return pWeight[idx(n, f)];
 }
 void print() {
 for (int r=0; r<this->nrows; r++) {
 for (int c=0; c<this->ncols; c++) {
 cout << pWeight[idx(r, c)] << "\t";
 }
 cout << endl;
 }
 }
};
void print_arr(float* t, int size) {
 for(int s=0; s<size; s++) {
 cout << t[s] << endl;
 }
}
int main(int argc, char** argv) {
 int N = 3;
 int F = 3;
 ProbDist* x = new ProbDist(N, F);
 x->set(0, 0, 0.3);
 x->set(0, 1, 0.1);
 x->set(0, 2, 0.6);
 x->set(1, 0, 0.1);
 x->set(1, 1, 0.4);
 x->set(1, 2, 0.5);
 x->set(2, 0, 0.5);
 x->set(2, 1, 0.3);
 x->set(2, 2, 0.2);
 x->print();
 float* t = new float[N];
 t[0] = 0;
 t[1] = 2;
 t[2] = 1;
 print_arr(t, N);
 return 0;
}
