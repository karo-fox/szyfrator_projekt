#include "CeasarSetter.h"
#include "UserInterface.h"
#include "ceasar.h"
#include "validators.h"
#include "ValidationException.h"

int CeasarSetter::set_offset() const {
	while (true) {
		ui_.show_text("Set offset: ");
		int offset = ui_.integer_input();
		try {
			validate_not_0(offset);
			validate_max_value(offset, max_offset_);
			validate_min_value(offset, 1);
			return offset;
		}
		catch (const ValidationException<int>& e) {
			ui_.show_text(e.what());
		}
	}
}

Direction CeasarSetter::set_direction() const {
	while (true) {
		ui_.show_text("Set direction (right or left): ");
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
			ui_.show_text(e.what());
		}
		
	}
}

void CeasarSetter::choose_alphabet(Alphabet alphabet) {
	switch (alphabet) {
	case Alphabet::en:
		CeasarSetter::max_offset_ = 26;
		return;
	case Alphabet::pl:
		CeasarSetter::max_offset_ = 32;
		return;
	default:
		return;
	}
}