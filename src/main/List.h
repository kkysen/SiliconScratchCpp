//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/LValue.h"

namespace scratch {
    
    class List final : public LValue {

    private:

    public:
        
        Lazy<TypeBase> elementType;
    
        explicit List(std::string name) : LValue(ValueKind::list, std::move(name)) {}
    
    };
    
}
