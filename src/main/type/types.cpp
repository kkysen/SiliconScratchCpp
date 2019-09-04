//
// Created by Khyber on 8/23/2019.
//

#include "src/main/type/types.h"

#include "src/main/type/Primitive.h"
#include "src/main/type/List.h"
#include "src/main/type/Polymorphic.h"

namespace scratch::type {
    
    stde::SmallPtr<TypeBase> combine(TypeBase&& a, TypeBase&& b) {
        if (a.kind == b.kind) {
            #define combine(T) stde::SmallPtr<T>(combine(a.as<T>(), b.as<T>()))
            switch (a.kind) {
                case TypeKind::integral:
                case TypeKind::floating:
                    return combine(Primitive);
                case TypeKind::list:
                    return combine(List);
                case TypeKind::polymorphic:
                    return combine(Polymorphic);
            }
        } else {
        
        }
    }
    
}