#include<iostream>
#include<stack>
#include<vector>

using namespace std ;

struct Trie {
    Trie* children[26];
    int substring_id;
    
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        substring_id = -1;
    }
};

int add_substring_to_trie(Trie* root, string& substring, int& next_available_id) {
    Trie* current_node = root;
    for (char character : substring) {
        int char_index = character - 'a';
        if (current_node->children[char_index] == NULL) {
            current_node->children[char_index] = new Trie();
        }
        current_node = current_node->children[char_index];
    }
    if (current_node->substring_id == -1) {
        current_node->substring_id = next_available_id++;
    }
    return current_node->substring_id;
}

class Solution {
private:
    void floyd_warshall(vector<vector<int>>& transformation_cost) {
        int total_substrings = transformation_cost.size();
        for (int intermediate_substring = 0; intermediate_substring < total_substrings; intermediate_substring++) {
            for (int from_substring = 0; from_substring < total_substrings; from_substring++) {
                for (int to_substring = 0; to_substring < total_substrings; to_substring++) {
                    if (transformation_cost[from_substring][intermediate_substring] != INT_MAX && 
                        transformation_cost[intermediate_substring][to_substring] != INT_MAX && 
                        transformation_cost[from_substring][intermediate_substring] + transformation_cost[intermediate_substring][to_substring] < transformation_cost[from_substring][to_substring]) {
                        transformation_cost[from_substring][to_substring] = transformation_cost[from_substring][intermediate_substring] + transformation_cost[intermediate_substring][to_substring];
                    }
                }
            }
        }
    }
    
    long long find_minimum_cost_from_position(int current_position, string& source, string& target, Trie* trie_root, vector<vector<int>>& transformation_cost, vector<long long>& memo) {
        if (current_position == source.size()) {
            return 0;
        }
        if (memo[current_position] != -1) {
            return memo[current_position];
        }
        long long minimum_cost = 1e12;
        if (source[current_position] == target[current_position]) {
            minimum_cost = find_minimum_cost_from_position(current_position + 1, source, target, trie_root, transformation_cost, memo);
        }
        Trie* source_trie_node = trie_root;
        Trie* target_trie_node = trie_root;
        for (int end_position = current_position; end_position < source.size(); end_position++) {
            int source_char_index = source[end_position] - 'a';
            int target_char_index = target[end_position] - 'a';
            source_trie_node = source_trie_node->children[source_char_index];
            target_trie_node = target_trie_node->children[target_char_index];
            if (!source_trie_node || !target_trie_node) {
                break;
            }
            if (source_trie_node->substring_id != -1 && target_trie_node->substring_id != -1 && transformation_cost[source_trie_node->substring_id][target_trie_node->substring_id] != INT_MAX) {
                long long cost_with_transformation = (long long)transformation_cost[source_trie_node->substring_id][target_trie_node->substring_id] + find_minimum_cost_from_position(end_position + 1, source, target, trie_root, transformation_cost, memo);
                minimum_cost = min(minimum_cost, cost_with_transformation);
            }
        }
        return memo[current_position] = minimum_cost;
    }
    
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        Trie* trie_root = new Trie();
        int next_substring_id = 0;
        int number_of_transformations = original.size();
        vector<vector<int>> transformation_cost(2 * number_of_transformations, vector<int>(2 * number_of_transformations, INT_MAX));
        for (int i = 0; i < 2 * number_of_transformations; i++) {
            transformation_cost[i][i] = 0;
        }
        for (int i = 0; i < original.size(); i++) {
            int source_substring_id = add_substring_to_trie(trie_root, original[i], next_substring_id);
            int target_substring_id = add_substring_to_trie(trie_root, changed[i], next_substring_id);
            transformation_cost[source_substring_id][target_substring_id] = min(transformation_cost[source_substring_id][target_substring_id], cost[i]);
        }
        floyd_warshall(transformation_cost);
        vector<long long> memo(source.size(), -1);
        long long final_result = find_minimum_cost_from_position(0, source, target, trie_root, transformation_cost, memo);
        return final_result == 1e12 ? -1 : final_result;
    }
};


int main (){

    
    return 0;
}