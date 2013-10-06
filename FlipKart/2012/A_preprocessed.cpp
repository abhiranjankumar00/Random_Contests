#include <iostream>
#include <vector>
using namespace std;

vector <string> st;
string toFind;
int N;

struct Node {
	Node *child[26];
	Node() {
		for(int i = 0; i < 26; i++)
			child[i] = NULL;
	}
}root;

void insert(int r = 0, int c = 0, int radd = 0, int cadd = 1, Node *nd = &root) {
	if(r == N || c == N)
		return;
	if(r < 0 || c < 0)
		return;

	int id = st[r][c] - 'a';

	if(nd->child[id] == NULL)
		nd->child[id] = new Node();

	insert(r+radd, c+cadd, radd, cadd, nd->child[id]);
}

bool find(int idx = 0, Node *nd = &root) {
	if(idx == (int)toFind.size())
		return true;

	int id = toFind[idx] - 'a';

	return nd->child[id] == NULL ? false : find(idx+1, nd->child[id]);
}

int main()
{
	int K;
	scanf("%d %d", &N, &K);

	st = vector <string> (N);

	for(int i = 0; i < N; i++)
		cin >> st[i];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int xadd = -1; xadd <= 1; xadd++)
				for(int yadd = -1; yadd <= 1; yadd++)
					if(!(xadd == 0 && yadd == 0 ))
						insert(i, j, xadd, yadd, &root);
/*	
	for(int i = 0; i < N; i++) {
		for(int j = 0 ; j < N; j++) {
			insert(i, j, 0, 1, &root);
			insert(i, j, 1, 1, &root);
			insert(i, j, 1, 0, &root);
			insert(i, j, 1, -1, &root);
			insert(i, j, 0, -1, &root);
			insert(i, j, -1, -1, &root);
			insert(i, j, -1, 0, &root);
			insert(i, j, -1, 1, &root);
		}
	}
*/
	while(K--) {
		cin >> toFind;
		if(find())
			cout << toFind << "\n";
	}

	return 0;

}
