//
// Created by Khyber on 2/17/2019.
//

#pragma once

#include "src/share/llvm/Types.h"
#include "src/share/llvm/lib/conversions.h"

namespace llvm {
    
    struct ConstString {
        Constant& array;
        Constant& pointer;
    };
    
    class Constants {
    
    public:
    
        const Types types;
        
        explicit constexpr Constants(LLVMContext& context) : types(context) {}
        
        explicit constexpr Constants(const Module& module) : Constants(module.getContext()) {}
        
        template <typename T>
        constexpr ConstantInt& integer(T t) const {
            return *ConstantInt::get(&types.integral<T>(), t, std::is_signed_v<T>);
        }
        
        // ConstantDataArray::get does the same thing,
        // but it uses Type::getScalarTy<T>(), which is a much less powerful types.get<T>().
        template <typename T>
        constexpr Constant& dataArray(ArrayRef<T> array) const {
            const auto data = reinterpret_cast<const char*>(array.data());
            const auto string = StringRef(data, array.size() * sizeof(T));
            return *ConstantDataArray::getRaw(string, array.size(), &types.get<T>());
        }
        
        template <typename T>
        constexpr UndefValue& undefined() const {
            return *UndefValue::get(&types.get<T>());
        }
    
        ConstString string(const std::string& s) const;
    
        ConstString string(std::string_view s) const;
        
    };
    
}
