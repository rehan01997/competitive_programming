#include<bits/stdc++.h>
using namespace std;

vector<int>heap{ 0 };     //min heap

void add( int val )
{
	heap.push_back( val );
	int  idx = heap.size() - 1;
	int parent = idx/2;

	while( idx != 1 && heap[parent] > heap[idx])
	{
		swap( heap[parent] , heap[idx]);
		idx = parent;
		parent = parent / 2;
	}
	return;
}
int sizee()
{
	return heap.size() - 1;
}
////********* remove ****************************************
void heapify( int idx )
{
	int li = 2*idx ;
	int ri = 2*idx + 1;

	int f_idx = idx;
	if( li < heap.size() && heap[li] < heap[idx] )   // li vs idx
	{
		f_idx = li;
	}
	if( ri < heap.size() && heap[ri] < heap[f_idx] )  //ri vs f_idx
	{
		f_idx = ri;
	}
	if( f_idx != idx)
	{
		swap( heap[idx] , heap[ f_idx] );
		heapify( f_idx );
	}
	return;
}
int remove()
{
	if( sizee() == 0) { cout<<"Underflow"; return -1; }
	int p = heap[1]; 

	swap( heap[1] , heap[ heap.size() - 1 ]);
	heap.pop_back();
	heapify( 1 );
	return p;
}
int top()
{
	if( sizee() == 0) { cout << "Underflow" ; return -1; }
	return heap[1]; 
}
int main()
{
	
	add(20);
	add(10);
	add(30);
	add(40);

	cout<< top() << endl; 
	add(50);
	cout<< top() << endl;
	cout << remove() << endl;
	cout<< top() << endl;
	cout << remove() << endl;

	cout << top() << endl;
	cout << remove() << endl;

	cout<< top() << endl;
	cout << remove() << endl;
	cout<< top() << endl;
	// for(int no : heap) cout << no << " ";
	// cout<< endl;
	
	// //cout << remove() << endl;
	// cout << size() <<endl;
	// cout<< top() << endl;
	
	return 0;
}