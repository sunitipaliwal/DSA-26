class Solution
{
public:
  int maxVowels(string s, int k)
  {
    int i = 0;
    int j = 0;
    int maxc = 0;
    int c = 0;
    string vowels = "aeiou";
    while (j < s.size())
    {

      if (vowels.find(s[j]) != string::npos)
        c++;

      if (j - i + 1 > k)
      {
        if (vowels.find(s[i]) != string::npos)
          c--;
        i++;
      }

      if (j - i + 1 == k)
        maxc = max(c, maxc);
      j++;
    }
    return maxc;
  }
};