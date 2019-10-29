#include <vector>

class Set {
public:
    explicit Set(const std::vector<int64_t> &vec) {
        for (unsigned int i = 0; i < vec.size(); ++i) {
            (*this).Add(vec[i]);
        }
    }
    Set() {}
    void Add(int64_t add) {
        if (!(*this).Contains(add)) {
            vector.push_back(add);
        }
    }

    void Remove(int64_t remove) {
        for (unsigned int i = 0; i < vector.size(); ++i) {
            if (remove == vector[i]) {
                int64_t buf = vector[vector.size() - 1];
                vector[vector.size()-1] = vector[i];
                vector[i] = buf;
                vector.pop_back();
            }
        }
    }

    bool Contains(int64_t check) const {
        for (unsigned int i = 0; i < vector.size(); ++i) {
            if (check == vector[i]) {
                return true;
            }
        }
        return false;
    }

    Set Union(const Set &hh) const {
        Set buff;
        for (unsigned int i = 0; i < vector.size(); ++i) {
            buff.Add(vector[i]);
        }
        for (unsigned int j = 0; j < hh.Data().size(); ++j) {
            buff.Add(hh.Data()[j]);
        }
        return buff;
    }

    Set Intersection(const Set &hh) const {
        Set buff;
        for (unsigned int i = 0; i < vector.size(); ++i) {
            for (unsigned int j = 0; j < hh.Data().size(); ++j) {
                if (vector[i] == hh.Data()[j]) {
                    buff.Add(vector[i]);
                }
            }
        }
        return buff;
    }

    Set Difference(const Set &hh) const {
        Set buff(vector);
        for (unsigned int i = 0; i < vector.size(); ++i) {
            for (unsigned int j = 0; j < hh.Data().size(); ++j) {
                if (vector[i] == hh.Data()[j]) {
                    buff.Remove(vector[i]);
                }
            }
        }
        return buff;
    }

    Set SymmetricDifference(const Set &hh) const {
        Set buff;
        for (unsigned int i = 0; i < vector.size(); ++i) {
            if (!hh.Contains(vector[i])) {
                buff.Add(vector[i]);
            }
        }
        for (unsigned int i = 0; i < hh.Data().size(); ++i) {
            if (!(*this).Contains(hh.Data()[i])) {
                buff.Add(hh.Data()[i]);
            }
        }
        return buff;
    }
    std::vector<int64_t> Data() const { return vector; }

private:
    std::vector<int64_t> vector;
};
