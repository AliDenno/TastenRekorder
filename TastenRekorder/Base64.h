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
}

#endif // BASE_64