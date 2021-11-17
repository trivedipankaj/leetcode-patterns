class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string temp ="";
        generate(0,0, n, 0, temp);
        return res;
    }
    
   void generate(int open, int closed, int n, int index, string &s){
        if(open == n && closed ==n){
            res.push_back(s);
            return;
        }
        if(open < n){
                s.push_back('(');
                generate(open+1, closed, n , index+1, s);
                s.pop_back();
            }
            if(open > closed){
                s.push_back(')');
                generate(open, closed+1, n, index+1, s);
                s.pop_back();
            }
        
         }
}

/*****BFS*****/

public:
    struct Node{
        string str;
        int open;
        int closed;

        Node(string s, int o, int c){
            str =s;
            open =o;
            closed =c;
        }
    };

    vector<string> generateParenthesis(int n) {
      vector<string> res;
      queue<Node> q;
        q.push(Node("",0,0));

        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(curr.open == n && curr.closed ==n){
                res.push_back(curr.str);
            }else{
                if(curr.open < n){
                    q.push(Node(curr.str+"(", curr.open+1, curr.closed));
                }
                if(curr.open > curr.closed){
                    q.push(Node(curr.str+")", curr.open, curr.closed+1));
                }

            }
        }

        return res;
    }
};;
