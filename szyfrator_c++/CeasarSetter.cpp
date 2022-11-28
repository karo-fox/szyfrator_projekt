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
			validateNot0(offset);
			validateMaxValue(offset, maxOffset_);
			validateMinValue(offset, 1);
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
			validateNotEmpty(input);
			validateAllowed(input, { "right", "left" });
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
		CeasarSetter::maxOffset_ = 26;
		return;
	case Alphabet::pl:
		CeasarSetter::maxOffset_ = 32;
		return;
	default:
		return;
	}
}