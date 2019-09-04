//
// Created by Khyber on 8/23/2019.
//

#pragma once

#include "src/main/type/TypeBase.h"
#include "src/share/stde/SmallPtr.h"

namespace scratch::type {
    
    stde::SmallPtr<TypeBase> combine(const TypeBase& a, const TypeBase& b);
    
}
