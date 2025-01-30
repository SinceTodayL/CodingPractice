#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<int> arr(500010, 0);
ll ans = 0;

void Merge(vector<int>& arr, int left, int right, int mid)
{
	vector<int> tmp(right - left + 1);
	int i = left, j = mid + 1;
	int count = 0;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) //这里用<=才能保证该算法的稳定性
			tmp[count++] = arr[i++];
		else{
			tmp[count++] = arr[j++];
			ans += (mid - i + 1);
		}
	}
	//剩余元素
	while (i <= mid) {
		tmp[count++] = arr[i++];
	}
	while (j <= right) {
		tmp[count++] = arr[j++];
	}
	for (int l = 0; l < (right - left + 1); l++) {
		arr[left + l] = tmp[l];
	}
}

void MergeSort(vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	Merge(arr, left, right, mid);
}

int main()
{
    cin >> N;
    int tmp;
    for(int i = 1; i <= N; ++i){
        scanf("%d", &tmp);
        arr[i-1] = tmp;
    }
    MergeSort(arr, 0, N - 1);
    cout << ans;
    return 0;
}

