/**
* @brief bonsai - A lightweight, single-header C++ HTTP micro-framework for building REST APIs quickly.
 * @version 0.0.1
 * @author Paul Contreras - github.com/pol-cova
 */
#ifndef BONSAI_HPP
#define BONSAI_HPP

#include <iostream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <string>

namespace bonsai {
    namespace constants {
        constexpr int DEFAULT_PORT = 8080;
        constexpr int DEFAULT_BROADCAST_PORT = 9999;
        constexpr std::string DEFAULT_HOST = "127.0.0.1";
    }

    namespace http {
        enum class Method {GET, POST, PUT, DELETE, PATCH, OPTIONS, HEAD};
        namespace status {
            enum class Code: int {OK=200, NOT_FOUND=404, INTERNAL_SERVER_ERROR=500};
        }

        namespace headers {
            class Headers {
                std::unordered_map<std::string, std::string> data;
                static std::string toLower(std::string key) {
                    std::ranges::transform(key, key.begin(),
                                           [](unsigned char c) { return std::tolower(c); });
                    return key;
                }
            public:
                void set(const std::string& key, const std::string& value) {
                    const std::string clean_key = toLower(key);
                    data[clean_key] = value;
                };
                std::string get(const std::string& key) {
                    return data[key];
                };
                [[nodiscard]] bool has(const std::string& key) const {
                    return data.contains(key);
                };
            };
        }

        // @brief Represents an HTTP request.
        class Request {
        private:
            Method method;
            std::string path;
            std::string version;
            headers::Headers request_headers;
            std::string body;

        public:
            Request(const Method m, std::string  url, std::string  ver )
                : method(m), path(std::move(url)), version(std::move(ver)) {}

            headers::Headers& headers() { return request_headers; }
        };

        // @brief Represents an HTTP response.
        class Response {

        };
    }



    class Bonsai {
    public:
        explicit Bonsai();
        ~Bonsai() = default;

        void run(int port = constants::DEFAULT_PORT);


    };

    inline Bonsai::Bonsai() {
    }

    inline void Bonsai::run(const int port) {
        std::cout << "Server is running on port " << port << "..." << std::endl;
    }

}
#endif //BONSAI_HPP
