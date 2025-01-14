template <typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>> {
public:
    bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it == this->c.end()) {
            return false; // Value not found
        }
        this->c.erase(it); // Remove element
        std::make_heap(this->c.begin(), this->c.end(), this->comp); // Re-heapify
        return true;
    }
};