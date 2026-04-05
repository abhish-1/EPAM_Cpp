// Create a struct named PlayerStats.
// It should contain the following public members: std::string playerId; //(e.g., "P001", "P002") - a unique identifier for the player. std::string playerName; //(e.g., "Alice", "Bob") int score; //(e.g., 1500, 1200)
// Use constructor initialization list for initializing the above class members

// Create another struct named PlayerRankComparator. This will be your functor.
// Inside PlayerRankComparator, overload the operator() that takes two constant references to PlayerStats objects (const PlayerStats& p1, const PlayerStats& p2).
// This operator() must return true if p1 should come before p2 in the sorted order, and false otherwise.
// Implement the ranking logic as described in the Context:
// Primary Sort: Compare score in descending order. If p1.score is greater than p2.score, p1 comes first.
// Secondary Sort (if scores are equal): Compare playerName in ascending order. If p1.playerName is alphabetically smaller than p2.playerName, p1 comes first.
// Tertiary Sort (if scores and names are equal): Compare playerId in ascending order. This is crucial for std::map's strict weak ordering requirement, even if playerName is expected to be unique.

#include<iostream>
#include<map>
#include<string>

using namespace std;

struct PlayerStats{
    string playerId;
    string playerName;
    int score; 
    
    PlayerStats(string id, string name, int s) : playerId(id), playerName(name), score(s) {}
};

struct PlayerRankComparator{
    bool operator()(const PlayerStats& p1, const PlayerStats& p2) const {
        if(p1.score > p2.score) return true;  
        if(p1.score < p2.score) return false;
        
        if(p1.playerName < p2.playerName) return true;  
        if(p1.playerName > p2.playerName) return false;
        
        return p1.playerId < p2.playerId;  
    }
};

int main(){
    map<PlayerStats, bool, PlayerRankComparator> leaderboard;
    
    leaderboard[PlayerStats("P001", "ATul", 1500)] = true;
    leaderboard[PlayerStats("P003", "cman", 1200)] = true;
    leaderboard[PlayerStats("P002", "dman", 1500)] = true;
    leaderboard[PlayerStats("P005", "vid", 1800)] = true;
    leaderboard[PlayerStats("P004", "djshashi", 1000)] = true;
    leaderboard[PlayerStats("P007", "meow", 1200)] = true;
    leaderboard[PlayerStats("P006", "gop", 1500)] = true;
    
    int rank = 1;
    for(const auto& entry : leaderboard){
        cout << "Rank " << rank << " ID: " << entry.first.playerId 
             << " Name: " << entry.first.playerName 
             << " Score: " << entry.first.score << endl;
        rank++;
    }
    
    return 0;
}