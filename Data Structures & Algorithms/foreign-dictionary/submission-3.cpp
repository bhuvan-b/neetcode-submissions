class Solution {
public:
    stack<char> st;
    vector<vector<char>> adj;
    vector<bool> vis;
    vector<bool> track;

    pair<char, char> findedge(string a, string b)
    {
        int i=0;
        while(i<min(a.length(),b.length()))
        {
            if(a[i]!=b[i])
                return {a[i], b[i]};
            i++;
        }

        return {'#','#'};
    }

    bool topo_sort(char c)
    {
        if(track[c-'a'])
            return false;

        if(vis[c-'a'])
            return true;

        vis[c-'a'] = true;
        track[c-'a'] = true;

        for(int i=0;i<adj[c-'a'].size();i++)
        {
            if(!topo_sort(adj[c-'a'][i]))
                return false;
        }

        track[c-'a'] = false;

        st.push(c);

        return true;
    }

    string foreignDictionary(vector<string>& words) {
        vector<pair<char, char>> edges;
        for(int i=1;i<words.size();i++)
        {
            if(words[i-1].length()>words[i].length())
            {
                int len = words[i].length();
                // cout << words[i-1].substr(0, len) << " " << words[i].substr(len) << endl;
                if(words[i-1].substr(0, len)==words[i].substr(0, len))
                {
                    return "";
                }
            }
            pair<char, char> pr = findedge(words[i-1], words[i]);
            if(pr.first=='#')
                continue;
            edges.push_back(pr);
        }
        adj = vector<vector<char>> (26);
        for(int i=0;i<edges.size();i++)
        {
            char fr = edges[i].first;
            char sc = edges[i].second;
            cout << fr << " " << sc << endl;
            adj[fr-'a'].push_back(sc);
        }

        st = stack<char> ();
        vis = vector<bool> (26, false);
        track = vector<bool> (26, false);

        for(char c='a';c<='z';c++)
        {
            if(adj[c-'a'].size()>0)
            {
                if(!topo_sort(c))
                    return "";
            }
        }

        unordered_map<char, int> cnt;

        string str = "";
        while(!st.empty())
        {
            str+=st.top();
            cnt[st.top()]++;
            st.pop();
        }

        // if(edges.size()==0)
        //     return str;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                if(cnt[words[i][j]]==0)
                {
                    str+=words[i][j];
                    cnt[words[i][j]]++;
                }
            }
        }

        return str;
    }
};
