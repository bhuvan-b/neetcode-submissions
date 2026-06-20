class Node {
public:
    int val;
    vector<Node*> vect;

    Node(int num)
    {
        val = num;
    }    
};

class Solution {
public:
    vector<bool> track;
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, Node*> mp;
        track = vector<bool> (n, false);

        for(int i=0;i<n;i++)
            mp[i] = new Node(i);

        for(int i=0;i<edges.size();i++)
        {
            // if(mp.find(edges[i][0])==mp.end())
            //     mp[edges[i][0]] = new Node(edges[i][0]);

            // if(mp.find(edges[i][1])==mp.end())
            //     mp[edges[i][1]] = new Node(edges[i][1]);

            mp[edges[i][0]]->vect.push_back(mp[edges[i][1]]);
            mp[edges[i][1]]->vect.push_back(mp[edges[i][0]]);
        }

        if(iscycle(mp[0], -1))
            return false;

        for(int i=0;i<n;i++)
        {
            if(!track[i])
                return false;
        }

        return true;
    }

    bool iscycle(Node* node, int prev)
    {
        if(!node)
            return false;

        // cout << node->val << " " << track[node->val] << endl;

        if(track[node->val])
        {
            return true;
        }

        track[node->val] = true;

        for(int i=0;i<node->vect.size();i++)
        {
            if((node->vect[i]->val!=prev) && iscycle(node->vect[i], node->val))
                return true;
        }

        // track[node->val] = false;

        return false;

    }
};

// 0 1
// 0 2
// 0 3
// 1 4


