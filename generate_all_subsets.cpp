#include <iostream>
#include <vector>
using namespace std;
// If set is {1,2,3,..,n}
vector<int> subset;
void gen(int k, int n)
{
	if (k == n + 1)
	{
		for (auto i : subset)
			cout << i << " ";
		cout << endl;
	}
	else
	{
		subset.push_back(k);
		gen(k + 1,n);
		subset.pop_back();
		gen(k + 1,n);
	}
}

vector<int> subsets;
void allSubsets(int s[], int n, int k)
{
	if (k == n)
	{
		for (auto i : subsets)
			cout << i << " ";
		cout << "\n";
	}
	else
	{
		subsets.push_back(s[k]);
		allSubsets(s, n, k + 1);
		subsets.pop_back();
		allSubsets(s, n, k + 1);
	}
}
int main()
{
	// generating all subsets of a set using recursion
	// set={1,2,3}
	gen(1, 3);
	int s[3] = {10, 20, 30};
	allSubsets(s, 3, 0);
	return 0;
}
