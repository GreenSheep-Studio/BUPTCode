#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct huff
{
	char data;
	double code;
	huff* left=NULL;
	huff* right=NULL;
	string every;
	friend bool operator< (huff a, huff b) 
	{
		return a.code > b.code; //С����
	}
};//ÿ���ӽڵ��ӵ�еĶ���

priority_queue<huff*> a;

huff* high;//���������ĸ��ڵ�

void creathuff() {
	huff* p1;
	huff* p2;
	huff* p3 = new huff;
	p1 = a.top();
	if (p1->code == 1) { 
		return; 
	}
	a.pop();
	p2 = a.top();
	a.pop();
	p3->left = p1;
	p3->right = p2;
	p3->code = p1->code + p2->code;
	a.push(p3);
	high = p3;
	creathuff();
}//������������
void dfs(huff*php,char word) {
	huff* hhh = new huff;
	hhh = php;
	if (hhh->left==NULL&& hhh->right==NULL)return;
	if (word != '\000') {
		hhh->every=hhh->every +word;
	}
		if (hhh->left != NULL)
			dfs(hhh->left,'0');
		if (hhh->right != NULL)
			dfs(hhh->right,'1');
}//�ܳ��������ڵ�Ĵ���ֵ

int main() {
	huff* tree[26];
	for (int i = 0; i < 26; i++) {
		tree[i] = new huff;
		tree[i] ->data = 'A' + i;
	}
	tree[0]->code = 0.0819;
	tree[1]->code= 0.0147;
	tree[2]->code= 0.0383;
	tree[3]->code= 0.0391;
	tree[4]->code = 0.1225;
	tree[5]->code= 0.0226;
	tree[6]->code= 0.0171;
	tree[7]->code= 0.0457;
	tree[8]->code= 0.0710;
	tree[9]->code= 0.0041;
	tree[10]->code= 0.0014;
	tree[11]->code= 0.0377;
	tree[12]->code= 0.0334;
	tree[13]->code= 0.0706;
	tree[14]->code= 0.0726;
	tree[15]->code= 0.0289;
	tree[16]->code= 0.0009;
	tree[17]->code= 0.0685;
	tree[18]->code= 0.0636;
	tree[19]->code= 0.0941;
	tree[20]->code= 0.0258;
	tree[21]->code= 0.0109;
	tree[22]->code= 0.0159;
	tree[23]->code= 0.0021;
	tree[24]->code= 0.0158;
	tree[25]->code= 0.0008;
	a.push(tree[0]);
	a.push(tree[1]);
	a.push(tree[2]);
	a.push(tree[3]);
	a.push(tree[4]);
	a.push(tree[5]);
	a.push(tree[6]);
	a.push(tree[7]);
	a.push(tree[8]);
	a.push(tree[9]);
	a.push(tree[10]);
	a.push(tree[11]);
	a.push(tree[12]);
	a.push(tree[13]);
	a.push(tree[14]);
	a.push(tree[15]);
	a.push(tree[16]);
	a.push(tree[17]);
	a.push(tree[18]);
	a.push(tree[19]);
	a.push(tree[20]);
	a.push(tree[21]);
	a.push(tree[22]);
	a.push(tree[23]);
	a.push(tree[24]);
	a.push(tree[25]);

	creathuff();//���������Ѿ�����������ÿ�ʼ���仯��ͼ
	dfs(high);
	for (int i = 0; i <= 25;i++)
	{
		cout <<tree[i]->code<<"  " << tree[i]->data << "  " << tree[i]->every << endl;
	}
    //���ʻ�Ȩֵ�����ȥ

}//�����к���
