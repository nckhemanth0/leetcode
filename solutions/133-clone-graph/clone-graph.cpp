/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution__ {
public:

    Node* root=nullptr;
    unordered_map<Node*,Node*> par;
    unordered_map<Node*,int> col;


    void dfs(Node* node, Node* parent){
        col[node]=1;
        Node* newNode=new Node(node->val);
        par[node]=newNode;
        if(parent==nullptr){
            root=newNode;
        }else{
            par[parent]->neighbors.push_back(newNode);
            newNode->neighbors.push_back(par[parent]);
        }
        for(auto child: node->neighbors){
            if(col[child]==0){
                dfs(child,node);
            }else if(col[child]==1 && child!=parent){
                par[child]->neighbors.push_back(newNode);
                newNode->neighbors.push_back(par[child]);
            }
        }
        col[node]=2;
    }

    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        dfs(node,nullptr);
        return root;
    }
};



/*
            if neighbor is unvisited:
                create its clone
                recurse
            add currentClone -> neighborClone

            0 / unvisited → clone not created yet
            1 / processing → clone created, neighbors maybe not finished
            2 / processed → clone fully built
*/

class Solution {
public:
    unordered_map<Node*, Node*> vis;
    void dfs(Node* node) {
        vis[node] = new Node(node->val);
        for (auto nei : node->neighbors) {
            if (!vis.count(nei)) {
                dfs(nei);
            }
            vis[node]->neighbors.push_back(vis[nei]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        dfs(node);
        return vis[node];
    }
};

/*

class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return node;
        }
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        Node* cloneNode = new Node(node->val, {});
        visited[node] = cloneNode;
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};

*/


/*
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        unordered_map<Node*, Node*> visited;
        deque<Node*> queue{node};
        visited[node] = new Node(node->val, {});
        while (!queue.empty()) {
            Node* n = queue.front();
            queue.pop_front();
            for (Node* neighbor : n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val, {});
                    queue.push_back(neighbor);
                }
                visited[n]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};
*/