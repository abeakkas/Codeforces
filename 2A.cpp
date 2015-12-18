#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    map<string, int> scores;
    vector<pair<string, int> > history;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        if(scores.find(name) == scores.end()) {
            scores[name] = score;
        } else {
            scores[name] += score;
        }
        history.push_back(make_pair(name, score));
    }
    string maxname;
    int maxscore = -1000000;
    vector<string> winners;
    for(map<string, int>::iterator i = scores.begin(); i != scores.end(); i++) {
        if(i->second > maxscore) {
            maxname = i->first;
            maxscore = i->second;
            winners.clear();
            winners.push_back(i->first);
        } else if(i->second == maxscore) {
            winners.push_back(i->first);
        }
    }
    if(winners.size() == 1) {
        cout << winners[0] << endl;
    } else {
        scores.clear();
        for(int i = 0; i < n; i++) {
            string name = history[i].first;
            int score = history[i].second;
            if(scores.find(name) == scores.end()) {
                scores[name] = score;
            } else {
                scores[name] += score;
            }
            if(scores[name] >= maxscore && find(winners.begin(), winners.end(), name) != winners.end()) {
                cout << name << endl;
                break;
            }
        }
    }
    return 0;
}
