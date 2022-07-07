
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int N, M, x;

vector<vector<long long>> matrix;
vector<vector<long long>> rSum;

int solve(vector<long long>& sum, int left, int right) {
	if (left + 1 == right) return 0;

	int count = 0;
	int mid = (left + right) / 2;

	count += solve(sum, left, mid);
	count += solve(sum, mid, right);

	vector<long long> tmp(right - left, 0);
	int index = 0;

	for (int i = left, j = mid, p = mid; i < mid; i++) {
		while (j < right && sum[j] - sum[i] <= x) j++;
		if (j - 1 >= mid) {
			count += j - mid;
		}

		while (p < right && sum[p] < sum[i]) tmp[index++] = sum[p++];
		tmp[index++] = sum[i];
	}

	for (int i = 0; i < index; i++) {
		sum[left + i] = tmp[i];
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T > 0) {
		cin >> N >> M >> x;

		matrix = vector<vector<long long>>(N, vector<long long>(M));
		rSum = vector<vector<long long>>(N, vector<long long>(M));

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> matrix[r][c];

				rSum[r][c] = matrix[r][c];
				if (c > 0) {
					rSum[r][c] += rSum[r][c - 1];
				}
			}
		}

		int count = 0;
		for (int s = 0; s < M; s++) {
			for (int e = s; e < M; e++) {
				vector<long long> sum(N + 1, 0);
				sum[0] = 0;
				for (int i = 1; i <= N; i++) {
					sum[i] = sum[i-1] + rSum[i-1][e];
					if (s > 0) sum[i] -= rSum[i-1][s - 1];
				}

				count += solve(sum, 0, N+1);
			}
		}

		cout << count << endl;

		T -= 1;
	}

	return 0;
}