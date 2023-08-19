class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<int> degrees(n);
    for (const vector<int>& road : roads) {
      int a = road[0];
      int b = road[1];
      ++degrees[a];
      ++degrees[b];
    }

    int max_degree = 0;
    int second_max_degree = 0;
    for (int degree : degrees) {
      if (degree < second_max_degree) {
        continue;
      }
      second_max_degree = degree;
      if (second_max_degree > max_degree) {
        swap(second_max_degree, max_degree);
      }
    }

    vector<bool> is_candidate(n);
    int candidate_count = 0;
    int king = -1;
    for (int i = 0; i < n; ++i) {
      if (degrees[i] == second_max_degree) {
        is_candidate[i] = true;
        ++candidate_count;
      }
      if (max_degree > second_max_degree && degrees[i] == max_degree) {
        king = i;
      }
    }

    if (max_degree == second_max_degree) {
      if (candidate_count > max_degree + 1) {
        return max_degree * 2;
      }
      int connection_count = 0;
      for (const vector<int>& road : roads) {
        int a = road[0];
        int b = road[1];
        if (is_candidate[a] && is_candidate[b]) {
          ++connection_count;
        }
      }
      if (connection_count < candidate_count * (candidate_count - 1) / 2) {
        return max_degree * 2;
      }
      return max_degree * 2 - 1;
    }

    int connection_count = 0;
    for (const vector<int>& road : roads) {
      int a = road[0];
      int b = road[1];
      if (a != king && b != king) {
        continue;
      }
      if (is_candidate[a] || is_candidate[b]) {
        ++connection_count;
      }
    }
    if (connection_count < candidate_count) {
      return max_degree + second_max_degree;
    }
    return max_degree + second_max_degree - 1;
  }
};