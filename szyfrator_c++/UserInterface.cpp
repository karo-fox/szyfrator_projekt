#include <string>
#include <utility>

#include "UserInterface.h"
#include "lang.h"
#include "en.h"
#include "pl.h"

langMap UserInterface::setup_lang_() {
	langMap lang_map{};
	lang_map.insert(std::pair<Language, locale>(Language::en, english));
	lang_map.insert(std::pair<Language, locale>(Language::pl, polish));
	return lang_map;
}

std::string UserInterface::parse(LangCode code) const {
	return translations_.at(settings_.lang).at(code);
}

template <typename T>
std::string UserInterface::parse(LangCode code, std::vector<T> args) const {
	return translations_.at(settings_.lang).at(code);
}

template <>
std::string UserInterface::parse(LangCode code, std::vector<std::string> args) const {
	std::string msg{ translations_.at(settings_.lang).at(code) };
	for (std::string& elem : args) {
		msg += " " + elem;
	}
	return msg;
}

template <>
std::string UserInterface::parse(LangCode code, std::vector<int> args) const {
	std::string msg{ translations_.at(settings_.lang).at(code) };
	for (int elem : args) {
		msg += " " + std::to_string(elem);
	}
	return msg;
}