#include <string>
using json = nlohmann::json;

class vk {
	private:
	std::string token;
	bool authorized = false;
	