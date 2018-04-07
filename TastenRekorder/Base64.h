#ifndef BASE_64_H
#define BASE_64_H

#include <vector>
#include <string>

namespace BASE64 {
	std::string base64_encode(const std::string &);
	// strings to be used in encryption and scrambling 
	const std::string &SALT1 = "LM::TB::BB";
	const std::string &SALT2 = "_:/_77";
	const std::string &SALT3 = "line=wowC++";

	std::string EncryptB64(std::string s)
	{
		// Switch around and play with these ... simply make it harder 
		s = SALT1 + s + SALT2 + SALT3;
		s = base64_encode(s);
		s.insert(7, SALT3);
		s += SALT1;
		s = base64_encode(s);
		s = SALT2 + SALT3 + SALT1;
		s = base64_encode(s);
		s.insert(1, "L");
		s.insert(7, "M");
		return s;
	}
	const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	std::string base64_encode(const std::string &s) {
		std::string ret;//output string
		int val = 0;
		int bits = -6; // Group of 6 (6 sub groups)
		const unsigned int b63 = 0x3F; // hexa decimal - always positive
		for (const auto &c : s) { // Auto for not knowing the type 
			val = (val << 8) + c; //left binary shifting <shift left by 8 places> equalt to val = val * 2 ^ 8
			bits += 8;
			while (bits >= 0) {
				ret.push_back(BASE64_CODES[(val >> bits)& b63]); // Right shifting then binary Add 
				bits -= 6;
			}
		}
		if (bits > -6) { // at least one is inserted 
			ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8))&b63]);
			
			while (ret.size() % 4) { // greater than zero true else false (no modules) 
				ret.push_back('=');

				return ret;
			}
		}
	}
}

#endif // BASE_64