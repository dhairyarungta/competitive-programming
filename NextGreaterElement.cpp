#include <vector>
#include <stack>
vector<int> nextGreaterElement(vector<int> input) {
  // Write your code here
  stack<int> s;
  vector<int> output(input.size());
  for (int i = input.size() - 1; i >= 0; i--) {
    while (!s.empty()) {
      if (s.top() > input[i]) {
        output[i] = s.top();
        s.push(input[i]);
        break;
      }
      s.pop();
    }

    if (s.empty()) {
      output[i] = -1;

      s.push(input[i]);
    }
  }
  return output;
}

