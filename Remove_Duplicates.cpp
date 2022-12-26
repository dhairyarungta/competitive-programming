//Recursive
string utilityFun(string s) {
  if (s.size() == 0) {
    return "";
  }

  string ans = utilityFun(s.substr(1));
  if (s[0] == ans[0])
    return ans;
  else
    return (s[0] + ans);
}

void removeConsecutiveDuplicates(char *input) {
  /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Change in the given string itself.
   * No need to return or print anything
   * Taking input and printing output is handled automatically.
   */

  string inputString = "";
  for (int i = 0; input[i] != 0; i++) {
    inputString = inputString + input[i];
  }

  inputString = utilityFun(inputString);
  for (int i = 0; i < inputString.size(); i++) {
    input[i] = inputString[i];
  }
  input[inputString.size()] = 0;
}