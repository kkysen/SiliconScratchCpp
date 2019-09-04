//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/Value.h"

namespace scratch {
    
    class Constant : public Value {

    public:
        
        Constant() : Value(ValueKind::constant) {}
        
    };
    
}
