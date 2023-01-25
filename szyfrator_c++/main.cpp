#include <memory>

#include "FileManager.h"
#include "ConsoleUI.h"
#include "ScreenController.h"

#include "EncryptionContext.h"
#include "CeasarCipher.h"
#include "CipherCommunicator.h"

#include "Exception.h"
#include "lang.h"

int main() {
	// prepare user interface, CipherCommunicator, EncryptionContext,
	// FileManager and ScreenController
	ConsoleUI ui{};
	const CipherCommunicator communicator{ ui };
	EncryptionContext context{
		std::make_unique<CeasarCipher>(CeasarCipher{}), communicator
	}; // initialize with default cipher
	const FileManager file_manager{};
	ScreenController controller{ ui, context, file_manager };

	while (true) {
		try {
			controller.start(); // start the program flow
		}
		catch (const Exception& e) {
			// in case of unhandled program exception, restart the program
			ui.show_text(ui.parse(LangCode::uknown_exception) + ": " + e.what());
			controller.reset();
		}
	}	
}
