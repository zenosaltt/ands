#ifndef TMFSET_HPP
#define TMFSET_HPP

class TMFSet {
    private:
        int *parent;
        int *rank;

    public:
        TMFSet(int n);
        ~TMFSet();

        int find(int x);
        void merge(int x, int y);
};

#endif