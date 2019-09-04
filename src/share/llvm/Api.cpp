//
// Created by Khyber on 7/30/2019.
//

#include "src/share/llvm/Api.h"

#include "src/share/stde/addStrings.h"

namespace llvm {
    
    std::string Api::nameFor(std::string_view symbolName) const {
        using namespace std::literals;
        return (("__"s += name) += "_"sv) += symbolName;
    }
    
    Api::Symbol Api::symbol(std::string_view symbolName) const {
        return Symbol(*this, symbolName);
    }
    
    Api::Symbol Api::operator()(std::string_view symbolName) const {
        return symbol(symbolName);
    }
    
    Api::Symbol::Symbol(const Api& api, std::string_view name) : api(api), name(api.nameFor(name)) {}
    
    Constant& Api::Symbol::global(Type& type) const {
        return *api.module.getOrInsertGlobal(name, &type);
    }
    
    Constant& Api::Symbol::global(Type& type, const Api::GlobalArgs& args) const {
        return *api.module.getOrInsertGlobal(name, &type, [&]() -> GlobalVariable* {
            return &args(name, type);
        });
    }
    
    Constant& Api::Symbol::constant(Constant& constant) const {
        return global(*constant.getType(), Api::GlobalArgs {
                .module = &api.module,
                .isConstant = true,
                .initializer = constant,
        });
    }
    
    ConstString Api::Symbol::string(const std::string& s) const {
        const auto string = api.constants.string(s);
        using namespace std::literals;
        using stde::string::operator+;
        const auto rawName = name + ".raw"s;
        return {
                .array = api(rawName).constant(string.array),
                .pointer = constant(string.pointer),
        };
    }
    
    ConstString Api::Symbol::string(std::string_view s) const {
        return string(std::string(s));
    }
    
}