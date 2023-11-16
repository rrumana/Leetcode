#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    int size;
    std::vector<std::list<int>> adj;

    Graph(int size){
        this->size = size;
        adj.resize(size);
    };
 
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
 
    // BFS traversal from node 0
    bool BFS(){
        // Mark all the vertices as not visited
        std::vector<bool> visited;
        visited.resize(size, false);
 
        // Create a queue for BFS
        std::list<int> queue;
 
        // Mark the current node as visited and enqueue it
        int current = 0;
        visited[0] = true;
        queue.push_back(0);
 
        while (!queue.empty()) {
 
            // Dequeue a vertex from queue and print it
            current = queue.front();
            //std::cout << current << std::endl;
            queue.pop_front();
 
            // enqueue all adjacent vertices that haven't already been queued
            for (auto adjacent : adj[current]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }

        return visited[size-1];
    }
};

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int currect = 0;
        int goal = nums.size()-1;

        // turn problem into graph
        Graph graph = Graph(nums.size());

        for(int i = 0; i <= goal; i++){
            if(nums[i] == 0) continue;
            for(int j = 1; j <= nums[i]; j++){
                if(i+j > goal) break;
                graph.addEdge(i, i+j);
            }
        }

        for(auto x : graph.adj){
            for(auto y : x){
                //std::cout << y << " ";
            }
            //std::cout << std::endl;
        }

        return graph.BFS();
    }
};

void test1() {
    std::vector<int> input = {2,3,1,1,4};
    bool output = false;
    bool expected = true;

    Solution solution;
	output = solution.canJump(input);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> input = {3,2,1,0,4};
    bool output = false;
    bool expected = false;

    Solution solution;
	output = solution.canJump(input);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

int main() {
    test1();
    test2();
	return 0;
}