#include <iostream>
#include <memory>
#include "EncryptionContext.h"
#include "CeasarCipher.h"
#include "CeasarSetter.h"
#include "CLI.h"

int main() {
	const CLI ui{};
	const CeasarSetter ceasar_setter{ ui };
	CeasarCipher ceasar{ ceasar_setter };
	ceasar.new_settings();
	EncryptionContext context{std::make_unique<CeasarCipher>(ceasar)};
	ui.show_text("Provide message: ");
	std::string input = ui.text_input();
	std::string e_message{ context.encrypt_message(input) };
	ui.show_text(e_message);
	std::string d_message{ context.decrypt_message(e_message) };
	ui.show_text(d_message);
}