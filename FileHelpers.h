#ifndef _OSDL_FILE_HELPER_FUNCTIONS_
#define _OSDL_FILE_HELPER_FUNCTIONS_

#include <string>

namespace oSDL
{
	std::string GetExtension(std::string& path);
	std::string GetFilename(std::string& path);
	std::string GetDirectory(std::string& path);
}

#endif
