#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode{
	char data;
	unsigned freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, unsigned freq){
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare{
	bool operator()(MinHeapNode* l, MinHeapNode* r){
		return (l->freq > r->freq);
	}
};

void printCodes(struct MinHeapNode* root, string str){
    if (!root)
		return;

	if (root->data != '#')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size){
	struct MinHeapNode *left, *right, *top;

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('#', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	printCodes(minHeap.top(), "");
}

int main(){

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

	HuffmanCodes(arr, freq, size);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9*1000;
  
    cout << "\nTime taken by program is : " << time_taken << setprecision(6);
    cout << "msec" << endl;

	return 0;
}
