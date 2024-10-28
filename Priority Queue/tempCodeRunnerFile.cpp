class maxHeap {
private:
    vector<int> &heap; // Vector to store heap elements

public:
    maxHeap(vector<int>&v) {
        //O(N) calculate by solving AGP
        heap = v;