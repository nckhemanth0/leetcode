class Solution {
public:

    class state{
    public:
        int w,node,stops;
    };

    class cmp{
    public:
        bool operator()(state const &st1, state const &st2) const{
            return st1.w>st2.w;
        }
    };

    // =============  ============= METHOD 1: Quick and intuitive ============= ============= 

    /* __2d_matrix
     in a 1d matrix with distance alone:
            The cheapest path (lowest cost) may not be valid if it takes too many edges.
            A more expensive path that uses fewer stops might actually lead to a valid cheaper route later.

            So, we can’t use only dist[v] (best cost to node).
            We also need to consider how many stops it took to get there.

            Each state in the heap is (cost, node, stops_used):
                You can think of the algorithm as exploring the graph like Dijkstra,
                but keeping multiple “versions” of each node — one for each allowed number of stops.

                Example:
                You might reach city A with:

                cost = 100, stops = 1

                cost = 120, stops = 0

            
    */

    int findCheapestPrice__2D(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<state>> adj(n);
        for(auto x: flights){
            adj[x[0]].push_back({x[2],x[1]});
        }
        // (or) can even remove this and replace k+1 instead of k wherever we used k below
        k++; // increase to start with 0 stops initially so i can think in that way while coding same functionality
        vector<vector<int>> dis(n, vector<int>(k+1,1e9));
        vector<vector<int>> vis(n, vector<int>(k+1,0));
        priority_queue<state,vector<state>,cmp> q;
        q.push({0,src,0});
        dis[src][0]=0;
        while(!q.empty()){
            state u=q.top();
            q.pop();
            // if it has come till here, then it satisfied stops constraint
            if(u.node==dst){
                return u.w; // or u.w
            }
            if(vis[u.node][u.stops]){
                continue;
            }
            vis[u.node][u.stops]=1;
            for(auto v: adj[u.node]){
                if(u.stops+1<=k && dis[v.node][u.stops+1]>dis[u.node][u.stops]+v.w){
                    dis[v.node][u.stops+1]=dis[u.node][u.stops]+v.w;
                    q.push({dis[v.node][u.stops+1],v.node,u.stops+1});
                }
            }
        }
        return -1;
    }

    // =============  ============= METHOD 3: 1D stops array instead of dist/vis like above in Dijkstras ============= ============= 

    /*
        Same concept of extra stop state in queue like in above function comment!
        exact below code without this stops array gave TLE with 49/58 passed
        
        ****
                so stops array like vis after processing a node, make sure that when the best distance of popped node is already updated and if the steps to reach that previous best updated distance is more than the steps are seeing now before push, then we can still push into queue so we can make best chnage with more steps to reach destination
        ****

        Also here since not just distance but with steps, the nodes can give better answer, so we dont keep vis like we do after popping (i.e.. if vis of u.= then continue)

        And using priority queue is making sure we pick least distance and steps array is making sure 
            if a node even with more/less distance with less stops is there, we are going to consider in future pushing into the priority queue
            to ignore more stops than optimal distance one being pushed in q. 
        So thats y just introducing this stops array in this exact code helped solve TLE by stopping any consequent stale neighbor node updates without adding this large distance with more stops node in pq (more stops than one with optimal stops)
    
    */

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<state>> adj(n);
        for(auto x: flights){
            adj[x[0]].push_back({x[2],x[1]});
        }
        k++; // increase to start with 0 stops initially so i can think in that way while coding same functionality
        priority_queue<state,vector<state>,cmp> q;
        vector<int> stops(n,1e9); // storing stops for best distance
        q.push({0,src,0});
        while(!q.empty()){
            state u=q.top();
            q.pop();
            // if it has come till here, then it satisfied stops constraint
            if(u.node==dst){
                return u.w; // or u.w
            }
            stops[u.node]=u.stops;
            for(auto v: adj[u.node]){
                if(u.stops+1<=k && stops[v.node]>u.stops+1){
                    q.push({u.w+v.w,v.node,u.stops+1});
                }
            }
        }
        return -1;
    }

    // ============= ============= ============= METHOD 2: Bellman–Ford ============= ============= =============

    /*
            BELLMAN-FORD:

            🧩 Bellman-Ford intuition (classic)

                    We don’t limit the number of edges in the path; we just know that any simple path can have ≤ V−1 edges.
                    So we run that many rounds to be sure the best info has propagated everywhere.

                    Example
                    0 --5--> 1 --2--> 2


                    dist[0]=0, others=∞

                    Iteration 1:

                    relax(0→1): dist[1]=5

                    relax(1→2): dist[2]=7 ← notice this used the new dist[1]=5 updated earlier in same iteration
                    ⇒ Path 0→1→2 (2 edges) formed inside one iteration

                    And that’s okay! Bellman–Ford wants that.
                    After 1 iteration we already know the cost of a 2-edge path.

                    That’s why it says:

                    “After i iterations, I know the shortest paths that use at most i edges.”

                    So the in-place update is exactly what allows that “at-most” behavior.

                ---------

            ✈️ Cheapest Flight with K Stops intuition

                    Here the rule is strict:

                    You may take at most K stops = K+1 edges.

                    We want to simulate “how far can I go if I take 0, 1, 2, …, K edges”.

                    So the i-th round should only use the information from paths that already have ≤ i−1 edges.

                    If you let in-place updates cascade like Bellman–Ford, a single iteration would already combine two edges from the same round, giving a path longer than allowed for that step.

                    Mini counter-example
                    0 --100--> 1 --100--> 2
                    k = 0  (no stops → only 1 edge)


                    If you update in-place:

                    relax(0→1): dist[1]=100

                    relax(1→2): dist[2]=200 ❌ used dist[1] that was just updated
                    → now dist[2] represents a 2-edge path while you’re in the “1-edge” round.

                    But we were supposed to stop at 1 edge.
                    So you’ve accidentally counted a path that has 2 edges, violating the constraint.

                    Using a copy (temp or prev) prevents that cascade:

                    Round 0 uses original distances (only source known).

                    Round 1 computes all nodes reachable in 1 edge using those originals.

                    Round 2 computes all nodes reachable in 2 edges using Round 1 values, and so on.

                    So after the i-th round, every distance truly represents the cheapest path with ≤ i edges.




                                    class Solution {
                                    public:
                                        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
                                            // Distance from source to all other nodes.
                                            vector<int> dist(n, numeric_limits<int>::max());
                                            dist[src] = 0;

                                            // Run only K+1 times since we want shortest distance in K hops.
                                            for (int i = 0; i <= k; i++) {
                                                // Create a copy of dist vector.
                                                vector<int> temp(dist);
                                                for (auto& flight : flights) {
                                                    if (dist[flight[0]] != numeric_limits<int>::max()) {
                                                        temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
                                                    }
                                                }
                                                // Copy the temp vector into dist.
                                                dist = temp;
                                            }
                                            return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
                                        }
                                    };
    */


    // ============= ============= ============= MISTAKE ============= ============= =============

    /*
        for this code, priority queue fails because, shortest path might have updated with best possible weights within k stops (lets say more stops than ans path).
        But when a more distance path comes into picture, it will not override this above distance and is not pushed into queue

        ex: [[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]]

        But with plain queue, it involves same node to be relaxed multiple times too unlike dijk where one node is relaxed once


    */
    int findCheapestPrice__queue_not_pq(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<state>> adj(n);
        for(auto x: flights){
            adj[x[0]].push_back({x[2],x[1]});
        }
        vector<int> vis(n,0);
        vector<int> dis(n,1e9);
        // priority_queue<state,vector<state>,cmp> q;
        queue<state> q;
        q.push({0,src,-1});
        dis[src]=0;
        while(!q.empty()){
            state u=q.front();
            cout<<u.w<<" "<<u.node<<" "<<u.stops<<endl;
            q.pop();
            // if(u.node==dst){
            //     return dis[u.node]; // or u.w
            // }
            vis[u.node]=1;
            for(auto v: adj[u.node]){
                if(dis[v.node]>u.w+v.w && u.stops+1<=k){ // u.w is src to u distance
                    dis[v.node]=u.w+v.w;
                    q.push({dis[v.node],v.node,u.stops+1});
                }
            }
        }
        return dis[dst]==1e9?-1:dis[dst];
    }


};