//
// Created by Khyber on 8/3/2019.
//

#include "src/main/main.h"

#include "src/main/instructions/block/operator/Negate.h"

#include <iostream>

int main(int argc, char**) {
    scratch::block::operator_::Negate negate(reinterpret_cast<scratch::Value&>(argc));
    std::cout << llvm::size(negate.reads()) << std::endl;
    std::cout << llvm::size(negate.args()) << std::endl;
    return 0;
}
