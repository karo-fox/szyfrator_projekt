#include <string>

#include "CipherCommunicator.h"
#include "ceasar.h"
#include "validators.h"
#include "ValidationException.h"
#include "lang.h"

int CipherCommunicator::set_offset() const {
	while (true) {
		ui_.show_text(ui_.parse(LangCode::set_offset) + " [0 - 26]:");
		int offset = ui_.integer_input();
		try {
			validate_not_0(offset);
			validate_max_value(offset, 26);
			validate_min_value(offset, 1);
			return offset;
		}
		catch (const ValidationException<int>& e) {
			ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
		}
	}
}

int CipherCommunicator::set_rails() const {
	while (true) {
		ui_.show_text(ui_.parse(LangCode::set_rails) + " [0 - ]:");
		int offset = ui_.integer_input();
		try {
			validate_not_0(offset);
			validate_min_value(offset, 1);
			return offset;
		}
		catch (const ValidationException<int>& e) {
			ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
		}
	}
}

Direction CipherCommunicator::set_direction() const {
	while (true) {
		ui_.show_text(ui_.parse(LangCode::set_direction) + " [left/right]:");
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

std::string CipherCommunicator::set_keyword() const {
	while (true) {
		ui_.show_text(ui_.parse(LangCode::set_keyword) + ":");
		std::string keyword = ui_.text_input();
		try {
			validate_not_empty(keyword);
			validate_max_length(keyword, 26);
			validate_alpha(keyword);
			return keyword;
		}
		catch (const ValidationException<std::string>& e) {
			ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
		}
	}
}
