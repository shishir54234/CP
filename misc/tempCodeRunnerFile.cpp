    int value = 0;
};
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> v(2);
        map<int,Node> m;
        int max1=0;
        vector<int> v1;
        vector<int> v2;
        if(matches.size()==0)
        {
            return v;
        }
        if(matches.size()>0)
        {
        int x=matches.size();
        for(int i=0;i<x;i++)