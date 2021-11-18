class TopVotedCandidate {
public:
    unordered_map<int, int> votes;
    unordered_map<int, int> topLeader;
    
    int maxVotes=0;
    int leader;
    int prevLeader;
    int currTime=-1;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        leader = persons[0];
    
        for(int i=0; i<persons.size(); i++){
            votes[persons[i]]++;
            if(votes[persons[i]] >= maxVotes){
                maxVotes = votes[persons[i]];
                leader = persons[i];
            }
         
            while( currTime < times[i]){
                topLeader[++currTime] = prevLeader;
            }
            topLeader[currTime] = leader;
            prevLeader = leader;
        }
    }
    
    
    int q(int t) {
        if(t > currTime) return topLeader[currTime];
        return topLeader[t];
    }
};

