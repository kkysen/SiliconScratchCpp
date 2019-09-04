//
// Created by Khyber on 7/30/2019.
//

#include "src/share/llvm/Constants.h"

namespace llvm {
    
    ConstString Constants::string(const std::string& s) const {
        Constant& array = *ConstantDataArray::getRaw(
                StringRef(s.c_str(), s.size() + 1),
                s.size() + 1,
                &types.get<const char>()
        );
        Constant& pointer = *ConstantExpr::getInBoundsGetElementPtr(
                nullptr,
                &array,
                &integer<u64>(0)
        );
        errs() << types.get<const char*>() << '\n';
        errs() << *array.getType() << '\n';
        errs() << *pointer.getType() << '\n';
//        errs() << ConstantExpr::getAsInstruction();
        return {.array = array, .pointer = pointer};
    }
    
    ConstString Constants::string(std::string_view s) const {
        return string(std::string(s));
    }
    
}
