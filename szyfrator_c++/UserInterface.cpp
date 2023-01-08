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