//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/instructions/block/operator/Operator1.h"

namespace scratch::block::operator_ {
    
    class Abs : public Operator1 {
    
    public:
        
        explicit Abs(Value& value) : Operator1("abs", value) {};
        
    };
    
}
