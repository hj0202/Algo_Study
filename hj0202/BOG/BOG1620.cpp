#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> pokedexNumber;
vector<pair<string, int>> pokedexString;

int binarySearch(int len, string find)
{
	int start = 0;
	int end = len - 1;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;
		int result = pokedexString[mid].first.compare(find);

		if (result == 0) {
			return pokedexString[mid].second;
		}
		else if (result > 0) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return 0;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	pokedexNumber.push_back("");

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		pokedexNumber.push_back(name);
		pokedexString.push_back(make_pair(name, i + 1));
	}

	sort(pokedexString.begin(), pokedexString.end());

	for (int i = 0; i < M; i++)
	{
		string quiz;
		cin >> quiz;

		if ('0' <= quiz[0] && quiz[0] <= '9')
		{
			int num = stoi(quiz);
			cout << pokedexNumber[num] << '\n';
		}
		else
		{
			cout << binarySearch(pokedexString.size(), quiz) << '\n';
		}
	}
}