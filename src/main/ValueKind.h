//
// Created by Khyber on 8/3/2019.
//

#pragma once

namespace scratch {
    
    class ValueKind {

    public:
        
        enum Raw {
            constant,
            instruction,
            variable,
            list,
        };

    private:
        
        Raw value;

    public:
    
        /*implicit*/ constexpr ValueKind(Raw value) noexcept : value(value) {}
    
        constexpr Raw raw() const noexcept {
            return value;
        }
    
        /*implicit*/ constexpr operator Raw() const noexcept {
            return raw();
        }
        
        constexpr bool isConstant() const noexcept {
            return value == constant;
        }
    
        constexpr bool isInstruction() const noexcept {
            return value == instruction;
        }
    
        constexpr bool isRValue() const noexcept {
            return true;
        }
    
        constexpr bool isLValue() const noexcept {
            return isVariable() || isList();
        }
    
        constexpr bool isVariable() const noexcept {
            return value == variable;
        }
    
        constexpr bool isList() const noexcept {
            return value == list;
        }
        
    };
    
}
