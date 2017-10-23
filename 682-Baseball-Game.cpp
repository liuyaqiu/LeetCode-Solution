/*
  Baseball Game

  You're now a baseball game point recorder.

  Given a list of strings, each string can be one of the 4 following types:

  Integer (one round's score): Directly represents the number of points you get in this round.
  "+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
  "D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
  "C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
  Each round's operation is permanent and could have an impact on the round before and the round after.

  You need to return the sum of the points you could get in all the rounds.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calPoints(vector<string>& ops) {
    vector<int> rounds;
    int res = 0;
    for(auto item: ops) {
        if(item == "+") {
            if(rounds.size() >= 2) {
                rounds.push_back(rounds[rounds.size() - 1] + rounds[rounds.size() - 2]);
                res += rounds.back();
            }
        }
        else if(item == "C") {
            if(!rounds.empty()) {
                res -= rounds.back();
                rounds.pop_back();
            }
        }
        else if(item == "D") {
            if(!rounds.empty()) {
                rounds.push_back(rounds.back() * 2);
                res += rounds.back();
            }
        }
        else {
            int val = stoi(item);
            rounds.push_back(val);
            res += rounds.back();
        }
    }
    return res;
}
