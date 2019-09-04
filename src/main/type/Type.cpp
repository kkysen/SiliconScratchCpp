//
// Created by Khyber on 8/26/2019.
//

#include "src/main/type/Type.h"

namespace {
    
    using namespace scratch;
    
    template <class T>
    Type combineAs(Type&& a, Type&& b) {
        return combine(std::move(a.as<T>()), std::move(b.as<T>())).template as<Type>();
    }
    
}

namespace scratch::type {
    
    Type combine(Type&& a, Type&& b) {
        if (a.kind == b.kind) {
            switch (a.kind) {
                case TypeKind::integral:
                case TypeKind::floating:
                    return combineAs<Primitive>(std::move(a), std::move(b));
                case TypeKind::list:
                    return combineAs<List>(std::move(a), std::move(b));
                case TypeKind::polymorphic:
                    return combineAs<Polymorphic>(std::move(a), std::move(b));
            } else {
            
            }
        }
    }
    
}