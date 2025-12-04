//
// Created by simone on 11/11/25.
//

#include "json_reader.hpp"
#include <iostream>
#include "../../util/util.hpp"
#include <fstream>

bool JSONReader::load(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;
    try {
        file >> data_;
    } catch (const nlohmann::json::parse_error &e) {
        error(true, ("Parse error: " + std::string(e.what()) + "\n").c_str());
    }
    return true;
}

bool JSONReader::has_field(const std::string &path) const {
    return visit(path);
}

nlohmann::detail::iteration_proxy<nlohmann::detail::iter_impl<const nlohmann::basic_json<>>> JSONReader::items(
    const std::string &path) const {
    const auto node = visit(path);
    return node->items();
}

const nlohmann::json* JSONReader::visit(const std::string &path) const {
    const nlohmann::json* current = &data_;
    size_t start = 0, end;
    while ((end = path.find('.', start)) != std::string::npos) {
        std::string key = path.substr(start, end - start);
        if (!current->contains(key)) return nullptr;
        current = &(*current)[key];
        start = end + 1;
    }
    const std::string last_key = path.substr(start);
    if (!current->contains(last_key)) return nullptr;
    return &(*current)[last_key];;
}
