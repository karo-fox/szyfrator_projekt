#include <iostream>
#include <memory>
#include "EncryptionContext.h"
#include "CeasarCipher.h"
#include "CeasarSetter.h"
#include "EnglishCLI.h"

int main() {
	const EnglishCLI ui{};
	const CeasarSetter ceasar_setter{ ui };
	CeasarCipher ceasar{ ceasar_setter };
	ceasar.new_settings();
	EncryptionContext context{std::make_unique<CeasarCipher>(ceasar)};
	std::string message{ context.encrypt_message("karolina") };
	ui.show_text(message);

	ui.show_text("[y/n]");
	ui.check_input();
}