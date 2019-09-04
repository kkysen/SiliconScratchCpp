//
// Created by Khyber on 8/26/2019.
//

#pragma once

#include "src/main/type/TypeBase.h"
#include "src/main/type/Primitive.h"
#include "src/main/type/List.h"
#include "src/main/type/Polymorphic.h"

namespace {
    
    using namespace scratch::type;
    
    union AllTypes {
        Primitive primitive;
        List list;
        Polymorphic polymorphic;
    };
    
}

namespace scratch {
    
    class Type : public TypeBase {

    private:
        
        static constexpr size_t paddingSize = sizeof(AllTypes) - sizeof(TypeBase);
        
        [[gnu::unused]] std::array<u8, paddingSize> padding;
        
    };
    
    Type combine(Type&& a, Type&& b);
    
}
