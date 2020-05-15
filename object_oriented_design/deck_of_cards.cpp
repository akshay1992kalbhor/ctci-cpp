#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <random>


using namespace std;


enum class Suit {
    diamond, heart, club, spade
};

enum class Rank: int {
    ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king 
};

struct Card {
    Suit s;
    Rank r;
    Card(int ss, int rr) : s{ss}, r{rr} {}

};

ostream& operator<<(ostream& os, const Card& c) {
    os << "Suit: " <<  static_cast<int>(c.s) << " " << "Rank: " << static_cast<int>(c.r);
    return os;
}

bool operator==(const Card& lhs, const Card& rhs) {
    return lhs.s == rhs.s && lhs.r == rhs.r;
}

struct CardHash {
    size_t operator()(const Card* c) const {
        return hash<int>()(static_cast<int>(c->s)) ^ hash<int>()(static_cast<int>(c->r));
    }
};


struct CRandom {
    mt19937 gen;
    CRandom() : gen{random_device{}()} {
    }
};

struct Deck {
    unordered_map<Card*, int, CardHash> m;
    vector<Card*> v;
    CRandom crand;
    Deck() : v{}, m{}, crand{} {
        for (int s = 0; s < 4; s++) {
            for (int r = 0; r < 12; r++) {
                Card* c = new Card{s, r};
                m[c] = 1;
                v.push_back(c);
            }
        }
    }
    const Card& get_random_card() {
        // random number btween/inc 0 - v.size()-1
        //return *v[0];
        uniform_int_distribution<size_t> dist{0, v.size()-1};
        return *v[dist(crand.gen)];
    }
    void add_card(Card& c) {
        v.push_back(&c);
    }
};

struct Player {
    vector<Card*> hand;
    Player() : hand{} {}
    int get_score() {
        return 0;
    }

}

struct Game {

}

int main() {
    Deck d{};
    cout << d.get_random_card() << endl;
}
