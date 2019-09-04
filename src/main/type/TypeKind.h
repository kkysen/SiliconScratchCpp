//
// Created by Khyber on 8/22/2019.
//

#pragma once

namespace scratch {
    
    class TypeKind {
    
    public:
        
        enum Raw {
            integral,
            floating,
            list,
            polymorphic,
        };
    
    private:
        
        Raw value;
    
    public:
        
        /*implicit*/ constexpr TypeKind(Raw value) noexcept : value(value) {}
        
        constexpr Raw raw() const noexcept {
            return value;
        }
        
        /*implicit*/ constexpr operator Raw() const noexcept {
            return raw();
        }
        
        constexpr bool isIntegral() const noexcept {
            return value == integral;
        }
        
        constexpr bool isFloatingPoint() const noexcept {
            return value == floating;
        }
        
        constexpr bool isPrimitive() const noexcept {
            return isIntegral() || isFloatingPoint();
        }
        
        constexpr bool isList() const noexcept {
            return value == list;
        }
        
        constexpr bool isPolymorphic() const noexcept {
            return value == polymorphic;
        }
        
    };
    
}
