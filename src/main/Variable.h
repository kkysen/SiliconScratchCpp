//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/LValue.h"

namespace scratch {
    
    class Variable final : public LValue {

    public:
        
        explicit Variable(std::string name) : LValue(ValueKind::variable, std::move(name)) {}
        
    };
    
}
