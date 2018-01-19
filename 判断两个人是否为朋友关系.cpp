#include <iostream>
using namespace std;

vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> B = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<pair<int, int>> R = {(1, 3), (2, 5), (3,5)};

int FindSet(int i) {
	while(B[i] != i) {
		i = B[i];
	}
	return i;
}

void UnionSet(int i, int j) {
	set_i = FindSet(i);
	set_j = FindSet(j);

	if (set_i == set_j) {
		return
	}
	if (set_i < set_j) {
		B[set_j] = set_i;
	} else {
		B[set_i] = set_j;
	}
}

int CheckRelation(int x, int y) {
	return FindSet(x) == FindSet(y);
}


int main(int argc, char** argv) {
	int x = 1, y = 5;
	for (auto p : R) {
		UnionSet(p.first, p.second);
	}

	return CheckRelation(x, y);
}