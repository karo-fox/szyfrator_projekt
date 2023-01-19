#pragma once

#include <map>
#include <string>

#include "lang.h"

std::map<LangCode, std::string> polish{
	// general codes
	{ LangCode::yes, "tak" },
	{ LangCode::no, "nie" },
	{ LangCode::current_language, "Polski" },
	{ LangCode::invalid_input, "Podano nieprawidlowe dane" },
	{ LangCode::key_continue, "Nacisnij dowolny klawisz zeby kontunuowac" },
	// screen titles codes
	{ LangCode::main_title, "Szyfrator" },
	{ LangCode::settings_title, "Ustawienia" },
	// settings screen codes
	{ LangCode::show_language, "Jezyk" },
	{ LangCode::save_to_file, "Zapis do pliku" },
	{ LangCode::choose_language, "Wybierz jezyk" },
	// screen actions codes
	{ LangCode::main_screen_actions, 
		"settings: przejdz do ustawien\n"
		"start: rozpocznij szyfrowanie lub rozszyfrowanie\n"
		"quit: zakoncz dzialanie programu\n" },
	{ LangCode::settings_screen_actions, 
		"language: zmien jezyk interfejsu\n"
		"file: wlacz/wylacz zapisywanie do pliku\n"
		"back: wroc do ekranu glownego\n" },
	{ LangCode::available_screen_actions, "Dostepne akcje" },
	{ LangCode::choose_screen_action, "Wybierz akcje" },
	{ LangCode::action_not_found, 
		"Nie znaleziono akcji. Upewnij sie, ze poprawnie wpisano opcje i sprobuj ponownie" },
	// cipher choice codes
	{ LangCode::choose_cipher, "Wybierz jeden z nastepujacych szyfrow" },
	{ LangCode::available_ciphers,
		"ceasar: Szyfr Cezara\n" },
	// other encryption codes
	{ LangCode::result, "Twoj wynik" },
	{ LangCode::encrypt_decrypt, "Chcesz zaszyfrowac czy odszyfrowac?" },
	{ LangCode::provide_message, "Podaj wiadomosc" },
	// ceasar's settings codes
	{ LangCode::set_offset, "Ustaw przesuniecie" },
	{ LangCode::set_direction, "Ustaw kierunek" },
	// validation messages codes
	{ LangCode::v_max_length, 
		"Nie moze przekroczyc maksymalnej dlugosci, maksymalna dlugosc" },
	{ LangCode::v_not_empty, "Nie moze byc pusta" },
	{ LangCode::v_allowed, "Niedozwolone dane" },
	{ LangCode::v_not_0, "Nie moze byc 0" },
	{ LangCode::v_max_value, "Nie moze byc wieksze od" },
	{ LangCode::v_min_value, "Nie moze byc mniejsze od" },
};
