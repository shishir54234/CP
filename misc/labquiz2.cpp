#include <bits/stdc++.h>
using namespace std;
//Just A template that I use for segment trees

// Program to find next smaller element for all elements in
// an array, using segment tree and coordinate compression

// --------Segment Tree Starts Here-----------------

vector<int> seg_tree;
vector<int> seg_tree1;

// combine function for combining two nodes of the tree, in
// this case we need to take min of two
int combine(int a, int b) { return min(a, b); }
int combine1(int a, int b) { return max(a, b); }


// build function, builds seg_tree based on vector parameter
// arr
void build1(vector<int>& arr, int node, int tl, int tr)
{
	// if current range consists only of one element, then
	// node should be this element
	if (tl == tr) {
		seg_tree[node] = arr[tl];
	}
	else {
		// divide the build operations into two parts
		int tm = (tr - tl) / 2 + tl;

		build1(arr, 2 * node, tl, tm);
		build1(arr, 2 * node + 1, tm + 1, tr);

		// combine the results from two parts, and store it
		// into current node
		seg_tree[node] = combine1(seg_tree1[2 * node],
								seg_tree1[2 * node + 1]);
	}
}
void build(vector<int>& arr, int node, int tl, int tr)
{
	// if current range consists only of one element, then
	// node should be this element
	if (tl == tr) {
		seg_tree[node] = arr[tl];
	}
	else {
		// divide the build operations into two parts
		int tm = (tr - tl) / 2 + tl;

		build(arr, 2 * node, tl, tm);
		build(arr, 2 * node + 1, tm + 1, tr);

		// combine the results from two parts, and store it
		// into current node
		seg_tree[node] = combine(seg_tree[2 * node],
								seg_tree[2 * node + 1]);
	}
}

// update function, used to make a point update, update
// arr[pos] to new_val and make required changes to segtree
void update(int node, int tl, int tr, int pos, int new_val)
{
	// if current range only contains one point, this must
	// be arr[pos], update the corresponding node to new_val
	if (tl == tr) {
		seg_tree[node] = new_val;
	}
	else {
		// else divide the range into two parts
		int tm = (tr - tl) / 2 + tl;

		// if pos lies in first half, update this half, else
		// update second half
		if (pos <= tm) {
			update(2 * node, tl, tm, pos, new_val);
		}
		else {
			update(2 * node + 1, tm + 1, tr, pos, new_val);
		}

		// combine results from both halfs
		seg_tree[node] = combine(seg_tree[2 * node],
								seg_tree[2 * node + 1]);
	}
}

// query function, returns minimum in the range [l, r]
int query(int node, int tl, int tr, int l, int r)
{
	// if range is invalid, then return infinity
	if (l > r) {
		return INT32_MAX;
	}

	// if range completely aligns with a segment tree node,
	// then value of this node should be returned
	if (l == tl && r == tr) {
		return seg_tree[node];
	}

	// else divide the query into two parts
	int tm = (tr - tl) / 2 + tl;

	int q1 = query(2 * node, tl, tm, l, min(r, tm));
	int q2 = query(2 * node + 1, tm + 1, tr, max(l, tm + 1),
				r);

	// and combine the results from the two parts and return
	// it
	return combine(q1, q2);
}

// --------Segment Tree Ends Here-----------------

void printNSE(vector<int> original, int n)
{
	vector<int> sorted(n);
	map<int, int> encode;

	// -------Coordinate Compression Starts Here ------

	// created a temporary sorted array out of original
	for (int i = 0; i < n; i++) {
		sorted[i] = original[i];
	}
	sort(sorted.begin(), sorted.end());

	// encode each value to a new value in sorted array
	int ctr = 0;
	for (int i = 0; i < n; i++) {
		if (encode.count(sorted[i]) == 0) {
			encode[sorted[i]] = ctr++;
		}
	}

	// use encode to compress original array
	vector<int> compressed(n);
	for (int i = 0; i < n; i++) {
		compressed[i] = encode[original[i]];
	}

	// -------Coordinate Compression Ends Here ------

	// Create an aux array of size ctr, and build a segtree
	// based on this array

	vector<int> aux(ctr, INT32_MAX);
	seg_tree = vector<int>(4 * ctr);

	build(aux, 1, 0, ctr - 1);

	// For each compressed[i], query for index of NSE and
	// update segment tree

	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = query(1, 0, ctr - 1, 0, compressed[i] - 1);
		update(1, 0, ctr - 1, compressed[i], i);
	}

	// Print -1 if NSE doesn't exist, otherwise print NSE
	// itself

	for (int i = 0; i < n; i++) {
		cout << original[i] << " ---> ";
		if (ans[i] == INT32_MAX) {
			cout << -1;
		}
		else {
			cout << original[ans[i]];
		}
		cout << "\n";
	}
}

// Driver program to test above functions
int main()
{
	vector<int> arr = { 11, 13, 21, 3 };
	printNSE(arr, 4);
	return 0;
}
