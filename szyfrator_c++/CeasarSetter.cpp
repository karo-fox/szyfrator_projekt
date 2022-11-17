#include "CeasarSetter.h"
#include "UserInterface.h"
#include "ceasar.h"

CeasarSetter::CeasarSetter(const UserInterface& ui)
	: ui_{ ui } {}

int CeasarSetter::set_offset() const {
	ui_.show_text("Set offset: ");
	int offset = ui_.integer_input();
	return offset;
}

Direction CeasarSetter::set_direction() const {
	ui_.show_text("Set direction( 0 for right or 1 for left): ");
	int direction = ui_.integer_input();
	return Direction(direction);
}