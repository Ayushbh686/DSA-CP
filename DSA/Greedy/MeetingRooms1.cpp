// Given an array of meeting time intervals consisting of start and end times [(s1,e1),(s2,e2),...] (si < ei), determine if a person could attend all meetings.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canAttendMeetings(vector<vector<int>> intervals) {
    int n = intervals.size();
    vector<int>start;
    vector<int>end;
    for(int i=0 ; i<n ; i++){
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int i=0 , j=0;
    int Rooms = 0 , minRooms = 0;
    while(i<n and j<n){
        if(start[i] < end[j]){
            Rooms++;
            minRooms = max(minRooms , Rooms);
            i++;
        }
        else if(start[i] > end[i]){
            Rooms--;
            j++;
        }
        else{ //start and end at same time
            i++;
            j++;
        }
    }
    return minRooms==1;
}

int main(){
    //pass test cqses
    cout<<canAttendMeetings({{1,2},{3,5},{5,6},{6,10}})<<endl;
    cout<<canAttendMeetings({{1,2},{3,5},{4,6},{6,10}})<<endl;
    return 0;
}