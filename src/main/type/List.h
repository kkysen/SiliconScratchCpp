//
// Created by Khyber on 8/22/2019.
//

#pragma once

#include "src/main/type/TypeBase.h"

namespace scratch::type {
    
    class List {

    private:
        
        stde::SmallPtr<TypeBase> _elementType;
        
    public:
        
        template <class TypeType, class... Args>
        static List make(Args&& ...args) {
            return List {stde::SmallPtr<TypeType>(std::forward<Args>(args)...)};
        }
        
        const TypeBase& elementType() {
            return *_elementType;
        }
        
    };
    
    List combine(List&& a, List&& b) {
        return List {combine(std::move(a.elementType()), std::move(b.elementType()))};
    }
    
}
