#include "CeasarCommunicator.h"
#include "UserInterface.h"
#include "ceasar.h"
#include "validators.h"
#include "ValidationException.h"
#include "lang.h"

int CeasarCommunicator::set_offset() const {
	while (true) {
		ui_.show_text(ui_.parse(LangCode::set_offset) + " [0 - 26]:");
		int offset = ui_.integer_input();
		try {
			validate_not_0(offset);
			validate_max_value(offset, max_offset_);
			validate_min_value(offset, 1);
			return offset;
		}
		catch (const ValidationException<int>& e) {
			ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
		}
	}
}

Direction CeasarCommunicator::set_direction() const {
	while (true) {
		ui_.show_text(ui_.parse(LangCode::set_direction) + "[left/right]:");
		std::string input = ui_.text_input();
		try {
			validate_not_empty(input);
			validate_allowed(input, { "right", "left" });
			if (input == "left") {
				return Direction::left;
			}
			else if (input == "right") {
				return Direction::right;
			}
		}
		catch (const ValidationException<std::string>& e) {
			ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
		}
		
	}
}