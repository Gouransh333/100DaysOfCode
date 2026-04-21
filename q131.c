A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.

class Solution {
    public string findOrder(string[] words) {
         int[] indegree = new int[26];
        bool[] present = new bool[26];
        List<int>[] adj = new List<int>[26];

        for (int i = 0; i < 26; i++)
            adj[i] = new List<int>();

        foreach (string word in words) {
            foreach (char c in word) {
                present[c - 'a'] = true;
            }
        }

        for (int i = 0; i < words.Length - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = Math.Min(w1.Length, w2.Length);
            int j = 0;

            while (j < len && w1[j] == w2[j]) j++;

            if (j < len) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                if (!adj[u].Contains(v)) {
                    adj[u].Add(v);
                    indegree[v]++;
                }
            } else if (w1.Length > w2.Length) {
                return "";
            }
        }

        Queue<int> q = new Queue<int>();
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.Enqueue(i);
            }
        }

        string result = "";

        while (q.Count > 0) {
            int u = q.Dequeue();
            result += (char)(u + 'a');

            foreach (int v in adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.Enqueue(v);
                }
            }
        }

        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) total++;
        }

        if (result.Length != total) return "";

        return result;
    }
        
    }
