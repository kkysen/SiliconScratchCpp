//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/Variable.h"
#include "src/main/List.h"

#include "llvm/ADT/StringMap.h"

namespace scratch {
    
    class Scope final {
    
        llvm::StringMap<Variable> variables;
        llvm::StringMap<List> lists;
    
    };
    
}
