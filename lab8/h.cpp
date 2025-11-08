#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

long long P = 31;
long long MOD = 1000000007;

vector<long long> get_hashes(string s)
{
	vector<long long> h(s.size());
	h[0] = s[0] - 'a' + 1;
	for (int i = 1; i < s.size(); i++)
	{
		h[i] = (h[i - 1] * P + (s[i] - 'a' + 1)) % MOD;
	}
	return h;
}

vector<long long> get_powers(int n)
{
	vector<long long> p(n);
	p[0] = 1;
	for (int i = 1; i < n; i++)
	{
		p[i] = (p[i - 1] * P) % MOD;
	}
	return p;
}

long long get_sub_hash(vector<long long> h, vector<long long> p, int l, int r)
{
	if (l == 0)
	{
		return h[r];
	}
	return (h[r] - h[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
}

bool has_common_substring(vector<string> strs, int len, string &res)
{
	unordered_set<long long> hashes;
	vector<long long> p = get_powers(len + 1);
	vector<long long> h0 = get_hashes(strs[0]);
	for (int i = 0; i + len - 1 < strs[0].size(); i++)
	{
		hashes.insert(get_sub_hash(h0, p, i, i + len - 1));
	}
	for (int k = 1; k < strs.size(); k++)
	{
		unordered_set<long long> temp;
		vector<long long> h = get_hashes(strs[k]);
		for (int i = 0; i + len - 1 < strs[k].size(); i++)
		{
			long long hh = get_sub_hash(h, p, i, i + len - 1);
			if (hashes.count(hh))
			{
				temp.insert(hh);
			}
		}
		hashes = move(temp);
		if (hashes.empty())
		{
			return false;
		}
	}
	vector<long long> h_first = get_hashes(strs[0]);
	for (int i = 0; i + len - 1 < strs[0].size(); i++)
	{
		if (hashes.count(get_sub_hash(h_first, p, i, i + len - 1)))
		{
			res = strs[0].substr(i, len);
			break;
		}
	}
	return true;
}

int main()
{
	int K;
	cin >> K;
	vector<string> strs(K);
	int min_len = 1000000;
	for (int i = 0; i < K; i++)
	{
		cin >> strs[i];
		if (strs[i].size() < min_len)
		{
			min_len = strs[i].size();
		}
	}
	int low = 1;
	int high = min_len;
	string answer = "";
	while (low <= high)
	{
		int mid = (low + high) / 2;
		string tmp;
		if (has_common_substring(strs, mid, tmp))
		{
			answer = tmp;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << answer << endl;
}