//
// Created by simone on 11/11/25.
//

#ifndef FARMANDCONQUER_JSON_READER_HPP
#define FARMANDCONQUER_JSON_READER_HPP

#include <string>
#include <json/json.hpp>


class JSONReader {
public:
    bool load(const std::string &filename);

    [[nodiscard]] bool has_field(const std::string &path) const;


    template<typename T>
    T get(const std::string &path) const {
        const nlohmann::json* current = &data_;
        size_t start = 0, end;
        while ((end = path.find('.', start)) != std::string::npos) {
            std::string key = path.substr(start, end - start);
            current = &current->at(key);
            start = end + 1;
        }
        const std::string last_key = path.substr(start);
        return current->at(last_key).get<T>();
    }

    nlohmann::detail::iteration_proxy<nlohmann::detail::iter_impl<const nlohmann::basic_json<>>> items(
        const std::string &path) const;

private:
    nlohmann::json data_;

    const nlohmann::json* visit(const std::string &path) const;
};

#endif //FARMANDCONQUER_JSON_READER_HPP
