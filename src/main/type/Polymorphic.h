//
// Created by Khyber on 8/23/2019.
//

#pragma once

#include "src/main/type/TypeBase.h"

#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/iterator.h"

namespace scratch::type {
    
    class Polymorphic {

    private:
        
        static constexpr auto defaultNumTypes = 2;
        
        llvm::SmallVector<stde::SmallPtr<TypeBase>, defaultNumTypes> _types;

    public:
        
        auto types() const noexcept {
            return llvm::make_pointee_range(_types);
        }
        
    };
    
    Polymorphic combine(Polymorphic&& a, Polymorphic&& b) {
    
    }
    
}
