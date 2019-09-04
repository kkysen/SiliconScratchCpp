//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/instructions/block/operator/Operator.h"

namespace scratch::block {
    
    class Operator1 : public Operator<1> {
    
    private:
        
        using Super = Operator<1>;
    
    protected:
        
        Operator1(std::string_view name, Value& value)
                : Super(name, {&value}) {}
        
    };
    
}
