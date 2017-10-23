/*
  Dota2 Senate

  In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the senate wants to make a decision about a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: 
A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: 
If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and make the decision about the change in the game.
Given a string representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party respectively. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party, you need to predict which party will finally announce the victory and make the change in the Dota2 game. The output should be Radiant or Dire.

 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

string predictPartyVictory(string senate) {
    set<int> radiant, dire, alls;
    for(int i = 0; i < senate.length(); i++) {
        alls.insert(i);
        if(senate[i] == 'R')
            radiant.insert(i);
        else
            dire.insert(i);
    }
    while(!radiant.empty() && !dire.empty()) {
        for(auto item: alls) {
            if(senate[item] == 'R') {
                if(dire.empty())
                    return "Radiant";
                auto ban = dire.upper_bound(item);
                if(ban == dire.end())
                    ban = dire.begin();
                alls.erase(*ban);
                dire.erase(ban);
            }
            else {
                if(radiant.empty())
                    return "Dire";
                auto ban = radiant.upper_bound(item);
                if(ban == radiant.end())
                    ban = radiant.begin();
                alls.erase(*ban);
                radiant.erase(ban);
            }
        }
    }
    if(radiant.empty())
        return "Dire";
    else
        return "Radiant";
}
