//
// Created by Khyber on 8/22/2019.
//

#pragma once

#include "src/main/type/TypeBase.h"
#include "src/share/common/numbers.h"
#include "src/share/common/math.h"

namespace scratch::type {
    
    class Primitive : public TypeBase {
    
    public:
        
        const u32 numBits;
        
        constexpr Primitive withNumBits(u32 newNumBits) const noexcept {
            return Primitive(kind, newNumBits);
        }
    
    private:
        
        explicit constexpr Primitive(TypeKind kind, u32 numBits) noexcept
                : TypeBase(kind), numBits(numBits) {}

    public:
        
        static constexpr Primitive integral(u32 numBits) noexcept {
            return Primitive(TypeKind::integral, numBits);
        }
    
        static constexpr Primitive floating(u32 numBits) noexcept {
            return Primitive(TypeKind::floating, numBits);
        }
    
        #define i(n) \
        static constexpr Primitive i##n() noexcept { \
            return integral(n); \
        }
        
        i(1)
        i(8)
        i(16)
        i(32)
        i(64)
        i(128)
    
        #undef i
    
        #define f(n) \
        static constexpr Primitive f##n() noexcept { \
            return integral(n); \
        }
        
        f(32)
        f(64)
    
        #undef f
        
        static constexpr Primitive boolean() noexcept {
            return i1();
        }
        
    };
    
    constexpr Primitive combine(Primitive&& a, Primitive&& b) noexcept {
        if (a.kind == b.kind) {
            return a.withNumBits(math::max(a.numBits, b.numBits));
        } else {
            return Primitive::floating(math::max(a.numBits, b.numBits));
        }
    }
    
}
