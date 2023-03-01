//
// Created by Antonin on 01/03/2023.
//

#ifndef TEST1_NPCCOUPLE_H
#define TEST1_NPCCOUPLE_H


#include <algorithm>
#include <stdexcept>

class NpcCouple {
public:
    NpcCouple(long idMate1, long idMate2) : _idMate1(std::min(idMate1, idMate2)), _idMate2(std::max(idMate2, idMate1)) {
        if (idMate1 == idMate2) {
            throw std::invalid_argument("couple shall have different id");
        }
    }

    ~NpcCouple() {

    }

    bool operator==(const NpcCouple& other) const {
        return other._idMate1 == _idMate1 && other._idMate2 == _idMate2;
    }

    size_t get_hash() const
    {
        std::hash<long> hash_fcn;
        return hash_fcn(_idMate1) ^ hash_fcn(_idMate2);
    }
private:
    long _idMate1;
    long _idMate2;
};

namespace std {

    template <>
    struct hash<NpcCouple>
    {
        size_t operator()(const NpcCouple& npcCouple) const
        {
            return npcCouple.get_hash();
        }
    };

}
#endif //TEST1_NPCCOUPLE_H
