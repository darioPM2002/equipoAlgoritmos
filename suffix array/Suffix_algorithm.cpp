#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void suffixArray(string s)
{
  s += "$";
  vector<string> suffix;
  vector<int> index;
  int count = 1;

  for (int i = s.length() - 1; i >= 0; i--)
  {
    suffix.push_back(s.substr(i, count));
    count++;
  }

  sort(suffix.begin(), suffix.end());

  for (int i = 0; i < s.length(); i++)
  {
    index.push_back(s.length() - suffix[i].length() + 1);
    cout << suffix[i] << " - " << index[i] << endl;
  }
}

int main()
{
  suffixArray("cacbcac");

  return 0;
}