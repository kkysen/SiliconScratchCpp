//
// Created by Khyber on 3/22/2019.
//

#pragma once

#include "src/share/llvm/Types.h"
#include "src/share/llvm/Constants.h"

#include "llvm/IR/Module.h"
#include "llvm/IR/DerivedTypes.h"

#include <string_view>

namespace llvm {
    
    class Api {
    
    public:
        
        const std::string_view name;
    
    private:
        
        Module& module;
    
    public:
        
        const Types types;
        
        const Constants constants;
        
        constexpr Api(std::string_view name, Module& module) noexcept
                : name(name), module(module), types(module.getContext()), constants(module) {}
    
    private:
        
        std::string nameFor(std::string_view symbolName) const;
    
    public:
        
        struct GlobalArgs {
            
            Module* module;
            bool isConstant;
            GlobalValue::LinkageTypes linkage;
            Constant& initializer;
            GlobalVariable* insertBefore;
            GlobalValue::ThreadLocalMode threadLocalMode;
            u32 addressSpace;
            bool isExternallyInitialized;
            
            GlobalVariable& operator()(StringRef fullName, Type& type) const {
                if (module) {
                    return *new GlobalVariable(
                            *module,
                            &type,
                            isConstant,
                            linkage,
                            &initializer,
                            fullName,
                            insertBefore,
                            threadLocalMode,
                            addressSpace,
                            isExternallyInitialized
                    );
                } else {
                    return *new GlobalVariable(
                            &type,
                            isConstant,
                            linkage,
                            &initializer,
                            fullName,
                            threadLocalMode,
                            addressSpace,
                            isExternallyInitialized
                    );
                }
            }
            
        };
        
        class Symbol {
        
        public:
            
            const Api& api;
            const std::string name;
            
            Symbol(const Api& api, std::string_view name);
            
            template <class F>
            FunctionCallee func() const {
                return api.module.getOrInsertFunction(name, &api.types.func<F>());
            }
            
            Constant& global(Type& type) const;
            
            Constant& global(Type& type, const GlobalArgs& args) const;
            
            template <typename T>
            Constant& global() const {
                return global(api.types.get<T>());
            }
            
            template <typename T>
            Constant& global(const GlobalArgs& args) const {
                return global(api.types.get<T>(), args);
            }
            
            template <typename T>
            Constant& integer(T t, bool isConstant = true, bool insert = true) const {
                return global<T>(Api::GlobalArgs {
                        .module = insert ? &api.module : nullptr,
                        .isConstant = isConstant,
                        .initializer = api.constants.integer(t),
                });
            }
            
            Constant& constant(Constant& constant) const;
            
            ConstString string(const std::string& s) const;
            
            ConstString string(std::string_view s) const;
            
        };
        
        Symbol symbol(std::string_view symbolName) const;
        
        Symbol operator()(std::string_view symbolName) const;
        
    };
    
}
