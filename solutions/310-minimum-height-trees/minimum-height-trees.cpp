class Solution {
public:
    vector<int> depth;
    vector<int> parent;

    void dfs(int u, int par, int dep, vector<vector<int>> &adj){
        parent[u]=par;
        depth[u]=dep;
        for(auto v: adj[u]){
            if(v!=par){
                dfs(v,u,dep+1,adj);
            }
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        depth.resize(n+1);
        parent.resize(n+1);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0,-1,0,adj);
        int diameter_start=0; 
        for(int i=0;i<n;i++){
            if(depth[diameter_start]<depth[i]){
                diameter_start=i;
            }
        }

        dfs(diameter_start,-1,0,adj);
        int diameter=0, diameter_end=diameter_start;
        for(int i=0;i<n;i++){
            if(depth[diameter_end]<depth[i]){
                diameter_end=i;
                diameter=depth[i];
            }
        }
        
        int count=diameter/2, temp=diameter_end;
        while(count){
            temp=parent[temp];
            count--;
        }
        vector<int> ans;
        ans.push_back(temp);
        if(diameter%2==1){
            ans.push_back(parent[temp]);
        }
        return ans;
    }

    // TC: O(N), SC: O(N)

    // =========== =========== =========== =========== =========== =========== =========== =========== =========== =========== ===========

    /*
        METHOD2: // Implementation heavy (good to know!!)
            The idea is that we trim out the leaf nodes layer by layer, until we reach the core of the graph, which are the centroids nodes.
            Once we trim out the first layer of the leaf nodes (nodes that have only one connection), some of the non-leaf nodes would become leaf nodes.
            The trimming process continues until there are only two nodes left in the graph, which are the centroids that we are looking for.
            The above algorithm resembles the topological sorting algorithm which generates the order of objects based on their dependencies.


                                public List<Integer> findMinHeightTrees(int n, int[][] edges) {
                                    if (n == 1) return Collections.singletonList(0);

                                    List<Set<Integer>> adj = new ArrayList<>(n);
                                    for (int i = 0; i < n; ++i) adj.add(new HashSet<>());
                                    for (int[] edge : edges) {
                                        adj.get(edge[0]).add(edge[1]);
                                        adj.get(edge[1]).add(edge[0]);
                                    }

                                    List<Integer> leaves = new ArrayList<>();
                                    for (int i = 0; i < n; ++i)
                                        if (adj.get(i).size() == 1) leaves.add(i);

                                    while (n > 2) {
                                        n -= leaves.size();
                                        List<Integer> newLeaves = new ArrayList<>();
                                        for (int i : leaves) {
                                            int j = adj.get(i).iterator().next();
                                            adj.get(j).remove(i);
                                            if (adj.get(j).size() == 1) newLeaves.add(j);
                                        }
                                        leaves = newLeaves;
                                    }
                                    return leaves;
                                }

    */

    // TC: O(N), SC: O(N)

};