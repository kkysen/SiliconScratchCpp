//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/instructions/block/operator/Operator.h"

namespace scratch::block {
    
    class Operator2 : public Operator<2> {
    
    private:
        
        using Super = Operator<2>;
    
    protected:
        
        Operator2(std::string_view name, Value& lhs, Value& rhs)
                : Super(name, {&lhs, &rhs}) {}
        
    };
    
}
