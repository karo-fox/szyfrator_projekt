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
	std::string input = ui.text_input();
	std::string message{ context.encrypt_message(input) };
	ui.show_text(message);
}