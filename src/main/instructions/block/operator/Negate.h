//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/instructions/block/operator/Operator1.h"

namespace scratch::block::operator_ {
    
    class Negate : public Operator1 {

    public:
        
        explicit Negate(Value& value) : Operator1("negate", value) {};
        
    };
    
}
