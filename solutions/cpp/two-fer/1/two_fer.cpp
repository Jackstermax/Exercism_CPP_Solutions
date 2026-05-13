#include "two_fer.h"

namespace two_fer {
    std::string two_fer(const std::string& name)    {
        std::string sentence {"One for @, one for me."};  
        sentence.replace(sentence.find('@'), 1, name.empty() ? "you" : name);
        return sentence;
    }
}  // namespace two_fer