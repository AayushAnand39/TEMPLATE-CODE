class DSU{
    vector<int> parent, rank, size;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int node){
        if (node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulpU = find(u);
        int ulpV = find(v);
        if (ulpU==ulpV) return;
        if (rank[ulpU]<rank[ulpV]){
            parent[ulpU] = ulpV;
        }
        else if (rank[ulpV]<rank[ulpU]){
            parent[ulpV] = ulpU;
            rank[ulpU]++;
        }
    }
    void unionBySize(int u, int v){
        int ulpU = find(u);
        int ulpV = find(v);
        if (ulpU==ulpV) return;
        if (size[ulpU]<size[ulpV]){
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
        else{
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }
};
