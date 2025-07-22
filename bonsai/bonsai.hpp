/**
* @brief bonsai - A lightweight, single-header C++ HTTP micro-framework for building REST APIs quickly.
 * @version 1.0.0
 * @author Paul Contreras - github.com/pol-cova
 */
#ifndef BONSAI_HPP
#define BONSAI_HPP

#include <iostream>

namespace bonsai {
    namespace constants {
        constexpr int DEFAULT_PORT = 8080;
    }

    class Bonsai {
    public:
        explicit Bonsai();
        ~Bonsai() = default;

        void run(int port = constants::DEFAULT_PORT);
    };

    inline Bonsai::Bonsai() {
        std::cout << "Bonsai HTTP micro-framework initialized." << std::endl;
        // Additional initialization code can go here
    }

    inline void Bonsai::run(const int port) {
        std::cout << "Server is running on port " << port << "..." << std::endl;
    }

}
#endif //BONSAI_HPP
