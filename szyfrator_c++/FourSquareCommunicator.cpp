#include <string>

#include "FourSquareCommunicator.h"
#include "validators.h"
#include "ValidationException.h"

std::string FourSquareCommunicator::set_keyword() const {
	while (true) {
		ui_.show_text(ui_.parse(LangCode::set_keyword));
		std::string keyword = ui_.text_input();
		try {
			validate_not_empty(keyword);
			validate_max_length(keyword, max_length_);
			return keyword;
		}
		catch (const ValidationException<std::string>& e) {
			ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
		}
	}
}