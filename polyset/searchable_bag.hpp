#pragma once

#include "bag.hpp"

// implemento questa classe  - non c'e' effittiva implem ho solo un blueprint

class searchable_bag : virtual public bag { //classe astratta
public:
    virtual ~searchable_bag() {}
    virtual bool has(int) const = 0; //metodo puro
};
