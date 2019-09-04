//
// Created by Khyber on 8/19/2019.
//

#pragma once

#include "src/main/type/TypeKind.h"

#include "src/share/stde/SmallPtr.h"

#include <type_traits>

namespace scratch {
    
    class TypeBase {
    
    public:
        
        const TypeKind kind;
    
    protected:
        
        explicit constexpr TypeBase(TypeKind kind) noexcept : kind(kind) {}
    
    public:
        
        template <class TypeType>
        const TypeType& as() const noexcept {
            static_assert(std::is_base_of_v<TypeBase, TypeType>);
            return reinterpret_cast<const TypeType&>(*this);
        }
    
        template <class TypeType>
        TypeType& as() noexcept {
            static_assert(std::is_base_of_v<TypeBase, TypeType>);
            return reinterpret_cast<TypeType&>(*this);
        }
        
    };
    
}
