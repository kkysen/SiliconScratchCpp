//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/instructions/block/operator/Operator2.h"

namespace scratch::block::operator_ {
    
    class Max : public Operator2 {
    
    public:
    
        Max(Value& lhs, Value& rhs) : Operator2("min", lhs, rhs) {}
        
    };
    
}
