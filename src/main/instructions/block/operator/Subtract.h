//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/instructions/block/operator/Operator2.h"

namespace scratch::block::operator_ {
    
    class Subtract : public Operator2 {
    
    public:
    
        Subtract(Value& lhs, Value& rhs) : Operator2("subtract", lhs, rhs) {}
        
    };
    
}
