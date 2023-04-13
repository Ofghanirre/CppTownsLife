//
// Created by Antonin on 13/04/2023.
//

#ifndef TEST1_RPGDATE_H
#define TEST1_RPGDATE_H

#include <string>

using namespace std;

enum Season {
    Spring = 0,
    Summer,
    Autumn,
    Winter
};
static string season_to_string(Season season) {
    switch (season) {
        case Spring: return "Spring";
        case Summer: return "Summer";
        case Autumn: return "Autumn";
        case Winter: return "Winter";
        default: return "";
    }
}

class RpgDate {
public:
    RpgDate(int year, Season season) : _year(year), _season(season) {
        if (year < 0) {
            throw "Year must be positive integer";
        }
    }

    [[nodiscard]] inline string to_string() const {
        return season_to_string(_season) + " " + std::to_string(_year);
    }

    int get_year() const;
    Season get_season() const;
    bool next();

    RpgDate& operator++();
    RpgDate& operator++(int);

private:
    int _year;
    Season _season;
};


#endif //TEST1_RPGDATE_H
