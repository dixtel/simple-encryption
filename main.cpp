#include <iostream>
#include <string>

const char alphabet[37] = {' ', 'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

const std::string encode_alphabet[37] = {"__.__", "._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___", "_._", "._..", "__", "_.", "___", ".__.", "__._", "._.", "...", "_", ".._", "..._", ".__", "_.._", "_.__", "__..", "_____", ".____", "..___", "...__", "...._", ".....", "_....", "__...", "___..", "_____"};

const std::string separator = ".._.."; 

void InputText(std::string &text, std::string valid_words);
void DrawMenu();
char InputNum();
void Encode();
void Decode();

int main() {
	bool exit = false;
	while(!exit) {

		DrawMenu();

		switch(InputNum()) {
			case '1':
				Encode();								
				break;
			case '2':
				Decode();
				break;
			default:
				exit = true;
				break;
		}



	}

	return  0;
}

void InputText(std::string &text, std::string valid_words) {
	std::cout << ">";
	std::getline(std::cin >> std::ws, text);
	for(int i = 0; i < text.size(); i++ ) {
		for(int j = 0; j < valid_words.size(); j++) {
			if(text[i] == valid_words[j]) {
				text.clear();
				std::cout << "error: valid word" << std::endl;
			}
		}
	}
}

void DrawMenu() {
	std::cout << "--- encryption program ---\n1.encode\n2.decode\nelse: exit\n";
}

char InputNum() {
	char num;
	std::cout << ">";
	std::cin >> num;
	return num;
}

void Encode() {
	std::string text_to_encode;
	std::string encode_text; 
	InputText(text_to_encode, "!@#$%^&*()_-+={[}]:;\"'|\\<,>.?/~`"); 
	
	for(int i = 0; i < text_to_encode.size(); i++) {
		for(int j = 0; j < 37; j++) {
			if(alphabet[j] == text_to_encode[i]) {
				encode_text += encode_alphabet[j] + separator;
			}
		}
	}

	std::cout << encode_text << std::endl;	
}

void Decode() {
	std::string text_to_decode;
	std::string decode_text; 
	InputText(text_to_decode, "!@#$%^&*()-+={[}]:;\"'|\\<,>?/~`"); 
	
	std::string morse_word;
	std::string is_separator;
	for(int i = 0; i < text_to_decode.size(); i++) {
		morse_word += text_to_decode[i];
		
		if((text_to_decode[i+1] == separator[0]) && (text_to_decode[i+2] == separator[1]) && (text_to_decode[i+3] == separator[2]) && (text_to_decode[i+4] == separator[3]) && (text_to_decode[i+5] == separator[4])) {
			for(int j = 0; j < 37; j++) {
				if(encode_alphabet[j] == morse_word) {
					decode_text += alphabet[j];
				}				
			}			
			i += separator.size();
			morse_word.clear();
		}	
	}

	std::cout << decode_text << std::endl;
}
