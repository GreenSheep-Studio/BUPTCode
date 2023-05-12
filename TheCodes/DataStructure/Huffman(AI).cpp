#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// A node in the Huffman tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }

    // Destructor to free dynamically allocated memory
    ~Node() {
        delete left;
        delete right;
    }
};

// Comparator function for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Build the Huffman tree and return the root node
Node* buildHuffmanTree(string str) {
    // Count the frequency of each character
    unordered_map<char, int> freqMap;
    for (char c : str) {
        freqMap[c]++;
    }

    // Create a priority queue of nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
        Node* node = new Node(it->first, it->second);
        pq.push(node);
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* a = pq.top();
        pq.pop();
        Node* b = pq.top();
        pq.pop();
        Node* parent = new Node('$', a->freq + b->freq);
        parent->left = a;
        parent->right = b;
        pq.push(parent);
    }

    // Return the root of the Huffman tree
    return pq.top();
}

// Print the Huffman codes for each character
void printHuffmanCodes(Node* root, string code) {
    if (root == nullptr) {
        return;
    }

    // Leaf node
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
        return;
    }

    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

int main() {
    string str = "hello world";
    Node* root = buildHuffmanTree(str);
    printHuffmanCodes(root, "");
    delete root;
    system("pause");
    return 0;
}
