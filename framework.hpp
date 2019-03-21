#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <utils.hpp>

namespace cs {
    class Framework {
    public:
        template<typename Func>
        static void execute(Func func, const std::string& message) {
            if (!cs::Benchmark::run(func)) {
                cs::Console::writeLine(message);
            }
        }
    };
}

#endif // FRAMEWORK_HPP
