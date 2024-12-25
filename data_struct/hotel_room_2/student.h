#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include <vector>

using namespace std;

class hotel {

map<int, set<int>> room_by_avail; 
vector<int> rooms;
map<int, int> ck_in, g, total;
int current_day = 0, total_room = 0;

public:
    hotel(vector <int> _rooms) {
        rooms = _rooms;
    	for (int i = 1; i < rooms.size(); ++i) {
            room_by_avail[rooms[i]].insert(i);
            total_room += rooms[i];
        }
    }

    void next_day() { current_day++; }

    vector <pair <int, int>> check_in(int group, int num) {
        vector<pair<int, int>> ret;
        if (total_room < num) return ret;
        ck_in[group] = current_day;
        g[group] = num;
        total_room -= num;
        while (num > 0) {
            auto it = room_by_avail.lower_bound(num);
            if (it == room_by_avail.end()) --it;
            int avail = it->first;
            if (avail <= num) {
                auto it2 = prev((it->second).end());
                ret.push_back({*it2, avail});
                rooms[*it2] -= avail;
                room_by_avail[0].insert(*it2);
                num -= avail;
                (it->second).erase(it2);
                if ((it->second).empty()) room_by_avail.erase(it);
            }
            else {
                auto it2 = prev((it->second).end());
                ret.push_back({*it2, num});
                rooms[*it2] -= num;
                room_by_avail[avail-num].insert(*it2);
                num = 0;
                (it->second).erase(it2);
                if ((it->second).empty()) room_by_avail.erase(it);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }

    int check_out(int group, int floor) {
        room_by_avail[rooms[floor]].erase(floor);
        if (room_by_avail[rooms[floor]].empty()) room_by_avail.erase(rooms[floor]);
        rooms[floor]++;
        total_room++;
        room_by_avail[rooms[floor]].insert(floor);
        total[group] += current_day - ck_in[group] + 1;
        return (--g[group] == 0 ? total[group] : 0);
    }
};

#endif
