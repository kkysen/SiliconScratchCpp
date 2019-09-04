//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/instructions/block/operator/Operator2.h"

namespace scratch::block::operator_ {
    
    class Min : public Operator2 {
    
    public:
    
        Min(Value& lhs, Value& rhs) : Operator2("min", lhs, rhs) {}
        
    };
    
}
