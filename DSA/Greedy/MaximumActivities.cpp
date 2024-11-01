//Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
//Note : Duration of the activity includes both starting and ending day.

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    // int activitySelection(vector<int> start, vector<int> end, int n)
    // {
    //     vector<pair<int,int>>v;
    //     for(int i=0 ; i<n ; i++){
    //         v.push_back({start[i],end[i]});
    //     }
    //     sort(v.begin() , v.end() , [](pair<int,int> a , pair<int,int> b) -> bool {
    //        return a.first == b.first ? a.second < b.second : a.first < b.first; 
    //     });
    //     int act = 1; //inittially doing first activity 
    //     int lastEnd = v[0].second;
    //     for(int i=1 ; i<n ; i++){
    //         if(lastEnd >= v[i].first) {
    //             lastEnd = min(v[i].second , lastEnd); //chosing minimum so that more activity can be done
    //         }
    //         else {
    //             act++;
    //             lastEnd = v[i].second;
    //         }
    //     }
    //     return act;
    // }

    //variation 2 by sorting from ending to avoid minimum 
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin() , v.end() , [](pair<int,int> a , pair<int,int> b) -> bool {
           return a.second < b.second; 
        });
        int act = 1;
        int lastEnd = v[0].second;
        for(int i=1 ; i<n ; i++){
            if(lastEnd < v[i].first) {
                act++;
                lastEnd = v[i].second;
            }
        }
        return act;
    }
};
//similar to non overlapping