#include <iostream>
#include <vector>

using namespace std;

void z(string main, string pattern = "")
{
  string concat;
  bool found = false;
  vector<int> result;
  result.push_back(0);
  if (pattern == "")
    concat = main;
  else
    concat = pattern + "$" + main;

  for (int i = 0; i < concat.size(); i++)

  {

    int count = 0;
    if (i == 0)
      continue;

    else
    {
      for (int j : concat)
      {
        if (concat[i + count] == j)

          count++;
        else
        {
          result.push_back(count);
          break;
        }
      }
    }
  }

  for (int i = 0; i < result.size(); i++)
  {
    if (result[i] == pattern.size())
    {
      found = true;
      cout << "true" << " " << i - pattern.size() << endl;
    }
  }
  if (!found)
    cout << "false" << endl;
}
