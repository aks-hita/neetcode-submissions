/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;
       sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        vector<int> rooms;
        rooms.push_back(intervals[0].end);
        for(int i=1;i<intervals.size();i++){
            bool assigned=false;
            for(int j=0;j<rooms.size();j++){
                if(intervals[i].start>=rooms[j]){
                    rooms[j]=intervals[i].end;
                    assigned=true;
                    break;    
                }
            }
            if(!assigned){
                rooms.push_back(intervals[i].end);
                assigned=true;
            }
        }
        return rooms.size(); 
    }
};
