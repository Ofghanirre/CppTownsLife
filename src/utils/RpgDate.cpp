//
// Created by Antonin on 13/04/2023.
//

#include "RpgDate.h"

bool RpgDate::next() {
    switch (_season) {
        case Spring: _season = Summer; return false;
        case Summer: _season = Autumn; return false;
        case Autumn: _season = Winter; return false;
        case Winter: {
            _season = Spring;
            _year++;
        }
    }
    return true;
}

RpgDate &RpgDate::operator++() {
    next();
    return *this;
}

RpgDate &RpgDate::operator++(int) {
    RpgDate& temp = *this;
    ++(*this);
    return temp;
}

int RpgDate::get_year() const {
    return _year;
}

Season RpgDate::get_season() const {
    return _season;
}

ostream& operator<<(ostream &_stream, const RpgDate &date) {
    return _stream << season_to_string(date.get_season()) + " of " + to_string(date.get_year());
}
