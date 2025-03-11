#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans = 0;
int m[1000010];
int mm[100010];

void Merge(int left, int right, int mid)
{
	vector<int> tmp(right - left + 1);
	int i = left, j = mid + 1;
	int count = 0;
	while (i <= mid && j <= right) {
		if (mm[i] <= mm[j]) {
			tmp[count++] = mm[i++];
			ans++;
		}
		else
			tmp[count++] = mm[j++];
	}
	//Ê£ÓàÔªËØ
	while (i <= mid) {
		tmp[count++] = mm[i++];
	}
	while (j <= right) {
		tmp[count++] = mm[j++];
	}
	for (int l = 0; l < (right - left + 1); l++) {
		mm[left + l] = tmp[l];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	Merge(left, right, mid);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0; i<n; ++i)
		cin>>m[i];
		for(int i=0; i<n; ++i)
		mm[m[i]]=i;
		ans = 0;
		MergeSort(0, n-1);
		cout<<ans<<endl;
	}
    return 0;
}

